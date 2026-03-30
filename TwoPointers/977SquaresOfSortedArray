class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        int k = nums.size()-1;

        int i = 0 , j = nums.size()-1;

        while(i<=j){
            int left = nums[i] * nums[i];
            int right = nums[j] * nums[j];

            if(left<right){
                ans[k] = right ; 
                j--;
            }
            else{
                ans[k] = left;
                i++;
            }
            k--;
        }
        return ans;
    }
};
