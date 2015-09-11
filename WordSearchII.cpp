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

    TrieNode* root;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for(auto i : words) trie.insert(i);
        vector<string> res;
        if (board.size() == 0 || words.size() == 0) return {};
        TrieNode* root = trie.root;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (root->children[INDEX(board[i][j])]) {
                    string tmp;
                    tmp.push_back(board[i][j]);
                    DFS(board, root->children[INDEX(board[i][j])], i, j, res, tmp);
                }
            }
        }
        return res;
    }
    
    void DFS(vector<vector<char>>& board, TrieNode* tp, int a, int b, vector<string>& res, string one) {
        if (tp->isWord) {res.push_back(one); tp->isWord = false;}
        char tmp = board[a][b];
        board[a][b] = '*';
        if (a+1 != board.size() && board[a+1][b] != '*' && tp->children[INDEX(board[a+1][b])] )
            DFS(board, tp->children[INDEX(board[a+1][b])], a+1, b, res, one + board[a+1][b]);
        if (a != 0 && board[a-1][b] != '*' && tp->children[INDEX(board[a-1][b])] )
            DFS(board, tp->children[INDEX(board[a-1][b])], a-1, b, res, one + board[a-1][b]);
        if (b+1 != board[0].size() && board[a][b+1] != '*' && tp->children[INDEX(board[a][b+1])])
            DFS(board, tp->children[INDEX(board[a][b+1])], a, b+1, res, one + board[a][b+1]);
        if (b != 0 && board[a][b-1] != '*' && tp->children[INDEX(board[a][b-1])] )
            DFS(board, tp->children[INDEX(board[a][b-1])], a, b-1, res, one + board[a][b-1]);
            
        board[a][b] = tmp;
    }
};


