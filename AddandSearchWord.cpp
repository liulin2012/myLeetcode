#define ALPHABETIC_SIZE 26
#define INDEX(c) (int(c-'a'))

class TrieNode {
public:
    bool isWord;
    TrieNode* children[ALPHABETIC_SIZE];
    // Initialize your data structure here.
    TrieNode() {
        memset(children, 0, sizeof(children));
        isWord = false;
    }
};

class WordDictionary {
public:
    WordDictionary(){
        root = new TrieNode();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* tmp = root;
        for (char c : word) {
            if (!tmp->children[INDEX(c)]) {
                tmp->children[INDEX(c)] = new TrieNode();
            }
            tmp = tmp->children[INDEX(c)];
        }
        tmp->isWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return searchHelper (word, 0, root);
    }
    
    bool searchHelper(string word, int begin, TrieNode* tp) {
        if (begin == word.size()) return tp->isWord;
        else if (word[begin] != '.') {
            if (tp->children[INDEX(word[begin])]) return searchHelper(word, begin + 1, tp->children[INDEX(word[begin])]);
            else return false;
        } else {
            for (auto it : tp->children) {
                if (it != nullptr) 
                    if (searchHelper(word, begin + 1, it))
                        return true;
            }
            return false;
        }
    }
    
private:
    TrieNode* root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");