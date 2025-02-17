const char *colorname[] = {

  /* 8 normal colors */
  [0] = "#f1f1f3", /* black   */
  [1] = "#6C676E", /* red     */
  [2] = "#566F90", /* green   */
  [3] = "#677898", /* yellow  */
  [4] = "#5C7CA4", /* blue    */
  [5] = "#5E81AC", /* magenta */
  [6] = "#688AB0", /* cyan    */
  [7] = "#2C323E", /* white   */

  /* 8 bright colors */
  [8]  = "#61636a",  /* black   */
  [9]  = "#6C676E",  /* red     */
  [10] = "#566F90", /* green   */
  [11] = "#677898", /* yellow  */
  [12] = "#5C7CA4", /* blue    */
  [13] = "#5E81AC", /* magenta */
  [14] = "#688AB0", /* cyan    */
  [15] = "#2C323E", /* white   */

  /* special colors */
  [256] = "#f1f1f3", /* background */
  [257] = "#2C323E", /* foreground */
  [258] = "#2C323E",     /* cursor */
};

/* Default colors (colorname index)
 * foreground, background, cursor */
 unsigned int defaultbg = 0;
 unsigned int defaultfg = 257;
 unsigned int defaultcs = 258;
 unsigned int defaultrcs= 258;
