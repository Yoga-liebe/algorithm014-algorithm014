class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        size_t n = nums.size();
        vector<int> res;
        for(int i = 0;i < n;i++){
            for(int j = i + 1;j < n;j++){
                if(target == nums[i] + nums[j]){
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
            
        }
        return res;
    }
};
