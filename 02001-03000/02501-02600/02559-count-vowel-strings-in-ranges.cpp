/* medium :: prefix-sum */
/*
    Generate a prefix sum for each position i of size words.size(). Precompute if each
    word is valid according to the problem. The number of words valid within a range
    can be computed from our prefix sum by doing pf[R+1] - pf[L], +1 because our pf
    array is shifted up by one.
    - -                  - -
    Time  :: O(N) ::     0ms
    Space :: O(N) :: 69.40MB
*/
class Solution {
public:
    // Solution entrypoint :: - -                                                      - -
    vector<int> vowelStrings( vector<string>& words, vector<vector<int>>& queries )
    {
        const unordered_set<char> vowels = { 'a', 'e', 'i', 'o', 'u' };
        int32_t         n = words.size();
        vector<int32_t> pf( n + 1, 0 );

        for ( int32_t i = 0; i < n; ++i )
        {
            // Push forward current prefix :
            pf[i + 1] = pf[i];

            // Qualified Word :
            if ( vowels.contains( words[i][0] ) && vowels.contains( words[i].back() ) ) {
                pf[i + 1]++;
            }
        }

        n = queries.size();
        vector<int32_t> ret( n, 0 );
        for ( int32_t i = 0; i < n; ++i )
        {
            // Right prefix - Left prefix :
            ret[i] = pf[queries[i][1] + 1] - pf[queries[i][0]];
        }

        return ret;
    }
};

//  End. :: - -                                                                        - -