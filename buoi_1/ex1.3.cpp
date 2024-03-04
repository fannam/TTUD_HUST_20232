#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;
int a[MAXN];
int M[21][MAXN];
void preprocessor(int M[21][MAXN], int a[], int n) {
    for (int i = 0; i < n; i++)
        M[0][i] = i;
    for (int j = 1; (1<<j)<=n; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            int left_half = M[j-1][i];
            int right_half = M[j-1][i + (1 << (j - 1))];
            if (a[left_half] < a[right_half])
                M[j][i] = left_half;
            else
                M[j][i] = right_half;
        }
    }
}
int query(int L, int R) {
    int k = log2(R - L + 1);
    return min(a[M[k][L]], a[M[k][R-(1<<k)+1]]);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    preprocessor(M, a, n);

    int num_query, sum = 0;
    cin>>num_query;
    while(num_query!=0){
        num_query--;
        int i, j;
        cin>>i>>j;
        sum+=query(i, j);
    }
    cout<<sum<<"\n";

    return 0;
}
