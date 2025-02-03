<div align="center">

# potato-c 
![GitHub top language](https://img.shields.io/github/languages/top/nimaaskarian/potato-c?color=orange)
![AUR version](https://img.shields.io/aur/version/potato-c?logo=archlinux)


A featureful, modular and fast pomodoro timer with server-client structure, written in C, that will make you faster without making your hardware go slow.

[Getting started](#getting-started) •
[Installation](#installation) •
[Configuration](#configuration) •
[Integrations](#third-party-integrations)

![potato-c in waybar](https://github.com/nimaaskarian/potato-c/assets/88832088/ecb5d7fd-f3cd-4cb1-8478-bc9425bc92da)

</div>

## Introduction
The Pomodoro method has made me very efficient and fast when doing my daily tasks, but all the pomodoro timer applications that existed, sucked in a way in my opinion. So I started coding potato-c. potato-c is a server-client application, inspired by many similar applications like mpd-mpc-ncmpc, I tried to keep the application simple, modular and as efficiant on resources as possible, so its kinda inspired by dwm and other [suckless](https://suckless.org) tools. But this doesn't make the application miss on any features that a pomodoro timer may need.

## The Pomodoro method
This method is about breaking your tasks into small intervals so you don't get zoned out from not having enough TikTok videos. This can be very good for homeworks and tasks of your job, University or school that you are not really into.

## Why potato-c
This program's base idea is from [Tomato.C](https://github.com/gabrielzschmitz/Tomato.C), "a pure C pomodoro timer",
which after trying to fork it, the ideas behind it seemed problematic to me.  
This program tries to be able to run on a potato (as the name suggests)
- Blazingly fast and efficient
- Modular and simple
- Based on POSIX Philosophy, does one thing, but is good at it.

## Installation 

### Manually building (recommended)
You can use make/git to build and install the package for yourself like so:
```shell
git clone https://github.com/nimaaskarian/potato-c
cd potato-c
sudo make install
```
This is the recommended way as you can change the `config.h`.
### Arch Linux (AUR)
You can install [potato-c from the AUR](https://aur.archlinux.org/packages/potato-c).

You may use an AUR helper like yay to automate the process:
```
yay -S potato-c
```

## Getting started
Simply put, this program consists of three binaries. Each intended for their own purposes:
- **potd:** the daemon responsible for a pomodoro session. Managing the timers and keeping
track of the progress.
- **potctl:** the interface to interacting with the timers using commandline.
- **potui:** the TUI to manage your timers with to-do lists.

In order to quickly set up a timer, do the following:
```bash
potd                # Starts a potato-c daemon (writes current remaining time to stdout by default)

# in another terminal
potctl              # Get the status of your daemon(s)
potctl -p           # Pauses the timer
potctl -u           # Unpauses the timer
potctl -t           # Toggle pauses the timer
potctl -r           # Resets the timer

potui               # Launch the TUI
```
For more detailed information on how to use the program refer to [usage](#usage).

## Configuration
For more configuration, you may edit the header file `config.h` (in suckless fashion) which is created after building the
project. All the definitions have reasonable names and are easy to understand.

Make sure to recompile the project once you edit the configuration file for the changes to take
effect:

```
sudo make install
```

Of course, you can change the `PREFIX` variable inside `config.mk` to change the installation directory.

## Usage
Some features that potato-c has, and you may want to use them.
### Controlling (Pausing, etc)
Even though the `potd` (potato-deamon) itself isn't able to get any inputs from the user, it can be controlled by `potctl` and `potui`. This control can be pausing, skipping, resetting, adding to timer, adding to pomodoros etc.

### To-do list
**To-do list feature has been removed due to it being not very unix like.**

You can use [c3](https://github.com/nimaaskarian/c3), which is a cross-platform, tree like todo list with calcurse format instead. It has a potato module as well!

### Commands on events
Specify a list of commands in config.h that will be ran for each event (pomodoro start, short break start, long break start).

### Using another computer as your server
You can use another computer in your local network as your pomodoro server. You can't really control it, but you can view the timer. Refer to `man potctl` for further details.

If you want more information, please refer to the man pages. If I do a documentation in here, I will likely forget to update it.
Just after installation, use the commands below to read the docs.
```shell
man potd
man potctl
man potui
```

## Integration
Since this program is modular and simple, adding information about timers to your bars is a 
straight-forward process:

### Polybar
```ini
[module/potato]
type = custom/script
exec = "potd -f"
tail = true
```

### Waybar
```json
"custom/potato": {
    "exec": "potd -fN"
},
```

This is of course, a very minimal implementation. You could add more with click events and `potctl` to make the bar module work like a charm.

## Contributing
Code as modular as possible. I'm still learning, so thats the only suggestion and rule I can have for contributors.
