#ifndef DRACULA_DARK_H_
#define DRACULA_DARK_H_

static const char *colorname[] = {
	/* Dracula Dark */
    /* 8 normal colors */
    [0] = "#000000", /* black   */
    [1] = "#ff5555", /* red     */
    [2] = "#50fa7b", /* green   */
    [3] = "#f1fa8c", /* yellow  */
    [4] = "#bd93f9", /* blue    */
    [5] = "#ff79c6", /* magenta */
    [6] = "#8be9fd", /* cyan    */
    [7] = "#bbbbbb", /* white   */

    /* 8 bright colors */
    [8]  = "#44475a", /* black   */
    [9]  = "#ff5555", /* red     */
    [10] = "#50fa7b", /* green   */
    [11] = "#f1fa8c", /* yellow  */
    [12] = "#bd93f9", /* blue    */
    [13] = "#ff79c6", /* magenta */
    [14] = "#8be9fd", /* cyan    */
    [15] = "#ffffff", /* white   */

    /* special colors */
    [256] = "#282a36", /* background */
    [257] = "#f8f8f2", /* foreground */
};

unsigned int defaultfg = 257; /* White */
unsigned int defaultbg = 256;  /* Background */
unsigned int defaultcs = 257; /* Cursor color */
unsigned int defaultrcs = 257; /* Reverse cursor color */

#endif // DRACULA_DARK_H_
