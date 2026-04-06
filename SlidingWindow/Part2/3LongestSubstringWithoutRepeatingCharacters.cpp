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

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        int maxLength = 1;
        unordered_map<char,int> m;

        int i = 0 , j = 0 ; 
         
        while(j<s.size()){
            while(m.find(s[j])!=m.end()){
                maxLength = max(maxLength,j-i);
                m[s[i]]--;
                if(m[s[i]]==0) m.erase(s[i]);
                i++;
            }
            m[s[j]]++;
            j++;
        }
        maxLength = max(maxLength,j-i);

        return maxLength;
    }
};
