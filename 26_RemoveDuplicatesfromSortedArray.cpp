/* Idea here is to use 2 pointer technique.
* first pointer keep track where to insert,
* second pointer traverse the array and keep comparing with
* first pointer. if difference is observed, copy next to first
* pointer.
* TIME: O(n)
* SPACE: O(1)
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        int i=0;
        for (int j=i+1; j<nums.size(); j++){
            if (nums[j]==nums[i]) continue;
            else{
                nums[++i] = nums[j];
            }
        }
        return i+1;
    }
};
