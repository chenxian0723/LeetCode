class LRUCache{
public:
    
    list<pair<int,int>> cache;
    unordered_map<int,list<pair<int,int>>::iterator> adr;
    int size;
    
    LRUCache(int capacity) {
        size=capacity;
    }
    
    int get(int key) {
        unordered_map<int,list<pair<int,int>>::iterator>::iterator mit=adr.find(key);
        if(mit!=adr.end()){
            list<pair<int,int>>::iterator lci=adr[key];
            int value=(*lci).second;
            cache.erase(lci);
            cache.push_back(make_pair(key,value));
            adr[key]=--cache.end();
            return value;
        }
        else
            return -1;
    }
    
    void set(int key, int value) {
        unordered_map<int,list<pair<int,int>>::iterator>::iterator mit=adr.find(key);
        if(mit!=adr.end()){
            cache.erase(adr[key]);
        }
        else{
            int num=cache.size();
            if(num==size){
                adr.erase(cache.front().first);
                cache.erase(cache.begin());
            }
        }
        cache.push_back(make_pair(key,value));
        adr[key]=--cache.end();
    }
};
