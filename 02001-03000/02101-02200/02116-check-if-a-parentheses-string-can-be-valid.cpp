/* medium :: string */
/*
    View the question as locked = "010100", s = "_)_)__" instead of s = "))()))". There
    must be enough malleable characters in the left to right and right to left traversals.
    There must be a positive balance in both directions.
    - -                  - -
    Time  :: O(N) ::     8ms
    Space :: O(1) :: 30.12MB
*/
class Solution {
public:
    // Solution entrypoint :: - -                                                      - -
    bool canBeValid( string s, string locked )
    {
        const int32_t n = s.length();
        if ( n & 0x1 ) { return false; }

        // Left to right '(' check :
        int32_t bal = 0;
        for ( int32_t i = 0; i < n; ++i )
        {
            if ( locked[i] == '0' || s[i] == '(' ) { bal++; }
            else                                   { bal--; }

            // More ')' and no useable unlocked char, unrecoverable :
            if ( bal < 0 ) { return false; }
        }

        // Right to left ')' check :
        bal = 0;
        for ( int32_t i = n - 1; i >= 0; --i )
        {
            if ( locked[i] == '0' || s[i] == ')' ) { bal++; }
            else                                   { bal--; }
    
            // More '(' and no useable unlocked char, unrecoverable :
            if ( bal < 0 ) { return false; }
        }

        return true;
    }
};

//  End. :: - -                                                                        - -