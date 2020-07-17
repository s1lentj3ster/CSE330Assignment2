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
    //int k = 0;
    thread_ID = 0;
    struct q runQ;
    //Full = (Se*) malloc(sizeof(semQ));
    //Empty = (semQ*) malloc(sizeof(semQ));

    //-----------------------------//
    // Taking in Input and parsing //
    //-----------------------------//

    scanf("%d,%d,%d,%d", &B,&Pr,&C,&N);
    while(scanf("%d", &test) != EOF){
        num[i] = test;
        i++;
        //printf("\n%d\n",i);
    }
    printf("%d\n", num[0]);
    printf("%d\n", num[1]);
    printf("%d\n", num[2]);
    printf("%d\n", num[3]);
    global = (int)(N);
    buffLoop = (int)(B);
    //printf(B);
    
    ConsInt = (int)(C);
    ProdInt = (int)(Pr);
    //------------------------------//
    //     Creating Buffer Array    //
    //------------------------------//
   // int buffer[B];
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
    //start_thread(Prod);
    
   // start_thread(Cons);
    //start_thread(block);
    //Everything working up to this point....
    //start_thread(yield);
   /* while(k <= i){
        
        if(num[k] < 0 ){
           // Cons();
           if(cons_id < (int)(C)){
            cons_id++;
            thread_ID = cons_id;
            //while(&Full.value == 0);;
            start_thread(Cons);
           }
             k++;
           }
           
            
        
        else 
        {
            //Prod();
            if(prod_id < (int)(Pr)){            
            prod_id++; 
            thread_ID = prod_id;
            //while(&Empty.value == 0);;
            start_thread(Prod);            
            }
            k++;
        }
         
           
        
        
        
    }*/

       
    run();


}
void Prod(int thread_ID){
        int x = 0; 
       // flag[0]=1; 
        //while((bufferInt != 1));; 
        //while(x < ProdInt){ 
          // while(flag[1]==1){
            //flag[0] = 0;
            //sleep(1);
            //flag[0] = 1;
          // }

           //Critical Section//

           // P(Empty);            
            buffer[bufferInt] = thread_ID;
            bufferInt = (bufferInt + 1) % B;
            
            //printf("Buffer location %d", bufferInt);
           // printf("\nthis is the %d producer\n", thread_ID);
           // V(Full);
            x++;  
            //End Critical Section//
            //flag[0] = 0;         
                        
        //}
        yield();
        
     //return;    
   
}


void Cons(int thread_ID){
    int y = 0;
    //while((bufferInt != 0));;
    //flag[1] = 1;
    //while(y < ConsInt){ 
      //  while(flag[0] == 1){
        //    flag[1]=0;
            //sleep(1);
          //  flag[1] = 1;
       // }    

        //Critical Section//

        //P(Full);
        buffer[bufferInt] = 0;       
        bufferInt = (bufferInt + 1) % B;
        printf("\nThis is the Consumer %d\n", thread_ID);     
        //V(Empty); 
        y++;   

        //End Critical Section//
        flag[1] = 0;  
        yield(); 
    //}
    return;
}

