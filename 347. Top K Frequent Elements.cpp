/*
Idea here is to make freq map and then throw that in 
max priority queue. Then get top k elements.
TIME: O(nlogn)
SPACE: O(n)
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for(auto n: nums) hash[n]++;
        
        auto cmp = [&](auto a, auto b){
            return hash[a] < hash[b];
        };
        priority_queue<int, vector<int>, decltype(cmp)> 
            pq(cmp);
        for (auto [key, val]: hash){
            pq.push(key);
        }
        vector<int> result;
        int count = 0;
        while (!pq.empty() && count < k){
            result.push_back(pq.top());
            pq.pop();
            count++;
        }
        
        return result;
    }
};
