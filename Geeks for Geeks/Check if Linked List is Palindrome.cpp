#include <vector>

class Solution{
    bool check(vector<int> a){
        int n = a.size();
        int s = 0;
        int e = n-1;
        
        while(s<=e){
            if(a[s] != a[e]){
                return 0;
            }
            e--;
            s++;
        }
        return 1;
    }
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        vector<int> ans;
        if(head->next == NULL){
            return true;
        }
        Node *temp =head;
        while(temp!=NULL){
            ans.push_back(temp->data);
            temp = temp->next;
        }
        return check(ans);
    }
};
