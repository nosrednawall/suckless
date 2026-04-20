#ifndef THEME_H
#define THEME_H

/* Aparência geral */
static const char *fonts[] = {
    "FiraCode Nerd Font:size=10:antialias=true:autohint=true",
    "JoyPixels:size=10:antialias=true:autohint=true"
};

/* Cores base */
static const char norm_fg[]       = "#839496";
static const char norm_bg[]       = "#002B36";
static const char norm_border[]   = "#b58900";

static const char sel_fg[]        = "#839496";
static const char sel_bg[]        = "#cb4b16";
static const char sel_border[]    = "#dc322f";

static const char urg_fg[]        = "#839496";
static const char urg_bg[]        = "#d33682";
static const char urg_border[]    = "#6c71c4";

/* Cores para tags */
static const char *tags_color[] = {
    "#b58900",
    "#cb4b16",
    "#dc322f",
    "#d33682",
    "#6c71c4",
    "#268bd2",
    "#859900",
    "#2aa198",
    "#f0c674"
};

#endif
