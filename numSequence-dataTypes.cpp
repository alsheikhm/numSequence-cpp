// Mohammed Al-Sheikh

// Preprocessor Directives
#include <iostream>
#include <fstream>
#include <climits>

int main()
{
    // Initialize first 3 values in the integer sequence as long long data type variables
    long long a = 1;
    long long b = 3;
    long long c = 5;
    
    // Initialize the largest integer and long long to be c as of now
    long long largestInt = c;
    long long largestLongLong = c;
    
    // Create and open the output text file
    std::ofstream outputFile;
    outputFile.open("sequence.txt");
    
    // Write to the text file the first 3 values in the integer sequence
    outputFile << a << std::endl;
    outputFile << b << std::endl;
    outputFile << c << std::endl;
    
    // This while loop determines the largest valid integer in the number sequence
    while(true)
    {
        // Check all possible scenarios from the formula to see if the next possible d value would overflow the int data type
        // If so, set largestInt variable equal to the current c value and break out of while loop
        if(c > (INT_MAX / 5))
        {
            largestInt = c;
            break;
        }
        else if(b > (INT_MAX / 3))
        {
            largestInt = c;
            break;
        }
        else if(((5 * c) - (3 * b)) > (INT_MAX - a))
        {
            largestInt = c;
            break;
        }
        
        // Declare and Calculate d using the given formula: f(n) = (5 * f(n-1)) - (3 * f(n-2)) + f(n-3)
        long long d = (5 * c) - (3 * b) + a;
        
        // Write to the output file the value d
        outputFile << d << std::endl;
        
        // Update the values of a, b, c to shift forward in case the largest integer hasn't been found yet
        a = b;
        b = c;
        c = d;
    }
    
    // This while loop determines the largest valid long long in the number sequence
    while(true)
    {
        // Check all possible scenarios from the formula to see if the next possible d value would overflow the long long data type
        // If so, set largestLongLong variable equal to the current c value and break out of while loop
        if(c > (LLONG_MAX / 5))
        {
            largestLongLong = c;
            break;
        }
        else if(b > (LLONG_MAX / 3))
        {
            largestLongLong = c;
            break;
        }
        else if(((5 * c) - (3 * b)) > (LLONG_MAX - a))
        {
            largestLongLong = c;
            break;
        }
        
        // Declare and Calculate d using the given formula: f(n) = (5 * f(n-1)) - (3 * f(n-2)) + f(n-3)
        long long d = (5 * c) - (3 * b) + a;
        
        // Write to the output file the value d
        outputFile << d << std::endl;
        
        // Update the values of a, b, c to shift forward in case the largest long long hasn't been found yet
        a = b;
        b = c;
        c = d;
    }
    
    // Display results of largest valid integer and long long in the number sequence
    std::cout << "THE LARGEST VALID int IN THE NUMBER SEQUENCE IS: " << largestInt << std::endl;
    std::cout << "THE LARGEST VALID long long IN THE SEQUENCE IS: " << largestLongLong << std::endl << std::endl;
    
    // Close output file
    outputFile.close();
    
    return 0;
}
