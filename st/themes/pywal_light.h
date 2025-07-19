const char *colorname[] = {

  /* 8 normal colors */
  [0] = "#12121b", /* black   */
  [1] = "#70996e", /* red     */
  [2] = "#7caa78", /* green   */
  [3] = "#b89e7f", /* yellow  */
  [4] = "#baa983", /* blue    */
  [5] = "#7d8da0", /* magenta */
  [6] = "#6687bb", /* cyan    */
  [7] = "#90909b", /* white   */

  /* 8 bright colors */
  [8]  = "#5c5c71",  /* black   */
  [9]  = "#96CC93",  /* red     */
  [10] = "#A6E3A1", /* green   */
  [11] = "#F6D3AA", /* yellow  */
  [12] = "#F9E2AF", /* blue    */
  [13] = "#A7BCD6", /* magenta */
  [14] = "#89B4FA", /* cyan    */
  [15] = "#c3c3c6", /* white   */

  /* special colors */
  [256] = "#12121b", /* background */
  [257] = "#c3c3c6", /* foreground */
  [258] = "#c3c3c6",     /* cursor */
};

/* Default colors (colorname index)
 * foreground, background, cursor */
 unsigned int defaultbg = 0;
 unsigned int defaultfg = 257;
 unsigned int defaultcs = 258;
 unsigned int defaultrcs= 258;
