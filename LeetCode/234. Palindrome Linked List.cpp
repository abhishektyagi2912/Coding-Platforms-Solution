/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    //step1
    ListNode *middle(ListNode *head){
        ListNode *fast = head->next;
        ListNode *slow = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode *reverse(ListNode *head){
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *forward = NULL;

        while(curr != NULL){
            forward = curr->next;
            curr->next = NULL;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        // head =  nuLl nhi hoga constraint given
        if(head->next == NULL){
            return true;
        }

        ListNode* mid = middle(head);
        // mid mil gya 
        //revrese krna
        ListNode *temp = mid->next;
        mid->next = reverse(temp);

        // compare head so we make two head for this
        ListNode *head1 = head;
        ListNode *head2 = mid->next;
        while(head2!=NULL){
            if(head1->val != head2->val){
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        // rverese ko shi krna h
        temp = mid->next;
        mid->next = reverse(temp);
        return true;

    }
};
