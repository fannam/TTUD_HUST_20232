#include<bits/stdc++.h>
using namespace std;

const int NMAX = 1e6+5;
long long a[NMAX];
long long dp[NMAX][2];

long long max_even_subsequence(int n){
	long long res = INT_MIN;
	if(a[0]%2==0){
		dp[0][0] = a[0];
		dp[0][1] = INT_MIN;
	}
	else {
		dp[0][1] = a[0];
		dp[0][0] = INT_MIN;
	}
	for(int i=1; i<n; i++){
		if(a[i]%2==0){
			dp[i][0] = max(a[i], dp[i-1][0] + a[i]);
			dp[i][1] = dp[i-1][1] + a[i];
		}
		else{
			dp[i][0] = dp[i-1][1] + a[i];
			dp[i][1] = max(a[i], dp[i-1][0] + a[i]);
		}
		res = max(res, dp[i][0]);
	}
	if(res==INT_MIN) return -1;
	return res;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	cout<<max_even_subsequence(n);
	
}
