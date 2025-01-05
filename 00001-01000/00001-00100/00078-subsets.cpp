/* medium :: backtracking */
/*
    This function generates all possible subsets (the power set) of a given array of
    unique integers. It uses backtracking to explore all combinations by either including
    or excluding each element. Duplicate subsets are avoided as elements are unique, and
    the function guarantees all subsets are returned.
    - -                       - -
    Time  :: O(2^N * N) ::    0ms = 2^N subsets, each requiring up to O(N) to copy.
    Space :: O(N)       :: 8.30MB = Temporary storage for subsets during recursion.
*/
class Solution {
public:
    // Solution entrypoint :: - -                                                      - -
    vector<vector<int32_t>> subsets( vector<int32_t>& nums )
    {
        vector<vector<int32_t>> ret;
        vector<int32_t>         subset;
        backtrack( nums, 0, subset, ret );
        return ret;
    }

    // Backtracking Utility Function :: - -                                            - -
    void backtrack(
        vector<int32_t>&         nums,
        const int32_t&           start,
        vector<int32_t>&         subset,
        vector<vector<int32_t>>& ret )
    {
        ret.push_back( subset );
        for ( int32_t i = start; i < nums.size(); i++ )
        {
            subset.push_back( nums[i] );
            backtrack( nums, i + 1, subset, ret );
            subset.pop_back();
        }
    }
};

//  End. :: - -                                                                        - -