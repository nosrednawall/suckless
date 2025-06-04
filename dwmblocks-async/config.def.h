#ifndef CONFIG_H
#define CONFIG_H

// String used to delimit block outputs in the status.
#define DELIMITER ""

// Maximum number of Unicode characters that a block can output.
#define MAX_BLOCK_OUTPUT_LENGTH 180

// Control whether blocks are clickable.
#define CLICKABLE_BLOCKS 1

// Control whether a leading delimiter should be prepended to the status.
#define LEADING_DELIMITER 0

// Control whether a trailing delimiter should be appended to the status.
#define TRAILING_DELIMITER 0

#define PATH(name) "/home/anderson/.config/suckless/scripts/"name

// Define blocks for the status feed as X(icon, cmd, interval, signal).
#define BLOCKS(X)             \
    /* X("", PATH("dwmblocks/sb-mpd"),       1, 1)  */  \
    X("", PATH("dwmblocks/sb-potato-c"),     1, 20)    \
    X("", PATH("dwmblocks/sb-players"),      1, 19)    \
    X("", PATH("dwmblocks/sb-weather"),     600,17)    \
    X("", PATH("dwmblocks/sb-update"),      6000,2)     \
    X("", PATH("dwmblocks/sb-loadavg"),     10,  3)     \
    X("", PATH("dwmblocks/sb-memory"),      10,  4)     \
    X("", PATH("dwmblocks/sb-disk"),        10,  5)     \
    X("", PATH("dwmblocks/sb-vpn"),         10, 16)    \
    X("", PATH("dwmblocks/sb-wifi"),        10,  6)     \
    X("", PATH("dwmblocks/sb-ethernet"),    10,  7)     \
    X("", PATH("dwmblocks/sb-brightness"),  0,   8)     \
    X("", PATH("dwmblocks/sb-volume"),      0,   9)     \
    X("", PATH("dwmblocks/sb-mic"),         0,  10)    \
    X("", PATH("dwmblocks/sb-record"),      10, 11)    \
    X("", PATH("dwmblocks/sb-keyboard"),    1,  12)    \
    X("", PATH("dwmblocks/sb-battery"),     30, 13)    \
    X("", PATH("dwmblocks/sb-moon"),        6000,18)    \
    X("", PATH("dwmblocks/sb-date"),        600,14)    \
    X("", PATH("dwmblocks/sb-hour"),        1,  15)

#endif  // CONFIG_H
/*
kill -43 $(pidof dwmblocks) //atualiza o block numero 15
kill -52 $(pidof dwmblocks) //atualiza o block numero 18

*/
/*
**
**#define BLOCKS(X)             \
    X("", PATH("sb-mpd"), 		600, 1)     \
    X("", PATH("sb-vpn"), 		600, 16)  \
    X("", PATH("sb-wifi"), 	 30, 6)  \
    X("", PATH("sb-ethernet"),   30, 7)  \
    X("", PATH("sb-brightness"),  0, 8)  \
    X("", PATH("sb-volume"), 	  0, 9)  \
    X("", PATH("sb-mic"), 		  0, 10)  \
    X("", PATH("sb-record"), 	 30, 11)  \
    X("", PATH("sb-battery"), 	 30, 13)  \
    X("", PATH("sb-hour"), 	  1, 15)

**
**
**
**
**#define BLOCKS(X)             \
    X("", PATH("sb-mpd"), 		600, 1)     \
    X("", PATH("sb-update"), 	600, 2)  \
    X("", PATH("sb-loadavg"), 	 10, 3)  \
    X("", PATH("sb-memory"), 	 30, 4)  \
    X("", PATH("sb-disk"), 	600, 5)  \
    X("", PATH("sb-vpn"), 		600, 16)  \
    X("", PATH("sb-wifi"), 	 30, 6)  \
    X("", PATH("sb-ethernet"),   30, 7)  \
    X("", PATH("sb-brightness"),  0, 8)  \
    X("", PATH("sb-volume"), 	  0, 9)  \
    X("", PATH("sb-mic"), 		  0, 10)  \
    X("", PATH("sb-record"), 	 30, 11)  \
    X("", PATH("sb-keyboard"),    0, 12)  \
    X("", PATH("sb-battery"), 	 30, 13)  \
    X("", PATH("sb-date"), 	600, 14)  \
    X("", PATH("sb-hour"), 	  1, 15)

#endif  // CONFIG_H

**
*/
