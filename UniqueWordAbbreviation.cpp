class ValidWordAbbr {
public:
    unordered_map<string, unordered_set<string>> index;
    ValidWordAbbr(vector<string> &dictionary) {
        for (int i = 0; i < dictionary.size(); i++) {
            string tmp;
            tmp.push_back(dictionary[i].front());
            if (dictionary[i].size() > 2)
                tmp += to_string(dictionary[i].size() - 2);
            tmp.push_back(dictionary[i].back());
            index[tmp].insert(dictionary[i]);
        }
    }

    bool isUnique(string word) {
        string tmp;
        tmp.push_back(word.front());
        if (word.size() > 2)
            tmp += to_string(word.size() - 2);
        tmp.push_back(word.back());
        return index[tmp].count(word) == index[tmp].size();
    }
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");