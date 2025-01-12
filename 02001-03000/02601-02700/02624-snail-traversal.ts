/* medium :: typescript */
/*
    The method first checks if the input dimensions (rowsCount * colsCount) match the
    length of the array, returning an empty array if they do not match. It then
    initializes a 2D result array of the specified dimensions (rowsCount x colsCount),
    filled with zeros. The elements are then placed into the matrix while alternating
    the direction of traversal for each column (top to bottom, then bottom to top).
    - -                  - -
    Time  :: O(N) ::   189ms
    Space :: O(N) :: 64.94MB
*/
declare global {
    interface Array<T> { snail( rowsCount: number, colsCount: number ): number[][]; }
}

// Solution entrypoint :: - -                                                          - -
Array.prototype.snail = function ( rowsCount: number, colsCount: number ): number[][]
{
    if ( rowsCount * colsCount != this.length ) { return []; }

    const result = (
        new Array( rowsCount )
    ).fill( [] ).map( _ => ( new Array( colsCount ) ).fill( 0 ) );

    let y = 0, x = 0, alt = 1;
    this.forEach(v =>
    {
        result[y][x] = v;
        y += alt;
        if ( y === rowsCount || y === -1 )
        {
            ++x;
            alt = -alt;
            y  += alt;
        }
    } );

    return result;
};

//  End. :: - -                                                                        - -