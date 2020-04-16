/*
Product of Array Except Self
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)
 */

#include <iostream>
#include <vector>
#include <algorithm>    // for transform

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> numsProduct = nums;

        int count = nums.size();
        for (int i=0; i<count; i++) {
            transform(nums.begin(), nums.end(), numsProduct.begin(), std::multiplies<int>() );
            
            
        }

        return numsProduct;
    }
};

void printVector(vector<int> vec) {
    for (int n : vec) {
        cout << n << " ";
    }
    cout << endl;
};

int main() {

    Solution s = Solution();
    
    int numArr[] = {1, 2, 3, 4};
    int n = sizeof(numArr) / sizeof(numArr[0]);
    vector<int> numbers(numArr, numArr + n);    // initializes vector and sets equal to the array
    printVector(numbers);   

    vector<int> newNumbers = s.productExceptSelf(numbers);
    printVector(newNumbers);

    return 0;
}

