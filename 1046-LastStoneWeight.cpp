/*
Last Stone Weight
We have a collection of stones, each stone has a positive integer weight.

Each turn, we choose the two heaviest stones and smash them together.  Suppose the stones have weights x and y with x <= y.  The result of this smash is:

If x == y, both stones are totally destroyed;
If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.
At the end, there is at most 1 stone left.  Return the weight of this stone (or 0 if there are no stones left.)

 

Example 1:

Input: [2,7,4,1,8,1]
Output: 1
Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of last stone.
 

Note:

1 <= stones.length <= 30
1 <= stones[i] <= 1000
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        vector<int> sortedStones(stones);
        // printVector(sortedStones);
        sort(sortedStones.begin(), sortedStones.end() );
    
        // printVector(sortedStones);

        while (sortedStones.size() >= 2) {
            int a = sortedStones.back();
            sortedStones.pop_back();
            int b = sortedStones.back();
            sortedStones.pop_back();

            int c = smashStones(a, b);
            insertSorted(c, sortedStones);

            // printVector(sortedStones);
        }
        
        return sortedStones.front();
    }

    int smashStones(int a, int b) {
        if (a>b) { return a-b; }
        else { return b-a; }
    }


    void insertSorted(int stone, vector<int> & stoneVec) {
        // cout << "Inserting " << stone << endl;

        vector<int>::iterator iter;     // required for vector.insert
        iter = stoneVec.begin();
        //check if empty
        if (stoneVec.empty() ) { stoneVec.push_back(stone); }
        // check back and front
        else if (stone >= stoneVec.back() ) { stoneVec.push_back(stone); }
        else if (stone <= stoneVec.front() ) { stoneVec.insert(iter, stone); }
        // else loop throu the rest
        else {
            int size = stoneVec.size();
            for (int i=1; i<size; i++) {
                if (stone <= stoneVec.at(i) ) {
                    stoneVec.insert(iter+i, stone);
                    return;
                }
            }
        }
    }

//     void printVector(vector<int> v) {
//         cout << "Vector: ";
//         for (int i : v) {
//             cout << i << " ";
//         }
//         cout << endl;
//     }

};

int main() {
    // #include <iostream>
    // #include <vector>

    // using namespace std;

    Solution s = Solution();
    
    int StonesArr[] = {2,7,4,1,8,1};
    int n = sizeof(StonesArr) / sizeof(StonesArr[0]);
    vector<int> stones(StonesArr, StonesArr + n );    
    
    cout << s.lastStoneWeight(stones);

    return 0;
}