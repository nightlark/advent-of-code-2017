#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <array>

std::array<int, 26> countLetters (std::string word) {
    std::array<int, 26> letter_counts;
    
    for (int i = 0; i < letter_counts.size(); i++)
    {
        letter_counts[i] = 0;
    }
    
    for (char letter : word)
    {
        letter_counts[letter-'a']++;
    }
    return letter_counts;
}

// Function to check if the passphrase is valid
bool validPassphrase (std::string passphrase) {
    // Track previously seen letter counts in words
    std::vector<std::array<int, 26>> letter_counts;
    
    std::istringstream ss(passphrase);
    std::string word;
    
    while (std::getline(ss, word, ' '))
    {
        std::array<int, 26> letter_distribution = countLetters(word);
        
        // Invalid if word is an anagram of another (same letter distribution)
        for (auto prev_letters : letter_counts)
        {
            if (prev_letters == letter_distribution)
            {
                return false;
            }
        }
        
        // Add word to the list of previously seen words    
        letter_counts.push_back(letter_distribution);
    }
    
    // Valid if no word was seen twice
    return true;
}

int main() {
    // The number of valid passphrases
    int num_valid_passphrases = 0;
    
    // Reads passphrases and checks if they are valid
    try {
        std::string passphrase;
        while (std::getline(std::cin, passphrase))
        {
            if (validPassphrase (passphrase))
            {
                num_valid_passphrases++;
            }
        }
    } catch (...) {}
    
    // Print the number of valid passphrases
    printf("%d\n", num_valid_passphrases);
}
