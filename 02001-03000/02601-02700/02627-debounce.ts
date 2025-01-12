/* medium :: typescript */
/*
    Creates a debounced version of the given function `fn` that delays its execution by
    `t` milliseconds. If the debounced function is called multiple times within the `t`
    milliseconds window, only the last call will be executed.
    - -                  - -
    Time  :: O(1) ::    69ms
    Space :: O(1) :: 51.89MB
*/
type F = ( ...p: any[] ) => any;

// Solution entrypoint :: - -                                                          - -
function debounce( fn: F, t: number ): F 
{
    let timer: ReturnType<typeof setTimeout>;

    return function ( ...args ) 
    {
        clearTimeout( timer );
        timer = setTimeout( () => fn( ...args ), t );
    };
}

//  End. :: - -                                                                        - -
