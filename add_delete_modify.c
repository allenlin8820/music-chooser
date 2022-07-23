#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "definition.h"

void Add() {
    printf ("type new song info( name, artist, length ) : \n");
    song newSong;

    printf("song : ");
    scanf("%[^\n]", &newSong.name );
    scanf("%c", &whitespace );

    printf("\nsinger : ");
    scanf("%[^\n]", &newSong.artist );
    scanf("%c", &whitespace );

    printf("\ntime : ");
    scanf("%[^\n]", &newSong.length );
    scanf("%c", &whitespace );

    newSong.deleted = false;
    songList[songIndex++] = newSong;


    printf ("Add success!\n");
}


void Delete() {
    printf ("type song info( song, singer, time ) : \n");
    char name[buf], artist[buf], length[buf];


    printf("song : ");
    scanf("%[^\n]", &name );
    scanf("%c", &whitespace );

    printf("\nsinger : ");                    // 一個一個對看要改甚麼 
    scanf("%[^\n]", &artist );                        
    scanf("%c", &whitespace );

    printf("\ntime : ");
    scanf("%[^\n]", &length );
    scanf("%c", &whitespace );

    int i = 0;
    bool success = false;                 //bool 布林變數 
    for (i = 0 ; i < 1024 ; i++) {
        if ( strcmp (songList[i].name, name)==0 && strcmp (songList[i].artist, artist)==0 && strcmp (songList[i].length, length)==0 ) {
            songList[i].deleted = true;
            printf ( "Delete success!\n" );
            success = true;
            break;
        } // if

    } // for

    if ( !success ) printf ( "Delete failed!\n" );
}


void Modify() {
    char name[buf], artist[buf], length[buf];
    printf ("type song info( name, artist, length ) : \n");
    printf ("name : ");
    scanf ("%[^\n]", name);
    scanf("%c", &whitespace );

    printf ("artist : ");
    scanf ("%[^\n]", artist);
    scanf("%c", &whitespace );

    printf ("length : ");
    scanf ("%[^\n]", length);
    scanf("%c", &whitespace );

    int i;
    for (i = 0 ; i < 1024 ; i++)
        if (strcmp (songList[i].name, name)==0 && strcmp (songList[i].artist, artist)==0 && strcmp (songList[i].length, length)==0 && songList[i].deleted==0)
            break;

    printf ("type type( name or artist or length ) : \n");
    char in[buf];
    scanf ("%s",in);
    printf ("change to : ");
    char in2[buf];
    scanf ("%s",in2);

    if (!strcmp (in, "name"))
        strcpy (songList[i].name, in2); // if
    else if (!strcmp (in, "artist"))
        strcpy (songList[i].artist, in2); // else if
    else if (!strcmp (in, "length"))
        strcpy (songList[i].length, in2); // else if
    else
        printf ("cant find ( name or artist or length )\n");

    printf ("Modify success!\n");
}
