/*
idea here is each index is uniquely mapped to value.
if index to value is not mapped, we will try to put value to correct index,
but if while exchanging that index is already having correct value, 
then this value is duplicate.
TIME: O(n) 
SPACE: O(1)
*/
class Solution {
public:
    
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        int i=0;
        while (i < nums.size()){
            if (i+1 != nums[i] && nums[i] != nums[nums[i]-1]){
                std::swap(nums[i], nums[nums[i]-1]);
            }
            else i++;
        }
        for(int i=0; i < nums.size(); i++){
            if (nums[i] != i+1) result.push_back(i+1);
        }
        
        return result;
    }
};
/*
Idea here is to sort the numbers and then check each number from 1-n
using binary search in sorted array.
TIME: O(nlogn)
SPACE: O(1)
*/
class SolutionBinarysearch {
public:
    
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        std::sort(nums.begin(), nums.end());
        for (int i=0; i < nums.size(); i++){
            if (!std::binary_search(nums.begin(), nums.end(), i+1)){                              result.push_back(i+1);
            }
        }
        return result;
    }
};
