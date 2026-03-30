class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";

        for(int i=0 ; i<s.size() ; i++){
            if(s[i]>=97 && s[i]<=122) temp += s[i];
            else if(s[i]>=65 && s[i]<=90) temp += (s[i]+32);
            else if(s[i]>='0' && s[i]<='9') temp += s[i];
        }

        int i = 0 , j = temp.size()-1;

        while(i<j){
            if(temp[i]!=temp[j]) return false;
            i++;
            j--;
        }

        return true;
    }
};
