class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if(a > 0)
            pq.push({a, 'a'});
        if(b > 0)
            pq.push({b, 'b'});
        if(c > 0)
            pq.push({c, 'c'});
        
        string result = "";
        while(!pq.empty()) {
            int currCount = pq.top().first;
            char currChar = pq.top().second;
            pq.pop();
            
            // We can't add currChar with largest frequency. Check for next largest frequency char
            if(result.length() > 1 && result[result.length()-1] == currChar && result[result.length()-2] == currChar) {
                
                if(pq.empty()) {
                    break;
                }
                
                int nextCount = pq.top().first;
                int nextChar = pq.top().second;
                pq.pop();
                
                result += nextChar;
                nextCount--;
                
                if(nextCount > 0)
                    pq.push({nextCount, nextChar});
            }
            else {
                // Add current char with largest freq
                result+= currChar;
                currCount--;   
            }
        
            if(currCount > 0) {
                pq.push({currCount, currChar});
            }
        }
        
        return result;
    }
};