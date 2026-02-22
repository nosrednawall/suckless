#!/usr/bin/env bash
###############################################################################
##
## Usage
##
##     ./<script_name> [<OPTIONS>] [<THEME_NAME>]
##
##     If it does not run, give execute permissions to the script with
##     chmod +x <script_name>. Then run ./<script_name>.
##
## Options
##
##     -h|--help            Optional. Show help message.
##     -l|--list            Optional. List available themes.
##     -s|--save <name>     Optional. Save current theme from X resources.
##     -c|--create <name>   Optional. Create a new theme from template.
##
## Description
##
##     This script manages dunst themes, generating a complete dunstrc file
##     by merging the base configuration with the selected theme.
##
##     Themes are stored in $HOME/.config/dunst/themes/ directory.
##
###############################################################################

set -e

# Check if appres is installed
if [ ! "$(command -v appres)" ]; then
    printf 'Install xorg-appres in archlinux and x11-utils in debian/ubuntu.\n'
    exit 1
fi

readonly script_name="$(basename "$0")"
readonly base_dir="$(realpath "$(dirname "$0")")"

# Show usage
usage() {
    grep -e '^##[^#]*$' "$base_dir/$script_name"  | \
        sed -e "s/^##[[:space:]]\{0,1\}//g" \
            -e "s/<script_name>/${script_name}/g"
    exit 2
} 2>/dev/null

# Parse arguments
THEME_NAME=""
SAVE_THEME=""
CREATE_THEME=""
LIST_THEMES=false

while [[ $# -gt 0 ]]; do
    case $1 in
        -h|--help)
            usage
            ;;
        -l|--list)
            LIST_THEMES=true
            shift
            ;;
        -s|--save)
            SAVE_THEME="$2"
            shift 2
            ;;
        -c|--create)
            CREATE_THEME="$2"
            shift 2
            ;;
        *)
            if [[ -z "$THEME_NAME" ]]; then
                THEME_NAME="$1"
                shift
            else
                printf '\nUnknown option or multiple themes specified.\n'
                usage
            fi
            ;;
    esac
done

# Function to get resource values
xrdb_get () {
    output="$(appres Dunst | grep "$1:" | head -n1 | cut -f2)"
    default="$2"
    printf '%s' "${output:-$default}"
}

#
# File paths
#
readonly user_conf_dir="${XDG_CONFIG_HOME:-$HOME/.config}/dunst"
readonly user_conf="$user_conf_dir/dunstrc"
readonly themes_dir="$user_conf_dir/themes"
readonly base_conf="$user_conf_dir/dunst-base.conf"
readonly backup_dir="$user_conf_dir/backups"

# Create directories if they don't exist
mkdir -p "$themes_dir"
mkdir -p "$backup_dir"

# List themes function
list_themes() {
    echo "Available themes:"
    if [ -d "$themes_dir" ] && [ "$(ls -A "$themes_dir" 2>/dev/null)" ]; then
        for theme in "$themes_dir"/*.conf; do
            if [ -f "$theme" ]; then
                theme_name=$(basename "$theme" .conf)
                current=""
                if [ -f "$user_conf" ]; then
                    # Check if this theme is currently applied by looking at the file content
                    if grep -q "# Theme: ${theme_name}" "$user_conf" 2>/dev/null; then
                        current=" (current)"
                    fi
                fi
                echo "  - $theme_name$current"
            fi
        done
    else
        echo "  No themes found in $themes_dir"
    fi
    
    # Check if base config exists
    if [ -f "$base_conf" ]; then
        echo ""
        echo "Base configuration: $base_conf"
    fi
}

# Create theme from template
create_theme() {
    local theme_name="$1"
    local theme_file="$themes_dir/${theme_name}.conf"
    
    if [ -f "$theme_file" ]; then
        echo "Theme '${theme_name}' already exists. Use -s to overwrite from X resources."
        return 1
    fi
    
    # Create template theme
    cat > "$theme_file" << EOF
# Theme: ${theme_name}
# Created: $(date)
# Edit the colors below to customize your theme

[urgency_low]
    background = "#282828"
    foreground = "#ebdbb2"
    frame_color = "#504945"
    # timeout = 10

[urgency_normal]
    background = "#282828"
    foreground = "#ebdbb2"
    frame_color = "#504945"
    # timeout = 10

[urgency_critical]
    background = "#282828"
    foreground = "#fb4934"
    frame_color = "#cc241d"
    # timeout = 0
EOF
    
    echo "Theme template created: ${theme_name}.conf"
    echo "Edit it with: nano $theme_file"
}

# Save theme from X resources
save_theme_from_xresources() {
    local theme_name="$1"
    local theme_file="$themes_dir/${theme_name}.conf"
    
    echo "Creating theme '${theme_name}' from X resources..."
    
    # Get colors from X resources with defaults
    bg_low="\"$(xrdb_get 'color0' '#2b303b')\""
    fg_low="\"$(xrdb_get 'color4' '#65737e')\""
    frame_low="\"$(xrdb_get 'color4' '#65737e')\""
    
    bg_normal="\"$(xrdb_get 'color0' '#2b303b')\""
    fg_normal="\"$(xrdb_get 'color2' '#a3be8c')\""
    frame_normal="\"$(xrdb_get 'color2' '#a3be8c')\""
    
    bg_critical="\"$(xrdb_get 'color0' '#2b303b')\""
    fg_critical="\"$(xrdb_get 'color1' '#bf616a')\""
    frame_critical="\"$(xrdb_get 'color1' '#bf616a')\""
    
    # Create theme file
    cat > "$theme_file" << EOF
# Theme: ${theme_name} (generated from X resources)
# Date: $(date)

[urgency_low]
    background = ${bg_low}
    foreground = ${fg_low}
    frame_color = ${frame_low}

[urgency_normal]
    background = ${bg_normal}
    foreground = ${fg_normal}
    frame_color = ${frame_normal}

[urgency_critical]
    background = ${bg_critical}
    foreground = ${fg_critical}
    frame_color = ${frame_critical}
EOF
    
    echo "Theme '${theme_name}' created from X resources."
}

# Apply theme function - now generates a complete dunstrc
apply_theme() {
    local theme_name="$1"
    local theme_file="$themes_dir/${theme_name}.conf"

    if [ ! -f "$theme_file" ]; then
        echo "Theme '${theme_name}' not found in $themes_dir"
        list_themes
        exit 1
    fi

    # Check if base config exists
    if [ ! -f "$base_conf" ]; then
        echo "Base configuration not found: $base_conf"
        echo "Please ensure dunst-base.conf exists."
        exit 1
    fi

    # Create backup of current config if it exists
    if [ -f "$user_conf" ]; then
        backup_file="$backup_dir/dunstrc.backup.$(date +%Y%m%d_%H%M%S)"
        cp "$user_conf" "$backup_file"
        echo "Backup created: $backup_file"
    fi

    # Generate complete dunstrc by merging base and theme
    {
        echo "# Dunst configuration file"
        echo "# Generated by $script_name on $(date)"
        echo "# Current theme: ${theme_name}"
        echo ""
        
        # Add base configuration
        cat "$base_conf"
        echo ""
        echo ""
        echo "# Theme: ${theme_name}"
        echo "# Colors and urgency settings"
        echo ""
        
        # Add theme configuration
        cat "$theme_file"
        
    } > "$user_conf"

    echo "Theme '${theme_name}' applied successfully!"
    echo "Configuration saved to: $user_conf"
    echo ""
    echo "To apply changes, restart dunst:"
    echo "  killall dunst 2>/dev/null && dunst &"
    echo ""
    echo "Or if using systemd:"
    echo "  systemctl --user restart dunst"
    echo ""
    echo "To revert to previous configuration:"
    echo "  cp $backup_dir/$(ls -t "$backup_dir" | head -1) $user_conf"
}

# Function to show current theme
show_current() {
    if [ -f "$user_conf" ]; then
        # Try to find theme information in the file
        theme_line=$(grep "^# Current theme:" "$user_conf" | head -1)
        if [ -n "$theme_line" ]; then
            echo "$theme_line"
        else
            # Check if it's a generated file by looking at urgency sections
            if grep -q "^\[urgency_low\]" "$user_conf"; then
                echo "Current configuration: Custom (not generated by this script)"
            else
                echo "Current configuration: Unknown format"
            fi
        fi
    else
        echo "No dunst configuration file found."
    fi
}

# Main execution
if [ "$LIST_THEMES" = true ]; then
    list_themes
    exit 0
fi

if [ -n "$SAVE_THEME" ]; then
    save_theme_from_xresources "$SAVE_THEME"
    exit 0
fi

if [ -n "$CREATE_THEME" ]; then
    create_theme "$CREATE_THEME"
    exit 0
fi

if [ -n "$THEME_NAME" ]; then
    apply_theme "$THEME_NAME"
    exit 0
fi

# If no arguments, show current status
echo "=== Dunst Theme Manager ==="
echo ""
show_current
echo ""
list_themes
echo ""
echo "Usage examples:"
echo "  $script_name -l                    # List themes"
echo "  $script_name -c mynewtheme          # Create new theme from template"
echo "  $script_name -s myxrestheme         # Create theme from X resources"
echo "  $script_name gruvbox-dark           # Apply theme"
