class Solution {
public:

    // Brute Force Approach
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
                // Update the ending time of the earlyEndingRoom based on current meeting
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

    int mostBooked(int n, vector<vector<int>>& meetings) {
        return mostBookedBrute(n, meetings);
    }
};