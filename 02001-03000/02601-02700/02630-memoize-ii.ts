/* hard :: typescript */
/*
    My solution uses a TrieNode structure. Whenever we reach a node for the first time,
    we will create a new node ( new Map ) right before proceeding.
    - -                   - -
    Time  :: O(N) ::    335ms
    Space :: O(N) :: 114.45MB
*/
type  Fn  = ( ...params: any ) => any
const res = "a";

// Solution entrypoint :: - -                                                          - -
function memoize( fn: Fn ): Fn
{
    const store = new Map();
    return ( ...args ) =>
    {
        let cur = store;
        for ( const arg of args )
        {
            // If we were never here before, we create a new node for it :
            if ( !cur.has( arg ) ) { cur.set( arg, new Map ); }
            cur = cur.get( arg );
        }
        // Case - Result found :
        if ( cur.has( res ) ) { return cur.get( res ); }

        // Case - Result needs to be created and stored :
        const tmp = fn( ...args );
        cur.set( res, tmp );

        return tmp;
    }
}

//  End. :: - -                                                                        - -