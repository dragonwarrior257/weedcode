/*
Idea here is to use xor trick which i dont know how it works.
TIME: O(n)
SPACE: O(1)
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long n=0;
        for (auto v: nums) n ^= v;
        
        // get rightmost bit set true mask.
        long rsb = n & -n;
        
        int num1=0;
        int num2=0;
        // lost me here .. dont know why this work.
        for (auto k: nums){
            if ((k & rsb) == 0) num1 ^= k;
            else num2 ^= k;
        }
        return vector<int>{num1, num2};
    }
};
/*
Idea here is to sort the sequence and skip same elements.
TIME: O(nlogn) + O(n) = O(nlogn)
SPACE: O(1)
*/
class Solutionsort {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> result;
        sort(nums.begin(), nums.end());
        int i=0;
        while (i < nums.size()){
            if (i+1 < nums.size()){
                if (nums[i]==nums[i+1]) i += 2;
                else result.push_back(nums[i++]);
            }
            else{
                result.push_back(nums[i++]);
            }
        }
        return result;
    }
};
