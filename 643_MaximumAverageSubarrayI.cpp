/*
* Idea here is to use sliding window technique.
* TIME: O(n)
* SPACE: O(1)
*/
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int maxsum = INT_MIN;
        int currsum{};
        int start=0;
        for(int end=0; end < nums.size(); end++){
            currsum += nums[end];
            if (end >= k-1){
                maxsum = std::max(maxsum, currsum);
                currsum -= nums[start];
                start++;
            }
        }
        return (double)maxsum/k;
    }
};

/*
* Idea is to find all possible sum of k items and avg.
* TIME: O(n*k) 
* SPACE: O(1)
*/
class SolutionBrute {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int maxsum = INT_MIN;
        for(int i=0; i<=nums.size()-k; i++){
            int sum{};
            for(int j=i; j< (i+k); j++){
                sum += nums[j];
            }
            maxsum = std::max(maxsum, sum);
        }
        return (double)maxsum/k;
    }
};
