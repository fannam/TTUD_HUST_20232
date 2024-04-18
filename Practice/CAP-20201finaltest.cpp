#include<bits/stdc++.h>
using namespace std;

int merge_and_count(vector<int>& arr1, int n, vector<int>& arr2, int m) {
    int counter = 0;
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    int i = 0, j = 0, k = 0;
    //vector<int> merged_arr(m + n);
    while (i < n && j < m) {
        if(arr1[i] < arr2[j]) {
            //merged_arr[k++] = arr1[i++];
            k++;
            i++;
        } 
		else if (arr1[i] > arr2[j]) {
            //merged_arr[k++] = arr2[j++];
            k++;
            j++;
        } 
		else {
            //merged_arr[k++] = arr1[i++];
            k++;
            i++;
            j++;
            counter++;
        }
    }
    return counter;
}

int main() {
    int T;
    cin>>T;
    while (T--) {
        int n, m;
        cin>>n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin>>a[i];
        cin>>m;
        vector<int> b(m);
        for(int i = 0; i < m; i++) cin>>b[i];
        cout<<merge_and_count(a, n, b, m)<<endl;
    }
    return 0;
}
