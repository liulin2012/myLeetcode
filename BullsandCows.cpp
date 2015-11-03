class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0;
        int cows = 0;
        int index[10] = {0};
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) bull++;
            else index[secret[i]-'0']++;
        }
        for (int i = 0; i < guess.size(); i++) {
            if (secret[i] != guess[i]) {
                if (index[guess[i]-'0'] != 0) {
                    cows++;
                    index[guess[i]-'0']--;
                }
            }
        }
        
        string res;
        res += to_string(bull) + "A";
        res += to_string(cows) + "B";
        return res;
    }
};