// Brute Force Approach

class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0 ;

        for(int i=0 ; i<s.size() ; i++){
            vector<int> v(26,0);
            int maxFreq = 0 ;
  
            for(int j=i ; j<s.size() ; j++){
                v[s[j]-'A']++;
                maxFreq = max(maxFreq,v[s[j]-'A']);

                if((j-i+1)-maxFreq<=k) ans = max(ans,j-i+1);
                else break;
            }
        }
        return ans;
    }
};

// Optimised Version :-

class Solution {
public:
    int checkLongest(string s , int k , char ch){
        int i = 0 , j = 0 ;
        int maxLength = 0 ;

        while(j<s.size()){
            if(s[j]==ch) j++;
            else if(s[j]!=ch && k>0){
                j++;
                k--;
            }
            else{
                maxLength = max(maxLength,j-i);
                while(s[i]==ch) i++;
                i++;
                k++;
            }
        }
        maxLength = max(maxLength,j-i);
        return maxLength;
    }
    int characterReplacement(string s, int k) {
        int ans = 0 ; 
        for(int i=0 ; i<26 ; i++){
            ans = max(ans,checkLongest(s,k,i+'A'));
        }
        return ans;
    }
};
