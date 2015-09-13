class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        for (int i = 0; i < citations.size(); i++) {
            if (i + 1 <= citations[i]) {
                if (i + 1 == citations.size() || citations[i + 1] <= i + 1) 
                    return i + 1;
            }
        }
    }
};