
// https://leetcode.com/problems/longest-consecutive-sequence/

/*
TIME: O(nlgn) but can be improved to O(n) amortized with path compression
*/
class unionfind{
    private:
    vector<int> id;
    vector<int> sz;
    int cnt;
    public:
    unionfind(int N): cnt{N}{
        id.resize(N);
        sz.resize(N);
        for (int i=0; i<N; i++){
            id[i]=i;
            sz[i]=1;
        }
    }
    void uni(int p, int q){
        int proot = find(p);
        int qroot = find(q);
        if (proot==qroot) return;
        
        if (sz[proot] < sz[qroot]){
            id[proot]=qroot;
            sz[qroot] += sz[proot];
        }
        else {
            id[qroot] = proot;
            sz[proot] += sz[qroot];
        }
        cnt--;
    }
    int find(int p){
        while (p != id[p]){
            p = id[p];
        }
        return p;
    }
    int maxsize(){
        int maxcc = numeric_limits<int>::min();
        for (int i=0; i<sz.size(); i++){
            maxcc = std::max(maxcc, sz[i]);
        }
        return maxcc==numeric_limits<int>::min() ? 0: maxcc;
    }
};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> hash;
        unionfind cc(nums.size());
        
        for (int i=0; i<nums.size(); i++){
            if (hash.find(nums[i]) != hash.end()) continue;
            
            hash[nums[i]] = i;
            
            if (hash.find(nums[i]+1) != hash.end()){
                cc.uni(i, hash[nums[i]+1]);
            }
            if (hash.find(nums[i]-1) != hash.end()){
                cc.uni(i, hash[nums[i]-1]);
            }
        }
        return cc.maxsize();
    }
};
