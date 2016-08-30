//
//  LargestSequenceSum.cpp
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
    vector<int> FindLargestSequenceSum(vector<int>& arr)
    {
        vector<int> result;
        
        // if all negative
        int max = 0x80000000, max_i = -1;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > max) {
                max = arr[i];
                max_i = i;
            }
        }
        if (max <= 0) {
            result.push_back(arr[max_i]);
            return result;
        }
        
        int sum = 0, max_sum = 0;
        int start = 0, end = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (sum + arr[i] < 0) {
                end = i-1;
                sum = 0;
            } else {
                if (sum == 0) {
                    start = i;
                }
                sum += arr[i];
                if (sum > max_sum) {
                    max_sum = sum;
                    end = i;
                }
            }
        }
        
        for (int i = start; i <= end; i++) {
            result.push_back(arr[i]);
        }
        return result;
    }
};

int main () {
    Solution sol;
    vector<int> a = {1, 4, -6, 2,3,2,9};
    auto result = sol.FindLargestSequenceSum(a);
    for_each(result.begin(), result.end(), [](int& num){
        cout << num << endl;
    });
}
