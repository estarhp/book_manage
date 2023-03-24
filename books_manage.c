#include "stdio.h"

struct book {
    int id;
    char s[50];
    char name[20];
    struct book *next;
} Book;

void add_book();

int init_book();


void Main_book_mana(){

}

void add_book(){

}

int init_book(){
    FILE *fp;

    char s[50];

    if ((fp = fopen("D:\\Desktop\\Clion\\books.txt", "r")) == NULL) {
        printf("Error!\n");
        return -1;
    }

    while (1){
        fgets(s, 40, fp);
        if(feof(fp)) break;
        printf("%s",s);

    }

}

};



