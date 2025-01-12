/* easy :: typescript */
/*
    Enhances arrays to provide a `last()` method that returns the last element of the
    array. If the array is empty, it returns -1.
    - -                  - -
    Time  :: O(1) ::    63ms
    Space :: O(1) :: 50.71MB
*/
// Solution entrypoint :: - -                                                          - -
Array.prototype.last = function(): number {
    return this.length ? this.at( -1 ) : -1;
};

//  End. :: - -                                                                        - -
