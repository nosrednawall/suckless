#ifndef DRACULA_DARK_H_
#define DRACULA_DARK_H_

static const char *colorname[] = {
	/* Dracula Dark */
    /* 8 normal colors */
    [0] = "#282a36", /* black   */
    [1] = "#ff5555", /* red     */
    [2] = "#50fa7b", /* green   */
    [3] = "#f1fa8c", /* yellow  */
    [4] = "#bd93f9", /* blue    */
    [5] = "#ff79c6", /* magenta */
    [6] = "#8be9fd", /* cyan    */
    [7] = "#f8f8f2", /* white   */

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
    [250] = "#282a36", /* background */
    [251] = "#f8f8f2", /* foreground */
};

unsigned int defaultfg = 7; /* White */
unsigned int defaultbg = 0;  /* Background */
unsigned int defaultcs = 7; /* Cursor color */
unsigned int defaultrcs = 0; /* Reverse cursor color */

#endif // DRACULA_DARK_H_
