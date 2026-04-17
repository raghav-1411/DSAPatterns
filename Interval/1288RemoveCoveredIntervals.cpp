// Brute Force Approach :- T.C = O(n^2) & S.C = O(1)

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int count = 0 ;

        for(int i=0 ; i<intervals.size() ; i++){
            int a = intervals[i][0] , b = intervals[i][1];
            bool isCovered = false;

            for(int j=0 ; j<intervals.size() ; j++){
                int c = intervals[j][0] , d = intervals[j][1];

                if(i!=j && (c<=a && b<=d)){
                    isCovered = true;
                }
            }

            if(!isCovered) count++;
        }
        return count;
    }
};

// Optimsed Approach :- T.C = O(nlogn) & S.C = O(n)

bool cmp(vector<int>& a , vector<int>& b){
    if(a[0]==b[0]) return a[1] > b[1];
    return a[0] < b[0];
}
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        vector<vector<int>> temp;
        temp.push_back(intervals[0]);

        for(int i=1 ; i<intervals.size() ; i++){
            if(temp[temp.size()-1][0]<=intervals[i][0] && intervals[i][1]<=temp[temp.size()-1][1]) continue;
            
            else temp.push_back(intervals[i]);
        }
        return temp.size();

    }
};

// Goat Approach -> T.C = O(nlogn) & S.C = O(1)

bool cmp(vector<int>& a, vector<int>& b) {
    if (a[0] == b[0])
        return a[1] > b[1];
    return a[0] < b[0];
}
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int maxEnd = intervals[0][1];
        int ans = 1;

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][1] > maxEnd) {
                maxEnd = intervals[i][1];
                ans++;
            }
        }
        return ans;
    }
};
