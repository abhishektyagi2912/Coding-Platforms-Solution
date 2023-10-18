class Solution {
public:
    long long gethour(vector<int>& piles, long long hr){
        long long total = 0;
        for(int i =0;i<piles.size(); i++){
            total+= ceil((double)piles[i]/(double)hr);
        }
        // cout<<total<<endl;
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long s = 1;
        long long e = *max_element(piles.begin(),piles.end());

        while(s<=e){
            int mid = s + (e-s)/2;

            long long hour = gethour(piles,mid);

            if(hour<=h){
                e= mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return s;
    }
};
