struct cacheNode{
    int _key, _value;
    cacheNode* _pre,*_next;
    cacheNode(int key = 0,int value = 0):_key(key),_value(value),_pre(nullptr),_next(nullptr){}
};
class LRUCache {
private:
    const int m_capacity;
    cacheNode *m_listHead, *m_listTail;
    unordered_map<int,cacheNode*> m_map;
    void moveToHead(cacheNode* node){
        if(m_listHead == node)return;
        //从原来的位置去掉node
        if(node->_next)node->_next->_pre = node->_pre;
        if(node->_pre)node->_pre->_next = node->_next;
        //把node放到头部
        addToHead(node);
    }
    void addToHead(cacheNode* node){
        node->_pre = m_listHead->_pre;
        m_listHead->_pre = node;
        node->_next = m_listHead;
        m_listHead = node;
    }
public:
    LRUCache(int capacity):m_capacity(capacity){
        m_listTail = new cacheNode();
        m_listHead = m_listTail;
    }
    ~LRUCache(){
        while(nullptr != m_listHead){
            cacheNode* temp = m_listHead->_next;
            delete m_listHead;
            m_listHead = temp;
        }
    }
    
    int get(int key) {
        if(m_map.end() == m_map.find(key))return -1;
        cacheNode* node = m_map[key];
        //移动node至头部
        moveToHead(node);
        return node->_value;
    }
    
    void put(int key, int value) {
        if(m_map.end() != m_map.find(key)){
            m_map[key]->_value = value;
            moveToHead(m_map[key]);  
            return;
        }
        
        if(m_map.size() >= m_capacity){
            m_map.erase(m_listTail->_pre->_key);
            //cacheNode* temp = m_listTail->_pre;
            if(m_listTail->_pre->_pre)m_listTail->_pre->_pre->_next = m_listTail;
            m_listTail->_pre = m_listTail->_pre->_pre;
            //delete temp;
        }
        cacheNode* node = new cacheNode(key,value);
        addToHead(node);
        m_map[key] = node;    
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
