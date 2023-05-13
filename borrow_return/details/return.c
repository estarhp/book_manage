//
// Created by 86139 on 2023/5/4.
//

#include "../borrow_return.h"
void showReurn(Return *head){
    for (Borrow *p= head; p ->next !=NULL; p= p->next) {
        printf("%d %s %s %d %s %s",
               p->reader.id,
               p->reader.name,
               p->reader.sex,
               p->book.id,
               p->book.writer,
               p->book.name);
    }
}
