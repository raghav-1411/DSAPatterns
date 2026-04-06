class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0 ;
        double ans = INT_MIN ;

        for(int i=0 ; i<k ; i++){
            sum += nums[i];
        }

        ans = max(ans,1.0*sum/k);
      
        int i = 1 , j = k;
      
        while(j<nums.size()){
            sum += nums[j];
            sum -= nums[i-1];
            
            ans = max(ans,1.0*sum/k);
            i++;
            j++;

        }
        return ans;

    }
};
