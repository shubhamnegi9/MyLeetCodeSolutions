class MyCalendar {
public: 
    vector<pair<int, int>> v;   // Vector of pair
    set<pair<int, int>> st;     // Ordered set of pair
    MyCalendar() {
        
    }
    
    // Brute Force Approach
    // T.C. = O(n^2)
    // S.C. = O(n)
    bool bookBrute(int start, int end) {
        for(auto [a, b]: v) {
            if(a < end && start < b) {      // Condition of overlapping
                return false;
            }  
        }
        
        // Interval do not overlap so add into vector and return true
        v.push_back({start, end});
        return true;
    }
    
    // Optimal Approach
    // T.C. = O(nlogn)
    // S.C. = O(n)
    bool bookOptimal(int start, int end) {
        
        //Find the first event that starts after or at the same time of {start, end}
        auto it = st.lower_bound({start, end});
        
        //Check if the current event overlaps with the next event
        if(it != st.end() && it->first < end) {
            return false;
        }
        
        //Check if the current event overlaps with the previous event
        if(it != st.begin()) {      // 'it' should not point to first element to find prev(it)
            auto prevItr = prev(it);
            if(prevItr->second > start) {
                return false;
            }
        }
        
        // Interval do not overlap so add into set and return true
        st.insert({start, end});
        return true;
    }
    
    bool book(int start, int end) {
        // Brute Force Approach
        // return bookBrute(start, end);
        
        // Optimal Approach
        return bookOptimal(start, end);
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */