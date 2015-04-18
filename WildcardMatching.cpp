class Solution {
public:
    bool isMatch(string s, string p) {
        int pos = 0;
        string sub = "";
        if (p.find('*') == std::string::npos) {
            int i = 0;
            if (s.size() != p.size()) return false;
            else {
                while (i != s.size()) {
                    if (s[i] == p[i] || p[i] == '?') i++;
                    else return false;
                }
                return true;
            }
        }
        int firstP = 0;
        while (p[firstP] != '*' ) {
            if (s[firstP] == p[firstP] || p[firstP] == '?') firstP++;
            else return false;
            if (firstP == s.size()) 
                break;
        }
        pos = firstP;
        
        for (int i = firstP; i < p.size(); i++) {
            if (p[i] != '*') {
                sub += p[i];
            }
            else {
                bool ifMatch = false;
                if (sub.empty()) continue;
                if (pos == s.size()) return false;
                for (int j = pos; j < s.size(); j++) {
                    int m = j;
                    for (int x = 0; x < sub.size(); x++) {
                        if (m == s.size()) return false;
                        if (sub[x] == '?' || sub[x] == s[m]) {
                            m++;
                            if (x == sub.size() - 1) ifMatch = true;
                        }
                        else break;
                    }
                    
                    if (ifMatch) {
                        pos = m;
                        break;
                    }
                }
                if (!ifMatch) return false; 
                sub = "";
            }
        }
        
        
        
        
        if (p[p.size() - 1] == '*') return true;
        else {
            int lastP = s.size() - sub.size();
            if (pos <= lastP) {
                int i =0;
                while (lastP != s.size()) {
                    if (sub[i] == s[lastP] || sub[i] == '?') {
                        lastP++;
                        i++;
                    }
                    else return false;
                }
                return true;
            }
            else return false;
        }
    }
};


class Solution {
public:
  bool isMatch(string s, string p) {
    int star = -1;
    int si = 0;
    int pi = 0;
    int ss = si;

    while (si < s.size()) {
      if (pi < p.size()) {
          if(p[pi] == '?' || s[si] == p[pi]) {si++; pi++; continue;}
          if(p[pi] == '*') {star = pi++; ss = si; continue;}
      }
      if(star >= 0) {pi = star + 1; si = ++ss; continue;}

      return false;
    }

    while(p[pi] == '*' && pi < p.size()) pi++;
    return pi == p.size();
  }
};