const char *colorname[] = {

  /* 8 normal colors */
  [0] = "#10151b", /* black   */
  [1] = "#B96D61", /* red     */
  [2] = "#BA9E76", /* green   */
  [3] = "#A9738A", /* yellow  */
  [4] = "#9A9D9F", /* blue    */
  [5] = "#9AA1A9", /* magenta */
  [6] = "#BFC9D2", /* cyan    */
  [7] = "#c3c4c6", /* white   */

  /* 8 bright colors */
  [8]  = "#5c6570",  /* black   */
  [9]  = "#B96D61",  /* red     */
  [10] = "#BA9E76", /* green   */
  [11] = "#A9738A", /* yellow  */
  [12] = "#9A9D9F", /* blue    */
  [13] = "#9AA1A9", /* magenta */
  [14] = "#BFC9D2", /* cyan    */
  [15] = "#c3c4c6", /* white   */

  /* special colors */
  [256] = "#10151b", /* background */
  [257] = "#c3c4c6", /* foreground */
  [258] = "#c3c4c6",     /* cursor */
};

/* Default colors (colorname index)
 * foreground, background, cursor */
 unsigned int defaultbg = 0;
 unsigned int defaultfg = 257;
 unsigned int defaultcs = 258;
 unsigned int defaultrcs= 258;
