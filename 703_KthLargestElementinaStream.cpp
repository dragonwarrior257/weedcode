/*
* Idea is to use the min priority queue and keep size to k.
* such that we have top K elements in the queue with kth element
* at the top of queue.
* TIME: O(nlogn) heapify + O((n-k)logn) resizing to k + O(logn) adding val = O(nlogn).
* SIZE: O(k) at anypoint of time there are k element in priority queue.
*/
class KthLargest {
public:
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    int K;
    KthLargest(int k, vector<int>& nums)
    :pq{nums.begin(), nums.end()}, K{k}{
        while (pq.size()>k){
            pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        while (pq.size()>K) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
