//给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
//
//请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
//
//你可以假设 nums1 和 nums2 不会同时为空。
//
//示例 1:
//
//nums1 = [1, 3]
//nums2 = [2]
//
//则中位数是 2.0
//示例 2:
//
//nums1 = [1, 2]
//nums2 = [3, 4]
//
//则中位数是 (2 + 3)/2 = 2.5


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        vector<int> sum_vec;
        int len1 = nums1.size();
        int len2 = nums2.size();
        if (len1 == 0) {
            sum_vec = nums2;
        } else if (len2 == 0) {
            sum_vec = nums1;
        } else {
            int i = 0, j = 0;
            while (i < len1 && j < len2) {
                if (nums1[i] < nums2[j]) {
                    sum_vec.push_back(nums1[i]);
                    ++i;
                }

                if (nums1[i] > nums2[j]) {
                    sum_vec.push_back(nums2[j]);
                    ++j;
                }
            }

            if (i == len1) {
                while (j < len2) {
                    sum_vec.push_back(nums2[j]);
                    ++j;
                }
            }

            if (j == len2) {
                while (i < len1) {
                    sum_vec.push_back(nums1[i]);
                    ++i;
                }
            }

        }

        int sum_len = sum_vec.size();
        if (sum_len % 2 == 0) {
            return (sum_vec[sum_len / 2 - 1] + sum_vec[sum_len / 2]) / double(2);
            //偶数
        } else {
            //奇数
            return sum_vec[(sum_len - 1) / 2];
        }

    }
};


int main() {
    Solution s;
    vector<int> a = {2, 3};
    vector<int> b = {1};
    vector<int> c = {4, 5};
    cout << s.findMedianSortedArrays(a, b) << endl;
    cout << s.findMedianSortedArrays(a, c) << endl;
    return 0;
}