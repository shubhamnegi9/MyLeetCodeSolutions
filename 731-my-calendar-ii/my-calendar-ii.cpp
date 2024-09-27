class MyCalendarTwo {
public:
    vector<pair<int, int>> overallBookings;         // Vector for storing overall booking regions
    vector<pair<int, int>> doubleBookings;   // Vector for storing double booking regions
    
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        
        // Checking if tripple booking is created by any of the double booking regions 
        for(auto [s, e]: doubleBookings) {
            if(max(s, start) < min(e, end)) {
                // Triple booking created
                return false;
            }
        }
        
        // Checking for double bookings and adding the overlapped regions to doubleBooking vector
        for(auto [s, e]: overallBookings) {
            if(max(s, start) < min(e, end)) {
                doubleBookings.push_back({max(s, start), min(e, end)});
            }
        }
        
        // Add to overall booking 
        overallBookings.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */