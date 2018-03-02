// Danny Luong
// Project 01 - Caesar's Cipher
// CS 3318 - Introduction to Computer Security
#include <iostream>
#include <fstream>

using namespace std;

// This function decrypts the Caesar Cipher
string encrypt(char text, int s) {
    string result = "";

    // Decrypt Uppercase Letters
    if (isupper(text)) {
        result = char(int(text + s - 65) % 26 + 65);
    }

    // Decrypt Lowercase letters
    else {
        result = char(int(text + s - 97) % 26 + 97);
    }
    return result;
}

int main() {
    ifstream inputFile;
    string fileName;
    char ch;
    int s = 15;
    
    cout << "Enter a file name: " << endl;
    cin >> fileName;
    cout << endl;

    inputFile.open(fileName.c_str(), ios::in);

    string original = "";
    string newText = "";
    
    //inputFile.open("cipher.txt");
    if (inputFile) {
        inputFile.get(ch);

        while (inputFile) {
            original += ch;

            if ((64 < int(ch) && int(ch) < 90) || (96 < int(ch) && int(ch) < 123)) {
                newText += encrypt(ch, s);
            }
            else {
                newText += ch;
            }
            inputFile.get(ch);
        }
        cout << "Original Text: " << endl;
        cout << original << endl << endl;
        cout << "The Offset Value is: " << s << endl << endl;
        cout << "Decoded Text: " << endl;
        cout << newText << endl;

        inputFile.close();
    }
    else {
        cout << fileName << " could not be opened.\n";
    }
    return 0;
}