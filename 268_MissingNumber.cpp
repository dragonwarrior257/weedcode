/*
using the xor property.
TIME: O(n)
SPACE: O(1)
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=0;
        for (int i=0; i <= nums.size(); i++){
            n ^= i;
        }
        int m=0;
        for (auto k: nums){
            m ^= k;
        }
        return n^m;
    }
};
/*
Idea here is to sort the array so that index to value mapping is done.
then compare the index and value, if different we found mismatch.
TIME: O(nlogn)
SPACE: O(1)
*/
class SolutionSort {
public:
    int missingNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int i;
        for ( i=0; i < nums.size(); i++){
            if (i != nums[i]) return i;
        }
        return i==nums.size()? nums.size(): -1;
    }
};

/*
Idea here is to use the cyclic sort which uses the fact that number
are in range 0-n. then compare the elements for mismatch.
TIME: O(n) + O(n) = O(n)
SPACE: O(1)
*/
class Solution {
public:
    void cyclesort(vector<int>& nums){
        int i=0;
        while (i <nums.size()){
            if (nums[i] < nums.size() && i != nums[i]){
                std::swap(nums[i], nums[nums[i]]);
            }
            else{
                i++;
            }
        }
    }
    int missingNumber(vector<int>& nums) {
        cyclesort(nums);
        int i;
        for ( i=0; i < nums.size(); i++){
            if (i != nums[i]) return i;
        }
        return i==nums.size()? nums.size(): -1;
    }
};
