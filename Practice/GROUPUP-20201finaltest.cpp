#include<bits/stdc++.h>
using namespace std;

int solve(deque<int>&dq){
	int total_time = 0;
	while(dq.size()!=1){
		if(dq.size()%2==0){
			int itr = dq.size()/2;
			int max_section = -1;
			while(itr--){
				int top1 = dq.front();
				dq.pop_front();
				int top2 = dq.front();
				dq.pop_front();
				int newtop = top1+top2;
				max_section = max(max_section, newtop);
				dq.push_back(newtop);
			}
			total_time += max_section;
		}
		else{
			int itr = dq.size()/2;
			int max_section = -1;
			while(itr--){
				int top1 = dq.front();
				dq.pop_front();
				int top2 = dq.front();
				dq.pop_front();
				int newtop = top1+top2;
				max_section = max(max_section, newtop);
				dq.push_back(newtop);
			}
			total_time += max_section;
			int last = dq.front();
			dq.pop_front();
			dq.push_back(last);
		}
	}
	return total_time;
}

int main(){
	int T;
	cin>>T;
	while(T-->0){
		int n, tmp;
		deque<int>dq;
		cin>>n;
		for(int i=0; i<n; i++){
			scanf("%d", &tmp);
			dq.push_back(tmp);
		}
		cout<<solve(dq)<<endl;
	}
}
