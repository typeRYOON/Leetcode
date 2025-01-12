/* easy :: math */
/*
    3^19 = 1162261467 is the max cube within our +2^31 range. If our number is
    positive and divides 3^19 perfectly (no decimal), our input n is a cube.
    - -                  - -
    Time  :: O(1) ::     0ms
    Space :: O(1) ::  8.98MB
*/
class Solution {
public:
    // Solution entrypoint :: - -                                                      - -
    bool isPowerOfThree( int n ) { return n > 0 && 1162261467 % n == 0; }
};

//  End. :: - -                                                                        - -