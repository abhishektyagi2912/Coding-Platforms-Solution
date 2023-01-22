/************************************************************

    Following is the linked list node structure.
    
    class Node 
    {
        public:
        int data;
        Node* next;

        Node(int data) 
        {
            this->data = data;
            this->next = NULL;
        }
    };
    
************************************************************/

Node * uniqueSortedList(Node * head) {
    // Write your code here.
     if(head == NULL) return head;

        Node* curr = head;
        while(curr!= NULL && curr->next!=NULL){
            if(curr->data == curr->next->data){
                Node* forward = curr->next; 
                curr->next = curr->next->next;
                delete forward;
            }
            else curr = curr->next;
        }
    return head;
}
