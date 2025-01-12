/* easy :: typescript */
/*
    A class that wraps an array of integers and provides functionality to:
    1. Sum the elements of two instances when added with the + operator.
    2. Return a string representation of the array in the form of a comma-separated
       list surrounded by brackets when using String().
    - -                  - -
    Time  :: O(N) ::    55ms
    Space :: O(N) :: 51.70MB
*/
// Solution entrypoint :: - -                                                          - -
class ArrayWrapper 
{
    private nums: number[];

    // Constructor accepts an array of integers :
    constructor( nums: number[] ) 
    {
        this.nums = nums;
    }

    // valueOf method for the + operator, returns the sum of all elements in the array :
    valueOf(): number 
    {
        return this.nums.reduce( ( acc, curr ) => acc + curr, 0 );
    }

    // toString method, returns a comma separated string surrounded by brackets
    toString(): string 
    {
        return `[${ this.nums.join( ',' ) }]`;
    }
}

//  End. :: - -                                                                        - -
