/* medium :: typescript */
/*
    Creates a time-limited version of an asynchronous function. If the original function 
    `fn` does not complete within the specified time `t`, the returned function rejects 
    with "Time Limit Exceeded". Otherwise, it resolves with the result of `fn`.
    - -                  - -
    Time  :: O(1) ::    76ms
    Space :: O(1) :: 51.26MB
*/
type Fn = ( ...params: any[] ) => Promise<any>;

// Solution entrypoint :: - -                                                          - -
function timeLimit( fn: Fn, t: number ): Fn 
{
    return async function ( ...args: any[] ) 
    {
        return new Promise( ( resolve, reject ) => 
        {
            const timeout_id = setTimeout( () => 
            {
                reject( "Time Limit Exceeded" );
            }, t );

            fn( ...args )
                .then( ( result ) => 
                {
                    clearTimeout( timeout_id );
                    resolve( result );
                })
                .catch( ( error ) => 
                {
                    clearTimeout( timeout_id );
                    reject( error );
                });
        });
    };
}

//  End. :: - -                                                                        - -
