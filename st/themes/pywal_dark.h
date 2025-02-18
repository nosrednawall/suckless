const char *colorname[] = {

  /* 8 normal colors */
  [0] = "#121213", /* black   */
  [1] = "#989A8A", /* red     */
  [2] = "#9FA18D", /* green   */
  [3] = "#AEAF97", /* yellow  */
  [4] = "#BBBEA2", /* blue    */
  [5] = "#C4C39B", /* magenta */
  [6] = "#C1C09E", /* cyan    */
  [7] = "#e1decc", /* white   */

  /* 8 bright colors */
  [8]  = "#9d9b8e",  /* black   */
  [9]  = "#989A8A",  /* red     */
  [10] = "#9FA18D", /* green   */
  [11] = "#AEAF97", /* yellow  */
  [12] = "#BBBEA2", /* blue    */
  [13] = "#C4C39B", /* magenta */
  [14] = "#C1C09E", /* cyan    */
  [15] = "#e1decc", /* white   */

  /* special colors */
  [256] = "#121213", /* background */
  [257] = "#e1decc", /* foreground */
  [258] = "#e1decc",     /* cursor */
};

/* Default colors (colorname index)
 * foreground, background, cursor */
 unsigned int defaultbg = 0;
 unsigned int defaultfg = 257;
 unsigned int defaultcs = 258;
 unsigned int defaultrcs= 258;
