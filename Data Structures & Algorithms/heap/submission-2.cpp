class MinHeap {
public:
    vector<int> heap; int len = 0;

    MinHeap() {}

    void push(int val) {
        len++;
        if(len > heap.size()){
            heap.push_back(val);
        } else{
            heap[len - 1] = val;  
        }

        int idx = len - 1;
        while(idx > 0){
            int parent = idx / 2;
            if(heap[idx] < heap[parent]){
                int tmp = heap[idx]; heap[idx] = heap[parent];
                heap[parent] = tmp;
            }
            idx = parent;
        }
        // heapifyHelper(0);
    }

    int pop() {
        if(len < 1) return -1;
        int topElement = heap[0];
        heap[0] = heap[len-1]; len--;
        heapifyHelper(0);
        return topElement;
    }

    int top() {
        if(len < 1) return -1;
        return heap[0];
    }

    void heapifyHelper(const int i){
        int left = i * 2 + 1;
        int right = i * 2 + 2;
        
        if(left < len) {
            heapifyHelper(left);
            if(heap[left] < heap[i]){
                int tmp = heap[left];
                heap[left] = heap[i];
                heap[i] = tmp;
            }   
            // cout << heap[i] << " " << heap[left] << " " << heap[right] << endl;
        }
        if(right < len) {
            heapifyHelper(right);
            if(heap[right] < heap[i]){
                int tmp = heap[right];
                heap[right] = heap[i];
                heap[i] = tmp;
            }
            // cout << heap[i] << " " << heap[left] << " " << heap[right] << endl;
        }
    }

    void heapify(const vector<int>& arr) {
        // heap = {4,6,3,2,1};
        heap = arr; 
        len = arr.size();
        heapifyHelper(0);
        // for(int i=0;i<arr.size();i++){
        //     if(left > arr.size() - 1) break;
        //     if(heap[left] < heap[i]){
        //         int tmp = arr[left];
        //         heap[left] = heap[i];
        //         heap[i] = tmp;
        //     }
        //     if(heap[right] < heap[i]){
        //         int tmp = heap[right];
        //         heap[right] = heap[i];
        //         heap[i] = tmp;
        //     }
        // }
        for(auto i : heap){
            cout << i << " ";
        }
        cout << endl;
    }
};
