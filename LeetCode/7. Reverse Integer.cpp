class Solution {
public:
    int reverse(int x) {
        long num = 0;
        while(x!=0){
            int r= x%10;
            x=x/10;
            num=num*10+r;
        }
        if(num<INT_MIN || num> INT_MAX){
            return 0;
        }else{
            return num;
        }
        
    }
};
