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

        cout << "Before Regex: Is " << S << " = " << T << "?" << endl;
        
        // use regex to remove the # symbols and preceding char in both strings
        regex backspaceLeading ("^[#]+");
        regex backspaceChar ("[^#][#]");
        smatch m;

        while (regex_search(S, m, backspaceLeading) || regex_search(S, m, backspaceChar)) {
            // first replace any leading backspaces
            S = regex_replace(S, backspaceLeading, "");
            // now remove any backspaces with chars in front of them
            S = regex_replace(S, backspaceChar, "");
        }
        while (regex_search(T, m, backspaceLeading) || regex_search(T, m, backspaceChar)) {
            // first replace any leading backspaces
            T = regex_replace(T, backspaceLeading, "");
            // now remove any backspaces with chars in front of them
            T = regex_replace(T, backspaceChar, "");
        }
        
        cout << "After Regex:  Is " << S << " = " << T << endl;
        
        if (S == T) { return true; }
        else  { return false; }
    }
};

int main() {
    #include <iostream>
    #include <string>

    using namespace std;

    Solution s = Solution();

    string str1 = "y#fo##f";
    string str2 = "f#f#o##f";

    bool result = s.backspaceCompare(str1, str2);
    cout << "RESULT: " << result;

    return 0;
}