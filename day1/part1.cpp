#include <string>
#include <iostream>

int main() {
    // CAPTCHA string
	  std::string captcha = "91211219";
    
    // Sum of all digits that match next digit in the list
    int sum = 0;
    
    // Loop through all digits (except the last) and see if they match the next one
    for (unsigned int i = 0; i < captcha.length() - 1; i++)
    {
        if (captcha[i] == captcha[i+1])
        {
            // Increment the sum by the digit value (converted from char by subtracting ascii value of '0')
            sum += (captcha[i] - '0');
        }
    }
    
    // Compare the first and last digit of the captcha, since it is circular
    if (captcha[0] == captcha[captcha.length()-1])
    {
        sum += (captcha[0] - '0');
    }
    
    // Print the result
    printf ("%d\n", sum);
}
