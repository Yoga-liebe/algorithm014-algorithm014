class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t count = 0;
        while(n != 0){
            count++;
            n = n&(n-1);
        }
        return count;
    }
};
