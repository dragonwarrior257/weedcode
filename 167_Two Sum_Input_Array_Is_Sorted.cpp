/*
 * Since array is sorted, we will use two pointer technique.
 * one pointer to first and second to last. 
 * if sum of first and last is equal to target, then return.
 * if sum of first and last is greater than target, we will decrement
 * last pointer to reduce sum and bring it close to target.
 * if sum of first and last is smaller than target, we will increment
 * first pointer to bring it close to target.
 * TIME: O(n)
 * SPACE: O(1)
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size()-1;
        vector<int> result;
        
        // i < j because if i==j then we cannot get two index.
        while (i < j){
            int sum = numbers[i] + numbers[j];
            if (sum == target){
                result.push_back(i+1);
                result.push_back(j+1);
                return result;
            }
            else if (sum < target) i++;
            else j--;
        }
        return result;
    }
};
