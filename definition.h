#include <stdbool.h>
#define buf 100

void Add();
void Modify();
void Delete();
void Search();
void Show();
void RandomPlay();


typedef struct song {
    char name[buf];
    char artist[buf];
    char length[buf];
    bool deleted;
}song;

song songList[1024];
int songIndex ;
char whitespace[1];

