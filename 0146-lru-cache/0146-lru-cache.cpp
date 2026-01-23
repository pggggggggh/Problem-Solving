class LRUCache {
private:
    int capacity;
    list<pair<int,int>> lst;
    unordered_map<int,list<pair<int,int>>::iterator> keyToIt;

public:
    LRUCache(int capacity): capacity(capacity) {}
    
    int get(int key) {
        if (keyToIt.find(key) == keyToIt.end()) return -1;
        list<pair<int,int>>::iterator it = keyToIt[key];
        pair<int,int> entry = *it;
        lst.erase(it);
        lst.push_back(entry);
        keyToIt[key] = prev(lst.end());
        return entry.second;
    }
    
    void put(int key, int value) {
        if (keyToIt.find(key) != keyToIt.end()) {
            list<pair<int,int>>::iterator it = keyToIt[key];
            lst.erase(it);
            lst.push_back({key,value});
            keyToIt[key] = prev(lst.end());
            return;
        }
        if (lst.size() == capacity) {
            int eraseKey = (*lst.begin()).first;
            keyToIt.erase(eraseKey);
            lst.erase(lst.begin());
        }
        lst.push_back({key,value});
        keyToIt[key] = prev(lst.end());
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */