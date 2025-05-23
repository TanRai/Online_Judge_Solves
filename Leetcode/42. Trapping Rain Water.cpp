class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> leftmax(height.size());
        vector<int> rightmax(height.size());

        int L=0;
        int max = 0;
        while(L<height.size())
        {
            max = std::max(max,height[L]);
            leftmax[L] = max;
            L++;
        }
        int R = height.size()-1;
        max = 0;
        while(R>=0)
        {
            max = std::max(max,height[R]);
            rightmax[R] = max;
            R--;
        }
        int amount = 0;
        for(int i=0;i<height.size();i++)
        {
            amount+= std::max(min(leftmax[i],rightmax[i])-height[i],0);
        }

        return amount;
    }
};