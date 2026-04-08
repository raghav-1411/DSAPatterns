class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        long long sum = 0 ;
        int count = 0 ;

        for(int i=0 ; i<k ; i++) sum += arr[i];

        if((1.0*sum/k)>=threshold) count++;

        int i = 1 , j = k ;

        while(j<arr.size()){
            sum -= arr[i-1];
            sum += arr[j];
            if((1.0*sum/k)>=threshold) count++;
            i++;
            j++;
        }
        return count;

    }
};
