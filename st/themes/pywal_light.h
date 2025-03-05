const char *colorname[] = {

  /* 8 normal colors */
  [0] = "#2b0a2e", /* black   */
  [1] = "#F790D3", /* red     */
  [2] = "#E4A7D6", /* green   */
  [3] = "#F9B4E6", /* yellow  */
  [4] = "#A5D2CB", /* blue    */
  [5] = "#ADE3D6", /* magenta */
  [6] = "#DDDADD", /* cyan    */
  [7] = "#f6e3f3", /* white   */

  /* 8 bright colors */
  [8]  = "#ac9eaa",  /* black   */
  [9]  = "#F790D3",  /* red     */
  [10] = "#E4A7D6", /* green   */
  [11] = "#F9B4E6", /* yellow  */
  [12] = "#A5D2CB", /* blue    */
  [13] = "#ADE3D6", /* magenta */
  [14] = "#DDDADD", /* cyan    */
  [15] = "#f6e3f3", /* white   */

  /* special colors */
  [256] = "#2b0a2e", /* background */
  [257] = "#f6e3f3", /* foreground */
  [258] = "#f6e3f3",     /* cursor */
};

/* Default colors (colorname index)
 * foreground, background, cursor */
 unsigned int defaultbg = 0;
 unsigned int defaultfg = 257;
 unsigned int defaultcs = 258;
 unsigned int defaultrcs= 258;
