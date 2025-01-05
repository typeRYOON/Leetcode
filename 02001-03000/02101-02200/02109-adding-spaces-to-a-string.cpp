/* medium :: string */
/*
    Reserve space for final string.
    Construct portions of string around spaces.
    - -                  - -
    Time  :: O(n) ::    15ms
    Space :: O(n) :: 82.61MB
*/
class Solution {
public:
    string addSpaces( string s, vector<int32_t>& spaces )
    {
        string ret;
        int32_t last_space = 0;
        ret.reserve( s.size() + spaces.size() );

        for ( const int32_t& i : spaces )
        {   // Add original chars before space to ret :
            ret += s.substr( last_space, i - last_space );
            ret += ' ';
            last_space = i;
        }
        ret += s.substr( last_space );
        return ret;
    }
};