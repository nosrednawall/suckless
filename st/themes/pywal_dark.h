const char *colorname[] = {

  /* 8 normal colors */
  [0] = "#141213", /* black   */
  [1] = "#727F7C", /* red     */
  [2] = "#6E866E", /* green   */
  [3] = "#729791", /* yellow  */
  [4] = "#8AAA92", /* blue    */
  [5] = "#A0AD95", /* magenta */
  [6] = "#C1BEA0", /* cyan    */
  [7] = "#c4c3c4", /* white   */

  /* 8 bright colors */
  [8]  = "#6f5a64",  /* black   */
  [9]  = "#727F7C",  /* red     */
  [10] = "#6E866E", /* green   */
  [11] = "#729791", /* yellow  */
  [12] = "#8AAA92", /* blue    */
  [13] = "#A0AD95", /* magenta */
  [14] = "#C1BEA0", /* cyan    */
  [15] = "#c4c3c4", /* white   */

  /* special colors */
  [256] = "#141213", /* background */
  [257] = "#c4c3c4", /* foreground */
  [258] = "#c4c3c4",     /* cursor */
};

/* Default colors (colorname index)
 * foreground, background, cursor */
 unsigned int defaultbg = 0;
 unsigned int defaultfg = 257;
 unsigned int defaultcs = 258;
 unsigned int defaultrcs= 258;
