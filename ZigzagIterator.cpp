class ZigzagIterator {
public:
    vector<int>::iterator iter1;
    vector<int>::iterator iter2;
    vector<int>::iterator end1;
    vector<int>::iterator end2;
    bool first;
    int num;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        iter1 = v1.begin();
        iter2 = v2.begin();
        end1 = v1.end();
        end2 = v2.end();
        first = true;
    }

    int next() {
        return num;
    }

    bool hasNext() {
        if (iter1 == end1 && iter2 == end2) return false;
        if (iter1 == end1) { num = *iter2; iter2++; return true;}
        else if (iter2 == end2) { num = *iter1; iter1++; return true;}
        
        if (first) {num = *iter1; iter1++; first = false; return true;}
        else {num = *iter2; iter2++; first = true; return true;}
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */