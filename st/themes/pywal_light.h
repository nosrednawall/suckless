const char *colorname[] = {

  /* 8 normal colors */
  [0] = "#1a1a0d", /* black   */
  [1] = "#857B4E", /* red     */
  [2] = "#7B8369", /* green   */
  [3] = "#A5933B", /* yellow  */
  [4] = "#9A9462", /* blue    */
  [5] = "#78898E", /* magenta */
  [6] = "#A6AA9D", /* cyan    */
  [7] = "#d3d6d6", /* white   */

  /* 8 bright colors */
  [8]  = "#939595",  /* black   */
  [9]  = "#857B4E",  /* red     */
  [10] = "#7B8369", /* green   */
  [11] = "#A5933B", /* yellow  */
  [12] = "#9A9462", /* blue    */
  [13] = "#78898E", /* magenta */
  [14] = "#A6AA9D", /* cyan    */
  [15] = "#d3d6d6", /* white   */

  /* special colors */
  [256] = "#1a1a0d", /* background */
  [257] = "#d3d6d6", /* foreground */
  [258] = "#d3d6d6",     /* cursor */
};

/* Default colors (colorname index)
 * foreground, background, cursor */
 unsigned int defaultbg = 0;
 unsigned int defaultfg = 257;
 unsigned int defaultcs = 258;
 unsigned int defaultrcs= 258;
