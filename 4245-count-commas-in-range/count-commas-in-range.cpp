class Solution {
public:
    int countCommas(int n) {
        // return max (n-999 ,0);
        return n <1000 ? 0 : n-999;
    }
};