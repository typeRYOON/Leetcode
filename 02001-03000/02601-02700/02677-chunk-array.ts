/* easy :: typescript */
/*
    Splits an array into subarrays of a specified chunk size.
    The last chunk may contain fewer elements if the array length isn't divisible by the chunk size.
    - -                  - -
    Time  :: O(N) ::    57ms
    Space :: O(N) :: 54.27MB
*/
// Solution entrypoint :: - -                                                          - -
function* generateSlice<T>(
    arr: readonly T[], start: number, size: number
    ): Generator<T, void, void> 
{
    for ( let i = start; size > 0 && i < arr.length; ++i, --size ) {
        yield arr[i];
    }
}

function* generateChunks<T>( arr: readonly T[], size: number ): Generator<T[], void, void>
{
    for ( let i = 0; i < arr.length; i += size ) {
        yield Array.from( generateSlice( arr, i, size ) );
    }
}

// Solution entrypoint :: - -                                                          - -
function chunk<T>( arr: readonly T[], size: number ): T[][] {
    return Array.from( generateChunks( arr, size ) );
}

//  End. :: - -                                                                        - -
