class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> index;
        vector<int> res;
        if (words.empty()) return res;
        int begin = 0, end = 0, num = words.size(), wordsize = words[0].size();
        for (string str : words)
            index[str]++;
        int times = wordsize;
        while (times--) {
            begin = times;
            end = times;
            while (end < s.size()) {
                if (num) {
                    if (index.find(s.substr(end, wordsize)) == index.end()) {
                        while (begin != end) {
                            index[s.substr(begin, wordsize)]++;
                            begin += wordsize;
                        }
                        begin += wordsize;
                        end += wordsize;
                        num = words.size();
                    } else if (index[s.substr(end, wordsize)] == 0) {
                        while (s.substr(end, wordsize) != s.substr(begin, wordsize)) {
                            index[s.substr(begin, wordsize)]++;
                            begin += wordsize;
                            num++;
                        }
                        begin += wordsize;
                        end += wordsize;
                    } else {
                        index[s.substr(end, wordsize)]--;
                        num--;
                        end += wordsize;
                    }
                        
                } else {
                    res.push_back(begin);
                    index[s.substr(begin, wordsize)]++;
                    num++;
                    begin += wordsize;
                }
            }
            if (num == 0) res.push_back(begin);
            while (begin != end) {
                index[s.substr(begin, wordsize)]++;
                begin += wordsize;
            }
            num = words.size();      
        }
        return res;
    }
};