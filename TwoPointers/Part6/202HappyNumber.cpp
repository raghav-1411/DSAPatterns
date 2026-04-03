// Approach 1 -> using extra unordered set due to which we have S.C = O(Logn) 

class Solution {
public:
    long long calculateSum(int n){
        long long ans = 0 ;
        while(n>0){
            ans += ((n%10)*(n%10));
            n /= 10;
        }
        return ans;
    }
    bool isHappy(int n) {
        unordered_set<int> s;
        while(s.find(n)==s.end()){
            s.insert(n);
            n = calculateSum(n);
            if(n==1) return true;
        }
        return false;

    }
};

// Approach 2 -> very good approach using slow and fast pointer no extra space 

class Solution {
public:
    long long sum(int n){
        long long ans = 0 ;
        while(n>0){
            ans += ((n%10)*(n%10));
            n /= 10;
        }
        return ans;
    }
    bool isHappy(int n) {
        int s = n , f = n ;
        while(f!=1){
            s = sum(s);
            f = sum(sum(f));
            if(f==1) return true;
            if(s==f) return false;
        }
        return true;
    }
};


