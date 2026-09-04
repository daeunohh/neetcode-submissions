class Solution {
public:
    vector<vector<int>> visited; 

    int func(vector<vector<int>>& grid, int i, int j, int cntPath){
        if(grid[i][j] == 1 || visited[i][j]) return cntPath;
        visited[i][j] = 1;

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};


        // cout << "b " << i << " " << j << " " << cntPath << endl;

        int c = 0;
        for(int d=0; d<4; d++){
            if(i+dx[d] < 0 || i+dx[d] >= grid.size() || j+dy[d] < 0 || j+dy[d] >= grid[0].size() || grid[i+dx[d]][j+dy[d]] == 1) 
                continue;
            c += func(grid, i+dx[d], j+dy[d], cntPath);
            // cout << "d:"<< i << " " << j << " " << i+dx[d] << " " << j+dy[d] << " " << c << endl;
        }
        cntPath += c;

        if(i == grid.size()-1 && j == grid[0].size() - 1){
            cntPath = 1;
        }
        // cout << "a " << i << " " << j << " " << cntPath << endl;
        visited[i][j] = 0;
        return cntPath;
    }
    
    int countPaths(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            auto tmp = vector<int>(grid[0].size());
            visited.push_back(tmp);
        }
        // cout << visited[1].size() << endl;
        return func(grid, 0, 0, 0);
    }
};
