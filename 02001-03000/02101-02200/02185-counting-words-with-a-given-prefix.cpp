/* easy :: string */
/*
    Check if each word starts with the pref string.
    - -                  - -
    Time  :: O(N) ::     0ms
    Space :: O(1) :: 13.04MB
*/
class Solution {
public:
    // Solution entrypoint :: - -                                                      - -
    int prefixCount( vector<string>& words, string pref )
    {
        int32_t ret = 0;
        for ( const string& word : words ) {
            if ( word.starts_with( pref ) ) { ret++; }
        }

        return ret;
    }
};

//  End. :: - -                                                                        - -