class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> mp;
        int k =0;
        for(int i =0;i<nums.size();i++){
            mp[nums[i]]++;  
        }

        for(auto& i :mp){
            //change in main array first and second point 
            if(i.second>=2){
                nums[k++]=i.first;
                nums[k++]=i.first;
            }
            else if(i.second== 1){
                nums[k++] = i.first;
            }
        }
        return k;

    }
};
