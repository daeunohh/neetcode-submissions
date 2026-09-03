// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;

//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    size_t length;
    void sort(vector<Pair>& pairs, int idx1, int idx2, size_t len){
        cout << "a" << idx1 << " " << idx2 << " " << len << endl;
        if(idx1 < 0 || idx2 >= length) return;
        if(len <= 1) return;

        int mid = (idx1 + idx2) / 2;
        
        sort(pairs, idx1, mid, mid - idx1 + 1);
        sort(pairs, mid + 1, idx2, idx2 - mid);

        cout << "b" << idx1 << " " << idx2 << " " << len << endl;

        int fir = idx1; int sec = mid + 1; vector<Pair> tmp;
        while(fir < mid + 1 && sec <= idx2){
            if(pairs[fir].key <= pairs[sec].key){
                tmp.push_back(pairs[fir]);
                fir++;
            }
            else{
                tmp.push_back(pairs[sec]);
                sec++;
            }
        }
        for(auto t : tmp) cout << t.key << " "; cout << endl; 
        while(fir < mid + 1){
            tmp.push_back(pairs[fir]);
            fir++;
        }while(sec <= idx2){
            tmp.push_back(pairs[sec]);
            sec++;
        }
        for(auto t : tmp) cout << t.key << " "; cout << endl; 
        for(int i=0; i < len; i++){
            pairs[idx1+i] = tmp[i];
        }
        for(auto t : pairs) cout << t.key << " "; cout << endl; 
    }

    vector<Pair> mergeSort(vector<Pair>& pairs) {
        length = pairs.size();
        sort(pairs, 0, pairs.size() - 1, pairs.size());
        return pairs;
    }
};
