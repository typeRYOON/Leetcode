/* medium :: typescript */
/*
    A class to manage key-value pairs with expiration times.
    The `set` method allows adding or updating a key with a value and a duration.
    The `get` method retrieves the value if the key is still valid.
    The `count` method returns the count of un-expired keys.
    - -                  - -
    Time  :: O(1) ::    73ms
    Space :: O(1) :: 51.21MB
*/
interface TTLValue {
    value: number;
    timer: ReturnType<typeof setTimeout>;
}

// Solution entrypoint :: - -                                                      - -
class TimeLimitedCache {
    cache = new Map<number, TTLValue>();

    set( key: number, value: number, duration: number ): boolean
    {
        const exists = this.cache.has( key );
        if ( exists ) clearTimeout( this.cache.get( key )!.timer );
        
        this.cache.set(
            key,
            { value, timer: setTimeout( () => this.cache.delete( key ), duration ) }
        );
        return exists;
    }

    get( key: number ): number 
    {
        return this.cache.has( key ) ? this.cache.get( key )!.value : -1;
    }

    count(): number 
    {
        return this.cache.size;
    }
}

//  End. :: - -                                                                        - -
