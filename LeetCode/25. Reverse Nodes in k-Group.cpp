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
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head== NULL){
            return NULL;
        }
        int size=0;
        ListNode* temp=head;
        while(temp!=NULL){
            temp = temp->next;
            size++;
        }
        if(size<k){
            return head;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        int count =0;
        while(count<k && curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        if(head!=NULL){
            head->next = reverseKGroup(next,k);
        }
        return prev;
    }
};
