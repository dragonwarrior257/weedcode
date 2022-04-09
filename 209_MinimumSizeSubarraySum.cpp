/*
* Idea here is to use sliding window technique.
* increase window to reach target and record minlen.
* then decrease the window till it becomes less than
* target and record the min.
* TIME: O(N+N) first to increase, then to decrease= O(N) 
* SPACE: O(1)
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minlen=INT_MAX;
        
        int start=0;
        int sum=0;
        for (int end=0; end < nums.size(); end++){
            sum += nums[end];
            while (start <= end && sum >= target){
                minlen = std::min(minlen, end-start+1);
                sum -= nums[start];
                start++;
            }
        }
        return minlen==INT_MAX?0:minlen;
    }
};

/* Idea here is to use the brute force to calculate all subarray,
* and check for minlen.
* TIME: O(N^2)
* SPACE: O(1)
*/
class SolutionBrute {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minlen=INT_MAX;
        
        for(int i=0; i<nums.size(); i++){
            int sum{};
            for(int j=i; j<nums.size(); j++){
                sum += nums[j];
                if (sum >= target){
                    minlen = std::min(minlen, j-i+1);
                    break;
                }
            }
        }
        return minlen==INT_MAX?0:minlen;
    }
};
