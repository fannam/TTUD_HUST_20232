#include <bits/stdc++.h>
using namespace std;
int A[1000][1000];
bool visited[1000][1000];
typedef struct position{
    int row, col, step;
}position;
queue<position>q;

int BFS(int m, int n, int r, int c){
    visited[r-1][c-1]=false;
    int dir_x[4]={0, 0, 1, -1};
    int dir_y[4]={1, -1, 0, 0};
    q.push({r-1, c-1, 0});
    while(!q.empty()){
        position cur_pos = q.front();
        q.pop();
        if(cur_pos.row==0||cur_pos.row==n-1||cur_pos.col==0||cur_pos.col==m-1){
            return cur_pos.step+1;
        }
        for(int i=0; i<4; i++){
            int next_x = cur_pos.row+dir_x[i];
            int next_y = cur_pos.col+dir_y[i];
            if(A[next_x][next_y]==0){
                if(!visited[next_x][next_y]){
                    q.push({next_x, next_y, cur_pos.step+1});
                    visited[next_x][next_y]=true;
                }
            }
        }
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, r, c;
    cin>>n>>m>>r>>c;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>A[i][j];
        }
    }
    cout<<BFS(m,n,r,c);
}
