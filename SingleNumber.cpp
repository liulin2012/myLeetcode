Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

//bit operation
class Solution {
public:
    int singleNumber(int A[], int n) {
        int result = 0;
        for (int i = 0; i < n; i++)
            result = result ^ A[i];
        return result;
    }
};

//hash table
class Solution {
public:
    int singleNumber(int A[], int n) {
        std::unordered_set<int> result;
        for (int i = 0; i < n; i++)
        {
            if (result.find(A[i]) == result.end()) result.insert(A[i]);
            else result.erase(A[i]);
        }
        auto iter = result.begin();
        return *iter;
    }
};