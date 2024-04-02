#include<bits/stdc++.h>
using namespace std;
const int NMAX = 1e5+5;
int n;
typedef struct interval{
	int start;
	int end;
}interval;

bool compare(interval i1, interval i2){
	if(i1.end<i2.end) return true;
	else if(i1.end==i2.end){
		if(i1.start>i2.start) return true;
		else return false;
	}
	else return false;
}
int disjoint_segment(vector<interval>&itv){
	sort(itv.begin(), itv.end(), compare);
	int count = 0;
	int current_time = -1;
	for(auto e : itv){
		if(e.start > current_time){
			count++;
			current_time = e.end;
		}
	}
	return count;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("ip.txt", "r", stdin);
	cin>>n;
	vector<interval>itv(n);
	for(int i=0; i<n; i++){
		cin>>itv[i].start>>itv[i].end;
	}
	
	int res = disjoint_segment(itv);
	cout<<res;
}
