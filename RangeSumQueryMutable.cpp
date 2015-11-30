struct SegmentTreeNode {
    int start, end, sum;
    SegmentTreeNode *left;
    SegmentTreeNode *right;
    SegmentTreeNode(int a, int b):start(a), end(b), sum(0), left(nullptr), right(nullptr){}
};

class NumArray {
    SegmentTreeNode *root;
public:
    NumArray(vector<int> &nums) {
        if (nums.empty()) root == nullptr;
        else root = constructST(nums, 0, nums.size()-1);
    }

    void update(int i, int val) {
        updateST(root, i, val);
    }

    int sumRange(int i, int j) {
        return queryST(root, i, j);
    }
    
    SegmentTreeNode* constructST(vector<int> &nums, int start, int end) {
        SegmentTreeNode* node = new SegmentTreeNode(start, end);
        if (start == end) {
            node->sum = nums[start];
            return node;
        } else {
            int mid = (start+end) / 2;
            node->left = constructST(nums, start, mid);
            node->right = constructST(nums, mid+1, end);
            node->sum = node->left->sum + node->right->sum;
            return node;
        }
    }
    
    int updateST(SegmentTreeNode* node, int i, int val) {
        int diff = 0;
        if (i == node->start && i == node->end) {
            diff = val - node->sum;
            node->sum = val;
        } else {
            int mid = (node->start + node->end) / 2;
            if (mid < i) diff = updateST(node->right, i, val);
            else diff = updateST(node->left, i, val);
            
            node->sum += diff;
        }
        return diff;
    }
    
    int queryST(SegmentTreeNode* node, int i, int j) {
        if (node == nullptr) return 0;
        if (node->start == i && node->end == j) return node->sum;
        int mid = (node->start + node->end) / 2;
        if (mid >= j) return queryST(node->left, i, j);
        if (mid < i) return queryST(node->right, i, j);
        return queryST(node->left, i, mid) + queryST(node->right, mid+1, j);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);