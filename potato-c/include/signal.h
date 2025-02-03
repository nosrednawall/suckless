#ifndef SIGNAL_H__
#define SIGNAL_H__

#include <signal.h>
#define SIG_PAUSE                 SIGUSR1
#define SIG_UNPAUSE               SIGUSR2
#define SIG_TPAUSE                41
#define SIG_SKIP                  42
#define SIG_DEC_10SEC             43
#define SIG_INC_10SEC             44
#define SIG_DEC_POMODORO_COUNT    45
#define SIG_INC_POMODORO_COUNT    46
#define SIG_RESET                 47
#endif // !SIGNAL_H__

