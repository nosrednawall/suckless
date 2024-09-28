#ifndef CONFIG_H
#define CONFIG_H

// String used to delimit block outputs in the status.
#define DELIMITER ""

// Maximum number of Unicode characters that a block can output.
#define MAX_BLOCK_OUTPUT_LENGTH 90

// Control whether blocks are clickable.
#define CLICKABLE_BLOCKS 1

// Control whether a leading delimiter should be prepended to the status.
#define LEADING_DELIMITER 0

// Control whether a trailing delimiter should be appended to the status.
#define TRAILING_DELIMITER 0

#define PATH(name) "/home/anderson/.dotfiles/.config/suckless/dwmblocks-async/scripts/"name

// Define blocks for the status feed as X(icon, cmd, interval, signal).
#define BLOCKS(X)             \
    X("", PATH("sb-mpd"), 		600, 1)  \
    X("", PATH("sb-update"), 	600, 2)  \
    X("", PATH("sb-loadavg"), 	 10, 3)     \
    X("", PATH("sb-memory"), 	 30, 4)    \
    X("", PATH("sb-disk"), 	600, 5)   \
    X("", PATH("sb-vpn"), 		600, 16)  \
    X("", PATH("sb-wifi"), 	 30, 6)  \
    X("", PATH("sb-ethernet"),   30, 7) \
    X("", PATH("sb-brightness"),  0, 8)  \
    X("", PATH("sb-volume"), 	  0, 9)  \
    X("", PATH("sb-mic"), 		  0, 10)  \
    X("", PATH("sb-record"), 	 30, 11)  \
    X("", PATH("sb-keyboard"),    0, 12)  \
    X("", PATH("sb-battery"), 	 30, 13)  \
    X("", PATH("sb-date"), 	600, 14)     \
    X("", PATH("sb-hour"), 	  1, 15)

#endif  // CONFIG_H

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
