/* easy :: array */
/*
    Using array indicing, retrieve the relevant
    portions of the matrix in the current loop
    iteration. Iterate closer to the center.
    - -                  - -
    Time  :: O(n) ::     0ms
    Space :: O(1) :: 14.80MB
*/
class Solution {
public:
    // Solution entrypoint :: - -                                                      - -
    int diagonalSum( vector<vector<int>>& mat )
    {
        const int32_t N = mat.size();
        const int32_t n = N / 2;
        int32_t ret = 0;

        // Iterate on each diagonal corner until we hit the center :
        for ( int32_t i = 0, j = 0; i < n; ++i, ++j )
        {
            // ret += TL + TR + BL + BR :
            ret += mat[i][j] + mat[i][N-j-1] + mat[N-i-1][j] + mat[N-i-1][N-j-1];
        }
        // On even N size, add center element :
        if ( N & 0x1 ) { ret += mat[n][n]; }
        return ret;
    }
};
//  End. :: - -                                                                        - -