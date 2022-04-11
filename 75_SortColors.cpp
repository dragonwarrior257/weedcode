/*
Idea here is to use the 3 way partition method from quicksort.
TIME: O(n)
SPACE: O(1)
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lt=0;
        int gt=nums.size()-1;
        int i=lt;
        
        while (i<=gt){
            if (nums[i] < 1){
                std::swap(nums[i++], nums[lt++]);
            }
            else if(nums[i]>1){
                std::swap(nums[i], nums[gt--]);
            }
            else i++;
        }
    }
};
