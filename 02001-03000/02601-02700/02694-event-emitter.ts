/* medium :: typescript */
/*
    A custom EventEmitter class that allows subscribing to events and emitting them.
    - -                  - -
    Time  :: O(1) ::    70ms
    Space :: O(N) :: 52.04MB
*/
type Callback = ( ...args: any[] ) => any;
type Subscription = {
    unsubscribe: () => void
};

// Solution entrypoint :: - -                                                          - -
class EventEmitter 
{
    private _subs: Record<string, Set<Callback>> = {};

    // Subscribe to an event with a callback function :
    subscribe( eventName: string, callback: Callback ): Subscription 
    {
        let set = this._subs[eventName];
        if ( !set ) 
        {
            this._subs[eventName] = set = new Set();
        }

        set.add( callback );

        // Return an object with an unsubscribe method to remove the callback :
        return {
            unsubscribe: () => {
                set.delete( callback );
            }
        };
    }

    // Emit an event, calling all the subscribed callbacks :
    emit( eventName: string, args: any[] = [] ): any 
    {
        const result: any[] = [];
        
        const set = this._subs[eventName];
        if ( set ) 
        {
            set.forEach( ( fn ) => {
                result.push( fn( ...args ) );
            } );
        }

        return result;
    }
}

//  End. :: - -                                                                        - -
