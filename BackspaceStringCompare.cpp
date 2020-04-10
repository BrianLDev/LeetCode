/*
Backspace String Compare
Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
Note:

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.
Follow up:

Can you solve it in O(N) time and O(1) space?
*/

#include <iostream>
#include <regex>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {

        cout << "Is " << S << " = " << T << endl;
        
        // use regex to remove the # symbols in both strings
        regex pound ([#]);
        regex_replace(S, pound, "");
        regex_replace(T, pound, "");    
        
        cout << "* After Regex: Is " << S << " = " << T << endl;
        
        if (S.len() == T.len()) { return true; }
        else  { return false; }
        
    }
};

int main() {
    #include <iostream>
    #include <string>

    using namespace std;

    Solution s = Solution();

    string str1 = "test";
    string str2 = "tes#t";

    cout << "*** RESULT: " << s.backspaceCompare();

    return 0;
}