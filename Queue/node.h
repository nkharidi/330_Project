#ifndef NODE_H
#define NODE_H


class Node
{
public:
    Node();
    Node(int ID, int arrTime, int serTime);
    Node(int ID, int arrTime, int serTime, Node *prev);

    int GetID();
    int GetServiceTime();
    int GetArrivalTime();
    int GetDequeueTime();

    Node *GetNext();
    Node *GetPrev();

    void SetID(int ID);
    void SetServiceTime(int serTime);
    void SetArrivalTime(int arrTime);
    void SetDequeueTime(int dqTime);
    void SetNext(Node *next);
    void SetPrev(Node *prev);
private:
    int ID_;
    int arrivalTime;
    int serviceTime;
    int dequeueTime;
    Node *next_;
    Node *prev_;
};

#endif // NODE_H
