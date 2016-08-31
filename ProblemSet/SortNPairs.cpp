//
//  SortNPairs.cpp
//  ProblemSet
//
//  Created by Neil on 8/29/16.
//  Copyright © 2016 Neil. All rights reserved.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Fractal {
    double value;
    std::pair<int, int> fractal;
};

// no way of O(N) time and O(N) space solution?
class Solution {
public:
    void SortNPairs(vector<std::pair<int, int>>& pairs, int n)
    {
        vector<double> decimalNums;
        // O(n)
        for (int i = 0; i < pairs.size(); i++) {
            decimalNums.push_back(pairs[i].first / (double)pairs[i].second);
        }
        
        //count sort, at most O(N*lgn)
        double minDiff = 1. / n;
        int digitCnt = 1;
        double precision = 1.;
        while (precision > minDiff) {
            precision /= 10;
            digitCnt++;
        }
        
        
    }
};

int main() {
    Fractal a;
    a.value = 1.;
    Fractal b;
    b = a;
    return 0;
}
