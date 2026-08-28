class Graph {
public:
    unordered_map<int, vector<int>> graph;
    Graph() {}

    void addEdge(int src, int dst) {
        if(graph.find(src) != graph.end()){
            graph[src].push_back(dst);
        }
        else{
            graph[src] = {dst};
        }
        // cout << "graph " << src;
        // for(auto d : graph[src]) cout << d << " ";
        // cout << endl;
    }

    bool removeEdge(int src, int dst) {
        if(graph.find(src) != graph.end()){
            vector<int>& dstsFromSrc = graph[src];
            auto it = std::find(dstsFromSrc.begin(), dstsFromSrc.end(), dst); 
            if(it != dstsFromSrc.end()){
                dstsFromSrc.erase(it); 
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }

    bool hasPath(int src, int dst) {
        set<int> visited = {src};
        deque<int> q = {src};
        // return true;
        while(!q.empty()){
            for (int x : q) cout << x << " ";
            int current = q.front();
            q.pop_front();

            if(current == dst) return true;
            // if(visited.find(current) != visited.end()) return false;

            if(graph.find(current) == graph.end()){  // no current node in the graph 
                continue;
            }
            vector<int>& dstsFromSrc = graph[current];
            for(auto it = dstsFromSrc.begin(); it != dstsFromSrc.end(); it++){
                if(visited.find(*it) != visited.end()) continue;
                visited.insert(*it);
                q.push_back(*it);
            }
        }
        return false;
    }
};
