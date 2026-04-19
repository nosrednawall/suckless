/* Terminal colors (16 first used in escape sequence) */
static const char *colorname[] = {
	/* 8 normal colors */
	"#1E1E2E",
	"#F38BA8",
	"#A6E3A1",
	"#F9E2AF",
	"#89B4FA",
	"#F5C2E7",
	"#94E2D5",
	"#BAC2DE",

	/* 8 bright colors */
	"#585B70",
	"#F38BA8",
	"#A6E3A1",
	"#F9E2AF",
	"#89B4FA",
	"#F5C2E7",
	"#94E2D5",
	"#A6ADC8",

[250] = "#CDD6F4", /* default foreground colour */
[251] = "#1E1E2E", /* default background colour */
[252] = "#F5E0DC", /*575268*/

};


/*
 * foreground, background, cursor, reverse cursor
 */
unsigned int defaultfg = 252;
unsigned int defaultbg = 0;
unsigned int defaultcs = 252;
static unsigned int defaultrcs = 0;
