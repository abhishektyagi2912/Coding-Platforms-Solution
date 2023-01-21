#include <bits/stdc++.h> 
/****************************************************************
    Following is the Linked List node structure

    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/


Node* kReverse(Node* head, int k) {
    // Write your code here.
    if(head==NULL ){
        return NULL;
    }
    Node* prev = NULL;
    Node *next = NULL;
    Node *curr = head;
    int cnt =0;
    while(curr != NULL && cnt < k ){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }

    if(next != NULL){
        head ->next = kReverse(next,k); //head k next m sb jod do
    }
    return prev;
}
