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
#include <cmath>
#include <map>
using namespace std;

class Fractal {
public:
    double value;
    std::pair<int, int> fractal;
    Fractal(int a, int b) : fractal(make_pair(a, b)), value(a / float(b)) {}
};

class Solution {
public:
    int getBit(int num, int i, int n) {
        int remain;
        if (i == 1) {
            remain = num % n;
        } else if (i == 2) {
            remain = (num % (n*n)) / n;
        } else {
            remain = num / (n*n);
        }
        return remain;
    }
    void SortNPairs(vector<Fractal>& fractals, int n)
    {
        for (auto it = fractals.begin(); it < fractals.end(); it++) {
            if (it->value == n) {
                fractals.erase(it);
                break;
            }
        }
        vector<int> ceilNums;
        for (int i = 0; i < fractals.size(); i++) {
            if (fractals[i].value == n) {
                continue;
            }
            ceilNums.push_back(fractals[i].value * n * n);
        }
//        for (int j = 0; j < ceilNums.size(); j++) {
//            cout << ceilNums[j] << endl;
//        }
//        cout << endl;
        
        vector<int> orders(n*n);
        for_each(orders.begin(), orders.end(), [&] (int& num) {
            static int i = 0;
            num = i++;
        });
        for (int i = 0; i < 3; i++) {
            vector<int> index(n);
            for (int j = 0; j < ceilNums.size(); j++) {
                int remain = getBit(ceilNums[orders[j]], i+1, n);
                index[remain]++;
            }
            vector<int> acc(n);
            for (int j = 1; j < index.size(); j++) {
                acc[j] = acc[j-1] + index[j-1];
            }
            vector<int> oldOrders = orders;
            for (int j = 0; j < ceilNums.size(); j++) {
                auto bit = getBit(ceilNums[oldOrders[j]], i+1, n);
                orders[acc[bit]++] = oldOrders[j];
            }
//            for (int j = 0; j < ceilNums.size(); j++) {
//                cout << ceilNums[orders[j]] << endl;
//            }
//            cout << endl;
        }
        vector<Fractal> results;
        for (int i = 0; i < orders.size(); i++) {
            if (i == orders.size()-1) {
                results.push_back(Fractal(n, 1));
            } else {
                results.push_back(fractals[orders[i]]);
            }
        }
        fractals = results;
    }
};

//int main() {
//    int n = 7;
//    vector<Fractal> fractals;
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= n; j++) {
//            fractals.push_back(Fractal(i, j));
//        }
//    }
//    random_shuffle(fractals.begin(), fractals.end());
//    Solution sol;
//    sol.SortNPairs(fractals, n);
//    for (int i = 0; i < fractals.size(); i++) {
//        cout << fractals[i].value << endl;
//    }
//    return 0;
//}
