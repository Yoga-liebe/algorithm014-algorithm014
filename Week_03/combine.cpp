class Solution {
public:
    void helper(int n, int k, int start, vector<int>& single, vector<vector<int>>& res){
        if(single.size() == k){
            res.push_back(single);
            return;
        }
        for(int i=start; i<=n ;i++){
            single.push_back(i);
            helper(n, k, i+1, single, res);
            single.pop_back();
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if(k > n) return res;   
        vector<int> single;
        helper(n, k, 1, single, res);
        return res;
    }

};