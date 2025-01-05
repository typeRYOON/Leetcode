/* medium :: backtracking */
/*
    This function checks if a given word can be found in a 2D grid of characters by
    traversing sequentially adjacent cells. Letters in the word must be constructed
    from horizontally or vertically neighboring cells, and the same cell cannot be reused.
    - -                            - -
    Time  :: O(M * N * 4^L) ::   731ms = M, N are grid dimensions;
    Space :: O(L)           :: 11.59MB = L is the word length.
*/
class Solution {
public:
    // Solution entrypoint :: - -                                                      - -
    bool exist( vector<vector<char>>& board, string word )
    {
        const int32_t m = board.size();
        const int32_t n = board[0].size();

        // Backtracking function to explore valid paths :
        function<bool( int8_t, int8_t, int8_t )> backtrack =
            [&]( int8_t i, int8_t j, int8_t k )
        {
            // Base case: All characters in the word are matched :
            if ( k == word.length() ) { return true; }

            // Out-of-bounds or character mismatch :
            if ( i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[k] ) {
                return false;
            }

            // Temporarily mark the cell as visited :
            char temp   = board[i][j];
            board[i][j] = '\0';

            // Explore all four possible directions :
            if ( backtrack( i + 1, j, k + 1 ) || backtrack( i - 1, j, k + 1 ) ||
                 backtrack( i, j + 1, k + 1 ) || backtrack( i, j - 1, k + 1 ) ) {
                return true;
            }

            // Restore the cell after backtracking :
            board[i][j] = temp; 
            return false;
        };

        // Start backtracking from each cell :
        for ( int32_t i = 0; i < m; ++i ) {
            for ( int32_t j = 0; j < n; ++j ) {
                if ( backtrack( i, j, 0 ) ) { return true; }
            }
        }
        return false;
    }
};

//  End. :: - -                                                                        - -