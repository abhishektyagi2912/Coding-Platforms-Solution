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
    // reverse the node
    ListNode *reverse(ListNode *head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* forward = NULL;

        while(curr != NULL){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    //insert at tail create a node and return ans to that
    void insert(ListNode *&head, ListNode* &tail, int val){
        ListNode *temp = new ListNode(val);
        //empty list
        if(head == NULL){
            head = temp;
            tail = temp;
            return;
        }
        else{
            // jo bhi last h vo tail
            tail->next = temp;
            tail = temp;
        }
    }
    ListNode *add(ListNode* l1, ListNode* l2){
        int carry = 0;

        ListNode* anshead = 0;
        ListNode* anstail = 0;

        while(l1 != NULL || l2 != NULL || carry !=0){
            int val1 = 0;
            if(l1 != 0){
                val1 = l1->val;
            }
            // mtlb jb tk list end na ho jaye
            int val2 = 0;
            if(l2 != 0){
                val2 = l2->val;
            }

            int sum = carry + val1 + val2;
            //for last digit
            int digit = sum%10;
            // last digit make node and insert it
            insert(anshead, anstail , digit);

            carry = sum/10;
            // this is for increament for while loop
            if(l1 != NULL){
                l1 = l1->next;
            }
            if(l2 != NULL){
                l2 = l2->next;
            }

        }
        return anshead;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //reverse 
        l1 = reverse(l1);
        l2 = reverse(l2);

        // ans calculate
        ListNode *ans = add(l1,l2);

        ans = reverse(ans);

        return ans;
    }
};
