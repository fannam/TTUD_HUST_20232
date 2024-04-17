#include<iostream>
#include<vector>
using namespace std;

const int NMAX = 1001;
int f0[NMAX], f1[NMAX];
//f0: ket thuc tai 0, f1: ket thuc tai 1
void init(int K1, int K2){
	f0[1] = 1;
	f1[1] = 0;
	for(int i=2; i<K1; i++){
		f0[i] = f1[i] = 0;
	}
	f0[K1] = 0;
	f1[K1] = 1;
	f0[K1+1] = 1;
	f1[K1+1] = 2;
}

int schedule(int n, int K1, int K2){
	init(K1, K2);
	for(int i=K1+2; i<=K2; i++){
		f0[i] = f1[i-1];
		int tmp = 0;
		for(int j=K1; j<=K2; j++){
			if(i-j>=1){
				tmp+=f0[i-j];
			}
		}
		f1[i] = tmp+1;
	}
	for(int i=K2+1; i<=n; i++){
		f0[i] = f1[i-1];
		int tmp = 0;
		for(int j=K1; j<=K2; j++){
			if(i-j>=1){
				tmp+=f0[i-j];
			}
		}
		f1[i] = tmp;
	}
	return f0[n]+f1[n];
}
int main(){
    int n, K1, K2;
    cin>>n>>K1>>K2;
    cout<<schedule(n, K1, K2)<<endl;
}
