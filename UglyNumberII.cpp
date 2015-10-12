class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 1) return 1;
        vector<int> vec(n);
        vec[0] = 1;
        int p2 = 0;
        int p3 = 0;
        int p5 = 0;
        for (int i = 1; i < vec.size(); i++) {
            vec[i] = min(vec[p2]*2, min(vec[p3]*3, vec[p5]*5));
            if (vec[i] == vec[p2]*2) p2++;
            if (vec[i] == vec[p3]*3) p3++;
            if (vec[i] == vec[p5]*5) p5++;
        }
        return vec[vec.size() - 1];
    }
};