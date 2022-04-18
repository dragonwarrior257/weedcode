/*
idea is to use dfs to find cycle in graph.
TIME: O(V+E) it is proportional to sum of all outgoing vertex in visited set.
SPACE: O(V)
*/
class Solution {
public:
    unordered_map<int, list<int>> adjlist;
    unordered_set<int> visited;
    bool cycle;
    
    void create_graph(unordered_map<int, list<int>>& adjlist,
                     vector<vector<int>>& edges){
        for (auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            adjlist[u].push_front(v);
        }
    }
    void dfs(int v, unordered_set<int>& onstack){
        visited.insert(v);
        onstack.insert(v);
        for (auto w: adjlist[v]){
            if (cycle == true) return;
            else if (visited.find(w) == visited.end()){
                dfs(w, onstack);
            }
            else if(onstack.find(w) != onstack.end()){
                cycle = true;
                return;
            }
        }
        //unwind elements from onstack as dfs return.
        onstack.erase(v);
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {  
        cycle = false;
        // create adjlist graph from edges.
        create_graph(adjlist, prerequisites);
        // start dfs on the graph to find cycle.
        for (int i=0; i < numCourses; i++){
            if (visited.find(i) == visited.end()){
             // set to keep track of visited node in current dfs run,
            // and to check for back,by checking on stack.
             unordered_set<int> onstack;
             dfs(i, onstack);   
            }
        }
        return !cycle;
    }
};
