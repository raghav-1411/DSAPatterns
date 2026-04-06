class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size() ; 
        if(n==0) return 0;
        int i = 0 , j = 0 , ans = 0;
        unordered_map<char,int> m;
        while(j<n){
            m[s[j]]++;
            while(m[s[j]]>1){
                m[s[i]]--;
                i++;
            }
            j++;
            ans = max(ans,j-i);
        }
        return ans;
    }
};
