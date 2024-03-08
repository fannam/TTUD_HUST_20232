#include<bits/stdc++.h>
using namespace std;
int X[30];
int c[30][30];
bool visited[30];
int current_capacity = 0;
int current_distance = 0;
int record = 1e9;
int n, k;
void TRY(int t){
	for(int city=1; city<=2*n; city++){
		if(!visited[city]){
			X[t] = city;
			current_distance += c[X[t-1]][city];
			visited[city] = true;
			//dieu kien dung
			if(t==2*n && city>n && visited[city-n]){
				if(current_capacity==1){
					record = min(record, current_distance + c[city][0]);
				}
			}
			//don khach
			else if(city<=n){
				if(current_capacity<k && current_distance<record){
					current_capacity++;
					TRY(t+1);
					current_capacity--;
				}
			}
			//tra khach
			else if(city>n){
				//neu da don nguoi muon xuong o city
				if(visited[city-n] && current_distance<record){
					current_capacity--;
					TRY(t+1);
					current_capacity++;
				}
			}
			X[t] = 0;
			current_distance -= c[X[t-1]][city];
			visited[city] = false;
		}
	}
}

int main() {
	X[0]=0;
	scanf("%d %d", &n, &k);
	for(int i=0; i<=2*n; i++){
		for(int j=0; j<=2*n; j++){
			scanf("%d", &c[i][j]);
		}
	}
	TRY(1);
	cout<<record;
}
	
