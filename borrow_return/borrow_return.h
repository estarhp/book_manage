

#ifndef UNTITLED_BORROW_RETURN_H
#define UNTITLED_BORROW_RETURN_H
#define Max_Borrow 3

typedef struct br {

    char name[12];
    char id[15];
    char sex[3];
    char borrow_books_name [Max_Borrow][Max_Borrow];
    char borrow_books_id [Max_Borrow][Max_Borrow];
    char borrow_books_writer [Max_Borrow][Max_Borrow];
    short borrow_number;
    short all_borrow_number;

} Borrow;

typedef struct re {

    char name[12];
    char id[15];
    char sex[3];
    char return_books_name [Max_Borrow][Max_Borrow];
    char return_books_id [Max_Borrow][Max_Borrow];
    char return_books_writer [Max_Borrow][Max_Borrow];
    short borrow_number;
    short all_borrow_number;

} Return;
void Main_br_mana();
void br_Menu();

#endif //UNTITLED_BORROW_RETURN_H
