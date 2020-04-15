/*
Perform String Shifts
You are given a string s containing lowercase English letters, and a matrix shift, where shift[i] = [direction, amount]:

direction can be 0 (for left shift) or 1 (for right shift). 
amount is the amount by which string s is to be shifted.
A left shift by 1 means remove the first character of s and append it to the end.
Similarly, a right shift by 1 means remove the last character of s and add it to the beginning.
Return the final string after all operations.

 

Example 1:

Input: s = "abc", shift = [[0,1],[1,2]]
Output: "cab"
Explanation: 
[0,1] means shift to left by 1. "abc" -> "bca"
[1,2] means shift to right by 2. "bca" -> "cab"
Example 2:

Input: s = "abcdefg", shift = [[1,1],[1,1],[0,2],[1,3]]
Output: "efgabcd"
Explanation:  
[1,1] means shift to right by 1. "abcdefg" -> "gabcdef"
[1,1] means shift to right by 1. "gabcdef" -> "fgabcde"
[0,2] means shift to left by 2. "fgabcde" -> "abcdefg"
[1,3] means shift to right by 3. "abcdefg" -> "efgabcd"
 

Constraints:

1 <= s.length <= 100
s only contains lower case English letters.
1 <= shift.length <= 100
shift[i].length == 2
0 <= shift[i][0] <= 1
0 <= shift[i][1] <= 100
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string stringShift(string s, vector<vector<int> > &shift) {

        int shiftCount = shift.size();
        vector<int> currShift;
        int direction, qty;

        for (int i=0; i < shiftCount; i++) {
            currShift = shift.front();
            shift.erase(shift.begin() );

            direction = currShift.front();
            qty = currShift.back();

            char letter;
            if (direction == 0) {
                // shift left
                cout << "Shifting left by " << qty << endl;
                for (int i=0; i<qty; i++) {
                    s += s[0];
                    s.erase(s.begin() );
                }
            }
            else if (direction == 1) {
                // shift right
                cout << "Shifting right by " << qty << endl;
                string tempStr;
                for (int i=0; i<qty; i++) {
                    tempStr = s.back();
                    s.insert(0, tempStr);
                    s.pop_back();
                }            
            }
            else {
                cout << "error: incorrect direction" << endl;
                return "error";
            }
        }
        
        return s;
    }
};

int main() {

    Solution s = Solution();
    
    string input = "abcdefg";
    cout << input << endl;

    vector<vector<int> > shiftVec;
    vector<int> shiftTemp;
    shiftTemp.push_back(0);
    shiftTemp.push_back(1);
    shiftVec.push_back(shiftTemp);
    shiftTemp.push_back(1);
    shiftTemp.push_back(2);
    shiftVec.push_back(shiftTemp);
    
    cout << s.stringShift(input, shiftVec);

    return 0;
}