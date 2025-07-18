const char *colorname[] = {

  /* 8 normal colors */
  [0] = "#1b150f", /* black   */
  [1] = "#98968E", /* red     */
  [2] = "#AFA894", /* green   */
  [3] = "#A7A79D", /* yellow  */
  [4] = "#869BB0", /* blue    */
  [5] = "#95A7B2", /* magenta */
  [6] = "#C6B998", /* cyan    */
  [7] = "#c6c4c3", /* white   */

  /* 8 bright colors */
  [8]  = "#70655c",  /* black   */
  [9]  = "#98968E",  /* red     */
  [10] = "#AFA894", /* green   */
  [11] = "#A7A79D", /* yellow  */
  [12] = "#869BB0", /* blue    */
  [13] = "#95A7B2", /* magenta */
  [14] = "#C6B998", /* cyan    */
  [15] = "#c6c4c3", /* white   */

  /* special colors */
  [256] = "#1b150f", /* background */
  [257] = "#c6c4c3", /* foreground */
  [258] = "#c6c4c3",     /* cursor */
};

/* Default colors (colorname index)
 * foreground, background, cursor */
 unsigned int defaultbg = 0;
 unsigned int defaultfg = 257;
 unsigned int defaultcs = 258;
 unsigned int defaultrcs= 258;
