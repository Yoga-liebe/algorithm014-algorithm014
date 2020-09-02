class Solution {
public:
    void helper(vector<vector<char>>& grid,int i ,int j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || '0' == grid[i][j]){
            return;
        }
        grid[i][j] = '0';
        helper(grid,i - 1,j);
        helper(grid,i + 1,j);
        helper(grid,i,j - 1);
        helper(grid,i,j + 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())return 0;
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(grid[i][j] == '1'){
                    helper(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};
//时间复杂度：O(n*n*偶尔触发递归的复杂度) “偶尔触发helper递归的复杂度”这个不会算
//空间复杂度：额外的空间是，偶尔触发的递归函数栈，栈是o(n)