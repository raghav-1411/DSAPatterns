// Approach 1 -> T.C = O(nlogn) & S.C = O(n)

class Solution {
public:
    static bool cmp(vector<int>& a , vector<int>& b){
        return a[0] < b[0];
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end(),cmp);
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        for(int i=1 ; i<intervals.size() ; i++){
            if(intervals[i][0]<=result[result.size()-1][1]){
                result[result.size()-1][0] = min(intervals[i][0],result[result.size()-1][0]);
                result[result.size()-1][1] = max(intervals[i][1],result[result.size()-1][1]);
            }
            else result.push_back(intervals[i]);
        }
        return result;

        
    }
};

// Optimised Approach -> T.C = O(n) & S.C = O(n)

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> temp;
        bool check = false;

        for(int i=0 ; i<intervals.size() ; i++){
            if(intervals[i][0]>newInterval[0] && !check){
                temp.push_back(newInterval);
                check = true;
            }
            temp.push_back(intervals[i]);
        }
        if(!check) temp.push_back(newInterval);

        vector<vector<int>> ans;
        ans.push_back(temp[0]);

        for(int i=1 ; i<temp.size() ; i++){
            if(ans[ans.size()-1][1]>=temp[i][0]){
                ans[ans.size()-1][1] = max(ans[ans.size()-1][1],temp[i][1]);
                ans[ans.size()-1][0] = min(ans[ans.size()-1][0],temp[i][0]);
            }
            else ans.push_back(temp[i]);
        }
        return ans;
    }
};
