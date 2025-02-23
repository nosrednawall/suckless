const char *colorname[] = {

  /* 8 normal colors */
  [0] = "#111c24", /* black   */
  [1] = "#4A5468", /* red     */
  [2] = "#655A6C", /* green   */
  [3] = "#A86169", /* yellow  */
  [4] = "#B7877B", /* blue    */
  [5] = "#5B7395", /* magenta */
  [6] = "#6587AE", /* cyan    */
  [7] = "#b5c7d7", /* white   */

  /* 8 bright colors */
  [8]  = "#7e8b96",  /* black   */
  [9]  = "#4A5468",  /* red     */
  [10] = "#655A6C", /* green   */
  [11] = "#A86169", /* yellow  */
  [12] = "#B7877B", /* blue    */
  [13] = "#5B7395", /* magenta */
  [14] = "#6587AE", /* cyan    */
  [15] = "#b5c7d7", /* white   */

  /* special colors */
  [256] = "#111c24", /* background */
  [257] = "#b5c7d7", /* foreground */
  [258] = "#b5c7d7",     /* cursor */
};

/* Default colors (colorname index)
 * foreground, background, cursor */
 unsigned int defaultbg = 0;
 unsigned int defaultfg = 257;
 unsigned int defaultcs = 258;
 unsigned int defaultrcs= 258;
