class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0 ; i<nums.size() ; i++){
            while(i<nums.size() && i>0 && nums[i]==nums[i-1]) i++;
            for(int j=i+1 ; j<nums.size() ; j++){
                while(j<nums.size() && j>i+1 && nums[j]==nums[j-1]) j++;
                int k = j+1;
                int l = nums.size()-1;

                while(k<l){
                    long long sum = 1LL * nums[i] + nums[j] + nums[k] + nums[l];

                    if(sum==target){
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;

                        while(k<l && nums[k]==nums[k-1]) k++;

                    }
                    else if(sum>target) l--;
                    else k++;
                }
            }
        }

        return ans;
    }
};
