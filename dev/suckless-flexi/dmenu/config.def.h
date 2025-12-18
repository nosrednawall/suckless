/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int topbar 	 = 1;               /* -b  option; if 0, dmenu appears at bottom */
static int opacity 	 = 1;               /* -o  option; if 0, then alpha is disabled */
static int fuzzy 	 = 1;               /* -F  option; if 0, dmenu doesn't use fuzzy matching */
static const int vertpad = 10;              /* vertical padding of bar */
static const int sidepad = 10;              /* horizontal padding of bar */
static char *fonts[] = 			    /* -fn option overrides fonts[0]; default X11 font or font set */
{
	"Victor Mono:style=Bold Italic:size=11:weight=160",
	"Twemoji:pixelsize=18:antialias=true:autohint=true",
};
static const char *prompt             = NULL;      /* -p  option; prompt to the left of input field */

static const unsigned int baralpha    = 0xd0;
static const unsigned int borderalpha = OPAQUE;
static const unsigned int alphas[][3]      = {
	/*                 fg      bg        border     */
	[SchemeNorm]   = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]    = { OPAQUE, baralpha, borderalpha },
	[SchemeBorder] = { OPAQUE, OPAQUE,   OPAQUE },
	[SchemeHp]     = { OPAQUE, baralpha, borderalpha },
	[SchemeHover]  = { OPAQUE, baralpha, borderalpha },
	[SchemeGreen]  = { OPAQUE, baralpha, borderalpha },
	[SchemeRed]    = { OPAQUE, baralpha, borderalpha },
	[SchemeYellow] = { OPAQUE, baralpha, borderalpha },
	[SchemeBlue]   = { OPAQUE, baralpha, borderalpha },
	[SchemePurple] = { OPAQUE, baralpha, borderalpha },
};

static
char *colors[][2] = {
	/*                 fg         bg       */
	[SchemeNorm]   = { "#bbbbbb", "#222222" },
	[SchemeSel]    = { "#eeeeee", "#005577" },
	[SchemeOut]    = { "#000000", "#00ffff" },
	[SchemeBorder] = { "#000000", "#005577" },
	[SchemeHp]     = { "#bbbbbb", "#333333" },
	[SchemeHover]  = { "#ffffff", "#353D4B" },
	[SchemeGreen]  = { "#ffffff", "#52E067" },
	[SchemeRed]    = { "#ffffff", "#e05252" },
	[SchemeYellow] = { "#ffffff", "#e0c452" },
	[SchemeBlue]   = { "#ffffff", "#5280e0" },
	[SchemePurple] = { "#ffffff", "#9952e0" },
};

static unsigned int lines      	   = 10; /* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int columns    	   = 0;  /* -g option; if nonzero, dmenu uses a grid comprised of columns and lines */
static unsigned int lineheight 	   = 40; /* -h option; minimum height of a menu line     */
static unsigned int min_lineheight = 8;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";

/* Size of the window border */
static unsigned int border_width = 0;

