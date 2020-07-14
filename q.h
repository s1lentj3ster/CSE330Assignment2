//Name: Brian Moore
//Class: CSE330 Summer 2020
//Assignment: Project 1
#ifndef Q_H
#define Q_H

#include <stdlib.h>
#include <unistd.h>
#include "TCB.h"

struct q{
    struct TCB_t *head; //First Element
    int number; //payload
};

//struct TCB_t* newItem();
//void InitQueue(struct TCB_t*);
//void AddQueue(struct TCB_t*, struct TCB_t*);
//struct TCB_t* delQueue(struct TCB_t);
//void rotateQueue(struct TCB_t*);

struct q* runQ;

int global_thread = 1;

void InitQueue(struct q *tcb){
	//Initial Queue object, set to NULL
    tcb->head = NULL;
    //tcb->number = 1;
    return;
}

struct TCB_t* newItem(){
    struct TCB_t *item = (struct TCB_t*) malloc(sizeof(struct TCB_t)); //allocate new queue. 


    //New Item, initialized to NULL for both next and prev
    item->next = NULL;
    item->prev = NULL;
     
    return item; //Returns the new item 

}

void AddQueue(struct q *tcb, struct TCB_t *item){
	
	//Checks if head is empty, only object in queue. Sets accordingly
    if(tcb->head == NULL)
        {
           tcb->head = item; 
           item->next = NULL;
           item->prev = NULL;
           
           
        }

    else
    {		//Checks if only 1 object in queue, if so, then add to next as circular linked list. 
         if(tcb->head->next == NULL)
            {
                tcb->head->next = item;
                tcb->head->prev = item;
                item->next = tcb->head;
                item->prev = tcb->head;
                
            }
            else
            {	//If multiple items, links to the head and links the head to it, effectively putting it at the "End" of the queue.
                item->next = tcb->head;
                item->prev = tcb->head->prev;
                tcb->head->prev->next = item;
                tcb->head->prev = item;
                
            }
    }
    
}

struct TCB_t* delQueue(struct q *tcb){
    
	struct TCB_t *item = tcb->head;
   
	//Checking if item is first item of queue
    if(tcb->head !=NULL)
    {	//Checking if only 1 item in queue
        if(tcb->head->next == NULL)
        {
            return item; //Only 1 item, item is returned
        }
        else
        {	//If not, then we reset the linking to remove the item from queue and then return at the bottom. 
            tcb->head->prev->next = tcb->head->next; //Setting the next link in the prev item to the next link on the head
            tcb->head->next->prev = tcb->head->prev; //setting the previous link in the next item to the prev link on the head
            tcb->head = tcb->head->next; //Setting head to point to the next item. 
            

        }
    }
    
    return item;    

}

void rotateQueue(struct q *tcb){

    AddQueue(tcb, delQueue(tcb));
    //better way to do this? Pulled from Project Doc.
}

#endif
