#ifndef THEME_H
#define THEME_H

/* Aparência geral */
static const char *fonts[] = {
    "FiraCode Nerd Font:size=10:antialias=true:autohint=true",
    "JoyPixels:size=10:antialias=true:autohint=true"
};

/* Cores base */
static const char norm_fg[]       = "EOF"
    echo -n "$COLOR_TEXT"
    cat >> "$theme_file" << 'EOF'
";
static const char norm_bg[]       = "EOF"
    echo -n "$COLOR_BACKGROUND"
    cat >> "$theme_file" << 'EOF'
";
static const char norm_border[]   = "EOF"
    echo -n "$COLOR_1"
    cat >> "$theme_file" << 'EOF'
";

static const char sel_fg[]        = "EOF"
    echo -n "$COLOR_TEXT"
    cat >> "$theme_file" << 'EOF'
";
static const char sel_bg[]        = "EOF"
    echo -n "$COLOR_2"
    cat >> "$theme_file" << 'EOF'
";
static const char sel_border[]    = "EOF"
    echo -n "$COLOR_3"
    cat >> "$theme_file" << 'EOF'
";

static const char urg_fg[]        = "EOF"
    echo -n "$COLOR_TEXT"
    cat >> "$theme_file" << 'EOF'
";
static const char urg_bg[]        = "EOF"
    echo -n "$COLOR_4"
    cat >> "$theme_file" << 'EOF'
";
static const char urg_border[]    = "EOF"
    echo -n "$COLOR_5"
    cat >> "$theme_file" << 'EOF'
";

/* Cores para tags */
static const char *tags_color[] = {
    "EOF"
    echo -n "$COLOR_1" >> "$theme_file"
    echo '",' >> "$theme_file"
    echo "    \"$COLOR_2\"," >> "$theme_file"
    echo "    \"$COLOR_3\"," >> "$theme_file"
    echo "    \"$COLOR_4\"," >> "$theme_file"
    echo "    \"$COLOR_5\"," >> "$theme_file"
    echo "    \"$COLOR_6\"," >> "$theme_file"
    echo "    \"$COLOR_7\"," >> "$theme_file"
    echo "    \"$COLOR_8\"," >> "$theme_file"
    echo "    \"$COLOR_9\"" >> "$theme_file"
    cat >> "$theme_file" << 'EOF'
};

#endif
