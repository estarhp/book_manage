#include "stdio.h"
//创建图书容器
typedef struct book {
    int id;
    char name[50];
    char writer[20];
} Book;

void add_book();

FILE * file_open();

void init_book(int number,FILE *fp,Book books[]);//初始化图书

int Books_number(FILE *fp);//计算文件中图书的数目

void Main_book_mana(){

    FILE *fp=file_open();

    int books_number=Books_number(fp);//计算图书数量

    Book books[books_number];//创建图书容器

    init_book(books_number,fp,books);//初始化，将书本放入容器

//    for (int i = 0; i < books_number; ++i) {
//        printf("%d %s %s\n",books[i].id,books[i].name,books[i].writer);
//    }



}

void add_book(){

}

int Books_number(FILE *fp) {

    int flag = 0, file_row = 0, count = 0;
    while (!feof(fp)) {
        flag = fgetc(fp);
        if (flag == '\n')
            count++;
    }
    file_row = count; //加上最后一行

    rewind(fp);
    return file_row;
}

void init_book(int number,FILE *fp,Book books[]){

    for (int i = 0; i < number; ++i) {
        scanf("%d %s %s",&books[i].id,&books[i].name,&books[i].writer);
    }//从文件读入书本

    fclose(fp);

}

FILE * file_open(){
    FILE *fp;

    if ((fp = freopen("../books.txt", "r",stdin)) == NULL){
        fp = freopen("books.txt", "r",stdin);
    }else printf("文件路径Error!\n");

    return fp;
}





