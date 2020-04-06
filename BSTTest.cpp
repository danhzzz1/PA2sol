#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unordered_set>
#include "BST.h"
using namespace std;

/**
 * Define messages for use in the tester
 */
#define MESSAGE_SUCCESS "Success"
#define MESSAGE_WRONG_SIZE "Incorrect size"
#define MESSAGE_FALSE_NEGATIVE "BST find returned false when element actually existed"
#define MESSAGE_FALSE_POSITIVE "BST find returned true when element didn't actually exist"

/**
 * Test BST class using numbers from standard input
 */
int main() {
    // randomly sample a bunch of integers
    srand(time(NULL));
    unordered_set<int> nums;
    while(nums.size() < 100) {
        nums.insert((rand() % 10000) - 5000);
    }

    // create and populate BST
    BST bst;
    unsigned int count = 0;
    for(int num : nums) {
        bst.insert(num);
        if(bst.size() != ++count) {
            cout << MESSAGE_WRONG_SIZE << endl;
            return 1;
        }
    }

    // clear and repopulate BST
    bst.clear();
    count = 0;
    for(int num : nums) {
        bst.insert(num);
        if(bst.size() != ++count) {
            cout << MESSAGE_WRONG_SIZE << endl;
            return 1;
        }
    }

    // check if numbers exist
    for(int num : nums) {
        if(!bst.find(num)) {
            cout << MESSAGE_FALSE_NEGATIVE << endl;
            return 1;
        }
    }

    // check numbers that shouldn't exist
    for(int i = 0; i < 100; ++i) {
        int num = (rand() % 10000) - 5000;
        while(nums.find(num) != nums.end()) {
            num = (rand() % 10000) - 5000;
        }
        if(bst.find(num)) {
            cout << MESSAGE_FALSE_POSITIVE << endl;
            return 1;
        }
    }

    // if it didn't fail yet, success!
    cout << MESSAGE_SUCCESS << endl;
    return 0;
}
