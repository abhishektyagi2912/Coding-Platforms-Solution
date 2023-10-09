class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int sum = numBottles;
        while(numBottles>= numExchange){
            int quo = numBottles/numExchange;
            int rem = numBottles%numExchange;
            numBottles = quo+rem;
            sum+=quo;
        }
        return sum;
    }
};
