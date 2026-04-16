bool cmp(vector<int>& a , vector<int>& b){
    if(a[0]==b[0]) return a[1] < b[1];
    return a[0] < b[0] ; 
}
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end(),cmp);
        vector<vector<int>> temp;
        int n = meetings.size();
        temp.push_back(meetings[0]);

        int ans = 0 ;

        ans += (meetings[0][0]-1);

        for(int i=1 ; i<n ; i++){
            if(temp[temp.size()-1][1]>=meetings[i][0]){
                temp[temp.size()-1][0] = min(temp[temp.size()-1][0],meetings[i][0]);
                temp[temp.size()-1][1] = max(temp[temp.size()-1][1],meetings[i][1]);
            }
            else temp.push_back(meetings[i]);
        }

        for(int i=0 ; i<temp.size()-1 ; i++){
            ans += (temp[i+1][0]-temp[i][1]-1);
        }
        ans += (days-temp[temp.size()-1][1]);

        
        return ans;
    }
};
