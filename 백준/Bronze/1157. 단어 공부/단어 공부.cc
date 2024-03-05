#include <iostream>
#include <unordered_map>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string word;
    cin >> word;

    unordered_map<char, int> frequency;

    // Count frequencies of characters in the word
    for (char c : word) {
        if (islower(c)) // Convert to uppercase if character is lowercase
            c = toupper(c);
        frequency[c]++;
    }

    // Find the character with the maximum frequency
    char mostFrequentChar = '\0';
    int maxFrequency = 0;
    bool multipleMaxFrequency = false;

    for (const auto& pair : frequency) {
        if (pair.second > maxFrequency) {
            maxFrequency = pair.second;
            mostFrequentChar = pair.first;
            multipleMaxFrequency = false;
        } else if (pair.second == maxFrequency) {
            multipleMaxFrequency = true;
        }
    }

    // Output the result
    if (multipleMaxFrequency) {
        cout << "?" << endl;
    } else {
        cout << mostFrequentChar << endl;
    }

    return 0;
}
