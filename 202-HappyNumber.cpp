/*
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 

Input: 19
Output: true
Explanation: 
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
*/

#include <iostream>
#include <vector>
#include <math.h>   // for pow

using namespace std;

class Solution {
public:
    bool isHappy(int n) {

        // start with a loop since we'll be iterating the whole process multiple times
        // cut off after 6 loops so it won't run endlessly
        for (int i=0; i<6; i++) {

            // Get the digits by converting int to an array of chars then back to ints
            string nStr = to_string(n); 
            // cout << nStr << endl;

            // now create a vector of the digits by converting back to int
            vector<int> nVec;
            for (char c : nStr) {
                // cout << "Converting " << c << " to int and we get " << charToInt(c) << endl;
                nVec.push_back(charToInt(c) );   // stoi converts back to int
            }

            // next get the sum of squares of the digits
            n = sumOfSquares(nVec);

            // finally, check if the result is 1, if not keep looping
            if (n==1)
                return true;
        }

        return false;
    }

    int charToInt(char c) {
        // corrects for the 0 offset
        return c - '0';
    }

    int sumOfSquares(vector<int> digits) {
        int subtotal = 0;
        for (int d : digits) {
            // cout << "--- " << d << "^2 = " << pow(d,2) << ".  Adding to " << subtotal << endl;
            subtotal += pow(d, 2);
        }
        return subtotal;
    }
};

int main() {
    #include <iostream>

    Solution s = Solution();
    std::cout << s.isHappy(19);

    return 0;
}