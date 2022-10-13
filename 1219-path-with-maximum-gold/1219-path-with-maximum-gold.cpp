class Solution {
public:
    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,-1,1};
    int rows;
    int cols;
    
    //fromHere(r,c) : grid 상태에서 (r,c)부터 시작해서 얻을 수 있는 골드 최대값
    int fromHere(int r, int c, vector<vector<int>>& grid){
        int result = grid[r][c];
        int temp = grid[r][c];
        grid[r][c] = 0;
        for(int dir = 0; dir<4; dir++){
            int nr = r + dr[dir];
            int nc = c + dc[dir];
            if(nr < 0 || nc < 0 || nr >= rows || nc >= cols)continue;
            if(grid[nr][nc] == 0)continue;
            result = max(result, temp + fromHere(nr, nc, grid));
        }
        grid[r][c] = temp;
        return result;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int answer = 0;
        rows = grid.size();
        cols = grid.front().size();
        for(int i = 0; i<rows; i++){
            for(int j = 0; j<cols; j++){
                if(grid[i][j] == 0)continue;
                answer = max(answer,fromHere(i,j,grid));
            }
        }
        
        return answer;
    }
};