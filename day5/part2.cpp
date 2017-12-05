#include <string>
#include <iostream>
#include <sstream>
#include <vector>

int main() {
    // Vector to store instruction array
    std::vector<int> imem;

    try {
        // Parse int from each line of input, add to end of instructions
        for (std::string line; std::getline(std::cin, line); ) {
            imem.push_back(std::stoi(line));
        }
    // Exception thrown when stdin given an empty line
    } catch (...) {}

    // Initialize program counter and number steps taken to 0
    int num_steps = 0;
    int pc = 0;
    
    // Execute until program counter exceeds instruction memory bounds
    while (pc < imem.size()) {
        // Store the offset to increment pc by
        int offset = imem[pc];
        
        // Decrease instruction by 1 if it is >= 3, otherwise increase by 1
        if (imem[pc] >= 3) {
            imem[pc] -= 1;
        } else {
            imem[pc] += 1;
        }
        
        // Move pc by saved offset
        pc += offset;
        num_steps++;
    }
    
    // Print the number of steps
    printf("%d\n", num_steps);
}
