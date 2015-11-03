class LRUCache{
public:
    LRUCache(int capacity):_capacity(capacity) {}
    
    int get(int key) {
        if (index.find(key) == index.end()) return -1;
        else {
            auto iter = index.find(key);
            int val = (*(iter->second)).second;
            li.push_front({key, val});
            li.erase(iter->second);
            iter->second = li.begin();
            return val;
        }
    }
    
    void set(int key, int value) {
        if (index.find(key) == index.end()) {
            if (index.size() == _capacity) {
                auto iter = li.back();
                index.erase(index.find(iter.first));
                li.pop_back();
            }
            
            li.push_front({key, value});
            index[key] = li.begin();
            
        } else {
            get(key);
            li.front().second = value;
        }
    }
    
private:
    int _capacity;
    unordered_map<int, list<pair<int, int>>::iterator> index;
    list<pair<int, int>> li;
};