#ifndef UNTITLED_BORROW_RETURN_H
#define UNTITLED_BORROW_RETURN_H
#include "../book_manage/book_manage.h"
#include "../reader_manage/reader_manage.h"
typedef struct br {
    char time[20];
   Reader reader;
   Book book;
   struct br *next;
} Borrow;

typedef struct re {
    char time[20];
    Reader reader;
    Book book;
    struct re *next;
} Return;
void Main_br_mana();
void br_Menu();
FILE * r_file_open();
FILE * b_file_open();
void put_return(FILE *fp,Return *head);
void put_borrow(FILE *fp,Borrow *head);
void showBorrow(Borrow *head);
void showReturn(Return *head);
void createTime(char time_str[]);
void register_borrow(Borrow *head,Book books[],int books_number,Reader readers[],int readers_number,FILE *fp);
void register_return(Return *head,Book books[],int books_number,Reader readers[],int readers_number,FILE *fp);
void rbclose(Borrow *bhead,Return *rhead);

#endif //UNTITLED_BORROW_RETURN_H
