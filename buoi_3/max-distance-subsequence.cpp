#include<bits/stdc++.h>
using namespace std;

bool can_place_c_elements(int arr[], int mid, int n, int c){
	int cur_pos = arr[0];
	int count = 1;
	for(int i=1; i<n; i++){
		if(arr[i] - cur_pos >= mid){
			cur_pos = arr[i];
			count++;
			if(count==c) return true;
		}
	}
	return false;
}

int max_distance_subsequence(int arr[], int n, int c){
	sort(arr, arr+n);
	int max_distance = -1;
	int left = 0;
	int right = arr[n-1]-arr[0];
	while(left<right){
		int mid = (left+right)/2;
		if(can_place_c_elements(arr, mid, n, c)){
			max_distance = max(max_distance, mid);
			left = mid + 1;
		}
		else right = mid;
	}
	return max_distance;
}
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int n, c;
		scanf("%d %d", &n, &c);
		int arr[n];
		for(int i=0; i<n; i++) scanf("%d", &arr[i]);
		printf("%d\n", max_distance_subsequence(arr, n, c));
	}
}
