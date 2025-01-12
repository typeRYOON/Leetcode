/* easy :: typescript */
/*
    Implements an asynchronous sleep function that pauses execution for a given
    number of milliseconds before resolving. Useful for delaying operations.
    - -                  - -
    Time  :: O(1) ::    57ms
    Space :: O(1) :: 51.34MB
*/
// Solution entrypoint :: - -                                                          - -
async function sleep( millis: number ): Promise<void> {
    return new Promise( ( resolve ) => setTimeout( resolve, millis ) );
}

//  End. :: - -                                                                        - -
