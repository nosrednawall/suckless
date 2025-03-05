const char *colorname[] = {

  /* 8 normal colors */
  [0] = "#0d110d", /* black   */
  [1] = "#9B8499", /* red     */
  [2] = "#B393B1", /* green   */
  [3] = "#C19ABE", /* yellow  */
  [4] = "#C59FC2", /* blue    */
  [5] = "#D4ABD1", /* magenta */
  [6] = "#E2B2DF", /* cyan    */
  [7] = "#c2c3c2", /* white   */

  /* 8 bright colors */
  [8]  = "#586c58",  /* black   */
  [9]  = "#9B8499",  /* red     */
  [10] = "#B393B1", /* green   */
  [11] = "#C19ABE", /* yellow  */
  [12] = "#C59FC2", /* blue    */
  [13] = "#D4ABD1", /* magenta */
  [14] = "#E2B2DF", /* cyan    */
  [15] = "#c2c3c2", /* white   */

  /* special colors */
  [256] = "#0d110d", /* background */
  [257] = "#c2c3c2", /* foreground */
  [258] = "#c2c3c2",     /* cursor */
};

/* Default colors (colorname index)
 * foreground, background, cursor */
 unsigned int defaultbg = 0;
 unsigned int defaultfg = 257;
 unsigned int defaultcs = 258;
 unsigned int defaultrcs= 258;
