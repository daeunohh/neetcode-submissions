class HashTable {
public:
    struct Pair{
        int key;
        int value; 
    };
    vector<vector<Pair>> ht;
    int cap; int sz = 0;

    HashTable(int capacity) {
        cap = capacity;
        for(int i=0;i<cap;i++){
            ht.push_back(vector<Pair>());
        }
    }

    void insert(int key, int value) {
        if(sz + 1 >= cap / 2){
            resize();
        }
        int h = key % cap; bool isFound = false;
        for(auto& p : ht[h]){
            if(p.key == key){
                p.value = value; isFound = true;
            }
        } 
        if(!isFound){
            ht[h].push_back({key, value});
            sz++;
        }
    }

    int get(int key) {
        int h = key % cap;
        for(auto p : ht[h]){
            if(p.key == key){
                return p.value;
            }
        }
        return -1;      
    }

    bool remove(int key) {
        int h = key % cap; bool isFound = false;
        for(auto& p : ht[h]){
            if(p.key == key){
                p.key = -1; p.value = -1; isFound = true;
            }                  
        } 
        if(!isFound){
            return false;
        }
        sz--; 
        return true;
        // for(auto a : ht[h]){
        //     cout << a.key << " " << a.value << endl; 
        // } cout << endl;
        


        // if(ht[h].key == key){
        //     ht[h].key = -1;
        //     ht[h].value = -1; 
        //     sz--;
        //     return true;
        // } else{
        //     return false;
        // } 
    }

    int getSize() const {
        return sz;
    }

    int getCapacity() const {
        return cap;
    }

    void resize() {
        int newCap = cap * 2;
        vector<vector<Pair>> newHt;

        for(int i=0;i<newCap;i++){
            newHt.push_back(vector<Pair>());
        }

        // cout << newHt.size() << endl;

        for(int i=0;i<cap;i++){
            for(auto& p : ht[i]){
                newHt[p.key % newCap].push_back(p);             
            }
        }
        
        ht = newHt;
        cap = newCap;
    }
};
