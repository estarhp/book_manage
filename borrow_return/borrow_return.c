#include "stdio.h"
#include "windows.h"
#include "borrow_return.h"
#include "malloc.h"


void Collect_br(Borrow *bhead,Return *rhead,Book books[],int books_number,Reader readers[],int readers_number,FILE *bfp,FILE *rfp);
int wherex_br();
int wherey_br();
void gotoxy_br(int x, int y);
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


    //br_Menu();
    Collect_br(bhead,rhead,books,books_number,readers,readers_number,bfp,rfp);
        //br_Menu();
// 1.展示借书记录，展示还书记录
//        showBorrow(bhead);
//        showReturn(rhead);
//2.借书登记，还书登记

//    register_borrow(bhead,books,books_number,readers,readers_number,bfp);
//    register_return(rhead,books,books_number,readers,readers_number,rfp);
    //释放链表内存，防止内存泄露
    rbclose(bhead,rhead);

    fclose(bfp);
    fclose(rfp);


}
void Collect_br(Borrow *bhead,Return *rhead,Book books[],int books_number,Reader readers[],int readers_number,FILE *bfp,FILE *rfp){
    br_Menu();//显示数据管理的子菜单
    int Scanf;
    scanf("%d",&Scanf );
    getchar();


    //收集用户的选择


    //跳入不同模块
    while(Scanf)
    {
        switch (Scanf) {
            case 0:
                break;
            case 1:
                showBorrow(bhead);
                break;
            case 2:
                showReturn(rhead);
                break;
            case 3:
                register_borrow(bhead,books,books_number,readers,readers_number,bfp);
                break;
            case 4:
                register_return(rhead,books,books_number,readers,readers_number,rfp);
                break;
            default:
                printf("请输入正确的数字\n");
                break;

        }
        //printf("|请按任意键返回子菜单|\n");
        fflush(stdin);
        getchar();
        system("cls");
        //从控件获取字符而无需回显;
        br_Menu();
        scanf("%d", &Scanf);
        //getchar();

    }

}


int wherex_br()

    {

        CONSOLE_SCREEN_BUFFER_INFO pBuffer;

        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &pBuffer);

        return (pBuffer.dwCursorPosition.X + 1);

    }

//获取光标的位置y

int wherey_br()

    {

        CONSOLE_SCREEN_BUFFER_INFO pBuffer;

        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &pBuffer);

        return (pBuffer.dwCursorPosition.Y + 1);

    }

//设置光标的位置

void gotoxy_br(int x, int y)

    {

        COORD c;

        c.X = x - 1;

        c.Y = y - 1;

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);

    }

 void br_Menu(){

        setbuf(stdout,0);//缓冲

        int x, y;

        //int select;
        system("cls");

        gotoxy_br(24, 5);

        printf("*******欢迎来到借还管理系统*******");

        gotoxy_br(15, 8);

        printf("*********************主菜单*********************");

        gotoxy_br(15, 9);

        printf("*                  1->展示借书记录             *");

        gotoxy_br(15, 10);

        printf("*                  2->展示还书记录             *");

        gotoxy_br(15, 11);
        printf("*                  3->借书登记                 *");
        gotoxy_br(15,12);

        printf("*                  4->还书登记                 *");

        gotoxy_br(15,13);
        printf("*                  0->返回主菜单               *");
        gotoxy_br(15,14);
        printf("************************************************");

        gotoxy_br(28, 16);

        printf("请输入你的选择(数字):[ ]");

        x = wherex_br();

        y = wherey_br();

        gotoxy_br(x - 2, y);


}

