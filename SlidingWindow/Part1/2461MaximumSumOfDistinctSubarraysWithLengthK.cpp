class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        long long ans = 0 ;
        long long sum = 0 ;

        for(int i=0 ; i<k ; i++){
            m[nums[i]]++;
            sum += nums[i];
        }

        if(m.size()==k) ans = max(ans,sum);      // means sb unique element hai

        int i = 1 , j = k ;

        while(j<nums.size()){
            m[nums[i-1]]--;
            sum -= nums[i-1];
            sum += nums[j];
            if(m[nums[i-1]]==0) m.erase(nums[i-1]);
            m[nums[j]]++;

            if(m.size()==k) ans = max(ans,sum);    // whenever we encountered map of unique elements only then we will update maxSum;
            i++;
            j++;
        }

        return ans;
    }
};
