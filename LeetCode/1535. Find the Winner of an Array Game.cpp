class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int maxelem=0;
        for(int i =0;i<arr.size();i++){
            maxelem = max(maxelem,arr[i]);
        }
        // cout<<maxelem;
        // if(arr[0]==maxelem) return arr[0];

        int curr = arr[0];
        int win =0;
        for(int i =1;i<arr.size();i++){
            int a= arr[i];
            if(curr>a) win++;
            else{
                curr = a;
                win = 1;
            }

            if(win == k || curr == maxelem) return curr;
        }
        return -1;
    }
};
