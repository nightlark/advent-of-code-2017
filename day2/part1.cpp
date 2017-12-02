#include <string>
#include <iostream>

int main() {
	  std::string input[] = {
"5  1 9 5",
"7  5 3",
"2  4 6 8"
};

    // Sum of all differences
    int sum = 0;
    
    for (auto line : input)
    {
        int smallest = 0x7FFFFFFF;
        int largest = 0;
        
        // The start position in the line for the current value
        std::string::size_type idx = 0;
        
        while (idx < line.length())
        {
            // The end position in the line for the current value
            auto val_pos_end = line.find("\t", idx+1);
            val_pos_end = (val_pos_end == -1) ? line.length() : val_pos_end;
            
            // The substring containing only the current value
            auto val_str = line.substr(idx, val_pos_end);
            
            // String to int for the value, with the number of characters used
            std::string::size_type sz = 0;
            int val = std::stoi(val_str, &sz);
            
            // See if the value is the largest or smallest so far in the line
            largest = (largest > val) ? largest : val;
            smallest = (smallest < val) ? smallest : val;
            idx += sz;
        }
        
        // Increment the sum with the difference of the largest and smallest values on the line
        sum += (largest - smallest);
    }
    
    // Print the result
    printf("%d\n", sum);
}
