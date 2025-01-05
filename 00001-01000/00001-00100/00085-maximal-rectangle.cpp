/* hard :: stack */
/*
    This function calculates the area of the largest rectangle containing only 1's in
    a binary matrix. It uses a histogram-based approach with a monotonic stack to compute
    the maximal rectangle row by row.
    - -                      - -
    Time  :: O(R * C) ::     0ms
    Space :: O(C)     :: 17.02MB
*/
class Solution {
public:
    // Solution entrypoint :: - -                                                      - -
    int maximalRectangle( vector<vector<char>>& matrix )
    {
        const uint16_t row = matrix.size();
        const uint16_t col = matrix[0].size();

        if ( row==1 && col==1 ) {
            return matrix[0][0] == '1';
        }
        vector<uint16_t> h( col + 1 );
        int32_t ret = 0;

        for ( int32_t i = 0; i < row; i++ )
        {
            vector<int32_t> mst = { -1 };
            for ( int32_t j = 0; j <= col; j++ )
            {
                // Count the successive '1's & store in h[j] :
                h[j] = ( j == col || matrix[i][j] == '0' ) ? 0 : h[j] + 1;

                // Monotonic stack has at least element -1 :
                while( mst.size() > 1 && ( j == col || h[j] < h[mst.back()] ) )
                {
                    const int32_t m = mst.back();
                    mst.pop_back();
                    ret = max( ret, h[m] * ( j - mst.back() - 1 ) );
                }
                mst.push_back( j );
            }
        }
        return ret;
    }
};

//  End. :: - -                                                                        - -