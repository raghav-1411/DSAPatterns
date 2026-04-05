class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int sum = 0;
        
        for(int i=0 ; i<k ; i++) sum += arr[i];
        
        int i=1 , j = k;
        int maxSum = sum;
        
        while(j<arr.size()){
            sum += arr[j];
            sum -= arr[i-1];
            maxSum = max(maxSum,sum);
            i++;
            j++;
        }
        
        return maxSum;
    }
};
