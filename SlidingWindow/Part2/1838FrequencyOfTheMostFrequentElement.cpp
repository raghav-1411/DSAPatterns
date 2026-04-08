class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long sum = 0 ;
        int maxLength = 0 ; 
        int i = 0 , j = 0 ;

        while(j<nums.size()){
            sum += nums[j];

            while(1LL * (j - i + 1) * nums[j] - sum > k){
                sum -= nums[i];
                i++;
            }
            maxLength = max(maxLength,j-i+1);
            j++;

        }

        return maxLength;
    }
};
