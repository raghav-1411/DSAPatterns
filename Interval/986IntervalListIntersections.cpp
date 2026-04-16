class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i = 0 , j = 0 ;
        vector<vector<int>> ans;

        while(i<firstList.size() && j<secondList.size()){
            int start = max(firstList[i][0],secondList[j][0]);
            int end = min(firstList[i][1],secondList[j][1]);
            if(firstList[i][1] >= secondList[j][0] && firstList[i][1] <= secondList[j][1]){
                ans.push_back({start,end});
            }
            else if(secondList[j][1] >= firstList[i][0] && secondList[j][1] <= firstList[i][1]){
                ans.push_back({start,end});
            }
            if(i!=firstList.size()-1 && firstList[i+1][0]<=secondList[j][1]) i++;
            else j++;

            // OR

            /*
            if(firstList[i][1]<=secondList[j][1]) i++;
            else j++;
            */
        }
        return ans;
    }
};
