/*
TIME: O(nk)
SPACE: O(k)
*/
class Solution {
private:
    double median(vector<long>& v){
        if (v.size()%2!=0) return (double)v[v.size()/2];
        else return (double)(v[v.size()/2]+v[v.size()/2-1])/2;
    }
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() < k) return vector<double>{};
        
        // keep window of size k and sort first k element.
        vector<long> window(nums.begin(), nums.begin()+k);
        sort(window.begin(), window.end());
        
        vector<double> result;
        
        int start=0;
        for (int end=start+k-1; end < nums.size(); end++){
            if (end-start+1 > k){
                // find median of window and update result.
                double med = median(window);
                result.push_back(med);
                // when window is slided, remove first element. O(k);
                auto it = find(window.begin(), window.end(), nums[start]);
                window.erase(it);
                // insert next element of window. O(k);
                auto itt= lower_bound(window.begin(), window.end(), nums[end]);
                window.insert(itt, nums[end]);
                start++;
            }
        }
        // add last window median.
        result.push_back(median(window));
        return result;
    }
};
