class Solution {
public:
    int climbStairs(int n) {
        if (2 >= n){
            return n;
        }
        int res = 0, first = 1,second = 2;
        for(int i = 3;i <= n;i++){
            res = first + second;
            first = second;
            second = res;
        }
        return res;
    }
};