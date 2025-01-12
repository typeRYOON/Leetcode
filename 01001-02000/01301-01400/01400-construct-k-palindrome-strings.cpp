/* medium :: counting */
/*
    If there's more odd char frequency counts than evens, there will be a
    mismatched character in our k palindrome string construction.
    - -                  - -
    Time  :: O(N) ::     0ms
    Space :: O(1) :: 14.95MB
*/
class Solution {
public:
    // Solution entrypoint :: - -                                                      - -
    bool canConstruct( string s, int k )
    {
        // Not enough chars to start with :
        if ( s.length() < k ) { return false; }

        vector<int32_t> freq( 26, 0x0 );
        for ( const char& c : s ) { freq[c - 'a']++; }

        int32_t odd_count = 0;
        for ( const int32_t& frequency : freq ) {
            if ( frequency & 0x1 ) { odd_count++; }
        }

        return odd_count <= k;
    }
};

//  End. :: - -                                                                        - -