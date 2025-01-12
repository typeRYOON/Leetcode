/* easy :: typescript */
/* 
    Calculator class providing basic mathematical operations (addition, subtraction,
    multiplication, division, and exponentiation) with method chaining. The constructor
    initializes the result with a given value. Each method returns the updated
    Calculator instance to allow consecutive operations.
    - -                  - -
    Time  :: O(1) ::    47ms
    Space :: O(1) :: 51.32MB
*/
// Solution entrypoint :: - -                                                          - -
class Calculator 
{
    private result: number;

    // Constructor initializes the result with the given value :
    constructor( value: number ) 
    {
        this.result = value;
    }

    // Adds the given value to the result and returns the updated Calculator :
    add( value: number ): Calculator 
    {
        this.result += value;
        return this;
    }

    // Subtracts the given value from the result and returns the updated Calculator :
    subtract( value: number ): Calculator 
    {
        this.result -= value;
        return this;
    }

    // Multiplies the result by the given value and returns the updated Calculator :
    multiply( value: number ): Calculator 
    {
        this.result *= value;
        return this;
    }

    // Divides the result by the given value and returns the updated Calculator
    // Throws an error if the value is 0 (division by zero)
    divide( value: number ): Calculator 
    {
        if ( value === 0 )
        {
            throw new Error( "Division by zero is not allowed" );
        }

        this.result /= value;
        return this;
    }

    // Raises the result to the power of the given value and returns the updated Calculator :
    power( value: number ): Calculator 
    {
        this.result = Math.pow( this.result, value );
        return this;
    }

    // Returns the current result :
    getResult(): number 
    {
        return this.result;
    }
}

//  End. :: - -                                                                        - -
