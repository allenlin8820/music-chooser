#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "definition.h"

void Show() {
    int count = 1, i;
    for (i = 0 ; i < 1024 ; i++) {
        if (songList[i].deleted==false) {     //ªì©l¤Ædeleted==false 

            printf ("%d  %s  %s  %s\n", count, songList[i].name, songList[i].artist, songList[i].length);
            count++;
        } // if
    } // for
}

