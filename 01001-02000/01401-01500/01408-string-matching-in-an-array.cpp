/* easy :: subset */
/*
    I know there's the KMP algorithm, I don't care. Bruteforce solution FTW. This
    solution iterates through all substrings for each words[i] and checks if each
    substring is within the words vector.
    - -                  - -
    Time  :: O(N^3) ::   0ms
    Space :: O(1) :: 11.44MB
*/
class Solution {
public:
    // Solution entrypoint :: - -                                                      - -
    vector<string> stringMatching( vector<string>& words )
    {
        const int32_t  n = words.size();
        vector<string> ret;

        for ( int32_t i = 0; i < n; ++i )
        {
            for ( int32_t j = 0; j < n; ++j )
            {
                if ( i != j && words[j].find( words[i] ) != string::npos )
                {
                    ret.push_back( words[i] );
                    break;
                }
            }
        }
        return ret;
    }
};

//  End. :: - -                                                                        - -