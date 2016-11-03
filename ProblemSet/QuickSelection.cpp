//
//  QuickSelection.cpp
//  ProblemSet
//
//  Created by Neil on 9/14/16.
//  Copyright © 2016 Neil. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int DirectNth(vector<int> vec, int s, int e, int pos)
{
    nth_element(vec.begin()+s, vec.begin()+s+pos, vec.begin()+e);
    
    return *(vec.begin()+s+pos);
}

int QuickSelection(vector<int> vec, int pos)
{
    if (vec.size() <= 10) {
        return DirectNth(vec, 0, (int)vec.size(), pos);
    }
    vector<vector<int>> groups;
    vector<int> groupMiddles;
    for (int i = 0; i < vec.size(); i += 5) {
        vector<int> group(vec.begin() + i, vec.begin() + i + 5);
        sort(group.begin(), group.end());
        groups.push_back(group);
        groupMiddles.push_back(group[2]);
    }
    int partition = QuickSelection(groupMiddles, (int)groupMiddles.size()/2);
    std::partition(groups.begin(), groups.end(), [partition](const vector<int>& group) {
        return group[2] < partition;
    });
    vector<int> min, mid, max;
    for (int i = 0; i < groups.size(); i++) {
        auto group = groups[i];
        if (i < groups.size() / 2) {
            for (int j = 0; j < 5; j++) {
                if (j <= 2) {
                    min.push_back(group[j]);
                } else {
                    mid.push_back(group[j]);
                }
            }

        } else if (i > groups.size() / 2) {
            for (int j = 0; j < 5; j++) {
                if (j >= 2) {
                    max.push_back(group[j]);
                } else {
                    mid.push_back(group[j]);
                }
            }
        } else {
            for (int j = 0; j < 5; j++) {
                if (j > 2) {
                    max.push_back(group[j]);
                }
                if (j < 2) {
                    min.push_back(group[j]);
                }
            }
        }
    }
    int partition_rank = (int)min.size();
    for (auto num : mid) {
        if (num < partition) {
            partition_rank++;
        }
    }
    if (partition_rank == pos) {
        return partition;
    } else if (partition_rank < pos) {
        auto left = mid;
        left.insert(left.end(), max.begin(), max.end());
        return QuickSelection(left, pos - partition_rank - 1);
    } else {
        auto left = mid;
        left.insert(left.end(), min.begin(), min.end());
        return QuickSelection(left, partition_rank - pos - 1);
    }
}


//int main()
//{
//    // must be dividable by 5
//    vector<int> arr(25, 0);
//    generate(arr.begin(), arr.end(), []() {
//        static int i = 0;
//        return i++;
//    });
//    random_shuffle(arr.begin(), arr.end());
//    cout << QuickSelection(arr, 12) << endl;
//    return 0;
//}
