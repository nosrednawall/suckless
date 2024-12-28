#!/bin/bash

# Carrega configuracoes do tema
source /home/anderson/.theme_selected
source /home/anderson/.bashrc

# Executa o script para verificar se o segundo monitor está ativo
if [ ! -f ~/.monitor_config.sh ]
then
    bash ~/.local/bin/check_second_monitor_is_active.sh
else
    bash ~/.monitor_config.sh
fi

env > /home/anderson/autostart_env.log

# Define o papel de parede usando feh
feh --recursive --bg-fill --randomize ~/.wallpapers/${THEME_MODE}/${COLOR_MODE}/ &

# Função para verificar se um processo está rodando
is_running() {
    ps aux | grep -v grep | grep -q "$1"
}

# Inicia o mate-power-manager se não estiver rodando
# is_running "xfce4-power-manager" || xfce4-power-manager &

# Applet som
#is_running "pasystray" || pasystray &

# Wifi
#is_running "nm-applet" || nm-applet &

# Polkit - para autenticar programas
is_running "lxpolkit" || lxpolkit &

# Inicia o xautolock com as configurações personalizadas se não estiver rodando
is_running "xautolock" || xautolock -time 15 -locker ~/.local/bin/dwm/slock_personalizado -detectsleep &

# Inicia o picom em modo background
is_running "picom" || picom -b

# Inicia o dunst se não estiver rodando
is_running "dunst" || dunst -conf "$HOME/.config/dunst/themes/${THEME_MODE}_${COLOR_MODE}" &

# Inicia o copyq se não estiver rodando
is_running "copyq" || copyq &

# Inicia o daemon do emacs se não estiver rodando
is_running "emacs --daemon" || emacs --daemon &

is_running "solaar" || /usr/bin/solaar -w hide

# Inicia o dwmblocks se não estiver rodando
#killall dwmblocks; export PATH=$PATH:$HOME/.config/suckless/scripts/dwmblocks/ && $HOME/.config/suckless/dwmblocks-async/build/dwmblocks &
is_running "dwmblocks" || /usr/local/bin/dwmblocks
