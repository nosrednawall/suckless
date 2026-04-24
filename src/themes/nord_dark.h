#ifndef THEME_H
#define THEME_H

/* Aparência geral */
static const char *fonts[] = {
    "FiraCode Nerd Font:size=10:antialias=true:autohint=true",
    "JoyPixels:size=10:antialias=true:autohint=true"
};

/* Cores base */
static const char norm_fg[]       = "#d8dee9";
static const char norm_bg[]       = "#2e3440";
static const char norm_border[]   = "#ebcb8b";

static const char sel_fg[]        = "#d8dee9";
static const char sel_bg[]        = "#d08770";
static const char sel_border[]    = "#bf616a";

static const char urg_fg[]        = "#d8dee9";
static const char urg_bg[]        = "#b48ead";
static const char urg_border[]    = "#81a1c1";

/* Cores para tags */
static const char *tags_color[] = {
    "#ebcb8b",
    "#d08770",
    "#bf616a",
    "#b48ead",
    "#81a1c1",
    "#88c0d0",
    "#a3be8c",
    "#4c566a",
    "#f5e5bc"
};

#endif
