const char *colorname[] = {

  /* 8 normal colors */
  [0] = "#0e0e16", /* black   */
  [1] = "#626479", /* red     */
  [2] = "#72738A", /* green   */
  [3] = "#8C798F", /* yellow  */
  [4] = "#9C8FA9", /* blue    */
  [5] = "#D597A7", /* magenta */
  [6] = "#D0BABA", /* cyan    */
  [7] = "#ebcec8", /* white   */

  /* 8 bright colors */
  [8]  = "#a4908c",  /* black   */
  [9]  = "#626479",  /* red     */
  [10] = "#72738A", /* green   */
  [11] = "#8C798F", /* yellow  */
  [12] = "#9C8FA9", /* blue    */
  [13] = "#D597A7", /* magenta */
  [14] = "#D0BABA", /* cyan    */
  [15] = "#ebcec8", /* white   */

  /* special colors */
  [256] = "#0e0e16", /* background */
  [257] = "#ebcec8", /* foreground */
  [258] = "#ebcec8",     /* cursor */
};

/* Default colors (colorname index)
 * foreground, background, cursor */
 unsigned int defaultbg = 0;
 unsigned int defaultfg = 257;
 unsigned int defaultcs = 258;
 unsigned int defaultrcs= 258;
