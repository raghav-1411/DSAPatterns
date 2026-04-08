class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i = 0 , j = 0 ;
        unordered_map<int,int> m;
        int maxLength = 0;

        while(j<fruits.size()){
            m[fruits[j]]++;

            while(m.size()>2){
                maxLength = max(maxLength,j-i);
                m[fruits[i]]--;
                if(m[fruits[i]]==0) m.erase(fruits[i]);
                i++;
            }
            j++;
        }
        maxLength = max(maxLength,j-i);
        return maxLength;
    }
};
