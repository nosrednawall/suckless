#ifndef THEME_H
#define THEME_H

/* Aparência geral */
static const char *fonts[] = {
    "FiraCode Nerd Font:size=10:antialias=true:autohint=true",
    "JoyPixels:size=10:antialias=true:autohint=true"
};

/* Cores base */
static const char norm_fg[]       = "#ebdbb2";
static const char norm_bg[]       = "#282828";
static const char norm_border[]   = "#d79921";

static const char sel_fg[]        = "#ebdbb2";
static const char sel_bg[]        = "#fe8019";
static const char sel_border[]    = "#fb4934";

static const char urg_fg[]        = "#ebdbb2";
static const char urg_bg[]        = "#d3869b";
static const char urg_border[]    = "#83a598";

/* Cores para tags */
static const char *tags_color[] = {
    "#d79921",
    "#fe8019",
    "#fb4934",
    "#d3869b",
    "#83a598",
    "#8ec07c",
    "#b8bb26",
    "#928374",
    "#f2c76e"
};

#endif
