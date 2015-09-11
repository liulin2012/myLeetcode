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

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* tmp = root;
        for (char c : word) {
            if (!tmp->children[INDEX(c)]) {
                tmp->children[INDEX(c)] = new TrieNode();
            }
            tmp = tmp->children[INDEX(c)];
        }
        tmp->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* tmp = root;
        for (char c : word) {
            if (!tmp->children[INDEX(c)]) return false;
            tmp = tmp->children[INDEX(c)];
        }
        return tmp->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* tmp = root;
        for (char c : prefix) {
            if (!tmp->children[INDEX(c)]) return false;
            tmp = tmp->children[INDEX(c)];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");