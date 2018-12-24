class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current_sum = INT_MIN;
        int greatest_sum = INT_MIN;
        
        for(auto num: nums){
            if(current_sum<0){
                current_sum = num;
            }else{
                current_sum += num;
            }
            
            if(current_sum > greatest_sum){
                greatest_sum = current_sum;
            }
        }
        return greatest_sum;
        
    }
};