//Name: Brian Moore
//Class: CSE330 Summer 2020
//Assignment: Project 1
#include <stdio.h>
#include <string.h>
#include "threads.h"

//Global Variables to be used in main and other functions
int thread;
int loopNum;
int iteration;
int global = 0;
int threadCount = 1;
void runFunction(int);


int main()
{
	//Instantiate new queue
    struct q runQ;
    InitQueue(&runQ);
    iteration = 1;
    
    thread_ID = 0; 
    scanf("%d, %d", &thread, &loopNum); //Grabs input from file and sets variables
   
    //Checking for no threads inputed and prints accordingly
    if(thread == 0)
        {
            printf("No Threads");
        }
   
    
    else
    {	//Loops through number of loops as indidcated, updates thread ID and queues with start_thread.
        while(iteration < thread + 1)
        {
        
            thread_ID++;
            start_thread(runFunction);
            iteration++;
                  
        }
    
     
   
       
    }

    run();
}

void runFunction(int thread_ID){
    int x = 1;
   
    while(x<=loopNum){
        
    global = global + thread_ID; //Adding to global by thread ID.
    printf("\nThis is %d th execution of thread %d with global var value %d\n", x, thread_ID, global);
	
	// Below are tests for my own sanity. Commented out. 	
	//--------------------------------------------------
    //global = global + thread_ID;   
    //printf("%d\n", runQ.number);
    //printf("testing\n");
    //printf("%d\n", x);
      
    yield();    
    x++;
    //threadCount++;
   }
 
}
