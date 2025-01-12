/* easy :: typescript */
/*
    Creates a cancellable function execution. If the returned cancel function is invoked 
    before the specified delay `t`, the execution of `fn` is canceled. Otherwise, `fn` 
    is executed with the provided arguments after the delay.
    - -                  - -
    Time  :: O(1) ::    76ms
    Space :: O(1) :: 51.67MB
*/
// Solution entrypoint :: - -                                                          - -
const cancellable = ( fn: Function, args: any[], t: number ): Function => 
{
    let will_call = true;
    setTimeout( () => will_call && fn( ...args ), t );

    return () => will_call = false;
};

//  End. :: - -                                                                        - -
