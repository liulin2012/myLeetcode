Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.


class Solution {
public:
    int numDistinct(string S, string T) {
        int s = S.size();
        int t = T.size();
        if (t > s) return 0;
        vector<int> m(s + 1, 1);
        int last = 1;
        m[0] = 1;
        for (int i = 0; i < t; i++) {
            last = m[i];
            m[i] = 0;
            for (int j = i + 1; j <= s; j++) {
                int tmp = m[j];
                m[j] = m[j - 1] + (S[j - 1] == T[i] ? last : 0);
                last = tmp;
            }
        }
        return m[s];
        
    }
};