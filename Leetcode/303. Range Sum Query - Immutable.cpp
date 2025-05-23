class NumArray {
    vector<int> arr;
    vector<int> prefix;
public:
    NumArray(vector<int>& nums) {
        int total = 0;
        for(auto i:nums)
        {
            arr.push_back(i);
            total+=i;
            prefix.push_back(total);
        }
    }
    
    int sumRange(int left, int right) {
        return prefix[right] - (left==0 ? 0 : prefix[left-1]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */