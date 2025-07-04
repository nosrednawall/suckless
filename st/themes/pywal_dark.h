const char *colorname[] = {

  /* 8 normal colors */
  [0] = "#121213", /* black   */
  [1] = "#877954", /* red     */
  [2] = "#76843C", /* green   */
  [3] = "#78866F", /* yellow  */
  [4] = "#8D9046", /* blue    */
  [5] = "#8B8970", /* magenta */
  [6] = "#909587", /* cyan    */
  [7] = "#c3c3c4", /* white   */

  /* 8 bright colors */
  [8]  = "#5a5a6e",  /* black   */
  [9]  = "#877954",  /* red     */
  [10] = "#76843C", /* green   */
  [11] = "#78866F", /* yellow  */
  [12] = "#8D9046", /* blue    */
  [13] = "#8B8970", /* magenta */
  [14] = "#909587", /* cyan    */
  [15] = "#c3c3c4", /* white   */

  /* special colors */
  [256] = "#121213", /* background */
  [257] = "#c3c3c4", /* foreground */
  [258] = "#c3c3c4",     /* cursor */
};

/* Default colors (colorname index)
 * foreground, background, cursor */
 unsigned int defaultbg = 0;
 unsigned int defaultfg = 257;
 unsigned int defaultcs = 258;
 unsigned int defaultrcs= 258;
