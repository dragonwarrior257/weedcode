/*
Idea here is to first create adjlist.
then check if there is no cycle, as topological sort needs DAG.
then run topological sort to find ordering.
TIME: O(V+E)
SPACE: O(V)
*/
class Solution {
public:
    unordered_map<int, list<int>> adjlist;
    unordered_set<int> visited;
    vector<int> order;
    bool hascycle;
    
    void build_graph(vector<vector<int>>& edges){
        for (auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            adjlist[u].push_front(v);
        }
    }
    void dfs(int v, unordered_set<int> &onstack){
        visited.insert(v);
        onstack.insert(v);
        for (auto w: adjlist[v]){
            if (hascycle) return;
            else if (visited.find(w) == visited.end()){
                dfs(w, onstack);
            }
            else if (onstack.find(w) != onstack.end()){
                hascycle = true;
            }
        }
        onstack.erase(v);
    }
    bool cycle_detection(int numCourses){
        hascycle = false;
        for (int u=0; u < numCourses; u++){
            if (visited.find(u) == visited.end()){
                unordered_set<int> onstack;
                dfs(u, onstack);
            }
        }
        return hascycle;
    }
    void dfs_sort(int u){
        visited.insert(u);
        for (auto w: adjlist[u]){
            if (visited.find(w)==visited.end()){
                dfs_sort(w);
            }
        }
        order.push_back(u);
    }
    void topological_sort(int numCourses){
         visited.clear();
         for (int i=0; i < numCourses; i++){
             if (visited.find(i) == visited.end()){
                 dfs_sort(i);
             }
         } 
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        build_graph(prerequisites);
        
        if (cycle_detection(numCourses)){
            return vector<int>{};
        }
        else{
            topological_sort(numCourses);
            return order;
        }
    }
};
