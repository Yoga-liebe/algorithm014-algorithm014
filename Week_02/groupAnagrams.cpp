class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string,vector<string>> mapRes;
        
        for(string& t:strs){
            int count[26] = {0};
            for(int i = 0;i < t.size();i++){
                count[t[i] - 'a']++;
            }
            string key = "";
            for(int i = 0;i < 26;i++){
                key += to_string(count[i]);
            }
            mapRes[key].push_back(t);
        }
        for(auto& m:mapRes)
        {
            res.push_back(m.second);
        }
        return res;
    }
};