// Danny Luong
// Project 01 - Caesar's Cipher
// CS 3318 - Introduction to Computer Security
#include <iostream>
#include <fstream>

using namespace std;

// This function decrypts the Caesar Cipher
string decrypt(char text, int s) {
    string result = "";

    // Decrypt Uppercase using the user provided offset value
    if (isupper(text)) {
        result = char(int(text + s - 65) % 26 + 65);
    }

    // Decrypt Lowercase using the user provided offset value
    else {
        result = char(int(text + s - 97) % 26 + 97);
    }
    return result;
}

int main() {
    ifstream inputFile;
    string fileName;
    char ch;
    int s;
    
    // Get the file name of encrypted text
    cout << "Enter a file name: " << endl;
    cin >> fileName;
    cout << endl;

    //  Have the user provide a possible offset value to test
    cout << "Enter shift value: " << endl;
    cin >> s;
    cout << endl;

    // Open the file
    inputFile.open(fileName.c_str(), ios::in);

    // Empty strings to store the file text before and after decryption
    string original = "";
    string newText = "";
    
    // Checks that inputFile exists
    if (inputFile) {
        inputFile.get(ch);

        while (inputFile) {
            // Adds the original characters of the file into a string
            original += ch;

            // Checks each character and checks to see if it is a letter value
            if ((64 < int(ch) && int(ch) < 90) || (96 < int(ch) && int(ch) < 123)) {
                // Adds the offsetted character values into the newText string
                newText += decrypt(ch, s);
            }
            // If character value is not a letter it remains unchanged
            else {
                newText += ch;
            }
            inputFile.get(ch);
        }
        // Prints the Original and Decoded Text
        cout << "Original Text: " << endl;
        cout << original << endl << endl;
        cout << "The Offset Value is: " << s << endl << endl;
        cout << "Decoded Text: " << endl;
        cout << newText << endl << endl;

        inputFile.close();
    }
    // Error handling incase the provided filename could not be opened
    else {
        cout << fileName << " could not be opened.\n";
    }
    return 0;
}