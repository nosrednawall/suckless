#!/bin/bash

# Verifica o número de pacotes com atualizações disponíveis
updates=$(aptitude search "~U" | wc -l)

# Informa atualizacao
if [[ $updates -ge 1 ]]; then
    notify-send -i "/usr/share/icons/Adwaita/24x24/legacy/software-update-available.png" "󱧕 Atualização Disponível" "Existem <b>$updates</b> atualizações disponíveis."
fi

# Exibe o número de pacotes com atualizações
echo "^c#6c71c4^󱧕 ^c#93a1a1^$updates"