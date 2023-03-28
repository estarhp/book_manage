#include "stdio.h"
#include "stdlib.h"
//����ͼ������
typedef struct book {
    int id;
    char name[50];
    char writer[20];
} Book;

void add_book(Book books[],int books_number,FILE *fp);

FILE * file_open();

void put_book(int number,FILE *fp,Book books[]);//��ʼ��ͼ��

int Books_number(FILE *fp);//�����ļ���ͼ�����Ŀ

void Menu_book();

void Collect(int books_number,Book *books,FILE *fp);

void delete_book();

void modify_book();

void query_book();

void show_book(int books_number,Book *books);

void Main_book_mana(){

    FILE *fp=file_open();

    int books_number=Books_number(fp);//����ͼ������

    Book books[books_number];//����ͼ������

    put_book(books_number,fp,books);//���鱾��������



    Menu_book();

    Collect(books_number,books,fp);

    fclose(fp);//�ر��ļ�





}

void show_book(int books_number,Book *books){
    for (int i = 0; i < books_number; ++i) {
        printf("%d %s %s\n",books[i].id,books[i].writer,books[i].name);
    }

}

void query_book(){
    printf("������");

}

void modify_book(){
    printf("������");

}


void delete_book(){
    printf("������");
}

void add_book(Book books[],int books_number,FILE *fp){
    Book addbook;
    printf("������Ҫ���ӵ�����");
    scanf("%s",&addbook.name);
    printf("������Ҫ����ͼ�������");
    scanf("%s",&addbook.writer);
    addbook.id=books[books_number-1].id+1;
    fprintf(fp, "%d %s %s\n", addbook.id, addbook.writer, addbook.name);



}

void Collect(int books_number,Book *books,FILE *fp){
    int Scanf;
    //�ռ��û���ѡ��
    scanf("%d",&Scanf);
    //���벻ͬģ��
    switch (Scanf) {

        case 1:add_book(books,books_number,fp);
            break;
        case 2:delete_book();
            break;
        case 3:modify_book();
            break;
        case 4:query_book();
            break;
        case 5:show_book(books_number,books);
            break;

    }
}

void Menu_book(){

    printf("\n\t##########################��ӭ����ͼ�����ϵͳ##########################\t\n"
           "\n\t                        1->����ͼ��                        \t\n"
           "\n\t                        2->ɾ��ͼ��                        \t\n"
           "\n\t                        3->�޸�ͼ��                        \t\n"
           "\n\t                        4->��ѯͼ��                        \t\n"
           "\n\t                        5->��ʾͼ��                        \t\n"
           "\n\t#######################������ѡ�����########################\t\n"
    );

}

int Books_number(FILE *fp) {

    int flag = 0, file_row = 0, count = 0;
    while (!feof(fp)) {
        flag = fgetc(fp);
        if (flag == '\n')
            count++;
    }
    file_row = count; //�������һ��

    rewind(fp);
    return file_row;
}

void put_book(int number,FILE *fp,Book books[]){


    for (int i = 0; i<number ; i++) {
        fscanf(fp,"%d %s %s",&books[i].id,&books[i].writer,&books[i].name);
    }//���ļ������鱾



}

FILE * file_open(){
    FILE *fp;
    if ((fp = fopen("../book_manage/books.txt", "a+")) == NULL){
        if ((fp = fopen("book_manage/books.txt", "a+")) == NULL){
            printf("�ļ�·��Error!\n");
        }
    }

    return fp;
}




