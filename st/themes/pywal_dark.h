const char *colorname[] = {

  /* 8 normal colors */
  [0] = "#121212", /* black   */
  [1] = "#A37C67", /* red     */
  [2] = "#7D836D", /* green   */
  [3] = "#A38F73", /* yellow  */
  [4] = "#C1A27A", /* blue    */
  [5] = "#A59E82", /* magenta */
  [6] = "#B0B38E", /* cyan    */
  [7] = "#d2d9c4", /* white   */

  /* 8 bright colors */
  [8]  = "#939789",  /* black   */
  [9]  = "#A37C67",  /* red     */
  [10] = "#7D836D", /* green   */
  [11] = "#A38F73", /* yellow  */
  [12] = "#C1A27A", /* blue    */
  [13] = "#A59E82", /* magenta */
  [14] = "#B0B38E", /* cyan    */
  [15] = "#d2d9c4", /* white   */

  /* special colors */
  [256] = "#121212", /* background */
  [257] = "#d2d9c4", /* foreground */
  [258] = "#d2d9c4",     /* cursor */
};

/* Default colors (colorname index)
 * foreground, background, cursor */
 unsigned int defaultbg = 0;
 unsigned int defaultfg = 257;
 unsigned int defaultcs = 258;
 unsigned int defaultrcs= 258;
