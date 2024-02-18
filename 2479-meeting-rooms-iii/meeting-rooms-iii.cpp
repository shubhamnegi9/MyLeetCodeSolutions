class Solution {
public:

    // Brute Force Approach
    // T.C. = O(mlogm) for sorting + O(m*n); m = no. of meetings, n = no. of rooms
    int mostBookedBrute(int n, vector<vector<int>>& meetings) {

        // Sort meetings based on their start times so that they can be given rooms early
        sort(meetings.begin(), meetings.end());

        // Vector for storing meeting end times (exclusive one) of each room
        vector<long long> meetingEndTime(n, 0);     // Taking long long since we are adding meeting times in it later
        // Vector for storing count of meetings held in each room
        vector<int> countOfMeetings(n, 0);

        for(vector<int> &meet: meetings) {
            int startTime = meet[0];
            int endTime = meet[1];
            // Duration of each meeting
            int duration = endTime - startTime;

            bool isRoomFound = false;
            long long earlyEndTime = LLONG_MAX; // Taking long long as we are assinging from meetingEndTime to it
            int earlyEndingRoom = 0;

            // Iterate in each room to find which one is available for current meeting
            for(int room = 0; room < n; room++) {
                
                // Room found for current meeting
                if(meetingEndTime[room] <= startTime) { 
                    meetingEndTime[room] = endTime;  // Updating meeting end time of current room
                    countOfMeetings[room]++;         // Updating count of meetings held in current room 
                    isRoomFound = true;
                    break;                           // No need to check for further rooms
                }

                // Keeping track of the room which will be available early (having least ending time) 
                // in case all the rooms are occupied
                if(meetingEndTime[room] < earlyEndTime) {
                    earlyEndTime = meetingEndTime[room];
                    earlyEndingRoom = room;
                }

            }

            // No room found for current meeting
            if(!isRoomFound) {
                // Pick the room for current meeting which will be available early (having least ending time) 
                // which will be earlyEndingRoom.
                // Update the ending time of the earlyEndingRoom based on current meeting duration
                meetingEndTime[earlyEndingRoom] += duration;
                // Updating count of meetings held in earlyEndingRoom
                countOfMeetings[earlyEndingRoom]++; 
            }

        }

        // Checking for the room which have maximum meetings
        int maxUsedRoom = -1;
        int maxUsed = 0;
        for(int room = 0; room < n; room++) {
            if(countOfMeetings[room] > maxUsed) {
                maxUsed = countOfMeetings[room];
                maxUsedRoom = room;
            }
        }

        return maxUsedRoom;
    }

    // Optimal Approach
    // T.C. = O(m) for iterating in meetings * O(logn) for pushing in heap
    //      = O(m*log(n)); m = no. of meetings, n = no. of rooms
    typedef pair<long long, int> P;
    int mostBookedOptimal(int n, vector<vector<int>>& meetings) {
        /*
            In Brute Force Approach, lot of time = O(n) was taken for iterating in 
            rooms and finding which room is available earliest for current meeting.
            We can use sorting also to find the room having least ending time but 
            it will increase the time complexity more to O(nlogn).
            That is why we will be using min heap to store the rooms having least ending 
            time at the top.
            Also we will be using another min heap to store the available rooms since we
            need to arrange the meeting in the lowest number room.  
        */

        // Sort meetings based on their start times so that they can be given rooms early
        sort(meetings.begin(), meetings.end());

        // Vector for storing count of meetings held in each room
        vector<int> countOfMeetings(n, 0);

        // Min Heap for storing ending times of each room and its room number as pair
        // P = pair<ending_time, room_number> 
        priority_queue<P, vector<P>, greater<P>> usedRooms;
        
        // Min Heap for storing available room numbers
        priority_queue<int, vector<int>, greater<int>> availableRooms;

        // Initially all rooms are available
        for(int room = 0; room < n; room++) {
            availableRooms.push(room);
        }

        for(vector<int> meet: meetings) {
            int startTime = meet[0];
            int endTime = meet[1];
            int duration = endTime - startTime;

            // Keep checking for the rooms in usedRooms which are available now 
            // (means its ending time is less than current meeting start time)
            // and move them to available rooms
            while(!usedRooms.empty() && usedRooms.top().first <= startTime) {
                int room = usedRooms.top().second;
                usedRooms.pop();
                availableRooms.push(room);
            }
            
            if(!availableRooms.empty()) {
                // Picking available room for current meeting and moving it to usedRooms
                int room = availableRooms.top();
                availableRooms.pop();
                usedRooms.push({endTime, room});
                countOfMeetings[room]++;    // Updating count of meetings held in room
            }
            else {
                // We don't have any available rooms for current meeting. 
                // Pick the room for current meeting which will be available early (having least ending time) 
                // which will be top of usedRooms 
                int room = usedRooms.top().second;
                long long endingTime = usedRooms.top().first;
                usedRooms.pop();
                // Update the ending time of this room based on current meeting duration
                usedRooms.push({endingTime + duration, room});
                countOfMeetings[room]++;    // Updating count of meetings held in room
            }   

        }

        // Checking for the room which have maximum meetings
        int maxUsedRoom = -1;
        int maxUsed = 0;
        for(int room = 0; room < n; room++) {
            if(countOfMeetings[room] > maxUsed) {
                maxUsed = countOfMeetings[room];
                maxUsedRoom = room;
            }
        }

        return maxUsedRoom;

    }

    int mostBooked(int n, vector<vector<int>>& meetings) {

        // Brute Force Approach
        // return mostBookedBrute(n, meetings);

        // Optimal Approach
        return mostBookedOptimal(n, meetings);
    }
};