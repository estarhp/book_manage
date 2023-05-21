//
// Created by 86139 on 2023/5/3.
//

#include "../book_manage.h"
#include "stdio.h"
#include "string.h"
#include "unistd.h"


int add_book(Book books[],int books_number,FILE *fp){
    fflush(stdin);
    rewind(fp);
    Book addbook;
    printf("请输入要添加的书名:\n");
    fgets(addbook.name, 50, stdin);

    if (strlen(addbook.name) == 49) {
        printf("你输的也太长了吧！！！！");
        sleep(2);
        return -1;
    }

    addbook.name[strcspn(addbook.name, "\n")] = '\0';
//   addbook.name[strlen(addbook.name)-2] = ' ';


    printf("请输入要添加图书的作者:\n");

    fgets(addbook.writer, 20, stdin);

    if (strlen(addbook.writer) == 19) {

        printf("你输的也太长了吧！！！！");
        sleep(2);
        return -1;
    }

    addbook.writer[strcspn(addbook.writer, "\n")] = '\0';





    addbook.id=books[books_number-1].id+1;
    fprintf(fp, "%d %s %s\n", addbook.id, addbook.writer, addbook.name);
    sleep(2);
    printf("您已添加成功新的书籍（重新进入系统时刷新数据）\n");

    return 1;
}
