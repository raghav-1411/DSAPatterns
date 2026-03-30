class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        if(word==abbr) return true;

        int i = 0 , j = 0;

        while(i<word.size() && j<abbr.size()){

            if(isdigit(abbr[j])){
                if(abbr[j]=='0') return false;         // if there are leading zeroes not valid mentioned in the qu !!
                int curr = 0 ;

                while(j<abbr.size() && isdigit(abbr[j])){      // form the number 
                    curr *= 10;
                    curr += (abbr[j]-'0');
                    j++;
                }

                i += curr;        
            }
            else{
                if(word[i]!=abbr[j]) return false;    // if the characters are not equal
                i++;
                j++;
            }
            
        }
        return i==word.size() && j==abbr.size();
    }
};
