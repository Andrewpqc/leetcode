#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index =1;
        int num =nums[0];
        int nums_count = nums.size();
        for(int i=1;i<nums_count;++i){
            if(nums[i]!=num){
                nums[index++]=nums[i];
            }
        }
        return index;
    }
};


int main(int argc, char** argv){
    Solution s;

    vector<int> v{1,1,2};
    cout<<s.removeDuplicates(v)<<endl;

    return 0;
}