/* medium :: typescript */
/*
    A generator function for inorder traversal over a multi-dimensional array of integers.
    It yields integers in the order of left-to-right traversal through nested arrays.
    - -                  - -
    Time  :: O(N) ::   199ms
    Space :: O(N) :: 81.27MB
*/
type MultidimensionalArray = ( MultidimensionalArray | number )[];

// Solution entrypoint :: - -                                                          - -
function* inorderTraversal(
    arr: MultidimensionalArray
    ): Generator<number, void, unknown>
{
    for ( const x of arr ) {
        Array.isArray( x ) ? yield* inorderTraversal( x ) : yield x;
    }
}

//  End. :: - -                                                                        - -