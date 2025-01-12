/* medium :: typescript */
/*
    Executes an array of asynchronous functions in parallel and returns a promise that
    resolves  with the results of all functions if they succeed. If any function fails,
    the promise rejects with the reason of the first rejection.
    - -                  - -
    Time  :: O(N) ::    86ms
    Space :: O(N) :: 51.81MB
*/
type Fn<T> = () => Promise<T>;

// Solution entrypoint :: - -                                                          - -
function promiseAll<T>( functions: Fn<T>[] ): Promise<T[]> 
{
    const functions_results: T[] = [];
    let completed = 0;

    return new Promise( ( resolve, reject ) => 
    {
        for ( let i = 0; i < functions.length; i++ ) 
        {
            functions[i]().then( ( result ) => 
            {
                functions_results[i] = result;
                completed++;

                if ( completed === functions.length ) {
                    resolve( functions_results );
                }
            } ).catch( reject );
        }
    } );
}

//  End. :: - -                                                                        - -
