#ifndef UNTITLED_BORROW_RETURN_H
#define UNTITLED_BORROW_RETURN_H
#include "../book_manage/book_manage.h"
#include "../reader_manage/reader_manage.h"
typedef struct br {
   Reader reader;
   Book book;
   struct br *next;
} Borrow;

typedef struct re {
    Reader reader;
    Book book;
    struct re *next;
} Return;
void Main_br_mana();
void br_Menu();

#endif //UNTITLED_BORROW_RETURN_H
