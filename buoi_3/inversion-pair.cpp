#include<bits/stdc++.h>
using namespace std;

const int NMAX = 1e6+5;
const int modulo = 1e9+7;
int n;
int a[NMAX];

int merge(int arr[], int left, int mid, int right){
    long long inversion_pair = 0;
    int left_subarr_size = mid - left + 1;
    int right_subarr_size = right - mid;
    int L[left_subarr_size], R[right_subarr_size];
    for(int i=0; i<left_subarr_size; i++) L[i] = arr[left+i];
    for(int j=0; j<right_subarr_size; j++) R[j] = arr[mid+1+j];
    int i=0, j=0;
    int k = left;
    while(i<left_subarr_size && j<right_subarr_size){
        if(L[i]<=R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
            inversion_pair += (mid - left + 1 - i); 
            inversion_pair %= modulo;
        }
        k++;
    }
    //neu 1 nua het phan tu
    while(i<left_subarr_size){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<right_subarr_size){
        arr[k] = R[j];
        j++;
        k++;
    }
    return inversion_pair;
}

int merge_sort(int arr[], int left, int right){
    long long res = 0;
    if(left>=right) return 0;
    else{
        int mid = left + (right - left)/2;
        res += merge_sort(arr, left, mid);
        res += merge_sort(arr, mid+1, right);
        res += merge(arr, left, mid, right);
    }
    return res%modulo;
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    long long inversion_pair = merge_sort(a, 0, n-1);
    cout<<inversion_pair<<endl;
}
