/* medium :: typescript */
/*
    A function that checks if a given object is an instance of a given class or
    superclass. The function verifies that the object has access to the class's methods
    and that the classFunction is indeed a function.
    - -                  - -
    Time  :: O(N) ::   104ms
    Space :: O(1) :: 58.71MB
*/
// Solution entrypoint :: - -                                                          - -
function checkIfInstanceOf( obj: any, classFunction: any ): boolean
{
    if ( obj == null || typeof classFunction !== 'function' ) { return false; }
    return Object( obj ) instanceof classFunction;
}

//  End. :: - -                                                                        - -