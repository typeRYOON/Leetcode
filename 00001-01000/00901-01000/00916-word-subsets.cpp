/* medium :: subset */
/*
    Each word in words1 must have all max occurences for each character from all
    strings in words2.
    Example:
        words1[i] = "leetcode"
        words2    = { "ee" "o" "oo" }
        max_freq  = {'e': 2, 'o': 2 }
        "leetcode" is not valid because two 'o' chars do not appear within "leetcode".
    - -                  - -
    Time  :: O(N) ::     8ms
    Space :: O(1) :: 61.69MB
*/
class Solution {
public:
    // Solution entrypoint :: - -                                                      - -
    vector<string> wordSubsets( vector<string>& words1, vector<string>& words2 )
    {
        vector<string> ret;
        vector<int32_t> max_freq( 26, 0 );
        vector<int32_t> freq    ( 26, 0 );

        for ( const string& word : words2 )
        {
            for ( char c : word ) { freq[c - 'a']++; }
            for ( int32_t i = 0; i < 26; ++i ) {
                max_freq[i] = max( max_freq[i], freq[i] );
            }
            fill( freq.begin(), freq.end(), 0x0 );
        }

        for ( const string& word : words1 )
        {
            bool valid_word = true;
            for ( char c : word ) { freq[c - 'a']++; }
            for ( int32_t i = 0; i < 26; ++i )
            {
                if ( max_freq[i] > freq[i] )
                {
                    valid_word = false;
                    break;
                }
            }
            if ( valid_word ) { ret.emplace_back( word ); }
            fill( freq.begin(), freq.end(), 0x0 );
        }

        return ret;
    }
};

//  End. :: - -                                                                        - -