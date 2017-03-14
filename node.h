#ifndef NODE_H
#define NODE_H


class Node
{
public:
    Node();
    Node(int data);


    int GetData();
    Node *GetNext();
    Node *GetPrev();

    void SetData(int data);
    void SetNext(Node *next);
    void SetPrev(Node *prev);
private:
    int *data_;
    Node *next_;

};

#endif // NODE_H
