#!/usr/bin/env sh

# Abre as URLs no navegador
docker-compose -f "$1/docker-compose.yml" ps --status running \
    | awk '{print $11}' \
    | grep -oP '\d+->\d+' \
    | awk -F'->' '{print "http://localhost:" $1}' \
    | xargs -I {} bash -c 'xdg-open {} &'
