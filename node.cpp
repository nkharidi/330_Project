#include "node.h"

Node::Node()
{
    data_ = nullptr;
    next_ = nullptr;

}

Node::Node(int data){
    data_ = new int(data);
    next_ = nullptr;

}



int Node::GetData(){
    return *data_;
}

Node* Node::GetNext(){
    return next_;
}



void Node::SetData(int data){
    *data_ = data;
}

void Node::SetNext(Node *next){
    next_ = next;
}



