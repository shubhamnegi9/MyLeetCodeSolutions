class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> devicesCountRowWise;
        for(string str:bank) {
            int devicesCount = 0;
            for(char ch: str) {
                if(ch == '1')
                    devicesCount++;
            }
            if(devicesCount > 0) {
                devicesCountRowWise.push_back(devicesCount);
            }
        }
        int n = devicesCountRowWise.size();
        //If there is only one row containing devices
        // then there cannot be any laser beams
        if(n == 1) 
            return 0;
            
        int laserBeamsSum = 0;
        for(int i = 1; i < n; i++) {
            laserBeamsSum += (devicesCountRowWise[i]* devicesCountRowWise[i-1]);
        }
        return laserBeamsSum;
    }
};