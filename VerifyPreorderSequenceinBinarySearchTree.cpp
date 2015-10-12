class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        if (preorder.empty()) return true;
        stack<int> st;
        st.push(preorder[0]);
        int leftmin = INT32_MIN;
        for (int i = 1; i < preorder.size(); i++) {
            if (preorder[i] < leftmin) return false;
            else {
                while (!st.empty() && st.top() < preorder[i]) {
                    leftmin = st.top();
                    st.pop();
                }
                st.push(preorder[i]);
            } 
        }
        return true;
    }
};


