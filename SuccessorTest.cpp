#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <set>
#include "BST.h"
using namespace std;

/**
 * Define messages for use in the tester
 */
#define MESSAGE_SUCCESS "Success"
#define MESSAGE_INCORRECT "Your successor() function returned the wrong node"
#define MESSAGE_PREMATURE_NULL "Your successor() function returned NULL too early"
#define MESSAGE_NOT_NULL_AT_END "Your successor() function was not NULL when we expected it to be (at the end)"

/**
 * Test BST class using numbers from standard input
 */
int main() {
    // randomly sample a bunch of integers
    srand(time(NULL));
    set<int> nums;
    while(nums.size() < 100) {
        nums.insert((rand() % 10000) - 5000);
    }

    // create and populate BST
    BST bst;
    for(int num : nums) {
        bst.insert(num);
    }

    // test successor
    BST::Node* curr = bst.getLeftMostNode();
    for(int num : nums) {
        if(curr == nullptr) {
            cout << MESSAGE_PREMATURE_NULL << endl;
            return 1;
        }
        if(curr->data != num) {
            cout << MESSAGE_INCORRECT << endl;
            return 1;
        }
        curr = curr->successor();
    }
    if(curr != nullptr) {
        cout << MESSAGE_NOT_NULL_AT_END << endl;
        return 1;
    }

    // if it didn't fail yet, success!
    cout << MESSAGE_SUCCESS << endl;
    return 0;
}
