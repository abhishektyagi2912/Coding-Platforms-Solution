class Solution
{
    Node *insertattail(Node* &head,Node* &tail,int d){
        Node* newnode = new Node(d);
        if(head == NULL){
            head = newnode;
            tail = newnode;
            return head;
        }
        else{
            tail->next = newnode;
            tail = newnode;
        }
    }
    public:
    Node *copyList(Node *head)
    {
        //step 1 create a clone linked list 
        Node* clonehead = NULL;
        Node* clonetail = NULL;
        
        Node* temp = head;
        while(temp != NULL){
            insertattail(clonehead,clonetail,temp->data);
            temp = temp->next;
        }
        // create a map function 
        unordered_map<Node*,Node*> oldNode;
        temp = head;
        Node* temp2 = clonehead;
        
        // create a mapping of the node
        while(temp != NULL){
            oldNode[temp] = temp2;
            temp = temp->next;
            temp2 = temp2->next;
        }
        // we want to set random pointer 
        temp = head;
        temp2 = clonehead;
        
        while(temp != NULL){
            temp2->arb = oldNode[temp->arb];
            temp2= temp2->next;
            temp = temp->next;
        }
        return clonehead;
    }

};
