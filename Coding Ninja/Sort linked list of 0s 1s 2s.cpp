/********************************
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

********************************/

Node* sortList(Node *head)
{
    // Write your code here.
    int zeros = 0;
    int ones = 0;
    int twos =0;
    Node *temp = head;
    while(temp !=NULL){
        if(temp->data == 0){
            zeros++;
        }
        else if (temp->data == 1){
            ones++;
        }
        else if(temp->data == 2){
            twos++;
        }
        temp = temp->next;
    }
    // idhr hum pr sare count hai
    temp= head;
    while(temp != NULL){
        if(zeros != 0){
            temp->data = 0;
            zeros--;
        }
        else if(ones != 0){
            temp->data = 1;
            ones--;
        }
        else if(twos != 0){
            temp->data = 2;
            twos--;
        }
        temp = temp->next;
    }
    return head;
}
