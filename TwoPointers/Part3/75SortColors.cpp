// Remember the concept ->

/*

0 to low-1 -> containing 0's
low-1 to mid-1 -> containing 1's
mid+1 to high -> 0/1/2
high+1 to n-1 -> containing 2's

*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0 , mid = 0 , high = nums.size()-1;

        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid]==1) mid++;
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }

    }
};
