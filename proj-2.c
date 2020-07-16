#include <stdio.h>
#include <string.h>
#include "threads.h"
#include "sem.h"


void Prod(int);
void Cons(int);
void block();
semQ *Full; //Consumer
semQ *Empty; //Producer


int B,Pr,C,N;  //Buffer, Producers, Consumers, Loops
int global;
int prod_id = 0; //in
int cons_id = 0; //out
int buffer[32]; //maybe this will work
int bufferInt = 0;
int buffLoop = 0;
int main(){
    int num[100];
    int test;
    int i = 0;
    int k = 0;
    thread_ID = 0;
    Full = (semQ*) malloc(sizeof(semQ));
    Empty = (semQ*) malloc(sizeof(semQ));
    scanf("%d,%d,%d,%d", &B,&Pr,&C,&N);
    while(scanf("%d", &test) != EOF){
        //printf("\n%d", test);
        num[i] = test;
        i++;
    }
    buffLoop = B;
    //bufferInt = B;
    struct q runQ;
    InitQueue(&runQ);
    
    //Empty.head = malloc(sizeof(semQ));
    InitSem(Full, 0);
    
    InitSem(Empty, buffLoop);
    

    //scanf("%d,%d,%d,%d",&B,&Pr,&C,&N);
    
    global = N;
    //start_thread(block);
    //Everything working up to this point....
    while(k <= i){
        if(num[k] < 0 ){
           // Cons();
           if(cons_id < C){
            cons_id++;
            thread_ID = cons_id;
            start_thread(Cons);
           }
            k++;
            
        }
        else 
        {
            //Prod();
            if(prod_id < Pr){
            
            prod_id++; 
            thread_ID = prod_id;           
            start_thread(Prod);
            
           }
          k++;
           
        }
        
        
    }
    run();   
}


void Prod(int thread_ID){
    if(bufferInt < buffLoop){
        int x = 1;
    
        while(x<= global){    
        P(Empty);
        buffer[bufferInt] = thread_ID;
        bufferInt++;           
        //printf("\n%d is this real?", global);    
        printf("\nthis is the %d producer\n", thread_ID);     
        //printf("\n%d", runQ.number);
        //printf("\n%d stopped. \n", runQ.number);
        V(Full);
        x++; 
        }
        
     }    
   yield();
}


void Cons(int thread_ID){
    int y = 1;
    while(y<=global){
        P(Full);
        printf("\nThis is the %d consumer\n", thread_ID);       
        V(Empty);       
    }
    
    //yield();
}

void block(){
    yield();
}
