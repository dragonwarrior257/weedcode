/*
Idea here is to use the maxheap priority queue.
such that it will store k smallest element.
if coming element is smaller than top element take out top, and push this.
TIME: O(nlogk)
SPACE: O(k)
*/
class Solution {
public:
    std::function<bool(vector<int>, vector<int>)>cmp = 
        [](vector<int> a, vector<int> b){
        int d1 = a[0]*a[0] + a[1]*a[1];
        int d2 = b[0]*b[0] + b[1]*b[1];
        return d1 < d2;
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>,
        vector<vector<int>>,
        decltype(cmp)> pq(points.begin(), points.begin()+k, cmp);
        
        for (int i=k; i < points.size(); i++){
            int d = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            auto ii = pq.top();
            if (d < (ii[0]*ii[0] + ii[1]*ii[1])){
                pq.pop();
                pq.push(points[i]);
            }
        }
        vector<vector<int>> result;
        while (!pq.empty()){
            result.push_back(pq.top());
            pq.pop();
        }
        return result;
    }
};

/*
Idea here is to simply sort the array and get first k element.
TIME: O(nlogn)
SPACE: O(1)
*/
class Solutionbrute {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(),
            [](auto a, auto b){
              int d1 = a[0]*a[0] + a[1]*a[1];
              int d2 = b[0]*b[0] + b[1]*b[1];
                return d1 < d2;
            });
        vector<vector<int>> result;
        for (int i=0; i < k; i++){
            result.push_back(points[i]);
        }
        return result;
    }
};
