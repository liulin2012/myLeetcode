class Solution {
public:
    string getPermutation(int n, int k) {
        int sum = 1;
        int a = n;
        while (a != 0) {sum *= a; a--;}
        vector<int> index(n + 1, 0);
        index[0] = 1;
        return Permu(n, k, index, sum);
    }
    
    string Permu(int n, int k, vector<int> index, int sum) {
        if (n == 0) return "";
        else {
            int m = (k - 1) / (sum / n) + 1;
            int res;
            for (int i = 1; i < index.size(); i++) {
                if (index[i] == 0) {
                     k -= sum/n;
                    m--;
                    if (m == 0) {res = i; index[i] = 1; break;}
                }
            }
            return to_string(res) + Permu(n - 1, k + sum / n, index, sum / n);
            
        }
    }
};

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numSet;
        int sum = 1;
        for (int i = 1; i <= n; i++) {
            numSet.push_back(i);
            sum *= i;
        }
        string res;
        k--;
        for (int i = 0; i < n; i++) {
            sum /= n - i;
            int tmp = k/sum;
            res.push_back(numSet[tmp]+'0');
            numSet.erase(numSet.begin()+tmp);
            k %= sum;
        }
        return res;
    }
};