#ifndef THEME_H
#define THEME_H

/* Aparência geral */
static const char *fonts[] = {
    "FiraCode Nerd Font:size=10:antialias=true:autohint=true",
    "JoyPixels:size=10:antialias=true:autohint=true"
};

/* Cores base */
static const char norm_fg[]       = "#c6d0f5";
static const char norm_bg[]       = "#303446";
static const char norm_border[]   = "#e5c890";

static const char sel_fg[]        = "#c6d0f5";
static const char sel_bg[]        = "#ef9f76";
static const char sel_border[]    = "#e78284";

static const char urg_fg[]        = "#c6d0f5";
static const char urg_bg[]        = "#ca9ee6";
static const char urg_border[]    = "#8caaee";

/* Cores para tags */
static const char *tags_color[] = {
    "#e5c890",
    "#ef9f76",
    "#e78284",
    "#ca9ee6",
    "#8caaee",
    "#81c8be",
    "#a6d189",
    "#b5bfe2",
    "#f5e0b8"
};

#endif
