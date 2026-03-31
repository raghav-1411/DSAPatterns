// Strobogrammatic number -> means after rotating 180 degree the number is same

/*
  0 after 180° rotation : (0 → 0)
1 after 180° rotation : (1 → 1)
8 after 180° rotation : (8 → 8)
6 after 180° rotation : (6 → 9)
9 after 180° rotation : (9 → 6)

*/

#include <iostream>
#include <vector>
#include <string>
#include<unordered_map>
using namespace std;
unordered_map<char,char> m = 
      {{'1','1'},{'9','6'},{'6','9'},{'8','8'},{'0','0'}};
      
bool check(string s){
  int i = 0 , j = s.size()-1;
    
  while(i<j){
    if(m.find(s[i])!=m.end()){
        if(m[s[i]]!=s[j]) return false;
    }
    else return false;
    i++;
    j--;
      
  }
  return true;
}
    


int main() {
    string s = "198861";     
    
    if(check(s)) cout<<"Yes it is a Strobogrammatic number";
    else cout<<"No it is not a Strobogrammatic number";

    return 0;
}
