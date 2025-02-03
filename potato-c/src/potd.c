#include <linux/limits.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <unistd.h>

#include "../include/timer.h"
#include "../include/signal.h"
#include "../include/socket.h"
#include "../include/pidfile.h"

#include "../config.h"
#include "../include/utils.h"

typedef struct {
  _Bool flush, notification;
  _Bool new_line_at_quit, print_pomodoro_count, run_socket;
  const char * format;
  Timer timer;
} App;

App app;

extern inline void quit(int signum)
{
  remove_pid_file(getpid());
  if (app.new_line_at_quit)
    puts("");

  if (signum == SIGQUIT)
    exit(0);
  printf("%d\n", signum);
  exit(1);
}

extern inline void read_options_to_app(int argc, char*argv[])
{
  int ch;
  while ((ch = getopt(argc, argv, "fnpNsP:S:L:C:")) != -1) {
    switch (ch) {
      case 'f':
        app.flush = 1;
        break;
      case 'n':
        app.notification = 1;
        break;
      case 'p':
        app.print_pomodoro_count = 1;
        break;
      case 'P':
        app.timer.pomodoro_minutes = atoi(optarg);
      break;
      case 'C':
        app.timer.initial_pomodoro_count = atoi(optarg);
      break;
      case 'S':
        app.timer.short_break_minutes = atoi(optarg);
      break;
      case 'L':
        app.timer.long_break_minutes = atoi(optarg);
      break;
      case 'N':
        app.new_line_at_quit = 1;
        break;
      case 's':
        app.run_socket = 0;
        break;
    }
  }
  read_format_from_optind(argc, argv, &app.format);
}


extern inline void run_before_command_based_on_timertype(TimerType type)
{
  switch (type) {
    case POMODORO_TYPE:
      for (unsigned int i = 0; i < LENGTH(ON_POMODORO_START_COMMANDS); i++)
        (void)system(ON_POMODORO_START_COMMANDS[i]);
      break;

    case SHORT_BREAK_TYPE: 
      for (unsigned int i = 0; i < LENGTH(ON_SHORT_BREAK_START_COMMANDS); i++)
        (void)system(ON_SHORT_BREAK_START_COMMANDS[i]);
      break;

    case LONG_BREAK_TYPE: 
      for (unsigned int i = 0; i < LENGTH(ON_LONG_BREAK_START_COMMANDS); i++)
        (void)system(ON_LONG_BREAK_START_COMMANDS[i]);
      break;

    case NULL_TYPE:
      break;
  }
}

inline void print_all()
{
  Timer_print_format(&app.timer, app.format);
  if (app.flush)
    fflush(stdout);
}

extern inline void send_notification_based_on_timertype(TimerType type)
{
  switch (type) {
    case POMODORO_TYPE:
      send_notification(pomodoro_notif);
      break;
    case SHORT_BREAK_TYPE: 
      send_notification(short_break_notif);
      break;
    case LONG_BREAK_TYPE: 
      send_notification(long_break_notif);
      break;
    default:
      break;
  }
}

extern inline void on_cycle(Timer * restrict timer) {
  if (!timer->paused)
    run_before_command_based_on_timertype(timer->type);

  if (app.notification)
    send_notification_based_on_timertype(timer->type);
}

extern inline void start_app_loop()
{
  while (1) {
    if (!app.timer.paused) {
      print_all();
    }
    Timer_sleep_reduce_second(&app.timer, on_cycle);
  }
}

extern inline void pause_timer_run_cmds() 
{
  if (app.timer.paused)
    return;
  Timer_pause(&app.timer);
  for (unsigned int i = 0; i < LENGTH(ON_PAUSE_COMMANDS); i++)
    (void)system(ON_PAUSE_COMMANDS[i]);
}

extern inline void unpause_timer_run_cmds()
{
  if (!app.timer.paused)
    return;
  Timer_unpause(&app.timer);
  for (unsigned int i = 0; i < LENGTH(ON_UNPAUSE_COMMANDS); i++)
    (void)system(ON_UNPAUSE_COMMANDS[i]);
}

extern inline void skip_signal_handler(int signum)
{
  Timer_cycle_type(&app.timer);
  Timer_set_seconds_based_on_type(&app.timer);

  run_before_command_based_on_timertype(app.timer.type);

  if (app.notification)
    send_notification_based_on_timertype(app.timer.type);

  if (app.timer.paused) {
    print_all();
  }
}

inline void initialize_app()
{
  app.flush = 0;
  app.notification = 0;
  app.print_pomodoro_count = 0;
  app.new_line_at_quit = 0;
  app.run_socket = 1;
  app.format = NULL;
}

extern inline void reset_signal_handler()
{
  Timer_initialize(&app.timer);
  Timer_set_seconds_based_on_type(&app.timer);

  run_before_command_based_on_timertype(app.timer.type);

  print_all();
}


extern inline void pause_signal_handler()
{
  pause_timer_run_cmds();
  if (!app.notification)
    return;
  send_notification(paused_notif);
}

extern inline void unpause_signal_handler()
{
  unpause_timer_run_cmds();
  if (!app.notification)
    return;
  send_notification(unpaused_notif);
}

extern inline void toggle_pause_signal_handler()
{
  if (app.timer.paused)
    unpause_timer_run_cmds();
  else
    pause_timer_run_cmds();

  if (!app.notification)
    return;
  if (app.timer.paused)
    send_notification(paused_notif);
  else 
    send_notification(unpaused_notif);
}

extern inline void increase_10sec_signal_handler()
{
  app.timer.seconds+=10;

  if (app.timer.paused) 
    print_all();

}

extern inline void decrease_10sec_signal_handler()
{
  if (app.timer.seconds > 10)
    app.timer.seconds-=10;
  else 
    app.timer.seconds = 0;

  if (app.timer.paused)
    print_all();
}

extern inline void increase_pomodoro_count_signal_handler()
{
  app.timer.pomodoro_count ++;

  if (app.timer.paused)
    print_all();
}

extern inline void decrease_pomodoro_count_signal_handler()
{
  if (app.timer.pomodoro_count > 0)
    app.timer.pomodoro_count --;

  if (app.timer.paused)
    print_all();
}

extern inline void assign_signals_to_handlers()
{
  signal(SIG_PAUSE, pause_signal_handler);
  signal(SIG_UNPAUSE, unpause_signal_handler);
  signal(SIG_TPAUSE, toggle_pause_signal_handler);
  signal(SIG_SKIP, skip_signal_handler);
  signal(SIG_INC_10SEC, increase_10sec_signal_handler);
  signal(SIG_DEC_10SEC, decrease_10sec_signal_handler);
  signal(SIG_INC_POMODORO_COUNT, increase_pomodoro_count_signal_handler);
  signal(SIG_DEC_POMODORO_COUNT, decrease_pomodoro_count_signal_handler);
  signal(SIG_RESET, reset_signal_handler);

  signal(SIGINT, quit);
  signal(SIGILL, quit);
  signal(SIGABRT, quit);
  signal(SIGFPE, quit);
  signal(SIGTERM, quit);
  signal(SIGQUIT, quit);
  signal(SIGTRAP, quit);
  signal(SIGKILL, quit);
  signal(SIGPIPE, quit);
  signal(SIGALRM, quit);
}

extern inline void *run_sock_server_thread(void *arg)
{
  int port = next_available_sock_port();
  remove_pid_file_by_port(port);

  write_sock_port_to_pid_file(getpid(), port);
  if (port == NO_PORT) {
    puts("Unable to create socket.");
    fflush(stdout);
    pthread_exit(NULL);
  }
  int server_fd, new_socket;
  ssize_t valread;
  struct sockaddr_in address;
  int opt = 1;
  socklen_t addrlen = sizeof(address);
  char buffer[1024] = { 0 };

  // Creating socket file descriptor
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
      perror("socket failed");
      exit(EXIT_FAILURE);
  }

  // Forcefully attaching socket to the port 8080
  if (setsockopt(server_fd, SOL_SOCKET,
                 SO_REUSEADDR | SO_REUSEPORT, &opt,
                 sizeof(opt))) {
      perror("setsockopt");
      exit(EXIT_FAILURE);
  }
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(port);

  // Forcefully attaching socket to the port 8080
  if (bind(server_fd, (struct sockaddr*)&address,
           sizeof(address))
      < 0) {
      perror("bind failed");
      exit(EXIT_FAILURE);
  }
  if (listen(server_fd, 3) < 0) {
      perror("listen");
      exit(EXIT_FAILURE);
  }
  while (1) {
    if ((new_socket
         = accept(server_fd, (struct sockaddr*)&address,
                  &addrlen))
        < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    valread = read(new_socket, buffer, 1024 - 1);

    if (!valread)
      continue;

    SocketRequest req;
    sscanf(buffer, "%d", &req);

    char * message;
    int number;
    switch (req) {
      case REQ_SECONDS: {
        number = app.timer.seconds;
        break;
      }
      case REQ_TYPE: {
        number = app.timer.type;
        break;
      }
      case REQ_POMODOROS: {
        number = app.timer.pomodoro_count;
        break;
      }
      case REQ_PAUSED: {
        number = app.timer.paused;
        break;
      }
      case REQ_TIMER_FULL:
        break;
    }
    size_t message_size;
    if (req == REQ_TIMER_FULL) {
      message_size = asprintf(&message, "%u-%u-%d-%d", app.timer.seconds, app.timer.pomodoro_count, app.timer.paused, app.timer.type);
    } else {
      message_size = asprintf(&message, "%d", number);
    }
    send(new_socket, message, message_size, 0);
    free(message);
    close(new_socket);
  }
  pthread_exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[])
{

  initialize_app();
  Timer_set_default(&app.timer);
  read_options_to_app(argc, argv);

  Timer_initialize(&app.timer);
  Timer_set_seconds_based_on_type(&app.timer);

  run_before_command_based_on_timertype(app.timer.type);

  create_pid_file(getpid());
  assign_signals_to_handlers();

  if (app.run_socket) {
    pthread_t thread1;
    pthread_create(&thread1, NULL, run_sock_server_thread, NULL);
  }

  if (app.notification)
    send_notification_based_on_timertype(app.timer.type);

  start_app_loop();

  return EXIT_SUCCESS;
}
