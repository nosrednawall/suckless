/* Default settings; can be overriden by command line. */

static int topbar = 1;                      /* -b  option; if 0, dmenu appears at bottom */
static int center = 1;                      /* -c  option; if 0, dmenu won't be centered on the screen */
static int min_width = 600;                 /* minimum width when centered */
/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[] =
{
//	"Fira Mono:pixelsize=14:antialias=true:autohint=true",
	"Caskaydia Mono Nerd Font:size=14:style=Regular:antialias=true:pixelsize=15",
    "Symbols Nerd Font:style=Bold:antialias=true:pixelsize=16",  //for dwmblocks
	"Font Awesome 6 Free Solid:style=Bold:pixelsize=16",  // for weather in dwmblocks
};
static const char *prompt      = NULL;      /* -p  option; prompt to the left of input field */

#include "themes/nord_dark.h"

/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines      = 35;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = "";

/* Size of the window border */
static unsigned int border_width = 3;
