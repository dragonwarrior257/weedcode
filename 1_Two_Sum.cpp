// https://leetcode.com/problems/two-sum/

/*
 * BRUTE force: we check all the possible pairs in the array.
 * TIME: O(n^2) as there are n*n pairs to check.
 * SPACE: O(1)
 */

class Solution_brute {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> result;
        for (int i = 0; i < nums.size(); i++){
            for (int j = i+1; j < nums.size(); j++){
                int sum = nums[i] + nums[j];
                if (sum == target){
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
    }
};

/*
 * FAST: we use hashmap to store complement of number.
 * as per problem there always exist a pair (x, y) such that
 * x+y = target. So, if (target-x)=y is not in hashmap we add x to hashmap
 * and when (target-y)=x is searched we will find it in hashmap.
 * we keep hashmap of number vs position. 
 * TIME: O(n) as whole array is traversed once.
 * SPACE: O(n) as max element on hashmap will full array. 
 **/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> result;
        std::unordered_map<int, int> table;
        for (int i=0; i<nums.size(); i++){
            int val = target-nums[i];
            auto search = table.find(val);
            // if we found the complement return.
            if (search != table.end()){
                result.push_back(i);
                result.push_back(search->second);
                return result;
            }
            // insert it in hashmap
            else {
                table[nums[i]] = i;
            }
        }
        return result;
    }
};
