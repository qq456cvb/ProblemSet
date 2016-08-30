//
//  MedianInTwoSortedArrays.cpp
//  ProblemSet
//
//  Created by Neil on 8/28/16.
//  Copyright © 2016 Neil. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int getNumber(const vector<int>& v, int idx)
    {
        if (idx < 0) {
            return 0x80000000; // negative infinity
        }
        if (idx >= v.size()) {
            return 0x7fffffff; // infinity
        }
        return v[idx];
    }
    
    int findkth(vector<int>& a, vector<int>& b, int k, int asize, int bsize)
    {
        int l = 0;
        int h = asize;
        
        while (l <= h) {
            int mid = (l+h)/2;
            if (getNumber(a, mid) < getNumber(b, k-mid-2)) {
                l = mid+1;
            } else if (getNumber(a, mid-1) > getNumber(b, k-mid-1)) {
                h = mid-1;
            } else {
                return min(getNumber(a, mid), getNumber(b, k-mid-1));
            }
        }
        return 0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = (int)nums1.size(), size2 = (int)nums2.size();
        if (size1 > size2) {
            return findMedianSortedArrays(nums2, nums1);
        } else {
            if ((size1+size2)%2 == 1) {
                return findkth(nums1, nums2, (size1+size2+1)/2, size1, size2);
            } else {
                return ((double)findkth(nums1, nums2, (size1+size2) / 2, size1, size2)
                        + (double)findkth(nums1, nums2, (size1+size2) / 2 + 1, size1, size2)) / 2;
            }
        }
            
    }
};

//int main () {
//    vector<int> a = {1};
//    vector<int> b = {};
//    Solution solution;
//    cout << solution.findMedianSortedArrays(a, b) << endl;;
//}
