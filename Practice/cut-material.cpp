#include<bits/stdc++.h>
using namespace std;
const int NMAX = 1e6;
int h[11], w[11];
bool mark[11][11];
int H, W, n;
int x[11], y[11], rotated[11];
void do_mark(int row, int col, int rot, int k, bool mark_value){
	int hk = h[k], wk = w[k];
	if(rot==1){
		hk = w[k];
		wk = h[k]; 
	}
	for(int i=row; i<row+wk; i++){
		for(int j=col; j<col+hk; j++){
			mark[i][j]=mark_value;
		}
	}
}

bool check(int row, int col, int rot, int k){
	int hk = h[k], wk = w[k];
	if(rot==1){
		hk = w[k];
		wk = h[k]; 
	}
	if(row+wk>W) return false;
	if(col+hk>H) return false;
	for(int i=row; i<row+wk; i++){
		for(int j=col; j<col+hk; j++){
			if(mark[i][j]) return false;
		}
	}
	return true;
}

bool TRY(int k){
	int wk = w[k], hk = h[k];
	for(int rot=0; rot<=1; rot++){
		if(rot==1){
			wk = h[k];
			hk = w[k];
		}
		for(int row=0; row<=W-wk; row++){
			for(int col=0; col<=H-hk; col++){
				if(check(row, col, rot, k)){
					x[k] = row;
					y[k] = col;
					rotated[k] = rot;
					do_mark(row, col, rot, k, true);
					if(k==n){
						return true;
					}
					else return TRY(k+1);
					do_mark(row, col, rot, k, false);
				}
			}
		}
	}
	return false;
}

int main(){
	scanf("%d %d %d", &H, &W, &n);
	for(int i=1; i<=n; i++) scanf("%d %d", &h[i], &w[i]);
	bool can_cut = TRY(1);
	if(can_cut) printf("1\n");
	else printf("0\n");
}
