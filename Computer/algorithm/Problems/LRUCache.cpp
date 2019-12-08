
class LRUCache{
  private:
      struct Node{
          int key;
          int value;
          Node(int k,int v):key(k), value(v){}
      };
  public:
    LRUCache(int c):capacity(c){}
    int get(int key){
        if(cacheMap.find(key) == cacheMap.end())
            return -1;
        cacheList.splice(cacheList.begin(),cacheList.end()); // 这里应该增加 cacheMap.find(key)吧?
        chcheMap[key] = chcheList.begin();
        return cacheMap[key]->value;
    }

    void set(int key, int value){
        if(cacheMap.find(key) == cacheMap.end()){
            if(cacheList.size() == capacity){
                cacheMap.erase(cacheList.back().key);
                cacheList.pop_back();
            }
            cacheList.push_front(Node(key,value));
            cacheMap[key] = cacheList.begin();
        } else {
            cacheMap[key]->value = value;
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            cacheMap[key] = cacheList.begin();
        }
    }
  private:
    int capacity;
    list<Node> cacheList;
    unordered_map<int, list<Node>::iterator> cacheMap;
};
