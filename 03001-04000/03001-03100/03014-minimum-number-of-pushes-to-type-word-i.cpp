/* easy :: counting */
/*
    At certain lengths the number of presses increases.
    - -                  - -
    Time  :: O(N) ::     0ms
    Space :: O(1) ::  8.28MB
*/
class Solution {
public:
    // Solution entrypoint :: - -                                                      - -
    int minimumPushes( string word )
    {
        int32_t       ret = 0;
        const int32_t n   = word.size();
        for ( int32_t i = 0; i < n; ++i )
        {
            if      ( i <= 7 )  { ret++;    }
            else if ( i <= 15 ) { ret += 2; }
            else if ( i <= 23 ) { ret += 3; }
            else                { ret += 4; }
        }

        return ret;
    }
};

//  End. :: - -                                                                        - -