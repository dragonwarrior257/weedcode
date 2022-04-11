
/*
Idea here is to sort the array and compare with original to
find the mismatch position.
TIME: O(nlogn)
SPACE: O(1)
*/
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp(nums.size());
        std::copy(nums.begin(), nums.end(), temp.begin());
        std::sort(temp.begin(), temp.end());
        
        int start=nums.size()-1;
        int end=0;
        for(int i=0; i<nums.size(); i++){
            if (nums[i]!=temp[i]){
                start=std::min(start, i);
                end=std::max(end,i);
            }
        }
        return end-start>0?end-start+1:0;
    }
};
