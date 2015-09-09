class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
       unordered_set<string> head({beginWord}), tail({endWord});
        int minPath = 2, headLen = 1, tailLen = 1;
        while(headLen && tailLen)
        {
            if(headLen > tailLen)   //two pointers are unnecessary!
            {
                swap(head, tail);
                swap(headLen, tailLen);
            }
            unordered_set<string> tmpSet;
            for(auto it = head.begin(); it != head.end(); ++it)
            {
                string str(*it);
                for(int i = 0; i < str.size(); ++i)
                {
                    int tmp = str[i];
                    for(char ch = 'a'; ch <= 'z'; ++ch)
                    {
                        if(ch == str[i])   continue;
                        str[i] = ch;
                        if(tail.find(str) != tail.end())
                            return minPath;
                        if(wordDict.find(str) != wordDict.end())
                        {
                            tmpSet.insert(str);
                            wordDict.erase(str);
                        }
                    }
                    str[i] = tmp;
                }
            }
            swap(head, tmpSet);
            headLen = head.size();
            ++ minPath;
        }
        return 0;
    }
};


class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        if (wordDict.find(beginWord) != wordDict.end()) wordDict.erase(wordDict.find(beginWord));
        if (wordDict.find(endWord) != wordDict.end()) wordDict.erase(wordDict.find(endWord));
        int res = 0;
        vector<string> last;
        last.push_back(beginWord);
        int round = 2;
        while (!last.empty()) {
            vector<string> tmpSet;
            for (string st : last) {
                if (oneCharDiff(st, endWord)) return round;
                else {
                    string str(st);
                    for(int i = 0; i < str.size(); ++i)
                    {
                        int tmp = str[i];
                        for(char ch = 'a'; ch <= 'z'; ++ch)
                        {
                            if(ch == str[i])   continue;
                            str[i] = ch;
                            if(wordDict.find(str) != wordDict.end())
                            {
                                tmpSet.push_back(str);
                                wordDict.erase(str);
                            }
                        }
                        str[i] = tmp;
                    }
                }
            }
            swap(last, tmpSet);
            round++;
        }
        
        return 0;
    }
    
    inline bool oneCharDiff(const string& str1, const string& str2) {
        int diff = 0;
        for (int i = 0; i < str1.size(); ++i)  {
            if (str1[i] != str2[i]) 
                ++diff;
            if (diff > 1) 
                return false;  // perhaps quicker
        }
        return diff == 1;
    }
};