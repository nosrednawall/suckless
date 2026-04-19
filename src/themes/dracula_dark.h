#ifndef THEME_H
#define THEME_H

/* Aparência geral */
static const char *fonts[] = {
    "FiraCode Nerd Font:size=10:antialias=true:autohint=true",
    "JoyPixels:size=10:antialias=true:autohint=true"
};

/* Cores base */
static const char norm_fg[]       = "#f8f8f2";
static const char norm_bg[]       = "#282a36";
static const char norm_border[]   = "#f1fa8c";

static const char sel_fg[]        = "#f8f8f2";
static const char sel_bg[]        = "#ffb86c";
static const char sel_border[]    = "#ff5555";

static const char urg_fg[]        = "#f8f8f2";
static const char urg_bg[]        = "#ff79c6";
static const char urg_border[]    = "#bd93f9";

/* Cores para tags */
static const char *tags_color[] = {
    "#f1fa8c",
    "#ffb86c",
    "#ff5555",
    "#ff79c6",
    "#bd93f9",
    "#8be9fd",
    "#50fa7b",
    "#6272a4",
    "#f8ffb8"
};

#endif
