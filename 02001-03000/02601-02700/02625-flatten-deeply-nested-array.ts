/* medium :: typescript */
/*
    Flattens a multi-dimensional array to a specified depth `n`. Elements at depth `n`
    and greater are left unflattened, while deeper levels are flattened recursively.
    - -                  - -
    Time  :: O(N) ::   168ms
    Space :: O(N) :: 80.66MB
*/
type MultiDimensionalArray = ( number | MultiDimensionalArray )[];

// Solution entrypoint :: - -                                                          - -
var flat = function ( arr: MultiDimensionalArray, n: number ): MultiDimensionalArray
{
    // Base case :
    if ( n === 0 ) { return arr; }

    const result: MultiDimensionalArray = [];

    arr.forEach( el => {
        if ( typeof el === 'number' ) {
            result.push( el );
        } else {
            result.push( ...flat( el, n - 1 ) );
        }
    });

    return result;
};

//  End. :: - -                                                                        - -
