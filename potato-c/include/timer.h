#ifndef TIMER_H__
#define TIMER_H__
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define SECONDS_IN_MINUTES 60
#define MINUTES_IN_HOUR    60
#define SECONDS_IN_HOUR    SECONDS_IN_MINUTES*MINUTES_IN_HOUR

typedef enum { 
  NULL_TYPE = -1,
  POMODORO_TYPE = 0,
  SHORT_BREAK_TYPE,
  LONG_BREAK_TYPE,
} TimerType;

typedef struct {
  bool paused;
  unsigned int seconds;
  TimerType type;
  unsigned int pomodoro_count, initial_pomodoro_count,
  pomodoro_minutes, short_break_minutes, long_break_minutes;
} Timer;

void Timer_sleep_reduce_second(Timer *restrict, void on_cycle(Timer * restrict));
void Timer_set_seconds_based_on_type(Timer * timer);
void Timer_cycle_type(Timer * timer);
void Timer_initialize(Timer *timer);
void Timer_set_default(Timer *timer);
void Timer_print(Timer *timer);
char * Timer_time_left(Timer *timer);
void Timer_pause(Timer * timer);
void Timer_unpause(Timer * timer);
void Timer_toggle_pause(Timer * timer);
void Timer_print_before_time(Timer timer);
char * Timer_resolve_format(Timer *timer, char const *format);
const char * Timer_before_time(TimerType type);
void Timer_print_format(Timer *timer, const char * format);
void read_format_from_optind(int argc, char *argv[], const char ** output_str);
int read_format_from_string(char*input_str,const char ** output_str);
const char * timer_type_string(TimerType type);
#endif
