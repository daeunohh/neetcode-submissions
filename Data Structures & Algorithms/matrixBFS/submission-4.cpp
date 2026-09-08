class Solution {
public:
    int X; int Y;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    int shortestPath(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;

        X = grid.size(); Y = grid[0].size();

        unordered_set<string> visit;
        queue<pair<int, int>> q;
        q.push({0,0});
        visit.insert("0,0");

        int len = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                auto cell = q.front();
                q.pop();
                int x = cell.first; int y = cell.second;
                if(x == X-1 && y == Y-1) return len;

                vector<vector<int>> dxys = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

                for(auto& dxy : dxys){
                    int dx = dxy[0]; int dy = dxy[1];
                    if(min(x + dx, y + dy) < 0 || (x+dx) == X || (y+dy) == Y || \
                        visit.find(to_string(x+dx) + ',' + to_string(y+dy)) != visit.end() || \
                        grid[x+dx][y+dy] == 1) continue;

                    q.push({x+dx, y+dy});
                    visit.insert(to_string(x+dx) + ',' + to_string(y+dy));
                }
            }
            len++;
        }
        return -1;
    }
};
