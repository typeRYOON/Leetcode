/* easy :: math */
/*
    Using division / modulus to
    retrieve the digit sum.
    - -                  - -
    Time  :: O(n) ::     0ms
    Space :: O(1) :: 19.25MB
*/
class Solution {
public:
    // Solution entrypoint :: - -                                                      - -
    int differenceOfSum(vector<int>& nums)
    {
        int32_t ret = 0, d_sum = 0;
        for ( int32_t& num_i : nums )
        {
            // Add element to element sum :
            ret += num_i;

            // Get digit sum :
            while ( num_i )
            {
                ret   -= num_i % 10;
                num_i /= 10;
            }
        }
        return abs( ret );
    }
};
//  End. :: - -                                                                        - -