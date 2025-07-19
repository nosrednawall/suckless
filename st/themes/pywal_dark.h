const char *colorname[] = {

  /* 8 normal colors */
  [0] = "#12121b", /* black   */
  [1] = "#96CC93", /* red     */
  [2] = "#A6E3A1", /* green   */
  [3] = "#F6D3AA", /* yellow  */
  [4] = "#F9E2AF", /* blue    */
  [5] = "#A7BCD6", /* magenta */
  [6] = "#89B4FA", /* cyan    */
  [7] = "#c3c3c6", /* white   */

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
