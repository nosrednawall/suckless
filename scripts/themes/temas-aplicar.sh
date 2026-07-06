#!/usr/bin/env sh

# ============================================
# TEMAS-APLICAR.SH - Versão corrigida
# ============================================

# Configurações
CONFIG_FILE="$HOME/.config/suckless/scripts/themes/temas.conf"
XRESOURCES_FILE="$HOME/.Xresources"
LOG_FILE="/tmp/temas-aplicar-debug.log"

# Função de debug
debug_log() {
    echo "[$(date '+%Y-%m-%d %H:%M:%S')] $1" | tee -a "$LOG_FILE"
}

# Função para verificar erro e parar
check_error() {
    if [ $? -ne 0 ]; then
        debug_log "❌ ERRO: $1"
        debug_log "❌ Script interrompido na linha $2"
        exit 1
    fi
}

debug_log "=========================================="
debug_log "INICIANDO SCRIPT - $(date)"
debug_log "=========================================="

# Função para ler valor de uma seção
get_theme_value() {
    local theme="$1"
    local key="$2"

    awk -v theme="[$theme]" -v key="$key" '
        $0 == theme { found=1 }
        found && $1 == key && $2 == "=" {
            gsub(/^[ \t]+/, "", $3)
            gsub(/[ \t]+$/, "", $3)
            print $3
            exit
        }
        found && /^\[/ && $0 != theme { exit }
    ' "$CONFIG_FILE"
}

# Função para carregar tema do arquivo de configuração
load_theme() {
    local theme_name="$1"

    debug_log "📂 Carregando tema: $theme_name"

    if ! grep -q "^\[$theme_name\]$" "$CONFIG_FILE"; then
        debug_log "❌ Tema não encontrado: $theme_name"
        return 1
    fi

    # Carrega todas as variáveis básicas
    THEME_GTK=$(get_theme_value "$theme_name" "theme_gtk")
    THEME_ICON=$(get_theme_value "$theme_name" "theme_icon")
    THEME_MODE=$(get_theme_value "$theme_name" "theme_mode")
    COLOR_MODE=$(get_theme_value "$theme_name" "color_mode")
    GTK_PREFER_DARK_MODE=$(get_theme_value "$theme_name" "gtk_prefer_dark")
    EMACS_THEME=$(get_theme_value "$theme_name" "emacs_theme")
    WALLPAPER_LIGHTDM=$(get_theme_value "$theme_name" "wallpaper")
    THEME_ICON_DUNST=$(get_theme_value "$theme_name" "theme_icon_dunst")

    # Cores base (para compatibilidade)
    COLOR_BACKGROUND=$(get_theme_value "$theme_name" "background")
    COLOR_BACKGROUND2=$(get_theme_value "$theme_name" "background2")
    COLOR_TEXT=$(get_theme_value "$theme_name" "text")

    # Cores principais (1-8)
    COLOR_1=$(get_theme_value "$theme_name" "color1")
    COLOR_2=$(get_theme_value "$theme_name" "color2")
    COLOR_3=$(get_theme_value "$theme_name" "color3")
    COLOR_4=$(get_theme_value "$theme_name" "color4")
    COLOR_5=$(get_theme_value "$theme_name" "color5")
    COLOR_6=$(get_theme_value "$theme_name" "color6")
    COLOR_7=$(get_theme_value "$theme_name" "color7")
    COLOR_8=$(get_theme_value "$theme_name" "color8")
    COLOR_9=$(get_theme_value "$theme_name" "color9")
    COLOR_10=$(get_theme_value "$theme_name" "color10")
    COLOR_11=$(get_theme_value "$theme_name" "color11")
    COLOR_12=$(get_theme_value "$theme_name" "color12")
    COLOR_13=$(get_theme_value "$theme_name" "color13")
    COLOR_14=$(get_theme_value "$theme_name" "color14")
    COLOR_15=$(get_theme_value "$theme_name" "color15")
    COLOR_16=$(get_theme_value "$theme_name" "color16")

    # ==========================================
    # CORES COMPLETAS DO TEMA DWM
    # ==========================================

    # Esquema Normal
    normfgcolor=$(get_theme_value "$theme_name" "normfgcolor")
    normbgcolor=$(get_theme_value "$theme_name" "normbgcolor")
    normbordercolor=$(get_theme_value "$theme_name" "normbordercolor")
    normfloatcolor=$(get_theme_value "$theme_name" "normfloatcolor")

    # Esquema Selecionado
    selfgcolor=$(get_theme_value "$theme_name" "selfgcolor")
    selbgcolor=$(get_theme_value "$theme_name" "selbgcolor")
    selbordercolor=$(get_theme_value "$theme_name" "selbordercolor")
    selfloatcolor=$(get_theme_value "$theme_name" "selfloatcolor")

    # Título Normal
    titlenormfgcolor=$(get_theme_value "$theme_name" "titlenormfgcolor")
    titlenormbgcolor=$(get_theme_value "$theme_name" "titlenormbgcolor")
    titlenormbordercolor=$(get_theme_value "$theme_name" "titlenormbordercolor")
    titlenormfloatcolor=$(get_theme_value "$theme_name" "titlenormfloatcolor")

    # Título Selecionado
    titleselfgcolor=$(get_theme_value "$theme_name" "titleselfgcolor")
    titleselbgcolor=$(get_theme_value "$theme_name" "titleselbgcolor")
    titleselbordercolor=$(get_theme_value "$theme_name" "titleselbordercolor")
    titleselfloatcolor=$(get_theme_value "$theme_name" "titleselfloatcolor")

    # Tags Normal
    tagsnormfgcolor=$(get_theme_value "$theme_name" "tagsnormfgcolor")
    tagsnormbgcolor=$(get_theme_value "$theme_name" "tagsnormbgcolor")
    tagsnormbordercolor=$(get_theme_value "$theme_name" "tagsnormbordercolor")
    tagsnormfloatcolor=$(get_theme_value "$theme_name" "tagsnormfloatcolor")

    # Tags Selecionado
    tagsselfgcolor=$(get_theme_value "$theme_name" "tagsselfgcolor")
    tagsselbgcolor=$(get_theme_value "$theme_name" "tagsselbgcolor")
    tagsselbordercolor=$(get_theme_value "$theme_name" "tagsselbordercolor")
    tagsselfloatcolor=$(get_theme_value "$theme_name" "tagsselfloatcolor")

    # Tags Não Utilizadas
    tagsunusedfgcolor=$(get_theme_value "$theme_name" "tagsunusedfgcolor")
    tagsunusedbgcolor=$(get_theme_value "$theme_name" "tagsunusedbgcolor")
    tagsunusedbordercolor=$(get_theme_value "$theme_name" "tagsunusedbordercolor")
    tagsunusedfloatcolor=$(get_theme_value "$theme_name" "tagsunusedfloatcolor")

    # Esquema Oculto
    hidnormfgcolor=$(get_theme_value "$theme_name" "hidnormfgcolor")
    hidnormbgcolor=$(get_theme_value "$theme_name" "hidnormbgcolor")
    hidselfgcolor=$(get_theme_value "$theme_name" "hidselfgcolor")
    hidselbgcolor=$(get_theme_value "$theme_name" "hidselbgcolor")

    # Esquema Urgente
    urgfgcolor=$(get_theme_value "$theme_name" "urgfgcolor")
    urgbgcolor=$(get_theme_value "$theme_name" "urgbgcolor")
    urgbordercolor=$(get_theme_value "$theme_name" "urgbordercolor")
    urgfloatcolor=$(get_theme_value "$theme_name" "urgfloatcolor")

    # Símbolo do Layout
    ltsymbolfgcolor=$(get_theme_value "$theme_name" "ltsymbolfgcolor")
    ltsymbolbgcolor=$(get_theme_value "$theme_name" "ltsymbolbgcolor")

    # Fallbacks para cores não definidas
    [ -z "$normfgcolor" ] && normfgcolor="$COLOR_TEXT"
    [ -z "$normbgcolor" ] && normbgcolor="$COLOR_BACKGROUND"
    [ -z "$normbordercolor" ] && normbordercolor="$COLOR_1"
    [ -z "$normfloatcolor" ] && normfloatcolor="$COLOR_8"

    [ -z "$selfgcolor" ] && selfgcolor="$COLOR_TEXT"
    [ -z "$selbgcolor" ] && selbgcolor="$COLOR_2"
    [ -z "$selbordercolor" ] && selbordercolor="$COLOR_3"
    [ -z "$selfloatcolor" ] && selfloatcolor="$COLOR_4"

    [ -z "$titlenormfgcolor" ] && titlenormfgcolor="$COLOR_TEXT"
    [ -z "$titlenormbgcolor" ] && titlenormbgcolor="$COLOR_BACKGROUND"
    [ -z "$titlenormbordercolor" ] && titlenormbordercolor="$COLOR_1"
    [ -z "$titlenormfloatcolor" ] && titlenormfloatcolor="$COLOR_8"

    [ -z "$titleselfgcolor" ] && titleselfgcolor="$COLOR_TEXT"
    [ -z "$titleselbgcolor" ] && titleselbgcolor="$COLOR_2"
    [ -z "$titleselbordercolor" ] && titleselbordercolor="$COLOR_3"
    [ -z "$titleselfloatcolor" ] && titleselfloatcolor="$COLOR_4"

    [ -z "$tagsnormfgcolor" ] && tagsnormfgcolor="$COLOR_TEXT"
    [ -z "$tagsnormbgcolor" ] && tagsnormbgcolor="$COLOR_BACKGROUND"
    [ -z "$tagsnormbordercolor" ] && tagsnormbordercolor="$COLOR_1"
    [ -z "$tagsnormfloatcolor" ] && tagsnormfloatcolor="$COLOR_8"

    [ -z "$tagsselfgcolor" ] && tagsselfgcolor="$COLOR_TEXT"
    [ -z "$tagsselbgcolor" ] && tagsselbgcolor="$COLOR_2"
    [ -z "$tagsselbordercolor" ] && tagsselbordercolor="$COLOR_3"
    [ -z "$tagsselfloatcolor" ] && tagsselfloatcolor="$COLOR_4"

    [ -z "$tagsunusedfgcolor" ] && tagsunusedfgcolor="$COLOR_TEXT"
    [ -z "$tagsunusedbgcolor" ] && tagsunusedbgcolor="$COLOR_BACKGROUND"
    [ -z "$tagsunusedbordercolor" ] && tagsunusedbordercolor="$COLOR_1"
    [ -z "$tagsunusedfloatcolor" ] && tagsunusedfloatcolor="$COLOR_8"

    [ -z "$hidnormfgcolor" ] && hidnormfgcolor="$COLOR_2"
    [ -z "$hidnormbgcolor" ] && hidnormbgcolor="$COLOR_BACKGROUND"
    [ -z "$hidselfgcolor" ] && hidselfgcolor="$COLOR_6"
    [ -z "$hidselbgcolor" ] && hidselbgcolor="$COLOR_BACKGROUND"

    [ -z "$urgfgcolor" ] && urgfgcolor="$COLOR_TEXT"
    [ -z "$urgbgcolor" ] && urgbgcolor="$COLOR_BACKGROUND"
    [ -z "$urgbordercolor" ] && urgbordercolor="$COLOR_3"
    [ -z "$urgfloatcolor" ] && urgfloatcolor="$COLOR_8"

    [ -z "$ltsymbolfgcolor" ] && ltsymbolfgcolor="$COLOR_2"
    [ -z "$ltsymbolbgcolor" ] && ltsymbolbgcolor="$COLOR_BACKGROUND"

    debug_log "✅ Tema carregado: $THEME_MODE $COLOR_MODE"
}

# Função para aplicar tema pywal
apply_pywal() {
    local mode="$1"
    local wallpaper="$2"

    debug_log "🎨 Aplicando pywal (mode=$mode)"

    if [ -n "$wallpaper" ]; then
        debug_log "   Wallpaper: $wallpaper"
        wal -i "$wallpaper" -n
    else
        debug_log "   Wallpaper: random"
        wal -i "$HOME/.wallpapers/random" -n
    fi
    check_error "Falha ao executar pywal" $LINENO

    sleep 1

    local colors_json="$HOME/.cache/wal/colors.json"
    if [ ! -f "$colors_json" ]; then
        debug_log "❌ pywal não gerou o arquivo de cores"
        return 1
    fi

    THEME_GTK="FlatColor"
    THEME_ICON="flattrcolor"
    THEME_MODE="Pywal"
    COLOR_MODE="${mode^}"
    WALLPAPER_LIGHTDM=$(basename "$(jq -r '.wallpaper' "$colors_json")")

    # Carrega cores do pywal
    COLOR_BACKGROUND=$(jq -r '.colors.color0' "$colors_json")
    COLOR_BACKGROUND2=$(jq -r '.colors.color0' "$colors_json")
    COLOR_TEXT=$(jq -r '.colors.color7' "$colors_json")

    COLOR_1=$(jq -r '.colors.color1' "$colors_json")
    COLOR_2=$(jq -r '.colors.color2' "$colors_json")
    COLOR_3=$(jq -r '.colors.color3' "$colors_json")
    COLOR_4=$(jq -r '.colors.color4' "$colors_json")
    COLOR_5=$(jq -r '.colors.color5' "$colors_json")
    COLOR_6=$(jq -r '.colors.color6' "$colors_json")
    COLOR_7=$(jq -r '.colors.color8' "$colors_json")
    COLOR_8=$(jq -r '.colors.color9' "$colors_json")

    COLOR_9=$(jq -r '.colors.color1' "$colors_json")
    COLOR_10=$(jq -r '.colors.color2' "$colors_json")
    COLOR_11=$(jq -r '.colors.color3' "$colors_json")
    COLOR_12=$(jq -r '.colors.color4' "$colors_json")
    COLOR_13=$(jq -r '.colors.color5' "$colors_json")
    COLOR_14=$(jq -r '.colors.color6' "$colors_json")
    COLOR_15=$(jq -r '.colors.color8' "$colors_json")
    COLOR_16=$(jq -r '.colors.color9' "$colors_json")

    # Mapeia cores do pywal para todas as variáveis do dwm
    normfgcolor="$COLOR_TEXT"
    normbgcolor="$COLOR_BACKGROUND"
    normbordercolor="$COLOR_1"
    normfloatcolor="$COLOR_8"

    selfgcolor="$COLOR_TEXT"
    selbgcolor="$COLOR_2"
    selbordercolor="$COLOR_3"
    selfloatcolor="$COLOR_4"

    titlenormfgcolor="$COLOR_TEXT"
    titlenormbgcolor="$COLOR_BACKGROUND"
    titlenormbordercolor="$COLOR_1"
    titlenormfloatcolor="$COLOR_8"

    titleselfgcolor="$COLOR_TEXT"
    titleselbgcolor="$COLOR_2"
    titleselbordercolor="$COLOR_3"
    titleselfloatcolor="$COLOR_4"

    tagsnormfgcolor="$COLOR_TEXT"
    tagsnormbgcolor="$COLOR_BACKGROUND"
    tagsnormbordercolor="$COLOR_1"
    tagsnormfloatcolor="$COLOR_8"

    tagsselfgcolor="$COLOR_TEXT"
    tagsselbgcolor="$COLOR_2"
    tagsselbordercolor="$COLOR_3"
    tagsselfloatcolor="$COLOR_4"

    tagsunusedfgcolor="$COLOR_TEXT"
    tagsunusedbgcolor="$COLOR_BACKGROUND"
    tagsunusedbordercolor="$COLOR_1"
    tagsunusedfloatcolor="$COLOR_8"

    hidnormfgcolor="$COLOR_2"
    hidnormbgcolor="$COLOR_BACKGROUND"
    hidselfgcolor="$COLOR_6"
    hidselbgcolor="$COLOR_BACKGROUND"

    urgfgcolor="$COLOR_TEXT"
    urgbgcolor="$COLOR_BACKGROUND"
    urgbordercolor="$COLOR_3"
    urgfloatcolor="$COLOR_8"

    ltsymbolfgcolor="$COLOR_2"
    ltsymbolbgcolor="$COLOR_BACKGROUND"

    debug_log "✅ Pywal aplicado"
}

# Função para gerar .Xresources
generate_xresources() {
    debug_log "📝 Gerando .Xresources"

    # Gera o arquivo usando um heredoc com substituição direta de variáveis
    cat > "$XRESOURCES_FILE" << EOF
! ==========================================
! Tema: $THEME_MODE $COLOR_MODE
! Gerado em: $(date)
! ==========================================

! Cores base
*background: $COLOR_BACKGROUND
*background2: $COLOR_BACKGROUND2
*foreground: $COLOR_TEXT

! Cores principais (1-16)
*color0: $COLOR_BACKGROUND
*color1: $COLOR_1
*color2: $COLOR_2
*color3: $COLOR_3
*color4: $COLOR_4
*color5: $COLOR_5
*color6: $COLOR_6
*color7: $COLOR_TEXT
*color8: $COLOR_BACKGROUND2
*color9: $COLOR_9
*color10: $COLOR_10
*color11: $COLOR_11
*color12: $COLOR_12
*color13: $COLOR_13
*color14: $COLOR_14
*color15: $COLOR_15
*color16: $COLOR_16

! ==========================================
! CORES COMPLETAS DO DWM
! ==========================================

! Esquema Normal
dwm.normfgcolor: $normfgcolor
dwm.normbgcolor: $normbgcolor
dwm.normbordercolor: $normbordercolor
dwm.normfloatcolor: $normfloatcolor

! Esquema Selecionado
dwm.selfgcolor: $selfgcolor
dwm.selbgcolor: $selbgcolor
dwm.selbordercolor: $selbordercolor
dwm.selfloatcolor: $selfloatcolor

! Título Normal
dwm.titlenormfgcolor: $titlenormfgcolor
dwm.titlenormbgcolor: $titlenormbgcolor
dwm.titlenormbordercolor: $titlenormbordercolor
dwm.titlenormfloatcolor: $titlenormfloatcolor

! Título Selecionado
dwm.titleselfgcolor: $titleselfgcolor
dwm.titleselbgcolor: $titleselbgcolor
dwm.titleselbordercolor: $titleselbordercolor
dwm.titleselfloatcolor: $titleselfloatcolor

! Tags Normal
dwm.tagsnormfgcolor: $tagsnormfgcolor
dwm.tagsnormbgcolor: $tagsnormbgcolor
dwm.tagsnormbordercolor: $tagsnormbordercolor
dwm.tagsnormfloatcolor: $tagsnormfloatcolor

! Tags Selecionado
dwm.tagsselfgcolor: $tagsselfgcolor
dwm.tagsselbgcolor: $tagsselbgcolor
dwm.tagsselbordercolor: $tagsselbordercolor
dwm.tagsselfloatcolor: $tagsselfloatcolor

! Tags Não Utilizadas
dwm.tagsunusedfgcolor: $tagsunusedfgcolor
dwm.tagsunusedbgcolor: $tagsunusedbgcolor
dwm.tagsunusedbordercolor: $tagsunusedbordercolor
dwm.tagsunusedfloatcolor: $tagsunusedfloatcolor

! Esquema Oculto
dwm.hidnormfgcolor: $hidnormfgcolor
dwm.hidnormbgcolor: $hidnormbgcolor
dwm.hidselfgcolor: $hidselfgcolor
dwm.hidselbgcolor: $hidselbgcolor

! Esquema Urgente
dwm.urgfgcolor: $urgfgcolor
dwm.urgbgcolor: $urgbgcolor
dwm.urgbordercolor: $urgbordercolor
dwm.urgfloatcolor: $urgfloatcolor

! Símbolo do Layout
dwm.ltsymbolfgcolor: $ltsymbolfgcolor
dwm.ltsymbolbgcolor: $ltsymbolbgcolor

! Cores individuais das tags (para compatibilidade)
dwm.tag1: $COLOR_1
dwm.tag2: $COLOR_2
dwm.tag3: $COLOR_3
dwm.tag4: $COLOR_4
dwm.tag5: $COLOR_5
dwm.tag6: $COLOR_6
dwm.tag7: $COLOR_7
dwm.tag8: $COLOR_8
dwm.tag9: $COLOR_9
EOF

    check_error "Falha ao gerar .Xresources" $LINENO
    debug_log "✅ .Xresources gerado com sucesso"

    cat > "$HOME/.theme_selected" <<EOF
#!/bin/bash
THEME_GTK="$THEME_GTK"
THEME_ICON="$THEME_ICON"
THEME_MODE="$THEME_MODE"
COLOR_MODE="$COLOR_MODE"
THEME_ICON_DUNST="$THEME_ICON_DUNST"
GTK_PREFER_DARK_MODE="$GTK_PREFER_DARK_MODE"
EMACS_THEME="$EMACS_THEME"
WALLPAPER_LIGHTDM="$WALLPAPER_LIGHTDM"
COLOR_BACKGROUND="$COLOR_BACKGROUND"
COLOR_BACKGROUND2="$COLOR_BACKGROUND2"
COLOR_TEXT="$COLOR_TEXT"
COLOR_1="$COLOR_1"
COLOR_2="$COLOR_2"
COLOR_3="$COLOR_3"
COLOR_4="$COLOR_4"
COLOR_5="$COLOR_5"
COLOR_6="$COLOR_6"
COLOR_7="$COLOR_7"
COLOR_8="$COLOR_8"
COLOR_9="$COLOR_9"
COLOR_10="$COLOR_10"
COLOR_11="$COLOR_11"
COLOR_12="$COLOR_12"
COLOR_13="$COLOR_13"
COLOR_14="$COLOR_14"
COLOR_15="$COLOR_15"
COLOR_16="$COLOR_16"

EOF
    check_error "Falha ao gerar .theme_selected" $LINENO
    debug_log "✅ .theme_selected gerado com sucesso - $THEME_ICON_DUNST"
}

# Função para aplicar configurações GTK
apply_gtk_settings() {
    debug_log "🎨 Aplicando configurações GTK"

    if [ -f ~/.config/gtk-2.0/gtkrc ]; then
        debug_log "   Atualizando GTK2"
        sed -i "s/^gtk-icon-theme-name =.*/gtk-icon-theme-name = \"$THEME_ICON\"/" ~/.config/gtk-2.0/gtkrc
        sed -i "s/^gtk-theme-name =.*/gtk-theme-name = \"$THEME_GTK\"/" ~/.config/gtk-2.0/gtkrc
    fi

    if [ -f ~/.config/gtk-3.0/settings.ini ]; then
        debug_log "   Atualizando GTK3"
        sed -i "s/^gtk-theme-name=.*/gtk-theme-name=$THEME_GTK/" ~/.config/gtk-3.0/settings.ini
        sed -i "s/^gtk-icon-theme-name=.*/gtk-icon-theme-name=$THEME_ICON/" ~/.config/gtk-3.0/settings.ini
        sed -i "s/^gtk-application-prefer-dark-theme=.*/gtk-application-prefer-dark-theme=$GTK_PREFER_DARK_MODE/" ~/.config/gtk-3.0/settings.ini
    fi

    debug_log "✅ GTK configurado"
}

# Função para aplicar wallpaper
apply_wallpaper() {
    debug_log "🖼️ Aplicando wallpaper"

    if [ "$pywal_flag" = "1" ]; then
        local wallpaper=$(jq -r '.wallpaper' ~/.cache/wal/colors.json)
        debug_log "   Wallpaper pywal: $wallpaper"
        feh --bg-fill "$wallpaper" &
    else
        local wallpaper_dir="$HOME/.wallpapers/${THEME_MODE}/${COLOR_MODE}"
        debug_log "   Procurando em: $wallpaper_dir"

        if [ -d "$wallpaper_dir" ]; then
            local wallpaper=$(find "$wallpaper_dir" -type f \( -iname \*.jpg -o -iname \*.png -o -iname \*.jpeg \) 2>/dev/null | shuf -n 1)

            if [ -n "$wallpaper" ]; then
                debug_log "   Wallpaper encontrado: $wallpaper"
                feh --bg-fill "$wallpaper" &
            else
                debug_log "   ⚠️ Nenhum wallpaper encontrado"
            fi
        else
            debug_log "   ⚠️ Diretório não existe: $wallpaper_dir"
        fi
    fi

    debug_log "✅ Wallpaper aplicado"
}

# Função para reiniciar serviços
restart_services() {
    debug_log "🔄 Reiniciando serviços"

    # Recarrega .Xresources
    debug_log "   Recarregando .Xresources"
    xrdb -merge "$XRESOURCES_FILE" 2>/dev/null || xrdb "$XRESOURCES_FILE"
    check_error "Falha ao carregar .Xresources" $LINENO

    # Reinicia Dunst (com cuidado para não matar o terminal)
    debug_log "   Reiniciando Dunst"
    if pgrep -x "dunst" > /dev/null; then
        debug_log "   Matando dunst existente"
        killall dunst 2>/dev/null
        sleep 0.5
    fi

    tema_dunst=$(echo "$choice" | sed 's/ /-/g' | tr '[:upper:]' '[:lower:]')
    if [ -f "$HOME/.config/dunst/scripts/switch-theme.sh" ]; then
        debug_log "   Aplicando tema dunst: $tema_dunst"
        #sh "$HOME/.config/dunst/scripts/switch-theme.sh" "$tema_dunst"
                sh "$HOME/.config/dunst/scripts/switch-theme.sh" "xresources"
    fi

    debug_log "   Iniciando dunst"
    dunst -conf "$HOME/.config/dunst/dunstrc" &
    sleep 0.5

    # Recarrega dwm
    if pgrep -x "dwm" > /dev/null; then
        debug_log "   Recarregando dwm"

        # Verifica se xdotool está disponível
        if command -v xdotool &> /dev/null; then
            debug_log "   Enviando Super+Shift+F5 via xdotool"
            xdotool key Super+Shift+F5 2>/dev/null
        else
            debug_log "   ⚠️ xdotool não encontrado"
        fi

        # Fallback
        debug_log "   Enviando sinal de reload via xsetroot"
        xsetroot -name "reload" 2>/dev/null
    else
        debug_log "   ⚠️ dwm não está rodando"
    fi

    # Recarrega outros aplicativos
    debug_log "   Recarregando aplicativos"
    pkill -USR1 st 2>/dev/null
    pkill -USR1 urxvt 2>/dev/null

    debug_log "✅ Serviços reiniciados"
}

# Script principal
main() {
    local choice="$1"
    local pywal_flag="0"

    debug_log "🚀 Iniciando main() com choice='$choice'"

    if [ -z "$choice" ]; then
        debug_log "❌ Nenhum tema selecionado"
        exit 0
    fi

    choice=$(echo "$choice" | sed 's/^[[:space:]]*//')
    debug_log "   Choice limpo: '$choice'"

    # Verifica se é tema pywal
    if [[ "$choice" == "Wallpaper"* ]] || [[ "$choice" == "pywal" ]]; then
        debug_log "🎨 Modo pywal detectado"
        pywal_flag="1"
        case "$choice" in
            "Wallpaper Aleatório Dark"|"pywal")
                apply_pywal "dark"
                ;;
            "Wallpaper Atual Dark")
                local current_wallpaper=$(grep -oP "'\K[^']+(?=')" ~/.fehbg 2>/dev/null)
                debug_log "   Wallpaper atual: $current_wallpaper"
                apply_pywal "dark" "$current_wallpaper"
                ;;
            "Wallpaper Aleatório Light")
                apply_pywal "light"
                ;;
            "Wallpaper Atual Light")
                local current_wallpaper=$(grep -oP "'\K[^']+(?=')" ~/.fehbg 2>/dev/null)
                debug_log "   Wallpaper atual: $current_wallpaper"
                apply_pywal "light" "$current_wallpaper"
                ;;
            *)
                debug_log "❌ Opção pywal inválida: $choice"
                echo "Opção pywal inválida: $choice"
                exit 1
                ;;
        esac
        check_error "Falha ao aplicar pywal" $LINENO
    else
        debug_log "📂 Modo tema normal"
        load_theme "$choice"
        if [ $? -ne 0 ]; then
            debug_log "❌ Falha ao carregar tema"
            exit 1
        fi
    fi

    debug_log "📢 Enviando notificação: Configurando $THEME_MODE $COLOR_MODE"
    dunstify "Aplicando tema" "Configurando $THEME_MODE $COLOR_MODE..." \
        -h int:value:10 \
        -i /usr/share/icons/ePapirus/16x16/status/package-reinstall.svg 2>/dev/null

    # Gera .Xresources
    generate_xresources

    # Aplica configurações GTK
    apply_gtk_settings

    # Aplica wallpaper
    debug_log "📢 Enviando notificação: Aplicando wallpaper"
    dunstify "Aplicando tema" "Aplicando wallpaper..." \
        -h int:value:30 \
        -i /usr/share/icons/ePapirus/16x16/status/package-reinstall.svg 2>/dev/null
    apply_wallpaper

    # Reinicia serviços
    debug_log "📢 Enviando notificação: Reiniciando serviços"
    dunstify "Aplicando tema" "Reiniciando serviços..." \
        -h int:value:50 \
        -i /usr/share/icons/ePapirus/16x16/status/package-reinstall.svg 2>/dev/null
    restart_services

    debug_log "📢 Enviando notificação: Pronto!"
    dunstify "Pronto" "Tema $THEME_MODE $COLOR_MODE aplicado com sucesso!" \
        -h int:value:100 \
        -i /usr/share/icons/ePapirus/16x16/status/package-install.svg 2>/dev/null

    debug_log "✅ Script finalizado com sucesso!"
    debug_log "=========================================="
}

# Executa o script
main "$@"

# Mostra o caminho do log
echo ""
echo "📋 Log salvo em: $LOG_FILE"
echo "   Veja o log com: cat $LOG_FILE"
echo "   Ou acompanhe com: tail -f $LOG_FILE"
