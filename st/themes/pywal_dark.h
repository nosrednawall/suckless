const char *colorname[] = {

  /* 8 normal colors */
  [0] = "#191c10", /* black   */
  [1] = "#988B6B", /* red     */
  [2] = "#98999E", /* green   */
  [3] = "#AFB1B6", /* yellow  */
  [4] = "#C1BEBD", /* blue    */
  [5] = "#9DAEC1", /* magenta */
  [6] = "#B2B9C3", /* cyan    */
  [7] = "#dedddd", /* white   */

  /* 8 bright colors */
  [8]  = "#9b9a9a",  /* black   */
  [9]  = "#988B6B",  /* red     */
  [10] = "#98999E", /* green   */
  [11] = "#AFB1B6", /* yellow  */
  [12] = "#C1BEBD", /* blue    */
  [13] = "#9DAEC1", /* magenta */
  [14] = "#B2B9C3", /* cyan    */
  [15] = "#dedddd", /* white   */

  /* special colors */
  [256] = "#191c10", /* background */
  [257] = "#dedddd", /* foreground */
  [258] = "#dedddd",     /* cursor */
};

/* Default colors (colorname index)
 * foreground, background, cursor */
 unsigned int defaultbg = 0;
 unsigned int defaultfg = 257;
 unsigned int defaultcs = 258;
 unsigned int defaultrcs= 258;
