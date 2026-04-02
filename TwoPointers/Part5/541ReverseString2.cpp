class Solution {
public:
    string reverseStr(string s, int k) {
        int i = 0 , j = 0 ;

        while(j<s.size()){
            if(j-i==k){
                reverse(s.begin()+i,s.begin()+j);
                j += k;
                i = j;
            }
            else j++;
        }
        reverse(s.begin()+i,s.begin()+j);
        return s;
    }
};
