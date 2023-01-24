/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/
Node *findmid(Node *head){
    Node *slow = head;
    Node* fast = head->next;
    while(fast !=NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    // this is mid 
    return slow;
}

Node * merge(Node* left, Node* right){
    if(left == NULL){
        return right;
    }
    if(right == NULL){
        return left;
    }
    // empty node let assume it start at -1
    Node *ans = new Node(-1);
    Node *temp = ans;
    
    while(left != NULL && right != NULL){
        if(left->data < right->data){
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else{
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }
    //if left node is not empty or right is empty
    while(left!=NULL){
        temp->next = left;
        temp = left;
        left = left->next;
    }
    while(right != NULL){
        temp->next = right;
        temp = right;
        right = right->next;
    }
    ans = ans->next;
    return ans;
}

class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        if( head == NULL || head -> next == NULL ) {
                return head;
        }
        
        Node *mid = findmid(head);
        Node *left = head;
        Node *right = mid->next;
        mid -> next = NULL;
        
        //recursive calls to sort both halves
        left = mergeSort(left);
        right = mergeSort(right);
        
        //return final merge linked list
        Node * ans = merge(left,right);
        
        return ans;
        
    }
};
