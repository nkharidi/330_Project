#include "queue.h"
#include <time.h>
#include <stdlib.h>

//constant variables to make changing values easier
const int MAX_STORE_OPEN_TIME = 720;
const int MAX_LINES = 3;

int main()
{

    srand(time(0));

    int arrivalTime = 0;
    int currentTime = 0;
    int customerID = 0;
    //int lineNumber = 0;

    //declaration of array of queues
    Queue *lines = new Queue[MAX_LINES]();

    //for loop to assign line numbers to each queue
    for(int i=0; i<MAX_LINES; i++)
    {
        lines[i].SetQueueNumber(i);//i is line number parameter
    }


    //while loop to step through each minute in the 12 hour day
    while(currentTime <= MAX_STORE_OPEN_TIME)
    {

    currentTime++;
    std::cout<<"                    CURRENT TIME: "<<currentTime<<std::endl;


      //initial if statement for first case of customer arriving
      if(arrivalTime == 0)
      {
        arrivalTime = currentTime + rand()%4+1;
      }

      //second if statement for all other cases
      if(arrivalTime == currentTime)
      {
          customerID++;
          int serviceTime = rand()%4+1;//sets random service time
          std::cout<<"Customer: "<<customerID<< " arrived at minute: "<<currentTime<<" With service time of: "<<serviceTime<<std::endl;

          //variables to find queue with least amount of customers
          int smallestQueueSize;
          smallestQueueSize = lines[0].GetQueueSize();//initailizes first queue to be shortest queue
          int smallestLineNumber = 0;

          for(int i=0; i<MAX_LINES; i++)
          {
              if(lines[i].GetQueueSize() < smallestQueueSize)//compares each queue with first queue
              {
                  smallestQueueSize = lines[i].GetQueueSize();//only reassigns if a queue is smaller than the first queue
                  smallestLineNumber = i;//assigns line number

              }
          }
          std::cout<<"the shortest line is: "<<smallestLineNumber+1<<std::endl;
          std::cout<<"Enqueueing to shortest Line Number: "<<smallestLineNumber+1<<std::endl;

          //calls enqueue function to add customers to correct line,taking a customer ID, arrival time and current time as parameters
          lines[smallestLineNumber].enqueue(customerID, arrivalTime, serviceTime, currentTime);

          //for loop to print each queue in the queue array
          for(int i=0; i<MAX_LINES; i++)
          {
              std::cout<<"Line number:"<<i+1<<" ";
              lines[i].printQueue();
          }

          arrivalTime = currentTime + rand()%4+1;//accumulates arrival times
       }

    //for loop to go through each array index and dequeue from each queue
    for(int i=0; i<MAX_LINES; i++)
    {
        lines[i].dequeue(currentTime);
    }


} //end of while loop


} //end of main

