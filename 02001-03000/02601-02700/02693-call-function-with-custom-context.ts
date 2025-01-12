/* medium :: typescript */
/*
    Enhances all functions with a callPolyfill method to set the 'this' context and
    pass additional arguments.
    - -                  - -
    Time  :: O(1) ::    52ms
    Space :: O(1) :: 51.24MB
*/
type JSONValue =
    null | boolean | number | string
         | JSONValue[] | { [key: string]: JSONValue };
interface Function {
    callPolyfill( context: Record<string, JSONValue>, ...args: JSONValue[] ): JSONValue;
}

// Solution entrypoint :: - -                                                          - -
Function.prototype.callPolyfill = function( context, ...args ): JSONValue 
{
    const sym = Symbol( 'fn' );
    return { ...context, [sym]: this }[sym]( ...args );
};

//  End. :: - -                                                                        - -
