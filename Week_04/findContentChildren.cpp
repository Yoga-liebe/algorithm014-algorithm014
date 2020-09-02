class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(g.empty() || s.empty())return 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i = 0;
        int j = 0;
        int res = 0;
        while(i < g.size() && j < s.size()){
            if(g[i] <= s[j]){
                res++;
                i++;
                j++;
            }else{
                j++;
            }
        }
        return res;
    }
};
//时间复杂度: O(2nlogn)+2n
//空间复杂度: 额外的是O(1)