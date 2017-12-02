#include <string>
#include <iostream>

int main() {
	  std::string input[] = {
"5  9 2 8",
"9  4 7 3",
"3  8 6 5"
};

    // Sum of evenly divisible values dividing each other
    int sum = 0;
    
    for (auto line : input)
    {
        int val1 = 0;
        int val2 = 0;
        
        // The start position in the line for the first value
        std::string::size_type idx1 = 0;
        
        while (idx1 < line.length())
        {
            // The end position in the line for the first value
            auto val1_pos_end = line.find("\t", idx1+1);
            val1_pos_end = (val1_pos_end == -1) ? line.length() : val1_pos_end;
            
            // The substring containing only the first value
            auto val1_str = line.substr(idx1, val1_pos_end);
            
            // String to int for the value, with the number of characters used
            std::string::size_type sz = 0;
            int val1 = std::stoi(val1_str, &sz);
            idx1 += sz;
            
            // The start position in the line for the second value
            std::string::size_type idx2 = 0;
            while (idx2 < line.length())
            {
                // The end position in the line for the second value
                auto val2_pos_end = line.find("\t", idx2+1);
                val2_pos_end = (val2_pos_end == -1) ? line.length() : val2_pos_end;
            
                // The substring containing only the second value
                auto val2_str = line.substr(idx2, val2_pos_end);
            
                // String to int for the value, with the number of characters used
                int val2 = std::stoi(val2_str, &sz);
                idx2 += sz;
                
                // Don't test the value against itself, check if the numbers are evenly divisible
                if (idx1 != idx2 && val1 % val2 == 0)
                {
                        sum += val1 / val2;
                        
                        // Kill the loops early and skip to next line
                        idx1 = line.length();
                        idx2 = line.length();
                    }
                }
            }
            
        }
    }
    
    // Print the result
    printf("%d\n", sum);
}
