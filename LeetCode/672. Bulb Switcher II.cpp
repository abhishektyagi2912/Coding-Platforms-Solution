class Solution {
public:
    int flipLights(int n, int p) {
        if (p == 0) return 1; 
        if (n == 1) return 2; 
        if (p == 1) return n > 2 ? 4 : 3; 
        if (n == 2) return 4; 
        return p == 2 ? 7 : 8;
    }
};
