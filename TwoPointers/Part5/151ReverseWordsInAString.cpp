// Approach 1 -> 

class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string t = "";
        for(int i = 0 ; i<s.size() ; i++){
            if(s[i]!=' '){
                t+=s[i];
            }
            else{
                v.push_back(t);
                t = "";
            }
        }
        v.push_back(t);
        vector<string> ans;
        for(int i=0 ; i<v.size() ; i++){
            if(v[i]!="") ans.push_back(v[i]);
        }
        reverse(ans.begin(),ans.end());
        s = "";
        for(int i=0 ; i<ans.size() ; i++){
            s+=ans[i];
            s+=' ';
        }
        s.pop_back();
        return s;
    }
};
