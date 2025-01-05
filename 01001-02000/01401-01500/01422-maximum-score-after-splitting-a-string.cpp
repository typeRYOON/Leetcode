/* easy :: array */
/*
    Do a prefix sum for zeroes in string s for each position i. Reverse through the
    string and get the '1' count and use the prefix array to check the score at each
    position i.
    - -                  - -
    Time  :: O(N) ::     0ms
    Space :: O(N) :: 08.96MB
*/
class Solution {
public:
    // Solution entrypoint :: - -                                                      - -
    int maxScore( string s )
    {
        int32_t         c = 0, ret = 0;
        const int32_t   n = s.size();
        vector<int16_t> zeroes( n, 0 );

        // Create prefix array of zeroes :
        for ( int32_t i = 0; i < n; ++i ) {
            if ( s.at(i) == '0' ) { zeroes[i] = ++c; }
        }

        // Check for ones, calculate score for each position 0 < i < n :
        c = 0;
        for ( int32_t i = n - 1; i > 0; --i )
        {
            if ( s.at(i) == '1' ) { c++; }
            ret = max( zeroes.at(i - 1) + c, ret );
        }

        return ret;
    }
};

//  End. :: - -                                                                        - -