class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0 , fast = 0 ;

        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];

            if(slow==fast) break;
        }

        int temp = 0;

        while(temp!=slow){
            slow = nums[slow];
            temp = nums[temp];
        }
        return slow;
    }
};
