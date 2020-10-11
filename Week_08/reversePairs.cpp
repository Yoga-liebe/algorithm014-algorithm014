class Solution {
public:
    int mergeSort(vector<int>& nums,int left, int right){
        if(left >= right)return 0;
        int mid = 1 + (right - left)/2;       
        int count = mergeSort(nums,left,mid) + mergeSort(nums,mid + 1,right);
        //merge
        //vector<int> cache;
        //int cache[right - left + 1] = {0};
        int cacheLen = right - left + 1;
        int *cache = new int[cacheLen] ();
        int i = left, t = left;
        int c = 0;
        for(int j = mid + 1; j <= right; j++,c++){
            while(i <= mid && nums[i] <= 2*(long)nums[j]) i++;
            while(t <= mid && nums[t] < nums[j]) cache[c++] = nums[t++];// cache.push_back(nums[t++]);
            //cache.push_back(nums[j]);
            cache[c] = nums[j];
            count += mid - i + 1;
        }
        while(t <= mid) cache[c++] = nums[t++];//cache.push_back(nums[t++]);
        for(int p = 0; p < cacheLen;p++){
            nums[left+p] = cache[p];
        }
        delete[] cache;
        return count;
    }
    int reversePairs(vector<int>& nums) {
        if(nums.empty())return 0;
        return mergeSort(nums,0,nums.size() - 1);
    }
};
