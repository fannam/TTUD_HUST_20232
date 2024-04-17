#include<bits/stdc++.h>
using namespace std;
const int NMAX = 60;
int d[NMAX][NMAX];
vector<int>x(NMAX);
vector<int>res(NMAX);
int a[NMAX];
int d_min = 1e9;
int a_max = 0;
bool visited[NMAX];
int n, Q;
int record = 1e9;
int cur_Q = 0;
int cur_distance = 0;
int final_Q = 0;
void TRY(int k){
	for(int v=1; v<=n; v++){
		if(!visited[v]){
			x[k] = v;
			visited[v] = true;
			cur_Q += a[v];
			cur_distance += d[x[k-1]][v];
			if(cur_Q>=Q){
				if(record > cur_distance+d[v][0]){
					record = cur_distance+d[v][0];
					res = x;
				}
			}
			else{
				if(cur_distance+(n-k+1)*d_min<record && cur_Q+(n-k)*a_max>=Q) TRY(k+1);
			}
			cur_Q -= a[v];
			visited[v] = false;
			cur_distance -= d[x[k-1]][v];
			x[k]=0;
		}
	}
}
int main(){
	cin>>n>>Q;
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
		a_max = max(a_max, a[i]);
	}
	for(int i=0; i<=n; i++){
		for(int j=0; j<=n; j++){
			scanf("%d", &d[i][j]);
			if(i!=j){
				d_min = min(d_min, d[i][j]);
			}
		}
	}
	x[0] = 0;
	TRY(1);
	int i=1;
	if(record==1e9) cout<<"-1";
	else{
		while(i<=n&&res[i]!=0){
		cout<<res[i++]<<" ";
		}
		cout<<endl<<record;
	}
}
