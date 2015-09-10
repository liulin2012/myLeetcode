class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result(1, 0);        
    for (int i = 0; i < n; i++) {
        int curCount = result.size();
        // push back all element in result in reverse order
        while (curCount) {
            curCount--;
            int curNum = result[curCount];
            curNum += (1<<i);
            result.push_back(curNum);
        } 
    }
    return result;
    }
};