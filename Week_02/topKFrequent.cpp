class BinHeapMax {
public:
    BinHeapMax(){
        m_binHeap.clear();
        m_heapSize = 0;
    }

    pair<int,int> findMax(){
        return m_binHeap[0];
    }

    void insertVal(pair<int,int> e){
        if(m_binHeap.size() == m_heapSize){
            m_binHeap.push_back(e);
        }
        else{
            m_binHeap[m_heapSize] = e;
        }
        m_heapSize++;

        heapifyup(m_heapSize - 1);
    }

    void deleteMax(){
        if(m_heapSize <= 0)return;
        m_binHeap[0] = m_binHeap[m_heapSize - 1];
        m_heapSize--;
        heapifydown(0);
    }
private:
    void swap(int index1, int index2){
        pair<int,int> tmp = m_binHeap[index1];
        m_binHeap[index1] = m_binHeap[index2];
        m_binHeap[index2] = tmp;
    }

    void heapifyup(int index){
        int indexFather = (index - 1) / 2;
        if(index == 0)return;
        if(m_binHeap[index].second > m_binHeap[indexFather].second){
            swap(index,indexFather);
            heapifyup(indexFather);
        }
    }
    void heapifydown(int index){    
        int indexLeft = index * 2 + 1;
        int indexRight = index * 2 + 2;

        if(indexLeft > m_heapSize - 1)return;

        int leftVal = m_binHeap[indexLeft].second;
        int rightVal = (indexRight > m_heapSize - 1) ? (leftVal - 1) : m_binHeap[indexRight].second;

        int indexValMax = (leftVal >= rightVal) ? indexLeft : indexRight;

        if(m_binHeap[index].second < m_binHeap[indexValMax].second){
            swap(index,indexValMax);
            heapifydown(indexValMax);
        }
    }
private:
    vector<pair<int,int>> m_binHeap;
    int m_heapSize;
};


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mapTmp;
        for(int i = 0; i < nums.size();i++){
            mapTmp[nums[i]]++;
        }

        BinHeapMax heap;
        for(auto e : mapTmp){
            heap.insertVal(e);
        }

        vector<int> res;
        for(int i = 0; i < k;i++){
            res.push_back(heap.findMax().first);
            heap.deleteMax();
        }
        return res;
    }
};