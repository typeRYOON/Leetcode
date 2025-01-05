/* medium :: two-pointers */
/*
     Each version string consists of integers separated by dots (.). The comparison
     is done revision by revision, from left to right. Parse Each Revision: Use a loop
     to extract revision numbers from both version strings, ignoring leading zeros.
    - -                     - -
    Time  :: O(N + M) ::    0ms
    Space :: O(1)     :: 7.40MB
*/
class Solution {
public:
    // Solution entrypoint :: - -                                                      - -
    int compareVersion( string version1, string version2 )
    {
        const int32_t m = version1.size(), n = version2.size();
        for ( int32_t i = 0, j = 0; ( i < m ) || ( j < n ); i++, j++ )
        {
            int32_t v1 = 0;
            int32_t v2 = 0;

            while ( ( i < m ) && ( version1[i] != '.' ) ) {
                v1 = v1 * 10 + ( version1[i++]  - '0' );
            }

            while ( ( j < n ) && ( version2[j] != '.' ) ) {
                v2 = v2 * 10 + ( version2[j++]  - '0' );
            }

            // Compare Check :
            if ( v1 < v2 ) { return -1; }
            if ( v1 > v2 ) { return +1; }
        }
        return 0;
    }
};

//  End. :: - -                                                                        - -