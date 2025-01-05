/* hard :: array */
/*
    Essentially, look for the next greater element to the right and left of some
    ith position. Use a left array interating forward, and a right array iterating back.
    - -                  - -
    Time  :: O(N) ::     0ms
    Space :: O(N) :: 23.02MB
*/
class Solution {
public:
    // Solution entrypoint :: - -                                                      - -
    int trap( vector<int>& height )
    {
        const int32_t   n = height.size();
        vector<int32_t> left( n );
        vector<int32_t> right( n );

        // Fill left array : 
        left[0] = height[0];
        for ( int32_t i = 1; i < n; ++i ) {
            left[i] = max( left[i - 1], height[i] );
        }

        // Fill right array
        right[n - 1] = height[n - 1];
        for ( int32_t i = n - 2; i >= 0; --i ) {
            right[i] = max( right[i + 1], height[i] );
        }

        // Calculate trapped water :
        int32_t ret = 0;
        for ( int32_t i = 0; i < n; i++ ) {
            ret += min( left[i], right[i] ) - height[i];
        }

        return ret;
    }
};

//  End. :: - -                                                                        - -