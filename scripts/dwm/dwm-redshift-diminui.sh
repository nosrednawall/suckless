#!/bin/bash

# Obtém a temperatura atual do monitor
temperatura=$(xrandr --verbose | awk '/Gamma/ {print $2}' | cut -d: -f3 | head -1)

# Verifica se conseguiu obter a temperatura
if [ -z "$temperatura" ]; then
    notify-send -t 3000 "Erro" "Não foi possível obter a temperatura atual" --icon=dialog-error
    exit 1
fi

case "$temperatura" in
    1.1)
        redshift -P -O 6500
        notify-send -t 3000 "Alterado a temperatura para 6500K" --icon="/usr/share/icons/ePapirus/16x16/actions/colors-chromablue.svg"
        ;;
    1.2)
        redshift -P -O 6000
        notify-send -t 3000 "Alterado a temperatura para 6000K" --icon="/usr/share/icons/ePapirus/16x16/actions/colors-chromablue.svg"
        ;;
    1.3)
        redshift -P -O 5500
        notify-send -t 3000 "Alterado a temperatura para 5500K" --icon="/usr/share/icons/ePapirus/16x16/actions/colors-chromablue.svg"
        ;;
    1.4)
        redshift -P -O 5000
        notify-send -t 3000  "Alterado a temperatura para 5000K" --icon="/usr/share/icons/ePapirus/16x16/actions/colors-chromablue.svg"
        ;;
    1.5)
        redshift -P -O 4500
        notify-send -t 3000  "Alterado a temperatura para 4500K" --icon="/usr/share/icons/ePapirus/16x16/actions/colors-chromablue.svg"
        ;;
    1.6)
        redshift -P -O 4200
        notify-send -t 3000  "Alterado a temperatura para 4200K" --icon="/usr/share/icons/ePapirus/16x16/actions/colors-chromablue.svg"
        ;;
    1.7)
        redshift -P -O 4000
        notify-send -t 3000  "Alterado a temperatura para 4000K" --icon="/usr/share/icons/ePapirus/16x16/actions/colors-chromablue.svg"
        ;;
    1.8)
        redshift -P -O 3850
        notify-send -t 3000  "Alterado a temperatura para 3850K" --icon="/usr/share/icons/ePapirus/16x16/actions/colors-chromablue.svg"
        ;;
esac
exit 0
