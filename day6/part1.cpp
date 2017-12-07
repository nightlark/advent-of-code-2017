#include <string>
#include <iostream>
#include <sstream>
#include <vector>

// Function to check if the current memory bank state has already been seen
bool existsInHistory (std::vector<std::vector<int>> history, std::vector<int> state) {
    for (auto prev_state : history)
    {
        if (prev_state == state)
        {
            return true;
        }
    }
    
    return false;
}

int main() {
    // The current memory bank state
    std::vector<int> mem;
    
    // History of previously seen memory bank states
    std::vector<std::vector<int>> history;
    
    // Read the current memory bank state
    std::string line;
    try {
        std::getline(std::cin, line);
    } catch (...) {}

    std::istringstream ss (line);
    std::string val;
    
    // Parse memory bank block counts
    try {
        while (std::getline(ss, val, '\t'))
        {
            mem.push_back(std::stoi(val));
        }
    } catch (...) {}

    // The number of block redistributions
    int num_redistributions = 0;

    // Loop until a previous block distribution is seen again
    while (!existsInHistory (history, mem))
    {
        // Add the current memory block state to the history
        history.push_back(std::vector<int> (mem));
        
        int most_blocks = 0;
        int most_blocks_index = 0;
        
        // Find the memory bank with the most blocks
        for (int i = 0; i < mem.size(); i++)
        {
            if (mem[i] > most_blocks)
            {
                most_blocks = mem[i];
                most_blocks_index = i;
            }
        }
        
        // Empty out the bank with the most blocks
        mem[most_blocks_index] = 0;
        
        // Distribute all the blocks
        while (most_blocks > 0)
        {
            // Begin redistribution at the next bank
            most_blocks_index = (most_blocks_index+1) % mem.size();
            mem[most_blocks_index]++;
            
            // Decrement the number of blocks left to redistribute
            most_blocks--;
        }
        
        num_redistributions++;
    }
    
    // Print the number of redistributions
    printf("%d\n", num_redistributions);
}
