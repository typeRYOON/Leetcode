/* medium :: typescript */
/*
    Memoizes a given function to cache results for unique inputs, avoiding redundant
    computations. Supports `sum`, `fib`, and `factorial` functions as inputs.
    - -                  - -
    Time  :: O(N) ::   289ms
    Space :: O(U) :: 86.76MB
*/
type Sum       = ( a: number, b: number ) => number;
type Fib       = ( n: number ) => number;
type Factorial = ( n: number ) => number;
type Fn        = Sum & Fib & Factorial;

// Solution entrypoint :: - -                                                          - -
function memoize( fn: Fn ): Fn 
{
    const cache: Map<string, ReturnType<Fn>> = new Map();

    return function ( ...args: Parameters<Fn> ): ReturnType<Fn> 
    {
        const key: string = args.join( ',' );
        if ( !cache.has( key ) )
        {
            cache.set( key, fn( ...args ) );
        }

        return cache.get( key )!;
    };
}

//  End. :: - -                                                                        - -