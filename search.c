#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "definition.h"

void Search() {
    int count = 1;
    char artist[buf];

    printf("type singer : ");
    scanf("%[^\n]", &artist );    // %[^\n]����\n���N�� 
    scanf("%c", &whitespace );  ///ENTER���N�� 
    printf(" %s has song  : \n", artist);

    printf ("NO.\tSong\tSinger\tTime\n");
    int i = 0;
    for (;i < 1024 ; i++) {
        if (strcmp (songList[i].artist, artist)==0 && songList[i].deleted==false) {           // �@��@����J���q��W 
            printf ("%d  %s  %s  %s\n", count, songList[i].name, songList[i].artist, songList[i].length);
            count++;
        } // if

    } // for

}
