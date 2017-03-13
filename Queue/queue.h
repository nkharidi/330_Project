#ifndef QUEUE_H
#define QUEUE_H


#include "node.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>

class Queue
{
public:
    Queue();

    void enqueue(int ID, int arrTime, int serTime, int currTime);
    void dequeue(int currTime);
    void printQueue();
    int GetQueueSize();
    int GetQueueNumber();
    void SetQueueNumber(int qNum);



    Node* peek();
private:
    int queueNumber = 0;
    Node *head_;
    Node *tail_;
};

#endif // QUEUE_H
