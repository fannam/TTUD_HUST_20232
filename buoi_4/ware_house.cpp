#include<bits/stdc++.h>
using namespace std;
const int NMAX = 1001;
const int TMAX = 101;
int a[NMAX], t[TMAX];
int dp[TMAX][NMAX];
int res = -1;
int maximum_amount(int N, int T, int D){
	for(int i=1; i<=T; i++){
		for(int j=1; j<=N; j++){
			if(t[j]>i) dp[i][j] = 0;
			else{
				dp[i][j] = a[j];
				int T_left = i - t[j];
				if(T_left>0){
					int cur_max = -1;
					int idx = -1;
					for(int k=1; k<=D; k++){
						cur_max = max(cur_max, dp[T_left][j-k]);
					}	
					dp[i][j] += cur_max;
				}
			}
			res = max(res, dp[i][j]);
		}
	}
	return res;
}

int main(){
	int N, T, D;
	cin>>N>>T>>D;
	for(int i=1; i<=N; i++) scanf("%d", &a[i]);
	for(int i=1; i<=N; i++){
		scanf("%d", &t[i]);
	}
	cout<<maximum_amount(N, T, D);

}
