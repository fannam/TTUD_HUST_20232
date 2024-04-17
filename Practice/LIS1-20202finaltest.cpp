#include<bits/stdc++.h>
using namespace std;
//mp[arr[j]] = j neu ton tai arr[j] trong mang voi j<i
//nguoc lai mp[arr[j]] = 0
int longest_increase_subsequence_by_one(vector<int>&arr, int n){
	if(n==1) return 1;
	int res = -1;
	map<int, int>mp;
	vector<int>dp(n+1);
	dp[1] = 1;
	mp[arr[1]] = 1;
	for(int i=2; i<=n; i++){
		mp[arr[i]] = i;
		int j = mp[arr[i]-1];
		if(j!=0){
			dp[i] = 1 + dp[j];
		}
		else dp[i] = 1;
		res = max(res, dp[i]);
	}
	return res;
}

int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		vector<int>arr(n+1);
		for(int i=1; i<=n; i++){
			scanf("%d", &arr[i]);
		}
		cout<<longest_increase_subsequence_by_one(arr, n)<<endl;
	}
}
