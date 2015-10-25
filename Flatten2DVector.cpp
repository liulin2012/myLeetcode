class Vector2D {
private:
    vector<vector<int>>::iterator i, endIter;
    int j = -1;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        if (!vec2d.empty()) {
            i = vec2d.begin();
            endIter = vec2d.end();
        }
    }

    int next() {
        // hasNext();
        return (*i)[j];
    }

    bool hasNext() {
        if (i == endIter) return false;
        else if ((*i).empty()) {i++; return hasNext();}
        if (j == (*i).size() - 1) {
            i++;
            j = 0;
            if (i == endIter) return false;
            else if ((*i).empty()) {j = -1; return hasNext();}
            else return true;
        }
        else {
            
            j++;
            return true;
        }
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */