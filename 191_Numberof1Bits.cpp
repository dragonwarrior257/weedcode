/*
* TIME: O(n)
* SPACE: O(1)
*/class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt=0;
        while (n){
            if (n & 0x1) cnt++;
            n = n >> 1;
        }
        return cnt;
    }
};
