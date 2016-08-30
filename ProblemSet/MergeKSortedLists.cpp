//
//  MergeKSortedLists.cpp
//  ProblemSet
//
//  Created by Neil on 8/28/16.
//  Copyright © 2016 Neil. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void mySwap(ListNode** a, ListNode** b)
{
    ListNode* temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(ListNode* arr[], int idx, int len)
{
    int parentIdx = idx;
    int childIdx = 2*idx+1;
    while (childIdx < len) {
        if (childIdx+1 < len) {
            if (arr[childIdx+1]->val < arr[childIdx]->val) {
                childIdx++;
            }
        }
        if (arr[parentIdx]->val > arr[childIdx]->val) {
            // need adjustment
            mySwap(&arr[parentIdx], &arr[childIdx]);
            parentIdx = childIdx;
            childIdx = 2*parentIdx+1;
        } else {
            return;
        }
    }
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *iter = nullptr, *result = nullptr;
        
        // construct heap
        int k = static_cast<int>(lists.size());
        if (k == 0) {
            return iter;
        }
        ListNode* heap[10000];
        int cnt = 0;
        for (int i = 0; i < k; i++) {
            if (lists[i]) {
                heap[cnt++] = lists[i];
            }
        }
        
        k = cnt;
        if (k == 0) {
            return iter;
        }
        for (int i = k / 2 - 1; i >= 0; i--) {
            minHeapify(heap, i, k);
        }
        
        
        int min = heap[0]->val;
        while (min != 0x7fffffff) {
            if (!iter) {
                iter = new ListNode(min);
            } else {
                iter->next = new ListNode(min);
                iter = iter->next;
            }
            
            if (result == nullptr) {
                result = iter;
            }
            heap[0] = heap[0]->next;
            if (heap[0] == nullptr) {
                heap[0] = new ListNode(0x7fffffff);
            }
            minHeapify(heap, 0, k);
            min = heap[0]->val;
        }
        return result;
    }
};