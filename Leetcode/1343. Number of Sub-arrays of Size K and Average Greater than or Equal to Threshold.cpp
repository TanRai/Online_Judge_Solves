class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        if(arr.size()<k)
            return 0;

        int res = 0;
        int L = 0;
        int sum = 0;
        for(int R=0;R<arr.size();R++)
        {
            sum+=arr[R];
            if(R-L+1 > k)
            {
                sum-=arr[L];
                L++;
            }
            if(sum/k >= threshold && R>=k-1)
                res++;
        }
        return res;
    }
};