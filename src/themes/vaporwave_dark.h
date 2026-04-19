#ifndef THEME_H
#define THEME_H

/* Aparência geral */
static const char *fonts[] = {
    "FiraCode Nerd Font:size=10:antialias=true:autohint=true",
    "JoyPixels:size=10:antialias=true:autohint=true"
};

/* Cores base */
static const char norm_fg[]       = "#d8d8d8";
static const char norm_bg[]       = "#2e1a47";
static const char norm_border[]   = "#ff77ff";

static const char sel_fg[]        = "#d8d8d8";
static const char sel_bg[]        = "#9c64e8";
static const char sel_border[]    = "#ff6c6c";

static const char urg_fg[]        = "#d8d8d8";
static const char urg_bg[]        = "#ff5a8f";
static const char urg_border[]    = "#7ec8ff";

/* Cores para tags */
static const char *tags_color[] = {
    "#ff77ff",
    "#9c64e8",
    "#ff6c6c",
    "#ff5a8f",
    "#7ec8ff",
    "#84e1f2",
    "#76ff7f",
    "#b8a4c9",
    "#ffa3ff"
};

#endif
