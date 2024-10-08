/* See LICENSE file for copyright and license details. */

/*imports*/
#include <X11/XF86keysym.h>

/* appearance */
static const unsigned int borderpx       = 4;   /* border pixel of windows */
static const unsigned int snap           = 32;  /* snap pixel */
static const unsigned int gappih         = 20;  /* horiz inner gap between windows */
static const unsigned int gappiv         = 10;  /* vert inner gap between windows */
static const unsigned int gappoh         = 10;  /* horiz outer gap between windows and screen edge */
static const unsigned int gappov         = 30;  /* vert outer gap between windows and screen edge */
static const int smartgaps_fact          = 1;   /* gap factor when there is only one client; 0 = no gaps, 3 = 3x outer gaps */
static const char autostartblocksh[]     = "autostart_blocking.sh";
static const char autostartsh[]          = "autostart.sh";
static const char dwmdir[]               = "dwm";
static const char localshare[]           = ".local/share";
static const int showbar                 = 1;   /* 0 means no bar */
static const int topbar                  = 1;   /* 0 means bottom bar */
static const int bar_height              = 40;   /* 0 means derive from font, >= 1 explicit height */
static const int vertpad                 = 10;  /* vertical padding of bar */
static const int sidepad                 = 10;  /* horizontal padding of bar */
/* Status is to be shown on: -1 (all monitors), 0 (a specific monitor by index), 'A' (active monitor) */
static const int statusmon               = -1;
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int showsystray             = 1;   /* 0 means no systray */

/* Indicators: see patch/bar_indicators.h for options */
static int tagindicatortype              = INDICATOR_TOP_LEFT_SQUARE;
static int tiledindicatortype            = INDICATOR_NONE;
static int floatindicatortype            = INDICATOR_TOP_LEFT_SQUARE;
//static const char *fonts[]               = { "monospace:size=10" };
static const char *fonts[]          	 = {"CaskaydiaMono Nerd Font:size=15:style=Regular:antialias=true:pixelsize=17"};
static const char dmenufont[]            = "CaskaydiaMono Nerd Font:size=15:style=Regular:antialias=true:pixelsize=17";

static char c000000[]                    = "#000000"; // placeholder value
#include "themes/solarized_dark.h"

/*
static char normfgcolor[]                = "#bbbbbb";
static char normbgcolor[]                = "#222222";
static char normbordercolor[]            = "#444444";
static char normfloatcolor[]             = "#db8fd9";

static char selfgcolor[]                 = "#eeeeee";
static char selbgcolor[]                 = "#005577";
static char selbordercolor[]             = "#005577";
static char selfloatcolor[]              = "#005577";

static char titlenormfgcolor[]           = "#bbbbbb";
static char titlenormbgcolor[]           = "#222222";
static char titlenormbordercolor[]       = "#444444";
static char titlenormfloatcolor[]        = "#db8fd9";

static char titleselfgcolor[]            = "#eeeeee";
static char titleselbgcolor[]            = "#005577";
static char titleselbordercolor[]        = "#005577";
static char titleselfloatcolor[]         = "#005577";

static char tagsnormfgcolor[]            = "#bbbbbb";
static char tagsnormbgcolor[]            = "#222222";
static char tagsnormbordercolor[]        = "#444444";
static char tagsnormfloatcolor[]         = "#db8fd9";

static char tagsselfgcolor[]             = "#eeeeee";
static char tagsselbgcolor[]             = "#005577";
static char tagsselbordercolor[]         = "#005577";
static char tagsselfloatcolor[]          = "#005577";

static char hidnormfgcolor[]             = "#005577";
static char hidselfgcolor[]              = "#227799";
static char hidnormbgcolor[]             = "#222222";
static char hidselbgcolor[]              = "#222222";

static char urgfgcolor[]                 = "#bbbbbb";
static char urgbgcolor[]                 = "#222222";
static char urgbordercolor[]             = "#ff0000";
static char urgfloatcolor[]              = "#db8fd9";
*/


static char *colors[][ColCount] = {
	/*                       fg                bg                border                float */
	[SchemeNorm]         = { normfgcolor,      normbgcolor,      normbordercolor,      normfloatcolor },
	[SchemeSel]          = { selfgcolor,       selbgcolor,       selbordercolor,       selfloatcolor },
	[SchemeTitleNorm]    = { titlenormfgcolor, titlenormbgcolor, titlenormbordercolor, titlenormfloatcolor },
	[SchemeTitleSel]     = { titleselfgcolor,  titleselbgcolor,  titleselbordercolor,  titleselfloatcolor },
	[SchemeTagsNorm]     = { tagsnormfgcolor,  tagsnormbgcolor,  tagsnormbordercolor,  tagsnormfloatcolor },
	[SchemeTagsSel]      = { tagsselfgcolor,   tagsselbgcolor,   tagsselbordercolor,   tagsselfloatcolor },
	[SchemeHidNorm]      = { hidnormfgcolor,   hidnormbgcolor,   c000000,              c000000 },
	[SchemeHidSel]       = { hidselfgcolor,    hidselbgcolor,    c000000,              c000000 },
	[SchemeUrg]          = { urgfgcolor,       urgbgcolor,       urgbordercolor,       urgfloatcolor },
};

const char *spcmd1[] = {"st", "-n", "spterm", "-g", "120x34", NULL };
const char *spcmd2[] = {"st", "-n", "spfm", "-g", "144x41", "-e", "ranger", NULL };
const char *spcmd3[] = {"flatpak", "run", "com.bitwarden.desktop", NULL };
const char *spcmd4[] = {"st", "-n", "sppulse", "-g", "100x34", "-e", "pulsemixer", NULL };
const char *spcmd5[] = {"st", "-n", "sptop", "-g", "150x50", "-e", "btop", NULL };
const char *spcmd6[] = {"st", "-n", "spnmtui", "-g", "100x34", "-e", "nmtui", NULL };
const char *spcmd7[] = {"st", "-n", "spncmpcpp", "-g", "100x34", "-e", "ncmpcpp", NULL };
const char *spcmd8[] = {"/opt/google/chrome/google-chrome", "--profile-directory=Default", "--app-id=hnpfjngllnobngcgfapefoaidbinmjnm", NULL };
const char *spcmd9[] = {"st", "-n", "spytfzf", "-g", "100x34", "-e", "ytfzf", NULL };
const char *spcmd10[] = {"qalculate-gtk", NULL };
static Sp scratchpads[] = {
   /* name          cmd  */
	{"spterm",      		spcmd1},
	{"spranger",    		spcmd2},
	{"bitwarden",   		spcmd3},
	{"sppulse",     		spcmd4},
	{"sptop",       		spcmd5},
	{"spnmtui",     		spcmd6},
	{"spncmpcpp",   		spcmd7},
	{"whatsapp-chrome",   	spcmd8},
	{"spytfzf",		   		spcmd9},
	{"qalculate-gtk",		spcmd10},
};

/* Tags
 * In a traditional dwm the number of tags in use can be changed simply by changing the number
 * of strings in the tags array. This build does things a bit different which has some added
 * benefits. If you need to change the number of tags here then change the NUMTAGS macro in dwm.c.
 *
 * Examples:
 *
 *  1) static char *tagicons[][NUMTAGS*2] = {
 *         [DEFAULT_TAGS] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H", "I" },
 *     }
 *
 *  2) static char *tagicons[][1] = {
 *         [DEFAULT_TAGS] = { "•" },
 *     }
 *
 * The first example would result in the tags on the first monitor to be 1 through 9, while the
 * tags for the second monitor would be named A through I. A third monitor would start again at
 * 1 through 9 while the tags on a fourth monitor would also be named A through I. Note the tags
 * count of NUMTAGS*2 in the array initialiser which defines how many tag text / icon exists in
 * the array. This can be changed to *3 to add separate icons for a third monitor.
 *
 * For the second example each tag would be represented as a bullet point. Both cases work the
 * same from a technical standpoint - the icon index is derived from the tag index and the monitor
 * index. If the icon index is is greater than the number of tag icons then it will wrap around
 * until it an icon matches. Similarly if there are two tag icons then it would alternate between
 * them. This works seamlessly with alternative tags and alttagsdecoration patches.
 */
static char *tagicons[][NUMTAGS] =
{
	[DEFAULT_TAGS]        = { " 1 ", " 2 ", " 3 ", " 4 ", " 5 ", " 6 ", " 7 ", " 8 ", " 9 " },
	[ALTERNATIVE_TAGS]    = { "A", "B", "C", "D", "E", "F", "G", "H", "I" },
	[ALT_TAGS_DECORATION] = { "<1>", "<2>", "<3>", "<4>", "<5>", "<6>", "<7>", "<8>", "<9>" },
};

/* There are two options when it comes to per-client rules:
 *  - a typical struct table or
 *  - using the RULE macro
 *
 * A traditional struct table looks like this:
 *    // class      instance  title  wintype  tags mask  isfloating  monitor
 *    { "Gimp",     NULL,     NULL,  NULL,    1 << 4,    0,          -1 },
 *    { "Firefox",  NULL,     NULL,  NULL,    1 << 7,    0,          -1 },
 *
 * The RULE macro has the default values set for each field allowing you to only
 * specify the values that are relevant for your rule, e.g.
 *
 *    RULE(.class = "Gimp", .tags = 1 << 4)
 *    RULE(.class = "Firefox", .tags = 1 << 7)
 *
 * Refer to the Rule struct definition for the list of available fields depending on
 * the patches you enable.
 */
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 *	WM_WINDOW_ROLE(STRING) = role
	 *	_NET_WM_WINDOW_TYPE(ATOM) = wintype
	 */
	RULE(.wintype = WTYPE "DIALOG", .isfloating = 1)
	RULE(.wintype = WTYPE "UTILITY", .isfloating = 1)
	RULE(.wintype = WTYPE "TOOLBAR", .isfloating = 1)
	RULE(.wintype = WTYPE "SPLASH", .isfloating = 1)
	RULE(.class = "Gimp", .tags = 1 << 4)
	RULE(.class = "Firefox", .tags = 1 << 7)
	RULE(.class = "mpv", .tags = 0, .isfloating = 1)
	RULE(.class = "copyq", .tags = 0, .isfloating = 1)
	RULE(.instance = "spterm", .tags = SPTAG(0), .isfloating = 1)
	RULE(.instance = "spfm",  .tags = SPTAG(1), .isfloating = 1)
	RULE(.instance = "bitwarden",  .tags = SPTAG(2), .isfloating = 1)
	RULE(.instance = "sppulse",  .tags = SPTAG(3), .isfloating = 1)
	RULE(.instance = "sptop",  .tags = SPTAG(4), .isfloating = 1)
	RULE(.instance = "spnmtui" ,  .tags = SPTAG(5), .isfloating = 1)
	RULE(.instance = "spncmpcpp",  .tags = SPTAG(6), .isfloating = 1)
	RULE(.instance = "crx_hnpfjngllnobngcgfapefoaidbinmjnm",  .tags = SPTAG(7), .isfloating = 1)
	RULE(.instance = "spytfzf",	 .tags = SPTAG(8), .isfloating = 1)
	RULE(.instance = "qalculate-gtk",  .tags = SPTAG(9), .isfloating = 1)
};

/* Bar rules allow you to configure what is shown where on the bar, as well as
 * introducing your own bar modules.
 *
 *    monitor:
 *      -1  show on all monitors
 *       0  show on monitor 0
 *      'A' show on active monitor (i.e. focused / selected) (or just -1 for active?)
 *    bar - bar index, 0 is default, 1 is extrabar
 *    alignment - how the module is aligned compared to other modules
 *    widthfunc, drawfunc, clickfunc - providing bar module width, draw and click functions
 *    name - does nothing, intended for visual clue and for logging / debugging
 */
static const BarRule barrules[] = {
	/* monitor   bar    alignment         widthfunc                 drawfunc                clickfunc                hoverfunc                name */
	{ -1,        0,     BAR_ALIGN_LEFT,   width_tags,               draw_tags,              click_tags,              hover_tags,              "tags" },
	{  0,        0,     BAR_ALIGN_RIGHT,  width_systray,            draw_systray,           click_systray,           NULL,                    "systray" },
	{ -1,        0,     BAR_ALIGN_LEFT,   width_ltsymbol,           draw_ltsymbol,          click_ltsymbol,          NULL,                    "layout" },
	{ statusmon, 0,     BAR_ALIGN_RIGHT,  width_status2d,           draw_status2d,          click_status2d,          NULL,                    "status2d" },
	{ -1,        0,     BAR_ALIGN_NONE,   width_wintitle,           draw_wintitle,          click_wintitle,          NULL,                    "wintitle" },
};

/* layout(s) */
static const float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "TTT",      bstack },
	{ "===",      bstackhoriz },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
	{ "|||",      col },
	{ "[D]",      deck },
	{ "(@)",      spiral },
	{ "[\\]",     dwindle },
	{ "HHH",      grid },
	{ "---",      horizgrid },
	{ ":::",      gaplessgrid },
	{ "###",      nrowgrid },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {
	"dmenu_run",
	"-m", dmenumon,
	"-fn", dmenufont,
	"-nb", normbgcolor,
	"-nf", normfgcolor,
	"-sb", selbgcolor,
	"-sf", selfgcolor,
	NULL
};
static const char *termcmd[]  = { "st", NULL };

static const Key keys[] = {
	/* modifier                     key            function                argument */
	{ MODKEY,                       XK_p,          spawn,                  {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return,     spawn,                  {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_b,          togglebar,              {0} },
	/*Modimentacao das janelas*/
	{ MODKEY,                       XK_Right,      	focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_Left,      	focusstack,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_Up,      	incnmaster,     {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_Down,      	incnmaster,     {.i = -1 } },
	{ MODKEY,           			XK_Up,      	setmfact,       {.f = -0.05} },
	{ MODKEY,             			XK_Down,      	setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, 		zoom,           {0} },
	{ MODKEY,                       XK_Tab,    		view,           {0} },

/*
	{ MODKEY,                       XK_j,          focusstack,             {.i = +1 } },
	{ MODKEY,                       XK_k,          focusstack,             {.i = -1 } },
	{ MODKEY,                       XK_i,          incnmaster,             {.i = +1 } },
	{ MODKEY,                       XK_d,          incnmaster,             {.i = -1 } },
	{ MODKEY,                       XK_h,          setmfact,               {.f = -0.05} },
	{ MODKEY,                       XK_l,          setmfact,               {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_h,          setcfact,               {.f = +0.25} },
	{ MODKEY|ShiftMask,             XK_l,          setcfact,               {.f = -0.25} },
	{ MODKEY|ShiftMask,             XK_o,          setcfact,               {0} },
	{ MODKEY|ControlMask|ShiftMask, XK_e,          aspectresize,           {.i = +24} },
	{ MODKEY|ControlMask|ShiftMask, XK_r,          aspectresize,           {.i = -24} },
	{ MODKEY,                       XK_Return,     zoom,                   {0} },

	{ MODKEY|ShiftMask,             XK_h,      setcfact,       {.f = +0.25} },
	{ MODKEY|ShiftMask,             XK_l,      setcfact,       {.f = -0.25} },
	{ MODKEY|ShiftMask,             XK_o,      setcfact,       {.f =  0.00} },

	{ MODKEY|Mod1Mask,              XK_u,      incrgaps,       {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_u,      incrgaps,       {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_i,      incrigaps,      {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_i,      incrigaps,      {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_o,      incrogaps,      {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_o,      incrogaps,      {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_6,      incrihgaps,     {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_6,      incrihgaps,     {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_7,      incrivgaps,     {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_7,      incrivgaps,     {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_8,      incrohgaps,     {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_8,      incrohgaps,     {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_9,      incrovgaps,     {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_9,      incrovgaps,     {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_0,      togglegaps,     {0} },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_0,      defaultgaps,    {0} },

*/

	{ MODKEY|Mod1Mask,              XK_u,          incrgaps,               {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_u,          incrgaps,               {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_i,          incrigaps,              {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_i,          incrigaps,              {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_o,          incrogaps,              {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_o,          incrogaps,              {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_6,          incrihgaps,             {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_6,          incrihgaps,             {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_7,          incrivgaps,             {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_7,          incrivgaps,             {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_8,          incrohgaps,             {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_8,          incrohgaps,             {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_9,          incrovgaps,             {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_9,          incrovgaps,             {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_0,          togglegaps,             {0} },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_0,          defaultgaps,            {0} },

	{ MODKEY,                       XK_Tab,        view,                   {0} },
	{ MODKEY|ShiftMask,             XK_c,          killclient,             {0} },
	{ MODKEY|ShiftMask,             XK_q,      						quit,           {0} },
	{ MODKEY|ShiftMask,				XK_r,      						quit,           {1} },

	//Layouts
	{ MODKEY,                       	XK_F1,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       	XK_F2,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,              				XK_F3,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,              				XK_F4,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY,             				XK_F5,      setlayout,      {.v = &layouts[4]} },
	{ MODKEY,             				XK_F6,      setlayout,      {.v = &layouts[5]} },
	{ MODKEY,              				XK_F7,      setlayout,      {.v = &layouts[6]} },
	{ MODKEY,              				XK_F8,      setlayout,      {.v = &layouts[7]} },
	{ MODKEY,             				XK_F9,      setlayout,      {.v = &layouts[8]} },
	{ MODKEY,                       	XK_F10,     setlayout,      {.v = &layouts[9]} },
	{ MODKEY,             				XK_F11,     setlayout,      {.v = &layouts[10]} },
	{ MODKEY,             				XK_F12,     setlayout,      {.v = &layouts[11]} },
	{ MODKEY|ShiftMask,              	XK_F1,      setlayout,      {.v = &layouts[12]} },
	{ MODKEY|ShiftMask,                 XK_F2,      setlayout,      {.v = &layouts[13]} },


	{ MODKEY,                       XK_space,      setlayout,              {0} },
	{ MODKEY|ShiftMask,             XK_space,      togglefloating,         {0} },
	{ MODKEY,                       XK_grave,      togglescratch,          {.ui = 0 } },

	{ MODKEY,            			XK_s,  	   togglescratch,  {.ui = 0 } },
	{ MODKEY|ShiftMask,            	XK_f,	   togglescratch,  {.ui = 1 } },
	{ MODKEY,            			XK_b,	   togglescratch,  {.ui = 2 } },
	{ MODKEY,            			XK_a,	   togglescratch,  {.ui = 3 } },
	{ MODKEY|ShiftMask,            	XK_h,	   togglescratch,  {.ui = 4 } },
	{ MODKEY,            			XK_n,	   togglescratch,  {.ui = 5 } },
	{ MODKEY,            			XK_m,	   togglescratch,  {.ui = 6 } },
	{ MODKEY,            			XK_c,	   togglescratch,  {.ui = 7 } },
	{ MODKEY,            			XK_y,	   togglescratch,  {.ui = 8 } },
	{ MODKEY,           			XK_q,	   togglescratch,  {.ui = 9 } },
	/*Meus atalhos*/
	{ ControlMask|Mod1Mask,         XK_l,                           spawn,          SHCMD("~/.local/bin/dwm/slock_personalizado") },
	{ 0,					        XK_Caps_Lock,                   spawn,          SHCMD("~/.local/bin/dwm/som_capslock_numlock") },
	{ 0,					        XK_Num_Lock,                    spawn,          SHCMD("~/.local/bin/dwm/som_capslock_numlock") },
	{ 0,					        XK_Scroll_Lock,                 spawn,          SHCMD("~/.local/bin/dwm/som_capslock_numlock") },
	{ MODKEY,			            XK_k,                           spawn,          SHCMD("~/.local/bin/dwm/altera-layout-teclado") },

	/*volume pulseaudio*/
	{ 0,                            XF86XK_AudioLowerVolume,        spawn,          SHCMD("~/.local/bin/dwm/diminui_volume") },
	{ 0,                            XF86XK_AudioRaiseVolume,        spawn,          SHCMD("~/.local/bin/dwm/aumenta_volume") },
	{ 0,                            XF86XK_AudioMute,               spawn,          SHCMD("~/.local/bin/dwm/muta_volume") },

	/*Volume Microfone Pulseaudio*/
	{ ControlMask,                  XF86XK_AudioRaiseVolume,        spawn,          SHCMD("~/.local/bin/dwm/aumenta_volume_microfone") },
	{ ControlMask,                  XF86XK_AudioLowerVolume,        spawn,          SHCMD("~/.local/bin/dwm/diminui_volume_microfone") },
	{ ControlMask,                  XF86XK_AudioMute,               spawn,          SHCMD("~/.local/bin/dwm/muta_microfone") },

	/*Player de musica*/
	{ 0,                            XF86XK_AudioPlay,               spawn,          SHCMD("~/.local/bin/dwm/playerctl_play") },
	{ 0,                            XF86XK_AudioStop,               spawn,          SHCMD("~/.local/bin/dwm/playerctl_stop") },
	{ 0,                            XF86XK_AudioPrev,               spawn,          SHCMD("~/.local/bin/dwm/playerctl_prev") },
	{ 0,                            XF86XK_AudioNext,               spawn,          SHCMD("~/.local/bin/dwm/playerctl_next") },

	/*Outros atalhos teclado*/
	{ 0,                            XF86XK_HomePage,                spawn,          SHCMD("~/.local/bin/dwm/homepage_program") },
	{ 0,                            XF86XK_Mail,                    spawn,          SHCMD("~/.local/bin/dwm/mail_program") },
	{ 0,                            XF86XK_Search,                  spawn,          SHCMD("~/.local/bin/dwm/search_program") },
	{ 0,                            XF86XK_Calculator,              spawn,          SHCMD("~/.local/bin/dwm/calculator_program") },

	/*Printscreen*/
	{ MODKEY|ShiftMask,             XK_s,                           spawn,          SHCMD("~/.local/bin/dwm/print_edita") },
	{ 0,                            XK_Print,                       spawn,          SHCMD("~/.local/bin/dwm/print_copia") },

	/*Brilho tela notebook*/
	{ 0,							XF86XK_MonBrightnessUp,			spawn,          SHCMD("~/.local/bin/dwm/brilho_tela_aumenta") },
	{ 0,							XF86XK_MonBrightnessDown,		spawn,          SHCMD("~/.local/bin/dwm/brilho_tela_diminui") },

	/*Dmenus*/
	{ MODKEY|ShiftMask,             XK_e,                           spawn,          SHCMD("~/.local/bin/dmenu/dmenu-saida-sistema" ) },
	{ ControlMask|Mod1Mask,         XK_p,                           spawn,          SHCMD("~/.local/bin/dmenu/dmenu-pass" ) },
	{ MODKEY|ShiftMask,             XK_d,                           spawn,          SHCMD("~/.local/bin/dmenu/dmenu-docker" ) },
	{ MODKEY|ShiftMask,				XK_w,							spawn,			SHCMD("~/.local/bin/dmenu/dmenu-controle-monitor" ) },
	{ MODKEY|ShiftMask,             XK_a,                           spawn,          SHCMD("~/.local/bin/dmenu/dmenu-controle-som") },
//	{ MODKEY|ShiftMask,             XK_y,                           spawn,          SHCMD("~/.local/bin/dmenu/dmenu-youtube") },
	{ MODKEY|ShiftMask,             XK_t,                           spawn,          SHCMD("~/.local/bin/dmenu/dmenu-tema") },
	{ MODKEY|ShiftMask,             XK_v,                           spawn,          SHCMD("~/.local/bin/dmenu/dmenu-vpn") },
	{ MODKEY|ShiftMask,	            XK_m,                           spawn,          SHCMD("~/.local/bin/dmenu/dmenu-powertop") },

	/*Rofi menus*/
	{ MODKEY,						XK_d,	   						spawn,          SHCMD("~/.local/bin/dwm/roficmd") },

	/*Lancamento Programas*/
	{ MODKEY,						XK_w,							spawn,			SHCMD("google-chrome" ) },
	{ MODKEY,						XK_e,							spawn,			SHCMD("emacsclient -c -a 'emacs'" ) },
//	{ MODKEY,						XK_o,							spawn,			SHCMD("flatpak run md.obsidian.Obsidian" ) },
//	{ MODKEY|ShiftMask,				XK_d,							spawn,			SHCMD("flatpak run so.libdb.dissent" ) },
//	{ MODKEY,						XK_t,							spawn,			SHCMD("flatpak run org.telegram.desktop" ) },
//	{ MODKEY,						XK_r,							spawn,			SHCMD("rstudio" ) },
	{ MODKEY,						XK_f,							spawn,			SHCMD("thunar" ) }
	{ MODKEY|ControlMask,           XK_grave,      setscratch,             {.ui = 0 } },
	{ MODKEY|ShiftMask,             XK_grave,      removescratch,          {.ui = 0 } },
	{ MODKEY,                       XK_0,          view,                   {.ui = ~SPTAGMASK } },
	{ MODKEY|ShiftMask,             XK_0,          tag,                    {.ui = ~SPTAGMASK } },
	{ MODKEY,                       XK_comma,      focusmon,               {.i = -1 } },
	{ MODKEY,                       XK_period,     focusmon,               {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,      tagmon,                 {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,     tagmon,                 {.i = +1 } },
	{ MODKEY|ControlMask,           XK_comma,      cyclelayout,            {.i = -1 } },
	{ MODKEY|ControlMask,           XK_period,     cyclelayout,            {.i = +1 } },
	TAGKEYS(                        XK_1,                                  0)
	TAGKEYS(                        XK_2,                                  1)
	TAGKEYS(                        XK_3,                                  2)
	TAGKEYS(                        XK_4,                                  3)
	TAGKEYS(                        XK_5,                                  4)
	TAGKEYS(                        XK_6,                                  5)
	TAGKEYS(                        XK_7,                                  6)
	TAGKEYS(                        XK_8,                                  7)
	TAGKEYS(                        XK_9,                                  8)
	/*Meus atalhos*/
	{ ControlMask|Mod1Mask,         XK_l,                           spawn,          SHCMD("~/.local/bin/dwm/slock_personalizado") },
	{ 0,					        XK_Caps_Lock,                   spawn,          SHCMD("~/.local/bin/dwm/som_capslock_numlock") },
	{ 0,					        XK_Num_Lock,                    spawn,          SHCMD("~/.local/bin/dwm/som_capslock_numlock") },
	{ 0,					        XK_Scroll_Lock,                 spawn,          SHCMD("~/.local/bin/dwm/som_capslock_numlock") },
	{ MODKEY,			            XK_k,                           spawn,          SHCMD("~/.local/bin/dwm/altera-layout-teclado") },

	/*volume pulseaudio*/
	{ 0,                            XF86XK_AudioLowerVolume,        spawn,          SHCMD("~/.local/bin/dwm/diminui_volume") },
	{ 0,                            XF86XK_AudioRaiseVolume,        spawn,          SHCMD("~/.local/bin/dwm/aumenta_volume") },
	{ 0,                            XF86XK_AudioMute,               spawn,          SHCMD("~/.local/bin/dwm/muta_volume") },

	/*Volume Microfone Pulseaudio*/
	{ ControlMask,                  XF86XK_AudioRaiseVolume,        spawn,          SHCMD("~/.local/bin/dwm/aumenta_volume_microfone") },
	{ ControlMask,                  XF86XK_AudioLowerVolume,        spawn,          SHCMD("~/.local/bin/dwm/diminui_volume_microfone") },
	{ ControlMask,                  XF86XK_AudioMute,               spawn,          SHCMD("~/.local/bin/dwm/muta_microfone") },

	/*Player de musica*/
	{ 0,                            XF86XK_AudioPlay,               spawn,          SHCMD("~/.local/bin/dwm/playerctl_play") },
	{ 0,                            XF86XK_AudioStop,               spawn,          SHCMD("~/.local/bin/dwm/playerctl_stop") },
	{ 0,                            XF86XK_AudioPrev,               spawn,          SHCMD("~/.local/bin/dwm/playerctl_prev") },
	{ 0,                            XF86XK_AudioNext,               spawn,          SHCMD("~/.local/bin/dwm/playerctl_next") },

	/*Outros atalhos teclado*/
	{ 0,                            XF86XK_HomePage,                spawn,          SHCMD("~/.local/bin/dwm/homepage_program") },
	{ 0,                            XF86XK_Mail,                    spawn,          SHCMD("~/.local/bin/dwm/mail_program") },
	{ 0,                            XF86XK_Search,                  spawn,          SHCMD("~/.local/bin/dwm/search_program") },
	{ 0,                            XF86XK_Calculator,              spawn,          SHCMD("~/.local/bin/dwm/calculator_program") },

	/*Printscreen*/
	{ MODKEY|ShiftMask,             XK_s,                           spawn,          SHCMD("~/.local/bin/dwm/print_edita") },
	{ 0,                            XK_Print,                       spawn,          SHCMD("~/.local/bin/dwm/print_copia") },

	/*Brilho tela notebook*/
	{ 0,							XF86XK_MonBrightnessUp,			spawn,          SHCMD("~/.local/bin/dwm/brilho_tela_aumenta") },
	{ 0,							XF86XK_MonBrightnessDown,		spawn,          SHCMD("~/.local/bin/dwm/brilho_tela_diminui") },

	/*Dmenus*/
	{ MODKEY|ShiftMask,             XK_e,                           spawn,          SHCMD("~/.local/bin/dmenu/dmenu-saida-sistema" ) },
	{ ControlMask|Mod1Mask,         XK_p,                           spawn,          SHCMD("~/.local/bin/dmenu/dmenu-pass" ) },
	{ MODKEY|ShiftMask,             XK_d,                           spawn,          SHCMD("~/.local/bin/dmenu/dmenu-docker" ) },
	{ MODKEY|ShiftMask,				XK_w,							spawn,			SHCMD("~/.local/bin/dmenu/dmenu-controle-monitor" ) },
	{ MODKEY|ShiftMask,             XK_a,                           spawn,          SHCMD("~/.local/bin/dmenu/dmenu-controle-som") },
//	{ MODKEY|ShiftMask,             XK_y,                           spawn,          SHCMD("~/.local/bin/dmenu/dmenu-youtube") },
	{ MODKEY|ShiftMask,             XK_t,                           spawn,          SHCMD("~/.local/bin/dmenu/dmenu-tema") },
	{ MODKEY|ShiftMask,             XK_v,                           spawn,          SHCMD("~/.local/bin/dmenu/dmenu-vpn") },
	{ MODKEY|ShiftMask,	            XK_m,                           spawn,          SHCMD("~/.local/bin/dmenu/dmenu-powertop") },

	/*Rofi menus*/
	{ MODKEY,						XK_d,	   						spawn,          SHCMD("~/.local/bin/dwm/roficmd") },

	/*Lancamento Programas*/
	{ MODKEY,						XK_w,							spawn,			SHCMD("google-chrome" ) },
	{ MODKEY,						XK_e,							spawn,			SHCMD("emacsclient -c -a 'emacs'" ) },
//	{ MODKEY,						XK_o,							spawn,			SHCMD("flatpak run md.obsidian.Obsidian" ) },
//	{ MODKEY|ShiftMask,				XK_d,							spawn,			SHCMD("flatpak run so.libdb.dissent" ) },
//	{ MODKEY,						XK_t,							spawn,			SHCMD("flatpak run org.telegram.desktop" ) },
//	{ MODKEY,						XK_r,							spawn,			SHCMD("rstudio" ) },
	{ MODKEY,						XK_f,							spawn,			SHCMD("thunar" ) }
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask           button          function        argument */
	{ ClkLtSymbol,          0,                   Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,                   Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,                   Button2,        zoom,           {0} },
	{ ClkStatusText,        0,                   Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,              Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,              Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,              Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,                   Button1,        view,           {0} },
	{ ClkTagBar,            0,                   Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,              Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,              Button3,        toggletag,      {0} },
};

