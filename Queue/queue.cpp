#include "queue.h"


Queue::Queue()
{
    head_ = nullptr;
    tail_ = nullptr;
}

void Queue::enqueue(int ID, int arrTime, int serTime, int currTime)
{
  if(head_ == nullptr)
  {
    head_ = new Node(ID, arrTime, serTime);
    head_->SetDequeueTime(currTime + serTime);
    tail_ = head_;
  }
  else
  {
    tail_->SetNext(new Node(ID, arrTime, serTime, tail_));
    tail_ = tail_->GetNext();
  }
}

void Queue::dequeue(int currTime)
{
  Node *temp = head_;
  while(temp != nullptr)
  {
    //calls GetDequeueTime function and assigns a dequeue time
    int head_dqTime = temp->GetDequeueTime();//GetDequeueTime == current time + service time. so each customer gets removed after their service time
    if(head_dqTime <= currTime)//only if dequeue time is less than current time
    {
      //wait time is not including service time
      std::cout<<"Customer "<<temp->GetID()<<" left at Time: "<<currTime<<" time spent waiting in queue: "<<(currTime - temp->GetArrivalTime() - temp->GetServiceTime())<< std::endl;
      temp = temp->GetNext();//gets the next customer
      head_ = temp;//makes next customer the new head
      if(head_ != nullptr)//only if head is not equal to nullptr
      {
        std::cout<<"Customer "<<temp->GetID()<<" became first in line at "<<currTime<<std::endl;
        head_->SetDequeueTime(currTime + head_->GetServiceTime());//sets dequeue time for next customer
      }
    }
    else
    {
        break;
    }
  }
}

void Queue::printQueue()
{
  Node *temp = head_;
  while(temp)
    {
      std::cout<<temp->GetID()<<"-->";
      temp = temp->GetNext();
    }
  std::cout<<std::endl;
}


int Queue::GetQueueSize()
{
    Node *temp = head_;
    int queueSize = 0;
    while(temp != nullptr)
    {
        queueSize = queueSize + 1;//increments queue size at the beginning of each loop
        temp = temp->GetNext();
    }
    //std::cout<<"Queue line number: "<<GetQueueNumber()<<" queueSize: "<<queueSize<< std::endl;
    return queueSize;
}

//functions to get and set queue line number
int Queue::GetQueueNumber()
{
    return queueNumber;
}

void Queue::SetQueueNumber(int qNum)
{
    queueNumber = qNum;
}

/*Node* Queue::peek()
{
  if(head_)
  {
    return head_;
  }
  std::cout<<"Queue is empty!"<<std::endl;
  return nullptr;
}*/
