#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int len = nums.size();

        while(i<len){
            if(nums[i]==val){
                nums[i]=nums[len-1];
                --len;
            }else ++i;
        }

        return len;
        
    }
};


int main(int argc, char** argv){
    Solution s;

    vector<int> v {1,2,0,5,3,1,5,2,8};
    int len =s.removeElement(v,2);
    for(int i =0;i<len; ++i){
        cout<<v[i]<<" ";
    }
    cout<<endl;


    return 0;
}