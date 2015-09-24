class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        st.push("/");
        string res;
        int index = 0;
        while (index < path.size()) {
            string tmp;
            if (path[index] == '/') {
                tmp = "/";
                while (index < path.size() && path[index] == '/') index++;
                while (index < path.size() && path[index] != '/') {
                    tmp.push_back(path[index++]);
                }
                if (tmp == "/." || tmp == "/") ;
                else if (tmp == "/..") {
                    if (st.empty()) st.push("/");
                    else {
                        st.pop();
                        if (st.empty()) st.push("/");
                    }
                } else {
                    if (st.empty()) st.push(tmp);
                    else if (st.top() == "/") {st.pop(); st.push(tmp);}
                    else st.push(tmp);
                    
                }
            }
        }
        while (!st.empty()) { res = st.top() + res; st.pop();}
        return res;
    }
};