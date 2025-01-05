/* easy :: tree */
/*
    Check children summed values
    against the root value.
    - -                  - -
    Time  :: O(1) ::     0ms
    Space :: O(1) :: 15.26MB
*/
class Solution {
public:
    // Solution entrypoint :: - -                                                      - -
    bool checkTree( TreeNode* r ) { return r->val == r->left->val + r->right->val; }
};
//  End. :: - -                                                                        - -