#include <bits/stdc++.h>
using namespace std;
const int NMAX = 1e6+1;
int n, L1, L2;
int a[NMAX];
int dp[NMAX];

int findMax(int left, int right, int &cur_idx){
	if(left<=cur_idx){
		//cout<<cur_idx;
		if(dp[cur_idx]<=dp[right]){
			cur_idx = right;
			return dp[right];
		}
		else{
			return dp[cur_idx];
		}
	}
	else{
		int maximal = 0;
		//cout<<cur_idx;
		for(int i=left; i<=right; i++){
			if(dp[i]>maximal){
				maximal = dp[i];
				cur_idx = i;
			}
		}
		return maximal;
	}
}

int main() {
	int res=0;
	cin>>n>>L1>>L2;
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	dp[0]=0;
	for(int i=1; i<=L1; i++){
		dp[i] = a[i];
	}
	int cur_index = 0;
	for(int i=L1+1; i<=n; i++){
		int x = findMax(i-L2, i-L1, cur_index);
		dp[i] = x + a[i];
		res = max(res, dp[i]);
	}
	cout<<res;
}
