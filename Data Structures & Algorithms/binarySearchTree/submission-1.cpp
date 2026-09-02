class TreeMap {

public:
    struct Node{
        int key;
        int val;
        Node* left;
        Node* right;

        Node(int key, int val){
            this->key = key;
            this->val = val;
            left = nullptr;
            right = nullptr;
        }
    };

    Node* root;

    TreeMap() {
        root = nullptr;
    }

    void insert(int key, int val) {
        Node* newNode = new Node(key, val);

        if(root == nullptr){
            root = newNode; return;
        }

        Node* node = root; 
        while(node != nullptr){
            if(node->key > key){
                if(node->left == nullptr){
                    node->left = newNode;
                }
                node = node->left;
            }
            else if(node->key < key){
                if(node->right == nullptr){
                    node->right = newNode;
                }
                node = node->right;
            }
            else{
                node->val = val;
                return;
            }
        }
        return;
    }

    int get(int key) {
        if(root == nullptr){
            return -1;
        }

        Node* node = root; 
        while(node != nullptr){
            if(node->key > key){
                node = node->left;
            }
            else if(node->key < key){
                node = node->right;
            }
            else{
                return node->val;
            }
        }
        return -1;
    }

    int getMin() {
        if(root == nullptr){
            return -1;
        }

        return findMin(root)->val;
    }

    Node* findMin(Node* node){
        while(node != nullptr){
            if(node->left == nullptr){
                break;
            }
            node = node->left;
        }
        return node;
    }

    int getMax() {
        if(root == nullptr){
            return -1;
        }

        Node* node = root; 
        while(node != nullptr){
            if(node->right == nullptr){
                break;
            }
            node = node->right;
        }
        return node->val;
    }

    Node* removeHelper(Node* node, int key){
        if(node == nullptr){
            return nullptr;
        }

        if(key > node->key){
            node->right = removeHelper(node->right, key);
        } else if(key < node->key){
            node->left = removeHelper(node->left, key);
        } else{
            if(node->left == nullptr) return node->right;
            else if(node->right == nullptr) return node->left;
            else{
                Node* minNode = findMin(node->right);
                node->key = minNode->key;
                node->val = minNode->val;
                node->right = removeHelper(node->right, minNode->key);
            }
        }
        return node;
    }

    void remove(int key) {
        root = removeHelper(root, key);        
    }

    void func(Node* node, vector<int>& ret){
        if(node == nullptr) return;
        // cout << node->key << endl;
        if(node->left != nullptr){
            func(node->left, ret);
        }
        ret.push_back(node->key);
        if(node->right != nullptr){
            func(node->right, ret);
        }
    }

    std::vector<int> getInorderKeys() {
        vector<int> ret = {};
        func(root, ret);
        return ret;
    }
};
