#include <stdio.h>
#include <string.h>
#include "threads.h"
#include "sem.h"

//Declaration of Functions//
void Prod(int);
void Cons(int);


//Declaration of Semaphore Queues//
struct Semaphore *Full; //Consumer
struct Semaphore *Empty;//Producer


//Global Variables//
int B,Pr,C,N;  //Buffer, Producers, Consumers, Loops
int global;
int prod_id = 0; //in
int cons_id = 0; //out
int bufferInt = 0;
int buffLoop = 0;
int buffer[32]; //maybe this will work

int ConsInt;
int ProdInt;
int flag[2] = {0,0};

//Main//
int main(){


    int num[100];
    int test;
    int i = 0;

    thread_ID = 0;
    struct q runQ;
    //-----------------------------//
    // Taking in Input and parsing //
    //-----------------------------//

    scanf("%d,%d,%d,%d", &B,&Pr,&C,&N);
    while(scanf("%d", &test) != EOF){
        num[i] = test;
        i++;
        
    }
    printf("%d\n", num[0]);
    printf("%d\n", num[1]);
    printf("%d\n", num[2]);
    printf("%d\n", num[3]);
    global = (int)(N);
    buffLoop = (int)(B);
    
    
    ConsInt = (int)(C);
    ProdInt = (int)(Pr);
    //------------------------------//
    //     Creating Buffer Array    //
    //------------------------------//
   
    buffer[32] = buffer[B];
    for(int r = 0; r< B; r++){
        buffer[r] = 0;
    //instantiate buffer
    }
    
     
    //runQ = (struct q*)malloc(sizeof(struct q));
    Full = (struct Semaphore*)malloc(sizeof(struct Semaphore));
    Empty = (struct Semaphore*)malloc(sizeof(struct Semaphore));
    InitQueue(&runQ);
    InitSem(Full, 0);
    InitSem(Empty, (int)(B));

    printf("%d", Empty->value);
    
    //printf("%d", i);
    
    start_thread(Prod);
    start_thread(Prod);
       
    run();


}
void Prod(int thread_ID){
        int x = 0;  
        buffer[bufferInt] = thread_ID;
        bufferInt = (bufferInt + 1) % B;
        x++;  
         //End Critical Section//
        yield();  
}


void Cons(int thread_ID){
    int y = 0;
    //Critical Section//

        
     buffer[bufferInt] = 0;       
    bufferInt = (bufferInt + 1) % B;
    printf("\nThis is the Consumer %d\n", thread_ID);     
    y++;   

    //End Critical Section//
    flag[1] = 0;  
    yield(); 
    //}
    return;
}

