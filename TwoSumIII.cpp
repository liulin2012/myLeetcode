class TwoSum {
public:
    unordered_multiset<int> index;
    // Add the number to an internal data structure.
	void add(int number) {
	    index.insert(number);
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
	    for (auto num : index) {
	        if (num != value-num && index.find(value - num) != index.end())
	            return true;
	        else if (num == value-num && index.count(num) > 1)
	            return true;
	    }
	    return false;
	}
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);