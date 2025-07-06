#ifndef CONFIG_H
#define CONFIG_H

// String used to delimit block outputs in the status.
#define DELIMITER "  "

// Maximum number of Unicode characters that a block can output.
#define MAX_BLOCK_OUTPUT_LENGTH 45

// Control whether blocks are clickable.
#define CLICKABLE_BLOCKS 1

// Control whether a leading delimiter should be prepended to the status.
#define LEADING_DELIMITER 0

// Control whether a trailing delimiter should be appended to the status.
#define TRAILING_DELIMITER 0

// Define blocks for the status feed as X(icon, cmd, interval, signal).
#define BLOCKS(X)             \
    X("", "/home/anderson/.config/suckless/others/suckless-flexi/dotfiles-suckless/bin/statusbar/sb-mic",      0,     11) \
    X("", "/home/anderson/.config/suckless/others/suckless-flexi/dotfiles-suckless/bin/statusbar/sb-packages", 30000, 12) \
    X("", "/home/anderson/.config/suckless/others/suckless-flexi/dotfiles-suckless/bin/statusbar/sb-cpu",      10,    18)  \
    X("", "/home/anderson/.config/suckless/others/suckless-flexi/dotfiles-suckless/bin/statusbar/sb-torrent",  20,    7) \
    X("", "/home/anderson/.config/suckless/others/suckless-flexi/dotfiles-suckless/bin/statusbar/sb-forecast", 18000, 5) \
    X("", "/home/anderson/.config/suckless/others/suckless-flexi/dotfiles-suckless/bin/statusbar/sb-memory",   10,    4) \
    X("", "/home/anderson/.config/suckless/others/suckless-flexi/dotfiles-suckless/bin/statusbar/sb-volume",   0,     10) \
    X("", "/home/anderson/.config/suckless/others/suckless-flexi/dotfiles-suckless/bin/statusbar/sb-nettraf",  1,     16) \
    X("", "/home/anderson/.config/suckless/others/suckless-flexi/dotfiles-suckless/bin/statusbar/sb-battery",  5,     3) \
    X("", "/home/anderson/.config/suckless/others/suckless-flexi/dotfiles-suckless/bin/statusbar/sb-clock",    60,    8) \
    X("", "/home/anderson/.config/suckless/others/suckless-flexi/dotfiles-suckless/bin/statusbar/sb-internet", 60,    1)

#endif  // CONFIG_H
