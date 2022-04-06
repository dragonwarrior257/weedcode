/*
* Idea here is to use priority queue to store the elements,
* becasue at every step we are picking largest of top two , 
* and priority queue is exact data structure that does well.
* TIME: O(nlogn) heapify + O(nlogn) pop elements = O(nlogn).
* SPACE: O(n)
*/
class Solution {
public:
    std::priority_queue<int> pq;
    int lastStoneWeight(vector<int>& stones) {
        //heapify
        for (auto stone: stones) pq.push(stone);
        // run the loop till zero or one element is left.
        while (pq.size()>1){
            int larger = pq.top();
            pq.pop();
            int large = pq.top();
            pq.pop();
            if (large == larger){
                continue;
            }
            else{
                pq.push(larger-large);
            }
        }
        //check if zero or one element is left.
        if (pq.size() == 0) return 0;
        else return pq.top();
    }
};
