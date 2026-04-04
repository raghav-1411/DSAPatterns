// Brute force Approach -> 

class Solution {
public:
    int calIndex(vector<int>& nums , int curr){
        int n = nums.size();
        int next = (curr + nums[curr]) % n;
        if(next < 0) next += n;
        return next;
    }

    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++){
            unordered_set<int> s;
            bool flag = nums[i] > 0;

            int curr = i;

            while(true){
                int next = calIndex(nums, curr);

                if(next == curr) break;

                bool flag2 = nums[next] > 0 ;

                if(flag!=flag2) break;

                if(s.find(next) != s.end()) return true;

                s.insert(curr);   
                curr = next;
            }
        }
        return false;
    }
};

// Optimised Approach :-

class Solution {
public:
    int calInd(vector<int> &nums, int curr) {
        int n = nums.size();
        int next = (curr + nums[curr]) % n;
        if (next < 0) next += n;
        return next;
    }

    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) continue;

            int slow = i, fast = i;

            while (nums[slow] * nums[calInd(nums, fast)] > 0 &&
                   nums[slow] * nums[calInd(nums, calInd(nums, fast))] > 0) {

                slow = calInd(nums, slow);
                fast = calInd(nums, calInd(nums, fast));

                if (slow == fast) {
                    if (slow == calInd(nums, slow)) break;
                    return true;
                }
            }

            int j = i;
            int val = nums[i];

            while (nums[j] * val > 0) {
                int next = calInd(nums, j);
                nums[j] = 0;
                j = next;
            }
        }

        return false;
    }
};


