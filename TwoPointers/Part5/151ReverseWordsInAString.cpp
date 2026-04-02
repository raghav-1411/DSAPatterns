// Approach 1 -> 

class Solution {
public:
    string reverseWords(string s) {
        vector<string> v ;
        string temp = "" , ans = "";

        for(int i=0 ; i<s.size() ; i++){
            if(s[i]==32){
                if(temp.size()>0) v.push_back(temp);
                temp = "";
            }
            else temp += s[i];
        }
        if(temp.size()>0) v.push_back(temp);
        reverse(v.begin(),v.end());

        for(int i=0 ; i<v.size() ; i++){
            ans += v[i];
            ans += ' ';
        }

        ans.pop_back();
        return ans;
        

    }
};
