class Solution {
    int next(int n){
        int totalsum = 0;
        while(n>0){
            int d = n%10;
            n = n/10;
            totalsum += d*d;
        }
        return totalsum;
    }
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = next(n);
        while(fast!= 1 && slow!= fast){
            slow = next(slow);
            fast = next(next(fast));
        }
        return fast == 1;
    }
};
