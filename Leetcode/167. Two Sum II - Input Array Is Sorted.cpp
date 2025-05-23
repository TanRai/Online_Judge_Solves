class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int L = 0;
        int R = numbers.size() - 1;
        vector<int> arr(2);
        while(L<R)
        {
            if(numbers[L]+numbers[R] == target)
                break;
            
            if(numbers[L]+numbers[R] > target)
                R--;

            if(numbers[L]+numbers[R] < target)
                L++;
        }
        arr[0] = L+1;
        arr[1] = R+1;
        return arr;
    }
};