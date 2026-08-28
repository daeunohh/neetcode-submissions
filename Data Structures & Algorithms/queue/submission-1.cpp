class Deque {
public:
    struct Node{
        int val;
        Node* prev; Node* next;
        Node(int value, Node* prev = nullptr, Node* next = nullptr){
            val = value;
            this->prev = prev;
            this->next = next;
        }
    };
    Node* head = nullptr; Node* tail = nullptr;

    Deque() {
        
    }

    bool isEmpty() {
        if(head == nullptr && tail == nullptr) return true;
        return false;
    }

    void append(int value) {
        if(isEmpty()){
            head = tail = new Node(value);
            return;
        }
        tail->next = new Node(value, tail, nullptr);
        tail = tail->next;
    }

    void appendleft(int value) {
        if(isEmpty()){
            head = tail = new Node(value);
            return;
        }
        head->prev = new Node(value, nullptr, head);
        head = head->prev;
    }

    int pop() {
        if(isEmpty()) return -1;
        int ret = tail->val;
        if(head == tail){
            delete tail;
            head = tail = nullptr;
            return ret;
        }
        Node* ntail = tail->prev;
        delete tail;
        tail = ntail;
        tail->next = nullptr;
        return ret;
    }

    int popleft() {
        if(isEmpty()) return -1;
        int ret = head->val;
        if(head == tail){
            delete head;
            head = tail = nullptr;
            return ret;
        }
        Node* nhead = head->next;
        delete head;
        head = nhead;
        head->prev = nullptr;
        return ret;
    }
};
