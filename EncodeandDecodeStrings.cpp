class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string tmp;
        for (string st : strs) {
            tmp += to_string(st.size()) + " " + st;
        }
        return tmp;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        int index = 0;
        vector<string> res;
        while (index != s.size()) {
            int num = stoi(s.substr(index));
            index += to_string(num).size() + 1;
            res.push_back(s.substr(index, num));
            index += num;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));