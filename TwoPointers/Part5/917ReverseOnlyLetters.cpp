class Solution {
public:
    bool check(char ch){
        if((ch>=65 && ch<=90) || (ch>=97 && ch<=122)) return true;
        return false;
    }
    string reverseOnlyLetters(string s) {
        int i = 0 , j = s.size()-1;

        while(i<j){
            if(check(s[i]) && check(s[j])){
                swap(s[i],s[j]);
                i++;
                j--;
            }
            else if(check(s[j])){
                i++;
            }
            else j--;
        }
        return s;
    }
};
