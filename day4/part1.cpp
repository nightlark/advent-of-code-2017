#include <string>
#include <iostream>
#include <sstream>
#include <set>

// Function to check if the passphrase is valid
bool validPassphrase (std::string passphrase) {
    // Track previously seen words
    std::set<std::string> prev_words;
    
    std::istringstream ss (passphrase);
    std::string word;
    
    while (std::getline(ss, word, ' '))
    {
        // Fail if we've already seen a word
        if (prev_words.find(word) != prev_words.end())
        {
            return false;
        }
        
        // Add word to the list of previously seen words    
        prev_words.insert(word);
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
