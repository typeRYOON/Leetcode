/* medium :: typescript */
/*
    Enhances arrays with a `groupBy` method that groups elements by a key generated
    by a callback function. The grouped array is an object where keys are returned
    by the callback, and values are arrays of items that generate each key.
    - -                  - -
    Time  :: O(n) ::     0ms
    Space :: O(n) :: 00.00MB
*/
declare global 
{
    interface Array<T> 
    {
        groupBy( fn: ( item: T ) => string ): Record<string, T[]>;
    }
}

// Solution entrypoint :: - -                                                          - -
Array.prototype.groupBy = function ( fn ) 
{
    const hash = {};
    for ( let item of this ) 
    {
        const key = fn( item );
        hash[ key ] ||= [];
        hash[ key ].push( item );
    }
    return hash;
}

//  End. :: - -                                                                        - -
