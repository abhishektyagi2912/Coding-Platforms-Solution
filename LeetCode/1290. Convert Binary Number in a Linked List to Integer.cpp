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
    int findlength(ListNode* head){
        ListNode* temp = head;
        int length = 0 ;
        while(temp != NULL){
            length++;
            temp = temp->next;
        }
        return length;
    }
public:
    int getDecimalValue(ListNode* head) {
        // first we find the length of linked list then decrease length of the LL
        ListNode* temp = head;
        int length = findlength(head)-1;
        int ans = 0;
        // second we travese a linked list and multiply by the value of the node
        while(temp != NULL){
            int value = pow(2, length) * temp->val;
            ans += value;
            temp = temp->next;
            length--;
        }
        return ans;
    }
};
