#include <bits/stdc++.h>

using namespace std;
typedef struct position{
    int row, col, step;
}position;
queue<position>q;
int main()
{
    int n, m, r, c;
    cin>>n>>m>>r>>c;
    int A[n][m];
    bool visited[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>A[i][j];
        }
    }
    visited[r-1][c-1]=false;
    int dir_x[4]={0, 0, 1, -1};
    int dir_y[4]={1, -1, 0, 0};
    q.push({r-1, c-1, 0});
    while(!q.empty()){
        position cur_pos = q.front();
        q.pop();
        if(cur_pos.row==0||cur_pos.row==n-1||cur_pos.col==0||cur_pos.col==m-1){
            printf("%d\n", cur_pos.step+1);
            break;
        }
        for(int i=0; i<4; i++){
            int next_x = cur_pos.row+dir_x[i];
            int next_y = cur_pos.col+dir_y[i];
            if(A[next_x][next_y]==0){
                if(!visited[next_x][next_y]){
                    q.push({next_x, next_y, cur_pos.step+1});
                }
            }
        }

    }
}
