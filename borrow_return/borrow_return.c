#include "stdio.h"
#include "borrow_return.h"
#include "malloc.h"

void Main_br_mana(){
    Borrow *bhead=NULL;
    Return *rhead=NULL;
    bhead=(Borrow *)malloc(sizeof(Borrow));
    rhead= (Borrow *)malloc(sizeof (Return));

    Borrow *bp= NULL;
    Return *rp= NULL;

    FILE *bfp= b_file_open();
    FILE *rfp= r_file_open();


    bp=bhead;
    rp=rhead;
    put_borrow(bfp,bp);
    put_return(rfp,rp);

    showBorrow(bhead);
    showReturn(rhead);

}

void br_Menu(){};

