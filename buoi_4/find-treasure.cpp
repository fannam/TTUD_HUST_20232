#include<bits/stdc++.h>
using namespace std;

typedef struct Treasure{
	int x;
	int y;
	int amount;
}Treasure;

long long find_treasure(vector<Treasure> &treasures, int n){
	vector<long long>dp(n);
	for(int i=0; i<n; i++){
		dp[i] = treasures[i].amount;
	}
	for(int i=1; i<n; i++){
		for(int j=0; j<i; j++){
			if(treasures[i].x>=treasures[j].x && treasures[i].y>=treasures[j].y){
				dp[i] = max(dp[i], dp[j] + treasures[i].amount);
			}
		}
	}
	long long maxGold = 0;
	for(int i=0; i<n; i++){
		maxGold = max(maxGold, dp[i]);
	}
	return maxGold;
}

int main(){
	int n;
	scanf("%d", &n);
	vector<Treasure>treasures(n);
	for(int i=0; i<n; i++){
		scanf("%d %d %d", &treasures[i].x, &treasures[i].y, &treasures[i].amount);
	}
	sort(treasures.begin(), treasures.end(), [](Treasure t1, Treasure t2){
		if(t1.x==t2.x) return t1.y<t2.y;
		return t1.x<t2.x;
	});
	cout<<find_treasure(treasures, n);
}
