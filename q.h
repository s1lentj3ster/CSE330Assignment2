
#include <stdlib.h>
#include <unistd.h>
#include "TCB.h"

struct q{
    struct TCB_t *head; //First Element
    int number; //payload
};




//int global_thread = 1;

void InitQueue(struct q *tcb){

    tcb->head = NULL;
   // tcb->number = 1;
    return;
}

struct TCB_t* newItem(){
    struct TCB_t *item = (struct TCB_t*) malloc(sizeof(struct TCB_t));
    item->next = NULL;
    item->prev = NULL;
         
    return item;

}

void AddQueue(struct q *tcb, struct TCB_t *item){

    if(tcb->head == NULL)
        {
           tcb->head = item; 
           item->next = NULL;
           item->prev = NULL;          
        }

    else
    {
         if(tcb->head->next == NULL)
            {
                tcb->head->next = item;
                tcb->head->prev = item;
                item->next = tcb->head;
                item->prev = tcb->head;             
            }
            else
            {
                item->next = tcb->head;
                item->prev = tcb->head->prev;
                tcb->head->prev->next = item;
                tcb->head->prev = item;               
            }
    }
    
}

// if (tcb->head != NULL //|| tcb->head->next == NULL)
        //if(tcb->head->next != NULL){
            //item->prev = tcb->head->prev;
            //tcb->head->prev->next = item;
            //tcb->head->prev = item;
        //}
        

struct TCB_t* delQueue(struct q *tcb){
    struct TCB_t *item = tcb->head;
    //first  item of queue

    if(tcb->head !=NULL)
    {
        if(tcb->head->next == NULL)
        {
            tcb->head = NULL;
        }
        else
        {
            tcb->head->prev->next = tcb->head->next;
            tcb->head->next->prev = tcb->head->prev;
            tcb->head = tcb->head->next;
            

        }
    }
    return item;

}


// if(tcb->head == NULL || tcb->head->next == NULL){
        //tcb->head->prev->next = tcb->head->next;
        //tcb->head->next->prev = tcb->head->prev;
        //tcb->head == tcb->head->next;

        //if(tcb->head->next == NULL)
            //tcb->head == NULL

        //return item;
//}
void rotateQueue(struct q *tcb){

    AddQueue(tcb, delQueue(tcb));
    //better way to do this?
}