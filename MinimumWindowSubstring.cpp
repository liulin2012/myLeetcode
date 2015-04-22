class Solution {
public:
    string minWindow(string S, string T) {
        string result = "";
        int length = T.length();
        int min = INT32_MAX, first = 0, second = 0, match = 0;
        unordered_map<char, int> windows;
        for (size_t i = 0; i < T.length(); i++) {
            auto iter = windows.find(T[i]);
            if (iter != windows.end()) iter->second++;
            else windows.insert({T[i], 1});
        }
        while (second != S.length() || (second == S.length() && match == length)) {
            if (match == length) {
                auto iter = windows.find(S[first]);
                if (iter != windows.end()) {
                    iter->second++;
                    if (iter->second > 0) match--;
                }
                first++;
            }
            else {
                auto iter = windows.find(S[second]);
                if (iter != windows.end()) {
                    iter->second--;
                    if (iter->second >=0) match++;
                }
                second++;
            }
            if (match == length && min > (second - first)) {min = second - first; result = S.substr(first, min);}
        }
        return result;
    }
};