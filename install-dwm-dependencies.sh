#!/usr/bin/env sh


echo "install core"
sudo pacman -S --noconfirm xorg-server base-devel make gcc libx11 libxft libxinerama harfbuzz \
    imlib2 libxrandr libxcb libx11 xcb-util gd xdotool xorg-xsetroot

echo "install term programs"
sudo pacman -S --noconfirm curl htop pv i2c-atools picom networkmanager dunst feh  libnotify \
    ripgrep fd findutils btop libnotify lxsession  pacman-contrib xf86-input-wacom libwacom \
    less xdg-user-dirs newsboat jq bc sxiv sxhkd brightnessctl redshift conky pipewire pipewire-alsa \
    pipewire-pulse pipewire-jack wireplumber pavucontrol alsa-utils

systemctl --user --now enable wireplumber.service

echo "install graphic programs"
sudo pacman -S --noconfirm gnupg pinentry pasystray solaar flameshot rofi copyq gpicview syncthing \
    firefox firefox-i18n-pt-br firefoxpwa pulsemixer geany arandr

echo "Install calcurse"
sudo pacman -S --noconfirm calcurse python-oauth2client python-httplib2

echo "Install thunar complete"
sudo pacman -S --noconfirm thunar ranger thunar-archive-plugin thunar-media-tags-plugin \
    udisks2 smbclient samba gvfs gvfs-smb cifs-utils xarchiver cpio unarj unzip zip unace unrar p7zip \
    sharutils uudeview arj cabextract lzip zlib laszip lbzip2 lrzip pbzip2 lzop \
    tumbler ffmpegthumbnailer thunar-shares-plugin thunar-vcs-plugin thunar-volman

# Bluetooth
echo "Install bluetooth support"
sudo pacman -S --noconfirm bluez bluez-tools bluez-utils blueman
sudo systemctl enable bluetooth.service

# Codecs
echo "Install codecs support"
sudo pacman -S --noconfirm ffmpeg gst-plugins-ugly gst-plugins-good gst-plugins-base gst-plugins-bad gst-libav gstreamer slop

# Music
echo "install mpd support"
sudo pacman -S --noconfirm playerctl mpd ncmpcpp mpc mpd-mpris rmpc
sudo systemctl disable mpd  # Disable service
sudo systemctl stop  mpd  # Stop
systemctl --user enable mpd  # Enable by user
systemctl --user start mpd
systemctl --user --now enable mpd-mpris


echo "Configuration"
## Altera o padrão de abertura de imagens para o sxiv
xdg-mime default sxiv.desktop image/png
xdg-mime default sxiv.desktop image/jpeg
xdg-mime default sxiv.desktop image/jpg
xdg-mime default sxiv.desktop image/gif
xdg-mime default sxiv.desktop image/svg+xml
