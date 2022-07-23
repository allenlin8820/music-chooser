#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "definition.h"

void Search() {
    int count = 1;
    char artist[buf];

    printf("type singer : ");
    scanf("%[^\n]", &artist );    // %[^\n]比對到\n的意思 
    scanf("%c", &whitespace );  ///ENTER的意思 
    printf(" %s has song  : \n", artist);

    printf ("NO.\tSong\tSinger\tTime\n");
    int i = 0;
    for (;i < 1024 ; i++) {
        if (strcmp (songList[i].artist, artist)==0 && songList[i].deleted==false) {           // 一行一行找輸入的歌手名 
            printf ("%d  %s  %s  %s\n", count, songList[i].name, songList[i].artist, songList[i].length);
            count++;
        } // if

    } // for

}
