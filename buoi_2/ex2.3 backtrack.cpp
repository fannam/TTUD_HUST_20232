#include<bits/stdc++.h>
using namespace std;
vector<int>canTeach[40];//danh sach mon hoc giao vien i co the day 
vector<int>conflict[40];//danh sach cac mon hoc trung gio voi mon hoc i 
int m, n;//m giao vien, n mon hoc
int X[40]; //X[i] la giao vien day mon hoc i
int max_load = 1e9;
int counter[40];
bool check(int v, int p){//giao vien v, mon hoc p
	//kiem tra gv co the day
	bool can_teach_1 = false, can_teach_2 = true;
	for(auto element:canTeach[v]){
		if(element==p){
			can_teach_1 = true;
			break;
		}
	}
	//kiem tra gv co bi trung lich khong
	for(auto element:conflict[p]){
		if(X[element]==v){
			can_teach_2 = false;
			break;
		}
	}
	return can_teach_1 && can_teach_2;
}
bool check_max(int v, int p){
	if(counter[v]<max_load-1) return true;
	return false;
}
void TRY(int p, int cur_max_load){//mon hoc p
	for(int v=1; v<=m; v++){//giao vien v
		if(check(v, p) && check_max(v, p)){
			X[p] = v;
			counter[v]++;
			cur_max_load = max(cur_max_load, counter[v]);
			if(p==n){
				max_load = min(max_load, cur_max_load);
			}
			else TRY(p+1, cur_max_load);
			X[p] = 0;
			counter[v]--;
		}
	}
	
}

int main(){
	scanf("%d %d", &m, &n);
	for(int i=1; i<=m; i++){
		int k;
		scanf("%d", &k);
		for(int j=0; j<k; j++){
			int tmp;
			scanf("%d", &tmp);
			canTeach[i].push_back(tmp);
		}
	}
  int k;
	scanf("%d", &k);
	for(int i=0; i<k; i++){
		int u,v;
		scanf("%d %d", &u, &v);
		conflict[u].push_back(v);
		conflict[v].push_back(u);
	}
	TRY(1, 0);
	if(max_load == 1e9) cout<<-1<<endl;
	else cout<<max_load<<endl;
}
