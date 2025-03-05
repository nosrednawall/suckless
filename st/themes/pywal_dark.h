const char *colorname[] = {

  /* 8 normal colors */
  [0] = "#070405", /* black   */
  [1] = "#955348", /* red     */
  [2] = "#A78C79", /* green   */
  [3] = "#6D848B", /* yellow  */
  [4] = "#A59A92", /* blue    */
  [5] = "#B1B0AE", /* magenta */
  [6] = "#C4BEB6", /* cyan    */
  [7] = "#c1c0c0", /* white   */

  /* 8 bright colors */
  [8]  = "#65525c",  /* black   */
  [9]  = "#955348",  /* red     */
  [10] = "#A78C79", /* green   */
  [11] = "#6D848B", /* yellow  */
  [12] = "#A59A92", /* blue    */
  [13] = "#B1B0AE", /* magenta */
  [14] = "#C4BEB6", /* cyan    */
  [15] = "#c1c0c0", /* white   */

  /* special colors */
  [256] = "#070405", /* background */
  [257] = "#c1c0c0", /* foreground */
  [258] = "#c1c0c0",     /* cursor */
};

/* Default colors (colorname index)
 * foreground, background, cursor */
 unsigned int defaultbg = 0;
 unsigned int defaultfg = 257;
 unsigned int defaultcs = 258;
 unsigned int defaultrcs= 258;
