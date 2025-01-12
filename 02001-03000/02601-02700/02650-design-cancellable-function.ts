/* hard :: typescript */
/*
    A cancellable function that manages long-running generator tasks, allowing
    cancellation before completion.
    - -                  - -
    Time  :: O(1) ::    58ms
    Space :: O(1) :: 51.82MB
*/
// Solution entrypoint :: - -                                                          - -
const cancellable = <T>(generator: Generator): [() => void, Promise<T>] => 
{
    let cancel: () => void;

    // Create a promise that will reject with "Cancelled" on cancel function invokation :
    const cancel_promise = new Promise<never>( ( _, reject ) => {
        cancel = () => reject( "Cancelled" );
    } );

    cancel_promise.catch( () => {} );

    // Create the promise that runs the generator and handles the cancellation logic :
    const promise = ( async (): Promise<T> =>
    {
        let next = generator.next();
        while ( !next.done )
        {
            try
            {
                next = generator.next(
                    await Promise.race( [next.value, cancel_promise] )
                );
            }
            catch ( e ) // Propogate back :
            {
                next = generator.throw( e );
            }
        }
        return next.value; 
    } )();

    return [cancel, promise];
};
