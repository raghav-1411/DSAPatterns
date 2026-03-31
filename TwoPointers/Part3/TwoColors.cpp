#include <iostream>
#include <vector>
using namespace std;
void display(vector<int>& nums){
    for(int i=0 ; i<nums.size() ; i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

int main() {
    vector<int> nums = {0,1,1,1,0,0,1,1};
    int i = 0 ;
    int j = nums.size()-1;
    
    cout<<"Before Sorting :- ";
    display(nums);
    
    while(i<j){
        if(nums[i]==0) i++;
        if(nums[j]==1) j--;
        else if(nums[i]==1 && nums[j]==0){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
    }
    
    cout<<"After Sorting :- ";
    display(nums);

    return 0;
}
