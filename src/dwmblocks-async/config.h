#define CONFIG_H

// String used to delimit block outputs in the status.
#define DELIMITER ""

// Maximum number of Unicode characters that a block can output.
#define MAX_BLOCK_OUTPUT_LENGTH 80

// Control whether blocks are clickable.
#define CLICKABLE_BLOCKS 1

// Control whether a leading delimiter should be prepended to the status.
#define LEADING_DELIMITER 0

// Control whether a trailing delimiter should be appended to the status.
#define TRAILING_DELIMITER 0

// Path for scripts - now using /usr/local/bin
#define SCRIPT_PATH(name) "~/.local/bin/dwmblocks/"name

// Define blocks for the status feed as X(icon, cmd, interval, signal).
#define BLOCKS(X)                                   \
    X("", SCRIPT_PATH("sb-potato-c"),      1, 19)   \
    X("", SCRIPT_PATH("sb-players"),       1, 18)   \
    X("", SCRIPT_PATH("sb-weather"),     600, 17)   \
    X("", SCRIPT_PATH("sb-update"),     6000, 16)   \
    X("", SCRIPT_PATH("sb-loadavg"),      10, 15)   \
    X("", SCRIPT_PATH("sb-memory"),       10, 14)   \
    X("", SCRIPT_PATH("sb-disk"),         10, 13)   \
    X("", SCRIPT_PATH("sb-vpn"),          10, 12)   \
    X("", SCRIPT_PATH("sb-wifi"),         10, 11)   \
    X("", SCRIPT_PATH("sb-ethernet"),     10, 10)   \
    X("", SCRIPT_PATH("sb-brightness"),    0,  9)   \
    X("", SCRIPT_PATH("sb-volume"),      600,  8)   \
    X("", SCRIPT_PATH("sb-mic"),         600,  7)   \
    X("", SCRIPT_PATH("sb-record"),       10,  6)   \
    X("", SCRIPT_PATH("sb-keyboard"),      1,  5)   \
    X("", SCRIPT_PATH("sb-battery"),      30,  4)   \
    X("", SCRIPT_PATH("sb-moon"),       6000,  3)   \
    X("", SCRIPT_PATH("sb-date"),        600,  2)   \
    X("", SCRIPT_PATH("sb-hour"),          1,  1)

/*
Comandos para atualizar blocos específicos:
kill -43 $(pidof dwmblocks)  // atualiza o bloco 15 (hora)
kill -52 $(pidof dwmblocks)  // atualiza o bloco 18 (lua)

Sinais correspondentes:
2: sb-update     15: sb-hour
3: sb-loadavg    16: sb-vpn  
4: sb-memory     17: sb-weather
5: sb-disk       18: sb-moon
6: sb-wifi       19: sb-players
7: sb-ethernet   20: sb-potato-c
8: sb-brightness
9: sb-volume
10: sb-mic
11: sb-record
12: sb-keyboard
13: sb-battery
14: sb-date
*/
