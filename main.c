#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#include "definition.h"

void Massages();
void Auto_add(FILE *fp);
void init();


int main () {

    srand (time(NULL));
    FILE *fp;
    char command [10];

    init();

    fp = fopen ("input.csv", "r");

    Auto_add(fp);
    fclose(fp);

    Massages();
    for ( scanf ("%s", command) ; strcmp(command, "0") != 0 ; scanf ("%s", command) ) {

        scanf("%c", &whitespace );
        if (strcmp(command, "1") == 0)
            Add();
        else if (strcmp(command, "2") == 0)
            Show();
        else if (strcmp(command, "3") == 0)
            Delete();
        else if (strcmp(command, "4") == 0)               // 只要輸入不等於0就會一直跑下去 
            Search();
        else if (strcmp(command, "5") == 0)
            Modify();
        else if (strcmp(command, "6") == 0)
            RandomPlay();
        else
            printf ("really??\n");

        Massages() ;
    } // for

    return 0;
} //


void Massages() {
    printf ("\n***  Question CD Player      ***\n");
    printf ("* 0. QUIT                      *\n");
    printf ("* 1. Add                       *\n");
    printf ("* 2. Show                      *\n");
    printf ("* 3. Delete                    *\n");
    printf ("* 4. Search                    *\n");
    printf ("* 5. Modify                    *\n");
    printf ("* 6. Random Play               *\n");
    printf ("********************************\n");
    printf ("Input a choice(0, 1, 2, 3, 4, 5, 6)  : ");
} // Massages()

void init() {
    int i = 0;
    for (i = 0 ; i < 1024 ; i++)
        songList[i].deleted = true;
}

void Auto_add(FILE *fp) {
    int i = 0, j = 0;
    char ch = '\"';
    char ch2[] = ",\n";
    char *token;
    char in[1024], in2[1024];
    char b[3][1024];

    while (fgets (in, 1024, fp) != NULL) {
        song newSong;
        newSong.deleted = false;                    //沒刪掉任何東西(初始化) 
        int k = 0;
        if (strchr (in, ch) == NULL) {
            token = strtok(in, ch2);
            while(token!=NULL){                     // while(token!=NULL)取出字串 
                strcpy(b[k++],token);
                token = strtok(NULL, ch2);
            }

            strcpy(newSong.name, b[0]);
            strcpy(newSong.artist, b[1]);
            strcpy(newSong.length, b[2]);
        } else {
            if (in[0] == '\"') {    // 雙引號'\"'  
                i++;
                while (in[i] != '\"') {
                    in2[j++] = in[i++];
                }
                in2[j]='\0';
                strcpy(newSong.name, in2);
                i++;
                i++;                  // 先給值再做運算    I+2會直接運算 效率比較低 
                j = 0;

                while (in[i] != ',') {
                    in2[j++] = in[i++];
                }
                in2[j]='\0';          // 空字元'\0' 
                strcpy(newSong.artist, in2);
                i++;
                j = 0;

                while (in[i] != '\n') {
                    in2[j++] = in[i++];
                }
                in2[j]='\0';
                strcpy(newSong.length, in2);
                i = 0;
                j = 0;
            }
            else{
                while (in[i] != ',') {
                    in2[j++] = in[i++];
                }
                in2[j]='\0';
                strcpy(newSong.name, in2);
                i++;
                i++;
                j = 0;

                while (in[i] != '\"') {
                    in2[j++] = in[i++];
                }
                in2[j]='\0';
                strcpy(newSong.artist, in2);
                i++;
                i++;
                j = 0;

                while (in[i] != '\n') {
                    in2[j++] = in[i++];
                }
                in2[j]='\0';
                strcpy(newSong.length, in2);
                i = 0;
                j = 0;
            }

        }
        songList[songIndex++] = newSong;
    }
}

