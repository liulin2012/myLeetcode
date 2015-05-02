class MinStack {
public:
    class Node {
    public:
        int val;
        Node* next;
        Node (int v) : val(v) {}
    };
    Node* root = nullptr;
    stack<int> minS;
    void push(int x) {
        Node* tmp = new Node(x);
        tmp->next = root;
        root = tmp;
        if (minS.empty()) minS.push(x);
        else if (minS.top() >= x) minS.push(x);
    }

    void pop() {
        if (minS.top() == root->val)  minS.pop();
        root = root->next;
    }

    int top() {
        return root->val;
    }

    int getMin() {
        return minS.top();
    }
};


class MinStack {
public:
    class Node {
    public:
        int val;
        Node* next;
        Node (int v) : val(v) {}
    };
    Node* root = nullptr;
    int minN = INT32_MAX;
    void push(int x) {
        Node* tmp = new Node(x);
        tmp->next = root;
        root = tmp;
        minN = min(x, minN);
    }

    void pop() {
        if (minN == root->val) {
            Node* tmp = root->next;
            minN = INT32_MAX;
            while (tmp != nullptr) {
                minN = min(tmp->val, minN);
                tmp = tmp->next;
            }
        }
        
        root = root->next;
    }

    int top() {
        return root->val;
    }

    int getMin() {
        return minN;
    }
};