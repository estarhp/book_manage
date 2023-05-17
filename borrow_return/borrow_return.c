#include "stdio.h"
#include "borrow_return.h"
#include "malloc.h"
#include "../reader_manage/reader_manage.h"
#include "../book_manage/book_manage.h"

void Main_br_mana(){
    Borrow *bhead=NULL;
    Return *rhead=NULL;
    bhead=(Borrow *)malloc(sizeof(Borrow));
    rhead= (Return *)malloc(sizeof (Return));
    bhead -> next =NULL;
    rhead -> next =NULL;


    FILE *bfp= b_file_open();
    FILE *rfp= r_file_open();


    put_borrow(bfp,bhead);
    put_return(rfp,rhead);





    //初始化reader模块
    FILE *fp1=name_open();

    int readers_number= Readers_number(fp1);//获得读者数量

    Reader readers[readers_number];//创建读者容器

    put_reader(readers_number,fp1,readers);//将读者信息放入容器

    //初始化book模块

    FILE *fp2=file_open();//打开书本文件

    int books_number=Books_number(fp2);//计算图书数量

    Book books[books_number];//创建图书容器

    put_book(books_number,fp2,books);//将书本放入容器

    fclose(fp1);//关闭文件
    fclose(fp2);//关闭文件

// 1.展示借书记录，展示还书记录
    //    showBorrow(bhead);
    //    showReturn(rhead);



//2.借书登记，还书登记

//    register_borrow(bhead,books,books_number,readers,readers_number,bfp);
//    register_return(rhead,books,books_number,readers,readers_number,rfp);






    //释放链表内存，防止内存泄露
    close(bhead,rhead);

    fclose(bfp);
    fclose(rfp);


}

void br_Menu(){};

