class Solution {
public:
    unordered_map<string , vector<string>> dpHash;
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {

        // time complexity is 2^n

        vector<string> result;

        //memorize the result, don't do the redundent work
        if (dpHash.find(s) != dpHash.end()) {
            return dpHash[s];
        }

        // Check should we go further?
        bool notFound = true;
        for (int i = s.size() - 1; i >=0; --i) {   // key here
            if (wordDict.find(s.substr(i)) != wordDict.end()) {
                notFound = false;
                break;
            } 
        }
        if (notFound) { return result; }
        
        // Further
        if (wordDict.find(s) != wordDict.end()) result.push_back(s);
        for (int i = s.size() - 1; i > 0; i--) {
            if (wordDict.find(s.substr(0, i)) != wordDict.end()) {
                vector<string> subRes = wordBreak(s.substr(i, s.size()), wordDict);
                for (auto str : subRes)
                    result.push_back(s.substr(0, i) + " " + str);
            }
        }
        dpHash[s] = result;
        return result;
    }
};