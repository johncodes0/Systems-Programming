// John Eng and Jamie Liao
#include <stdio.h>
#include "sorted-list.h"

int compare(void *x, void *y){
    int xInt = *((int *)x);
    int yInt = *((int *)y);
    
    //Can use a ternary operator here
//    return (xInt == yInt) ? 0 : ((xInt>yInt) ? 1 : -1);
    if(xInt == yInt)
        return 0;
    if(xInt > yInt)
        return 1;
    return -1;
}

void destruct(void *x){
    (void) x;
}


int main(int argc, char **argv){
    //check if at least 1 entry
    if(argv[1] == 0)
        return 0;
    //create the SortedListPtr struct + mallocs a struct
    SortedListPtr s = (SortedListPtr)(SLCreate(compare, destruct));

    int i = 1;
    void *x;
    printf("argc %d\n", argc);
    //insert all in argv into LL. Sorts as items are inserted O(n^2)
    for(; i < argc; i++){
        x = (void *)argv[i];
        printf("\nCurrently added: %s\n", argv[i]);
        SLInsert(s, x);
    }
    
    //prints out node data .. sorta. It prints out something else in memory, not exact int
    Node tmp = s->front;
    int *num;
    i = 1;
    do{
        num = (int *)(tmp->data);
        printf("Print: %d\n",*num);
        tmp = tmp->next;
        i++;
    }while(i < argc);
    
    
    
    //-------------------------------------------------------------------------------------------
    // John's Code
    
    
    SortedListIteratorPtr iter = SLCreateIterator(s);
    
    void* ptr;
    while (1) {
        ptr = SLGetItem(iter);
        if (ptr == 0) {
            break;
        } else {
            printf("%d\n",*((int*)ptr));
        }
    }
    
    //-------------------------------------------------------------------------------------------
    
    
    //removal of SL and all nodes
//    i = 1;
//    do{
//        SLRemove(s, (void *)argv[i]);
//        i++;
//        printf("\n");
//    }while(i < argc);
//    if(!s->front)
//        printf("YAY\n");
//    SLDestroy(s);
//    if(!s)
//        printf("SortedListPtr successfully deleted");
//    
//    printf("Test");
    return 0;
}