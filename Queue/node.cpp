#include "node.h"

Node::Node(){
    ID_ = 0;
    arrivalTime = 0;
    serviceTime = 0;
    next_ = nullptr;
    prev_ = nullptr;
}

Node::Node(int ID,int arrTime, int serTime ){
    ID_ = ID;
    arrivalTime = arrTime;
    serviceTime = serTime;
    next_ = nullptr;
    prev_ = nullptr;
}
Node::Node(int ID,int arrTime, int serTime , Node *prev){
    ID_ = ID;
    arrivalTime = arrTime;
    serviceTime = serTime;
    next_ = nullptr;
    prev_ = prev;
}

int Node::GetID(){
    return ID_;
}

int Node::GetArrivalTime(){
    return arrivalTime;
}
int Node::GetServiceTime(){
    return serviceTime;
}

int Node::GetDequeueTime(){
    return dequeueTime;
}

Node* Node::GetNext(){
    return next_;
}

Node* Node::GetPrev(){
    return prev_;
}

void Node::SetID(int ID){
    ID_ = ID;
}
void Node::SetArrivalTime(int arrTime){
    arrivalTime = arrTime;
}
void Node::SetServiceTime(int serTime){
    serviceTime = serTime;
}
void Node::SetDequeueTime(int dqTime){
    dequeueTime = dqTime;
}
void Node::SetNext(Node *next){
    next_ = next;
}

void Node::SetPrev(Node *prev){
    prev_ = prev;
}
