#!/bin/bash

# Configurações
CONFIG_FILE="$HOME/.config/suckless/scripts/themes/temas.conf"
SUCKLESS_BASE="$HOME/.config/suckless/src"
THEMES_DIR="$SUCKLESS_BASE/themes"
SUCKLESS_DIRS=("dwm" "st" "dmenu" "slock")

# Detecta distribuição para sudo_askpass
if [ -f /etc/os-release ]; then
    . /etc/os-release
    case "$ID" in
        arch) sudo_askpass="/usr/lib/ssh/gnome-ssh-askpass3" ;;
        debian) sudo_askpass="/usr/bin/ssh-askpass" ;;
        *) sudo_askpass="/usr/bin/ssh-askpass" ;;
    esac
fi

# Função para ler valor de uma seção
get_theme_value() {
    local theme="$1"
    local key="$2"

    awk -v theme="[$theme]" -v key="$key" '
        $0 == theme { found=1 }
        found && $1 == key && $2 == "=" {
            gsub(/^[ \t]+/, "", $3)
            gsub(/[ \t]+$/, "", $3)
            print $3
            exit
        }
        found && /^\[/ && $0 != theme { exit }
    ' "$CONFIG_FILE"
}

# Função para carregar tema do arquivo de configuração
load_theme() {
    local theme_name="$1"

    # Verifica se o tema existe
    if ! grep -q "^\[$theme_name\]$" "$CONFIG_FILE"; then
        echo "Tema não encontrado: $theme_name"
        return 1
    fi

    # Carrega todas as variáveis
    THEME_GTK=$(get_theme_value "$theme_name" "theme_gtk")
    THEME_ICON=$(get_theme_value "$theme_name" "theme_icon")
    THEME_MODE=$(get_theme_value "$theme_name" "theme_mode")
    COLOR_MODE=$(get_theme_value "$theme_name" "color_mode")
    GTK_PREFER_DARK_MODE=$(get_theme_value "$theme_name" "gtk_prefer_dark")
    EMACS_THEME=$(get_theme_value "$theme_name" "emacs_theme")
    WALLPAPER_LIGHTDM=$(get_theme_value "$theme_name" "wallpaper")

    COLOR_BACKGROUND=$(get_theme_value "$theme_name" "background")
    COLOR_BACKGROUND2=$(get_theme_value "$theme_name" "background2")
    COLOR_TEXT=$(get_theme_value "$theme_name" "text")

    COLOR_1=$(get_theme_value "$theme_name" "color1")
    COLOR_2=$(get_theme_value "$theme_name" "color2")
    COLOR_3=$(get_theme_value "$theme_name" "color3")
    COLOR_4=$(get_theme_value "$theme_name" "color4")
    COLOR_5=$(get_theme_value "$theme_name" "color5")
    COLOR_6=$(get_theme_value "$theme_name" "color6")
    COLOR_7=$(get_theme_value "$theme_name" "color7")
    COLOR_8=$(get_theme_value "$theme_name" "color8")
    COLOR_9=$(get_theme_value "$theme_name" "color9")
    COLOR_10=$(get_theme_value "$theme_name" "color10")
    COLOR_11=$(get_theme_value "$theme_name" "color11")
    COLOR_12=$(get_theme_value "$theme_name" "color12")
    COLOR_13=$(get_theme_value "$theme_name" "color13")
    COLOR_14=$(get_theme_value "$theme_name" "color14")
    COLOR_15=$(get_theme_value "$theme_name" "color15")
    COLOR_16=$(get_theme_value "$theme_name" "color16")

    # Exporta variáveis
    export THEME_NAME="$theme_name"
    export THEME_GTK THEME_ICON THEME_MODE COLOR_MODE
    export GTK_PREFER_DARK_MODE EMACS_THEME WALLPAPER_LIGHTDM
    export COLOR_BACKGROUND COLOR_BACKGROUND2 COLOR_TEXT
    export COLOR_{1..16}
}

# Função para gerar arquivo de tema do suckless
generate_suckless_theme() {
    local theme_file="$THEMES_DIR/${THEME_MODE,,}_${COLOR_MODE,,}.h"
    mkdir -p "$THEMES_DIR"

    cat > "$theme_file" << EOF
#ifndef THEME_H
#define THEME_H

/* Aparência geral */
static const char *fonts[] = {
    "FiraCode Nerd Font:size=10:antialias=true:autohint=true",
    "JoyPixels:size=10:antialias=true:autohint=true"
};

/* Cores base */
static const char norm_fg[]       = "$COLOR_TEXT";
static const char norm_bg[]       = "$COLOR_BACKGROUND";
static const char norm_border[]   = "$COLOR_1";

static const char sel_fg[]        = "$COLOR_TEXT";
static const char sel_bg[]        = "$COLOR_2";
static const char sel_border[]    = "$COLOR_3";

static const char urg_fg[]        = "$COLOR_TEXT";
static const char urg_bg[]        = "$COLOR_4";
static const char urg_border[]    = "$COLOR_5";

/* Cores para tags */
static const char *tags_color[] = {
    "$COLOR_1",
    "$COLOR_2",
    "$COLOR_3",
    "$COLOR_4",
    "$COLOR_5",
    "$COLOR_6",
    "$COLOR_7",
    "$COLOR_8",
    "$COLOR_9"
};

#endif
EOF
}

# Função para aplicar configurações GTK
apply_gtk_settings() {
    # GTK2
    if [ -f ~/.config/gtk-2.0/gtkrc ]; then
        sed -i "s/^gtk-icon-theme-name =.*/gtk-icon-theme-name = \"$THEME_ICON\"/" ~/.config/gtk-2.0/gtkrc
        sed -i "s/^gtk-theme-name =.*/gtk-theme-name = \"$THEME_GTK\"/" ~/.config/gtk-2.0/gtkrc
    fi

    if [ -f ~/.gtkrc-2.0 ]; then
        sed -i "s/^gtk-icon-theme-name=.*/gtk-icon-theme-name=\"$THEME_ICON\"/" ~/.gtkrc-2.0
        sed -i "s/^gtk-theme-name=.*/gtk-theme-name=\"$THEME_GTK\"/" ~/.gtkrc-2.0
    fi

    # GTK3
    if [ -f ~/.config/gtk-3.0/settings.ini ]; then
        sed -i "s/^gtk-theme-name=.*/gtk-theme-name=$THEME_GTK/" ~/.config/gtk-3.0/settings.ini
        sed -i "s/^gtk-icon-theme-name=.*/gtk-icon-theme-name=$THEME_ICON/" ~/.config/gtk-3.0/settings.ini
        sed -i "s/^gtk-application-prefer-dark-theme=.*/gtk-application-prefer-dark-theme=$GTK_PREFER_DARK_MODE/" ~/.config/gtk-3.0/settings.ini
    fi

    # Flatpak
    if command -v flatpak &> /dev/null; then
        SUDO_ASKPASS="$sudo_askpass" sudo flatpak override --filesystem="$HOME/.themes" 2>/dev/null
        SUDO_ASKPASS="$sudo_askpass" sudo flatpak override --env=GTK_THEME="$THEME_GTK" 2>/dev/null
    fi
}

# Função para compilar programas suckless
compile_suckless() {
    local progress=40
    local success=true

    for program in "${SUCKLESS_DIRS[@]}"; do
        local program_dir="$SUCKLESS_BASE/$program"

        if [ ! -d "$program_dir" ]; then
            echo "Aviso: Diretório não encontrado: $program_dir"
            continue
        fi

        echo "Compilando $program em $program_dir..."

        cd "$program_dir" || {
            echo "Erro: Não foi possível acessar $program_dir"
            success=false
            continue
        }

        # Limpa compilações anteriores
        rm -f config.h

        # Compila
        if ! make; then
            echo "Erro: Falha ao compilar $program"
            success=false
            continue
        fi

        # Instala
        if ! SUDO_ASKPASS="$sudo_askpass" sudo make clean install; then
            echo "Erro: Falha ao instalar $program"
            success=false
            continue
        fi

        dunstify "Aplicando tema" "Compilando $program..." \
            -h int:value:$((progress+=15)) \
            -i /usr/share/icons/ePapirus/16x16/status/package-reinstall.svg
    done

    if [ "$success" = false ]; then
        dunstify "Erro" "Falha na compilação de algum programa" -u critical
    fi
}

# Função para aplicar wallpaper
apply_wallpaper() {
    if [ "$pywal_flag" = "1" ]; then
        sudo cp -r "$pywal_wallpaper" "/usr/share/images/desktop-base/$WALLPAPER_LIGHTDM" 2>/dev/null
    else
        local wallpaper_dir="$HOME/.wallpapers/${THEME_MODE}/${COLOR_MODE}"

        if [ -d "$wallpaper_dir" ]; then
            local wallpaper=$(find "$wallpaper_dir" -type f \( -iname \*.jpg -o -iname \*.png -o -iname \*.jpeg \) 2>/dev/null | shuf -n 1)

            if [ -n "$wallpaper" ]; then
                feh --bg-fill "$wallpaper" &
                sudo cp -r "$wallpaper" "/usr/share/images/desktop-base/$WALLPAPER_LIGHTDM" 2>/dev/null
            fi
        fi
    fi
}

# Função para aplicar tema pywal
apply_pywal() {
    local mode="$1"
    local wallpaper="$2"

    pywal_flag="1"

    # Executa pywal
    if [ -n "$wallpaper" ]; then
        bash "$HOME/.config/suckless/scripts/others/pywal-execute" "$mode" "$wallpaper"
    else
        bash "$HOME/.config/suckless/scripts/others/pywal-execute" "$mode"
    fi

    sleep 1

    # Carrega cores do pywal
    local colors_json="$HOME/.cache/wal/colors.json"

    if [ ! -f "$colors_json" ]; then
        echo "Erro: pywal não gerou o arquivo de cores"
        return 1
    fi

    pywal_wallpaper=$(jq -r '.wallpaper' "$colors_json")

    # Define variáveis do pywal
    THEME_GTK="FlatColor"
    THEME_ICON="flattrcolor"
    THEME_MODE="Pywal"
    COLOR_MODE="${mode^}"
    GTK_PREFER_DARK_MODE=1
    EMACS_THEME="doom-one"
    WALLPAPER_LIGHTDM="$(basename "$pywal_wallpaper")"

    # Carrega cores do JSON
    COLOR_BACKGROUND=$(jq -r '.colors.color0' "$colors_json")
    COLOR_BACKGROUND2=$(jq -r '.colors.color0' "$colors_json")
    COLOR_TEXT=$(jq -r '.colors.color7' "$colors_json")

    COLOR_1=$(jq -r '.colors.color1' "$colors_json")   # Yellow
    COLOR_2=$(jq -r '.colors.color2' "$colors_json")   # Orange
    COLOR_3=$(jq -r '.colors.color3' "$colors_json")   # Red
    COLOR_4=$(jq -r '.colors.color4' "$colors_json")   # Magenta
    COLOR_5=$(jq -r '.colors.color5' "$colors_json")   # Violet
    COLOR_6=$(jq -r '.colors.color6' "$colors_json")   # Blue
    COLOR_7=$(jq -r '.colors.color8' "$colors_json")   # Green
    COLOR_8=$(jq -r '.colors.color9' "$colors_json")   # Cyan

    COLOR_9=$(jq -r '.colors.color1' "$colors_json")   # Yellow
    COLOR_10=$(jq -r '.colors.color2' "$colors_json")  # Orange
    COLOR_11=$(jq -r '.colors.color3' "$colors_json")  # Red
    COLOR_12=$(jq -r '.colors.color4' "$colors_json")  # Magenta
    COLOR_13=$(jq -r '.colors.color5' "$colors_json")  # Violet
    COLOR_14=$(jq -r '.colors.color6' "$colors_json")  # Blue
    COLOR_15=$(jq -r '.colors.color8' "$colors_json")  # Green
    COLOR_16=$(jq -r '.colors.color9' "$colors_json")  # Cyan

    export COLOR_BACKGROUND COLOR_BACKGROUND2 COLOR_TEXT
    export COLOR_{1..16}
}

# Função para atualizar arquivos de configuração
update_config_files() {
    # Atualiza includes nos config.def.h
    for program in "${SUCKLESS_DIRS[@]}"; do
        local config_file="$SUCKLESS_BASE/$program/config.def.h"

        if [ -f "$config_file" ]; then
            # Caminho relativo para o tema (themes/...)
            sed -i "s|^#include \"themes/.*|#include \"themes/${THEME_MODE,,}_${COLOR_MODE,,}.h\"|" "$config_file"
            echo "Atualizado $config_file para incluir themes/${THEME_MODE,,}_${COLOR_MODE,,}.h"
        fi
    done

    # Atualiza Emacs Doom
    if [ -f ~/.config/doom/config.el ]; then
        sed -i "s|(setq doom-theme .*)|(setq doom-theme '$EMACS_THEME)|" ~/.config/doom/config.el
    fi

    # Atualiza Btop
    if [ -f ~/.config/btop/btop.conf ]; then
        sed -i "s|^color_theme =.*|color_theme = \"${THEME_MODE,,}_${COLOR_MODE,,}\"|" ~/.config/btop/btop.conf
    fi

    # Atualiza LightDM
    if [ -d /etc/lightdm ]; then
        sudo cp -r "$HOME/.icons/$THEME_ICON" /usr/share/icons/ 2>/dev/null
        sudo cp -r "$HOME/.themes/$THEME_GTK" /usr/share/themes/ 2>/dev/null

        sudo rm -f /etc/lightdm/lightdm-gtk-greeter.conf

        sudo bash -c "cat > /etc/lightdm/lightdm-gtk-greeter.conf << EOF
[greeter]
background=/usr/share/images/desktop-base/$WALLPAPER_LIGHTDM
theme-name=$THEME_GTK
cursor-theme-name=capitaine-cursors-gruvbox-white
icon-theme-name=$THEME_ICON
default-user-image=/var/lib/AccountsService/icons/default.png
indicators=~a11y;~language;~spacer;~host;~clock;~spacer;~session;~power;
EOF"

        # Slock wallpaper
        sudo rm -rf /usr/share/images/desktop-base/wallpaper-slock
        sudo ln -s "/usr/share/images/desktop-base/$WALLPAPER_LIGHTDM" /usr/share/images/desktop-base/wallpaper-slock
    fi
}

# Função para reiniciar serviços
restart_services() {
    # Reinicia Dunst
    killall dunst 2>/dev/null
    dunst -conf "$HOME/.config/dunst/themes/${THEME_MODE}_${COLOR_MODE}" &

    # Fecha programas systray
    killall copyq 2>/dev/null
    killall solaar 2>/dev/null
    killall slock 2>/dev/null

    # Reinicia dwmblocks
    kill -10 $(pidof dwmblocks) 2>/dev/null

    # Restart dwm (apenas se estiver rodando)
    if pgrep -x "dwm" > /dev/null; then
        xdotool key Super_L+r 2>/dev/null
    fi
}

# Script principal
main() {
    local choice="$1"
    local pywal_flag="0"

    if [ -z "$choice" ]; then
        exit 0
    fi

    # Remove espaços do início
    choice=$(echo "$choice" | sed 's/^[[:space:]]*//')

    # Verifica se é tema pywal
    if [[ "$choice" == "Wallpaper"* ]] || [[ "$choice" == "pywal" ]]; then
        case "$choice" in
            "Wallpaper Aleatório Dark"|"pywal")
                apply_pywal "dark"
                ;;
            "Wallpaper Atual Dark")
                local current_wallpaper=$(grep -oP "'\K[^']+(?=')" ~/.fehbg 2>/dev/null)
                apply_pywal "dark" "$current_wallpaper"
                ;;
            "Wallpaper Aleatório Light")
                apply_pywal "light"
                ;;
            "Wallpaper Atual Light")
                local current_wallpaper=$(grep -oP "'\K[^']+(?=')" ~/.fehbg 2>/dev/null)
                apply_pywal "light" "$current_wallpaper"
                ;;
            *)
                echo "Opção pywal inválida: $choice"
                exit 1
                ;;
        esac
    else
        load_theme "$choice"

        if [ $? -ne 0 ]; then
            exit 1
        fi
    fi

    # Salva tema selecionado
    cat > ~/.theme_selected << EOF
#!/bin/bash
THEME_GTK="$THEME_GTK"
THEME_ICON="$THEME_ICON"
THEME_MODE="$THEME_MODE"
COLOR_MODE="$COLOR_MODE"
GTK_PREFER_DARK_MODE="$GTK_PREFER_DARK_MODE"
EMACS_THEME="$EMACS_THEME"
WALLPAPER_LIGHTDM="$WALLPAPER_LIGHTDM"
COLOR_BACKGROUND="$COLOR_BACKGROUND"
COLOR_BACKGROUND2="$COLOR_BACKGROUND2"
COLOR_TEXT="$COLOR_TEXT"
COLOR_1="$COLOR_1"
COLOR_2="$COLOR_2"
COLOR_3="$COLOR_3"
COLOR_4="$COLOR_4"
COLOR_5="$COLOR_5"
COLOR_6="$COLOR_6"
COLOR_7="$COLOR_7"
COLOR_8="$COLOR_8"
COLOR_9="$COLOR_9"
COLOR_10="$COLOR_10"
COLOR_11="$COLOR_11"
COLOR_12="$COLOR_12"
COLOR_13="$COLOR_13"
COLOR_14="$COLOR_14"
COLOR_15="$COLOR_15"
COLOR_16="$COLOR_16"
EOF

    dunstify "Aplicando tema" "Configurando $THEME_MODE $COLOR_MODE..." \
        -h int:value:10 \
        -i /usr/share/icons/ePapirus/16x16/status/package-reinstall.svg

    # Aplica todas as configurações
    generate_suckless_theme
    apply_gtk_settings
    update_config_files

    dunstify "Aplicando tema" "Aplicando wallpaper..." \
        -h int:value:30 \
        -i /usr/share/icons/ePapirus/16x16/status/package-reinstall.svg

    apply_wallpaper

    dunstify "Aplicando tema" "Compilando programas..." \
        -h int:value:40 \
        -i /usr/share/icons/ePapirus/16x16/status/package-reinstall.svg

    compile_suckless

    dunstify "Aplicando tema" "Reiniciando serviços..." \
        -h int:value:90 \
        -i /usr/share/icons/ePapirus/16x16/status/package-reinstall.svg

    restart_services

    dunstify "Pronto" "Tema $THEME_MODE $COLOR_MODE aplicado com sucesso!" \
        -h int:value:100 \
        -i /usr/share/icons/ePapirus/16x16/status/package-install.svg
}

main "$@"
