/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp = node->next;

        int valu = temp->val;
        temp->val = node->val;

        node->val = valu;

        node->next= temp->next;
        temp->next = NULL;

    }
};
