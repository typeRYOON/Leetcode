/* medium :: prefix-sum */
/*
    Note: I think you can solve this also by summing each i value and multiplying it by
    two and checking if it's >= the nums sum. Essentially checking if the running sum is
    >= the total sum. My code below is essentially subtracting from the sum and checking
    if pf[i] is >= the subtraction result. I could have honestly not subtracted and
    checked if pf[i]*2 >= sum, this means the front half is >= the latter half.
    - -                  - -
    Time  :: O(N) ::     0ms
    Space :: O(N) :: 97.00MB
*/
class Solution {
public:
    // Solution entrypoint :: - -                                                      - -
    int waysToSplitArray( vector<int>& nums )
    {
        const int32_t   n   = nums.size();
        int32_t         ret = 0;
        vector<int64_t> pf( n, 0x0 );

        pf[0] = nums[0];
        for ( int32_t i = 1; i < n; ++i ) {
            pf[i] = pf[i - 1] + nums[i];
        }

        const int32_t nums_sum = pf[n - 1];
        for ( int32_t i = 1; i <= n; ++i )
        {
            if ( pf[i-1] >= nums_sum - pf[i-1] ) {
                ret++;
            }
        }

        return ret;
    }
};

//  End. :: - -                                                                        - -