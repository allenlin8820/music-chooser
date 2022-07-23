#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "definition.h"


void RandomPlay() {
    int x = rand() % 1024;
    while (songList[x].deleted)      // .deleted¤£­«½Æ 
        x = (x + 1) % 1024;

    printf ("%s  %s  %s\n", songList[x].name, songList[x].artist, songList[x].length);
}
