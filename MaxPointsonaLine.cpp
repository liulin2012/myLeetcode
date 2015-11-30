/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if (points.size() < 2) return points.size();
        
        int result = 0;
        for (int i = 0; i < points.size(); i++) {
            unordered_map<int, unordered_map<int, int>> index;
            int num = 0, overlap = 0;
            for (int j = i+1; j < points.size(); j++) {
                int x = points[i].x - points[j].x;
                int y = points[i].y - points[j].y;
                if (x == 0 && y == 0) {
                    overlap++;
                    continue;
                }
                int gcd = generate_gcd(x, y);
                x /= gcd;
                y /= gcd;
                if (index.find(x) == index.end()) {
                    index[x][y] = 1;
                } else {
                    if (index[x][y] == 0) {
                        index[x][y] = 1;
                    } else {
                        index[x][y]++;
                    }
                }
                num = max(num, index[x][y]);
            }
            result = max(result, num+overlap+1);
        }
        return result;
    }
    
    int generate_gcd(int x, int y) {
        if (y == 0) return x;
        else return generate_gcd(y, x%y);
    }
};