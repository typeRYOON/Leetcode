/* medium :: typescript */
/*
    Removes all keys with falsy values from the given object or array, including
    nested objects/arrays.
    - -                  - -
    Time  :: O(N) ::    84ms
    Space :: O(N) :: 62.68MB
*/
type JSONValue =
    null | boolean | number | string | JSONValue[]
         | { [key: string]: JSONValue };
type Obj = Record<string, JSONValue> | Array<JSONValue>;

// Solution entrypoint :: - -                                                          - -
function compactObject( obj: Obj ): Obj
{
    if ( Array.isArray( obj ) )
    {
        return obj.filter( Boolean ).map( val =>
        {
            if ( typeof val === 'object' )
            {
                return compactObject( val );
            }
            return val;
        } );
    }

    for ( const [key, val] of Object.entries( obj ) )
    {
        if ( !val )
        {
            delete obj[key];
            continue;
        }

        if ( typeof val === 'object' )
        {
            obj[key] = compactObject( val );
        }
    }

    return obj;
}

//  End. :: - -                                                                        - -
