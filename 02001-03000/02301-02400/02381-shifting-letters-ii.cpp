/* medium :: prefix-sum */
/*
    Create a shift prefix array ss where we make ss[shifts[i][0]] += direction. Direction
    should be 1 or -1 if shifts[i][2] == 1 or 0 respectively. ss[shifts[i][1]] should be
    -= direction. After this, we should move the values upwards through the array, this
    is the prefix sum part of the solution. Finally we apply the shift at each s[i]
    using ss[i]. ( ss[i] % 26 + 26 ) % 26 is the number of shifts at ss[i].
    - -                      - -
    Time  :: O(N + M) ::     0ms
    Space :: O(N)     :: 97.86MB
*/
class Solution {
public:
    // Solution entrypoint :: - -                                                      - -
    string shiftingLetters( string s, vector<vector<int>>& shifts )
    {
        const int32_t   n = s.length();
        vector<int32_t> ss( n + 1, 0 );

        for ( auto& shift : shifts )
        {
            int32_t direction = ( shift[2] == 1 ? 1 : -1 );
            ss[shift[0]]     += direction;
            ss[shift[1] + 1] -= direction;
        }

        int32_t pf = 0;
        for ( int32_t i = 0; i < n; ++i )
        {
            pf   += ss[i];
            ss[i] = pf;
        }

        for ( int32_t i = 0; i < n; ++i ) {
            s[i] = 'a' + ( s[i] - 'a' + ( ss[i] % 26 + 26 ) % 26 ) % 26;
        }

        return s;
    }
};

//  End. :: - -                                                                        - -