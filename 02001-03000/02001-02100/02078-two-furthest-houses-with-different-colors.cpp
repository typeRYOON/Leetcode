/* easy :: array */
/*
    Best solution will have the base color be in the leftmost or rightmost index of
    0 and n - 1. From there increment inwards on the array until we encounter a
    different color.
    Some base cases to consider and why it's a good idea to do two passes:
        0 1 0 0 0 0
        0 0 0 0 1 0
    - -                  - -
    Time  :: O(N) ::     0ms
    Space :: O(1) :: 12.08MB
*/
class Solution {
public:
    // Solution entrypoint :: - -                                                      - -
    int maxDistance( vector<int>& colors )
    {
        const int32_t n = colors.size();

        int32_t ret;
        int32_t base_color = colors[0];
        for ( int32_t i = n - 1; i >= 1; --i )
        {
            if ( colors[i] != base_color )
            {
                ret = i;
                break;
            }
        }

        base_color = colors[n - 1];
        for ( int32_t i = 0; i < n - 1; ++i )
        {
            if ( colors[i] != base_color )
            {
                ret = max( ret, n - i - 1 );
                break;
            }
        }

        return ret;
    }
};

//  End. :: - -                                                                        - -