//
// Created by 86139 on 2023/5/4.
//

#include "../borrow_return.h"
void showReturn(Return *head){
    for (Return *p= head->next; p ->next !=NULL; p= p->next) {
        printf("%s %d %s %s %d %s %s\n",
               p->time,
               p->reader.id,
               p->reader.name,
               p->reader.sex,
               p->book.id,
               p->book.writer,
               p->book.name);
    }
}

void register_return(Return *head,Book books[],int books_number,Reader readers[],int readers_number){

}
