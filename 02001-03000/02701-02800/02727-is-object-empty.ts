/* easy :: typescript */
/*
    Checks if an object or an array is empty. An empty object has no key-value pairs,
    and an empty array has no elements.
    - -                  - -
    Time  :: O(N) ::    58ms
    Space :: O(1) :: 51.82MB
*/
// Solution entrypoint :: - -                                                          - -
function isEmpty(
    obj: Readonly<Record<PropertyKey, unknown>> | readonly unknown[],
    ): boolean 
{
    if ( Array.isArray( obj ) ) { return obj.length === 0; }
    for ( const _property in obj ) { return false; }

    return true;
}

//  End. :: - -                                                                        - -
