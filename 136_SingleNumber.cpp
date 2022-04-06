/*
* Idea here is to use XOR because XOR of same number is zero.
*TIME: O(n)
*SPACE: O(1)
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for (auto num: nums){
            x ^= num;
        }
        return x;
    }
};
