class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int left, right, up, down;
        left = max(A, E);
        right = min(C, G);
        up = min(D, H);
        down = max(F, B);
        if (left >= right || up <= down) return (C-A)*(D-B) + (G-E)*(H-F);
        else return (C-A)*(D-B) + (G-E)*(H-F) - (right - left) * (up - down);
    }
};