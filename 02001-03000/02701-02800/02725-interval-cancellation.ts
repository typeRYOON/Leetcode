/* easy :: typescript */
/*
    Creates a cancellable repeating function execution. The function `fn` is executed 
    immediately and then repeatedly every `t` milliseconds until the returned 
    cancel function is invoked. After invoking the cancel function, all future 
    executions are stopped.
    - -                  - -
    Time  :: O(1) ::    76ms
    Space :: O(1) :: 51.50MB
*/

// Solution entrypoint :: - -                                                          - -
function cancellable( fn: Function, args: any[], t: number ): Function 
{
    let should_repeat = true;

    const repeat = () => 
    {
        fn( ...args );
        setTimeout( () => 
        {
            should_repeat && repeat();
        }, t );
    };
    repeat();

    return () => should_repeat = false;
}

//  End. :: - -                                                                        - -
