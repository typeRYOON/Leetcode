/* easy :: priority-queue */
/*
    Using a priority queue, retrieve the top element,
    and push the floored square root result back into
    the priority queue.
    - -                  - -
    Time  :: O(n) ::     0ms
    Space :: O(n) :: 13.92MB
*/
class Solution {
public:
    // Solution entrypoint :: - -                                                      - -
    long long pickGifts( vector<int>& gifts, int k )
    {
        priority_queue<int32_t> pq( gifts.begin(), gifts.end() );

        // Run k times :
        while ( k-- )
        {
            pq.push( floor( sqrt( pq.top() ) ) );    
            pq.pop();
        }

        // Sum the remaining pq elements :
        int64_t ret = 0;
        while ( !pq.empty() )
        {
            ret += pq.top();
            pq.pop();
        }
        return ret;
    }
};
//  End. :: - -                                                                        - -