#include <iostream>
#include <vector>
#include <algorithm>    // for std::sort

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int unique;
        
        // first create a copy then sort the array so the original is unaffected
        vector<int> sortnums(nums.begin(), nums.end() );
        // std::sort(nums.begin(), nums.end() );
        std::sort(sortnums.begin(), sortnums.end());
        
        for (int n : nums) {
            cout << n << " ";
        }
        cout << endl;
        for (int n : sortnums) {
            cout << n << " ";
        }
        cout << endl;
        
        // check if there is only 1 number in the array
        if (sortnums.size() == 1) 
            return sortnums[0];
        
        // compare the first two
        if (sortnums[0] != sortnums[1])
            return sortnums[0];
        
        // now check all the others
        else {
            for (int i=1; i<sortnums.size(); i++) {
                if (i==sortnums.size()-1 ) {
                    // we've reached the end so it must be the last number
                    cout << "Reached end" << endl;
                    unique = sortnums[i];
                    return unique;
                }
                else {
                    cout << "Checking (" << sortnums[i] << " vs " << sortnums[i+1] << ") AND (" << sortnums[i] << " vs " << sortnums[i-1] << ")" << endl;
                    if((sortnums[i] != sortnums[i+1]) && (sortnums[i] != sortnums[i-1])) {
                        cout << "FOUND IT! " << sortnums[i] << endl;
                        unique = sortnums[i];
                        return unique;
                    }
                }
            }
        }
        return unique;
    }
};

class SolutionFast {
    // After completing the challenge, this was the solution from the fastest results
public:
    int singleNumber(vector<int>& nums) {
        int t = nums[0];
        for (int i=1; i < nums.size(); i++) {
            t ^= nums[i];   // ^= is an XOR operator.  Any matching items offset each other and you're left with the unique number
        }
        return t;
    }
};

int main() {
    #include <iostream>
    #include <vector>

    int arr[] = {17,12,5,-6,12,4,17,-5,2,-3,2,4,5,16,-3,-4,15,15,-4,-5,-6};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> test(arr, arr + n );

    Solution s = Solution();
    cout << s.singleNumber(test) << endl;

    SolutionFast sf = SolutionFast();
    cout << sf.singleNumber(test) << endl;


    return 0;
}