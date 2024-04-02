#include<bits/stdc++.h>
using namespace std;
//We find the min and max of the numbers and then perform binary search within this range
//We then check our nums array to see if there is a continuous subarray with at least length k that has average greater than mid
//If that is the case, we know our average is at least mid, so we set our min to mid
//Otherwise, we set our max to mid
//We build a valid function to check if the nums array has the subarray
//We first accumulate the first k items difference with target, if the sum is greater than 0, we can return true
//Otherwise, we need to see if the remaining elements' difference can form a sum greater than min sum (k elements before or min prev sum encountered so far)
//Time complexity O(nlog(max-min))
//Space complexity O(1)
bool isValid(double mid, vector<int>& nums, int k) {
    double min_sum = 0;
    double cur_sum = 0;
    //check first k elements
    for(int i=0; i<k; ++i){
        cur_sum += nums[i] - mid; 
    }
    if(cur_sum >= 0) return true; 
    double prev_sum = 0;
    //check remaining elements 
    for(int i=k; i<nums.size(); ++i) {
        cur_sum += nums[i] - mid;
        prev_sum += nums[i - k] - mid;
        min_sum = min(min_sum, prev_sum);
        if(cur_sum>=min_sum) return true;
    }
    return false;
}

double findMaxAverage(vector<int>& nums, int k) {
    double l = *min_element(nums.begin(), nums.end());
    double r = *max_element(nums.begin(), nums.end());
    while(r - l > 1e-8){
        double mid = (l + r)/2;
        if(isValid(mid, nums, k)){
            l = mid;
        } 
		else{
            r = mid;
        }
    }
    return l;
}

int main() {
	int n, k;
	cin>>n>>k;
    vector<int>nums(n);
    for(int i=0; i<n; i++) cin>>nums[i];
    printf("%.5lf", findMaxAverage(nums, k));
}
