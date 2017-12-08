#include <string>
#include <iostream>
#include <sstream>
#include <map>

std::map<std::string, int> registers;

// Function to interpret the instruction
void interpret (std::string instruction) {
    std::istringstream ss(instruction);
    
    std::string reg;
    std::string op;
    std::string amt_str;
    int amt;
    std::string cond_reg;
    std::string comparison;
    std::string cmp_str;
    int cmp;
    
    // Parse the instruction
    try {
        std::getline(ss, reg, ' ');
        std::getline(ss, op, ' ');
        std::getline(ss, amt_str, ' ');
        amt = std::stoi(amt_str);
        std::getline(ss, cond_reg, ' ');
        std::getline(ss, cond_reg, ' ');
        std::getline(ss, comparison, ' ');
        std::getline(ss, cmp_str, ' ');
        cmp = std::stoi(cmp_str);
    } catch (...) {}
    
    int cond_reg_val = 0;
    try {
        cond_reg_val = registers.at(cond_reg);
    } catch (...) {}
    
    bool comp_result = false;
    
    // Perform the comparison
    if (comparison == ">") {
        comp_result = (cond_reg_val > cmp);
    } else if (comparison == "<") {
        comp_result = (cond_reg_val < cmp);
    } else if (comparison == ">=") {
        comp_result = (cond_reg_val >= cmp);
    } else if (comparison == "<=") {
        comp_result = (cond_reg_val <= cmp);
    } else if (comparison == "==") {
        comp_result = (cond_reg_val == cmp);
    } else if (comparison == "!=") {
        comp_result = (cond_reg_val != cmp);
    }
    
    // Adjust register value based on the result of the comparison
    if (comp_result) {
        try {
            registers.at(reg);
        } catch (...) {
            registers[reg] = 0;
        }
        
        if (op == "inc") {
            registers[reg] += amt;
        } else if (op == "dec") {
            registers[reg] -= amt;
        }
    } else {
        amt = 0;
    }
}

int main() {
    // Reads and interprets instructions
    try {
        // The current instruction
        std::string instruction;
        while (std::getline(std::cin, instruction))
        {
            interpret(instruction);
        }
    } catch (...) {}
    
    // Find the largest register value
    int largest = 0;
    for (auto val : registers) {
        if (val.second > largest) {
            largest = val.second;
        }
    }
    
    // Print the largest register value
    printf("%d\n", largest);
}
