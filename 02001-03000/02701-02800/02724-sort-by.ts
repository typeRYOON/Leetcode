/* easy :: typescript */
/*
    Sorts an array based on the numerical values returned by a callback function `fn`.
    The array is sorted in ascending order according to the numbers generated by `fn`.
    - -                         - -
    Time  :: O(N*log(N)) ::   139ms
    Space :: O(1)        :: 66.68MB
*/
// Solution entrypoint :: - -                                                          - -
const sortBy = <T>( arr: T[], fn: ( value: T ) => number ): T[] =>
    arr.sort( ( a, b ) => fn( a ) - fn( b ) );

//  End. :: - -                                                                        - -
