#include <bits/stdc++.h>

using namespace std;
int matrix[1000][1000];
int hist[1000][1000];
int max_area = 0;
int cur_area;
stack<int>st;
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            cin>>matrix[i][j];
        }
    for(int i=0; i<n; i++){
        hist[0][i]=matrix[0][i];
    }
    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j]==1) hist[i][j]=hist[i-1][j]+1;
            else hist[i][j]=0;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(st.empty()||hist[i][st.top()]<=hist[i][j]){
                st.push(j++);
            }
            else{
                int top = st.top();
                st.pop();
                cur_area = hist[i][top] * (st.empty()?j:j-st.top()-1);
                max_area = max(max_area, cur_area);
            }
            while(!st.empty()){
                int top = st.top();
                st.pop();
                cur_area = hist[i][top] * (st.empty()?j:j-st.top()-1);
                max_area = max(max_area, cur_area);
            }
        }
    }
    cout<<max_area;
}
