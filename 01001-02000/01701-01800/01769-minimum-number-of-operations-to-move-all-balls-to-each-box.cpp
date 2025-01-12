/* medium :: prefix-sum */
/*
    This function calculates the minimum number of operations needed to move all balls
    to each box in a binary string. The operations are calculated using a prefix and
    suffix sum approach.
    - -                  - -
    Time  :: O(N) ::     0ms
    Space :: O(1) :: 12.24MB
*/
class Solution {
public:
    // Solution entrypoint :: - -                                                      - -
    vector<int> minOperations( string boxes )
    {
        const int32_t   n    = boxes.length();
        int32_t         sum  = boxes[0] == '0' ? 0 : 1;
        int32_t         last = 0;
        vector<int32_t> ret( n, 0x0 );

        // Forward Pass - Calculate operations considering all balls to the left :
        for ( int32_t i = 1; i < n; ++i )
        {
            ret[i] = sum + ret[i - 1];          // Add prev ops and cur ball count.
            if ( boxes[i] == '1' ) { sum++; }
        }

        // Backward Pass - Calculate operations considering all balls to the right :
        sum  = boxes[n - 1] == '0' ? 0 : 1;
        for ( int32_t i = n - 2; i >= 0; --i )
        {
            ret[i] += sum + last;               // Add ops from the right.
            last    = sum + last;               // Update cumulative ops.
            if ( boxes[i] == '1' ) { sum++; }
        }

        return ret;
    }
};

//  End. :: - -                                                                        - -