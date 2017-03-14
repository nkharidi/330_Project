#include "stack.h"

stack::stack()

{
    head_ = nullptr;

}

void stack::Push(int data){
    if(!head_){
        head_ = new Node(data);

    }else{

        Node *newNode = new Node(data);
        newNode-> SetNext(head_ );
        head_ = newNode;
    }
}

Node* stack::Pop(){
    if(head_){
        Node *temp = head_;
        head_ = head_->GetNext();
        return temp;
    }
    std::cout<<"stack is empty!"<<std::endl;
    return nullptr;
}

void stack::printStack(){
    Node *temp = head_;
    while(temp){
        std::cout<<temp->GetData()<<" ";
        temp = temp->GetNext();
    }
    std::cout<<std::endl;
}

Node* stack::peek(){
    if(head_){
        return head_;
    }
    std::cout<<"stack is empty!"<<std::endl;
    return nullptr;
}


