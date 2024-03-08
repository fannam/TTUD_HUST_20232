#include<iostream>
#define MAX 100000
int x[MAX];
int t[MAX];
int a[MAX];
int n, M;
//void solution(){
//	for(int i=1; i<=n; i++){
//		printf("%d ", x[i]);
//	}
//	printf("\n");
//}
int counter = 0;
bool check(int v, int k){
	t[k]=t[k-1]+v*a[k];
	if(t[k]>M) return false;
	return true;
}
void Try(int k){
	for(int v=1; v<=M; v++){
		if(check(v,k)){
			x[k]=v;
			if(k==n){
				if(t[k]==M) counter++;
			}
			else Try(k+1); 
		}
	}
}
int main(){
	t[0]=0;
	x[0]=0;
	scanf("%d %d", &n, &M);
	for(int i=1; i<=n; i++) 
		scanf("%d", &a[i]);
	Try(1);
	printf("%d", counter);
}
