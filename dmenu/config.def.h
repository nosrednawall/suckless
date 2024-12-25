/* Default settings; can be overriden by command line. */

static int topbar = 1;                      /* -b  option; if 0, dmenu appears at bottom */
static int center = 1;                      /* -c  option; if 0, dmenu won't be centered on the screen */
static int min_width = 500;                 /* minimum width when centered */
/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[] =
{
	"CaskaydiaMono Nerd Font:size=15:style=Regular:antialias=true:pixelsize=17"
};
static const char *prompt      = NULL;      /* -p  option; prompt to the left of input field */

#include "themes/solarized_dark.h"

/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines      = 30;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = "";

/* Size of the window border */
static unsigned int border_width = 3;
