/* easy :: hashmap */
/*
    Because each height is unique, map
    each height to a string. Sort heights
    in descending order and use map to
    reconstruct the names vector.
    - -                  - -
    Time  :: O(n) ::     7ms
    Space :: O(n) :: 27.44MB
*/
class Solution {
public:
    // Solution entrypoint :: - -                                                      - -
    vector<string> sortPeople(vector<string>& names, vector<int>& heights)
    {
        // Collect the heights mapped to names :
        unordered_map<int32_t, string> height_map;
        int32_t n = names.size();
        for ( int32_t i = 0; i < n; ++i )
        {
            height_map.emplace(
                heights.at(i), names.at(i)
            );
        }
        names.clear();
        sort( heights.begin(), heights.end(), greater<>() );

        // Reconstruct the names vecot using our height map :
        for ( const int32_t& height : heights ) {
            names.emplace_back( height_map.at( height ) );
        }
        return names;
    }
};
//  End. :: - -                                                                        - -