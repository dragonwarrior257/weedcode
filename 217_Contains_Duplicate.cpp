//https://leetcode.com/problems/contains-duplicate/

/*
Brute Force: 
We pick element one by one and search it in rest of array.
This Brute force solution cause time limit exceed.
TIME = O(n^2)
SPACE = O(1)

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        for(int i=0; i < nums.size(); i++){
            for (int j=i+1; j < nums.size(); j++){
                if (nums[j]==nums[i]) return true;
            }
        }
        return false;
    }
};
*/

/*
Fast solution:
we pick an element and search in hash.
if it does not exist, insert the element in hash.
else element is found in hash (means duplicate)
so return true.
TIME: O(n)
SPACE: O(n)
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> hash;
        for(auto& num: nums){
            if (hash.find(num) != hash.end()){
                return true;
            }
            else{
                hash.insert(num);
            }
        }
        return false;
    }
};

