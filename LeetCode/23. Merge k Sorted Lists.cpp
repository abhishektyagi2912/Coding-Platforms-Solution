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
class compare{
    public:
    int operator()(ListNode*a, ListNode* b){
        return a->val>b->val;
    }

};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare> h;
        int k = lists.size();
        if(k==0){
            return NULL;
        }

        for(int i =0;i<k;i++){
            if(lists[i]!=NULL){
                h.push(lists[i]);
            }
        }

        ListNode* head=NULL;
        ListNode* tail =NULL;

        while(h.size()>0){
            ListNode* temp = h.top();
            h.pop();

            if(head == NULL){
                head = temp;
                tail = temp;
                if(head->next!=NULL){
                    h.push(head->next);
                }
            }
            else{
                tail->next = temp;
                tail = temp;
                if(tail->next != NULL){
                    h.push(tail->next);
                }
            }
        }
        return head;
    }
};
