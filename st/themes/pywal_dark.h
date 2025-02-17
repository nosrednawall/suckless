const char *colorname[] = {

  /* 8 normal colors */
  [0] = "#191d24", /* black   */
  [1] = "#935660", /* red     */
  [2] = "#BA6C7B", /* green   */
  [3] = "#C46E7B", /* yellow  */
  [4] = "#5D6A88", /* blue    */
  [5] = "#667192", /* magenta */
  [6] = "#90748F", /* cyan    */
  [7] = "#d4afb7", /* white   */

  /* 8 bright colors */
  [8]  = "#947a80",  /* black   */
  [9]  = "#935660",  /* red     */
  [10] = "#BA6C7B", /* green   */
  [11] = "#C46E7B", /* yellow  */
  [12] = "#5D6A88", /* blue    */
  [13] = "#667192", /* magenta */
  [14] = "#90748F", /* cyan    */
  [15] = "#d4afb7", /* white   */

  /* special colors */
  [256] = "#191d24", /* background */
  [257] = "#d4afb7", /* foreground */
  [258] = "#d4afb7",     /* cursor */
};

/* Default colors (colorname index)
 * foreground, background, cursor */
 unsigned int defaultbg = 0;
 unsigned int defaultfg = 257;
 unsigned int defaultcs = 258;
 unsigned int defaultrcs= 258;
