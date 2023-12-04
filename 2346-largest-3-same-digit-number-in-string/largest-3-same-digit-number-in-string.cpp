class Solution {
public:
    bool contains(string good, string num) {
        for(int i = 0; i <= num.size()-3; ++i) {
            if(good[0] == num[i] && good[1] == num[i+1] && good[2] == num[i+2])
                return true;
        }
        return false;
    }

    string largestGoodInteger(string num) {
        vector<string> goodNums = {"999", "888", "777", "666", "555", "444", "333", "222", "111", "000"};

        for(auto good: goodNums) {
            if(contains(good, num)) {
                return good;
            }
        }
        return "";
    }

    /*
        T.C. = O(n)
        S.C. = O(1)
    */
};