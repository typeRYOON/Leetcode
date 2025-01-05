/* medium :: hashmap */
/*
    Create a map that takes a char and returns the first index and a possible later index.
    If we can fit at least one char in between these indices there are subsequences.
    We then add all unique chars in between those two indices to our returned integer.
    Example:
        string "aoba" => { 'a': { 0, 3 }, ... }
        chars 'o' and 'b' will be encountered, add 2 to returned integer.
        "aoa" and "aba"
    - -                  - -
    Time  :: O(N) ::   164ms
    Space :: O(N) :: 16.13MB
*/
class Solution {
public:
    // Solution entrypoint :: - -                                                      - -
    int countPalindromicSubsequence( string s )
    {
        const int32_t n   = s.length();
        int32_t       ret = 0;
        unordered_map<char, pair<int32_t, int32_t>> occ;

        for ( int32_t i = 0; i < n; ++i )
        {
            // First occurence index :
            if ( !occ.contains( s[i] ) ) {
                occ[s[i]].first = i;
            }
            // Most recent :
            occ[s[i]].second = i;
        }

        for ( auto& [chr, p] : occ )
        {
            // No valid space :
            if ( p.second - p.first <= 1 ) { continue; }

            unordered_set<char> chars;
            for ( int32_t i = p.first + 1; i < p.second; ++i ) {
                chars.insert( s[i] );
            }
            ret += chars.size();
        }

        return ret;
    }
};

//  End. :: - -                                                                        - -