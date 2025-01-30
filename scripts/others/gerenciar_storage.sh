#!/bin/bash

# Configurações
SERVER="192.168.42.198"
SHARE="storage"
MOUNT_POINT="/mnt/storage"

# Credenciais em /etc/samba/credentials/share
#USERNAME="umbrel"
#PASSWORD="$(pass show samba-local)"

OPTIONS="workgroup=workgroup,iocharset=utf8,uid=1000,gid=1000"

# Função para montar o compartilhamento
montar() {
    # Criar o diretório de montagem, se não existir
    if [ ! -d "$MOUNT_POINT" ]; then
        echo "Criando diretório de montagem: $MOUNT_POINT"
        sudo mkdir -p "$MOUNT_POINT"
    fi

    # Verificar se já está montado
    if mount | grep -q "$MOUNT_POINT"; then
        echo "O compartilhamento já está montado em $MOUNT_POINT."
    else
        echo "Montando o compartilhamento..."
        #sudo mount -t cifs "//$SERVER/$SHARE" "$MOUNT_POINT" -o username=$USERNAME,password=$PASSWORD,$OPTIONS
        sudo mount -t cifs "//$SERVER/$SHARE" "$MOUNT_POINT" -o credentials=/etc/samba/credentials/share,$OPTIONS

        # Verificar se a montagem foi bem-sucedida
        if mount | grep -q "$MOUNT_POINT"; then
            echo "Montagem concluída com sucesso!"
        else
            echo "Erro ao montar o compartilhamento."
        fi
    fi
}

# Função para desmontar o compartilhamento
desmontar() {
    if mount | grep -q "$MOUNT_POINT"; then
        echo "Desmontando $MOUNT_POINT..."
        sudo umount "$MOUNT_POINT"

        if mount | grep -q "$MOUNT_POINT"; then
            echo "Erro ao desmontar o compartilhamento."
        else
            echo "Desmontagem concluída com sucesso!"
        fi
    else
        echo "O compartilhamento não está montado."
    fi
}

# Verificar argumento passado
case "$1" in
    montar)
        montar
        ;;
    desmontar)
        desmontar
        ;;
    *)
        echo "Uso: $0 {montar|desmontar}"
        exit 1
        ;;
esac
