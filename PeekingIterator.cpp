// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
    vector<int>::const_iterator it;
    vector<int>::const_iterator nextIt;
    vector<int>::const_iterator end;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    nextIt = nums.begin();
	    
	    end = nums.end();
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if(hasNext()) return *nextIt;
        else return 0;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    it = nextIt;
	    nextIt++;
	    return *it;
	}

	bool hasNext() const {
	    if (nextIt == end) return false;
	    else return true;
	}
};