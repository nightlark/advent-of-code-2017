#include <string>
#include <iostream>

int main() {
    // CAPTCHA string
	  std::string captcha = "12131415";
    
    // Sum of all digits that match next digit in the list
    int sum = 0;
    
    // Looking at the digit halfway around the list (captcha has even number of digits)
    int step = captcha.length() / 2;
    
    // Loop through all digits and see if they match the one halfway around the list
    for (unsigned int i = 0; i < captcha.length(); i++)
    {
        // Modulo to wrap-around if i+step goes past the end of the captcha string
        if (captcha[i] == captcha[(i+step)%captcha.length()])
        {
            // Increment the sum by the digit value (converted from char by subtracting ascii value of '0')
            sum += (captcha[i] - '0');
        }
    }
    
    // Print the result
    printf ("%d\n", sum);
}
