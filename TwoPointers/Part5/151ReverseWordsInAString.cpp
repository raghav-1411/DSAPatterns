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

// Approach 2 ->

class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int l = 0 , r = s.size()-1;

        while(s[l]==32) l++;
        while(s[r]==32) r--;

        for(int i=l ; i<=r ; i++){
            if(s[i]!=32) ans += s[i];
            else{
                if(ans[ans.size()-1]!=32) ans += s[i];
            }
        }

        reverse(ans.begin(),ans.end());

        int i = 0 , j = 0;

        while(j<ans.size()){
            if(ans[j]==32){
                reverse(ans.begin()+i,ans.begin()+j);
                j++;
                i = j ;
            }
            else j++;
        }
        reverse(ans.begin()+i,ans.end());
        return ans;

    }
};

// Best Approach -> In place sorting :-

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();

        reverse(s.begin(), s.end());

        int i = 0, j = 0;

        while (j < n) {
            while (j < n && s[j] == ' ') j++;

            if (j >= n) break;

            if (i > 0){                // because we want one space after each word we are doing it before because afterwards we will do reverse
                s[i] = ' ';
                i++;
            }

            int start = i;
            while (j < n && s[j] != ' ') {
                s[i] = s[j];
                i++;
                j++;
            }

            reverse(s.begin() + start, s.begin() + i);
        }
        
        s.resize(i);        // limit the string to size i!! 

        return s;
    }
};
