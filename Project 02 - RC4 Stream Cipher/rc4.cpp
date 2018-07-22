// Danny Luong
// Project 02 - RC4
// CS 3318 - Introduction to Computer Security

// Implement the RC4 stream cipher in C++.
// User should be able to enter any key that is 5 bytes to 32 bytes long.
// Be sure to discard the first 3072 bytes of the pseudo random numbers.
// THE KEY OR THE INPUT TEXT MUST NOT BE HARD CODED IN THE PROGRAM.
// You should write TWO separate programs: encryption and decryption.
// The encryption program should input the plaintext file and output a
// cipher text in hex. The decryption program should input the cipher
// text file in hex and output the plaintext.

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;

unsigned char S[256];
unsigned int i, j;

char KSA(char *key)
{
    int key_length;

    key_length = strlen(key);

    for (int i = 0; i < 256; i++)
    {
        S[i] = i; // S[i] := i
    }

    int j = 0; // j := 0

    for (int i = 0; i < 256; i++)
    {
        j = (j + S[i] + key[i % key_length]) % 256; // j:=(j+S[i]+key[i%key_length])%256

        // swap values of S[i] and S[j]
        swap(S, i, j);
    }

    return *S;
}

char PRGA(unsigned char *S)
{
    int i = 0; // i := 0
    int j = 0; // j := 0

    // while GeneratingOutput:
    i = (i + 1) % 256;    // i := (i + 1) % 256
    j = (j + S[i]) % 256; // j := (j + S[i]) % 256

    // swap values of S[i] and S[j]
    swap(S, i, j);

    //output K
    return S[(S[i] + S[j]) % 256]; //K := S[(S[i] + S[j]) % 256]
}

// Created a swap function for less redundancy
void swap(unsigned char *S, unsigned int i, unsigned int j)
{
    int temp_i, temp_j = 0;

    // Assign temp values for swapping
    temp_i = S[i];
    temp_j = S[j];

    // Reassign values
    S[i] = temp_j;
    S[j] = temp_i;
}

// This function encrypts the Caesar Cipher
char encrypt(char *key, char *plaintext)
{
    char result;
    char keystream;
    int text_length = strlen(plaintext);

    *S = KSA(key);
    for (int i = 0; i <= text_length; i++)
    {
        keystream = PRGA(S);
        result += plaintext[i] ^ keystream;
    }

    return result;
}

// This function decrypts the ciphertext
char *decrypt(char *ciphertext)
{
    char *result;

    return result;
}

int main()
{
    ifstream inputFile;
    string fileName;
    string userKey;

    char *ch;
    char key[32];
    char plaintext[256];
    char ciphertext[256];
    string newplaintext;

    // Get the file name of the plaintext
    cout << "Enter the plaintext file name: " << endl;
    cin >> fileName;
    cout << endl;

    // User declared key between 5 bytes to 32 bytes long
    cout << "Enter any key between 5 bytes to 32 bytes: " << endl;
    cin >> userKey;
    cout << endl;

    for (int i; i < userKey.length(); i++)
    {
        key[i] += userKey[i];
    }

    // Prints the Original and Decoded Text
    cout << "Plaintext: " << endl;
    cout << plaintext << endl
         << endl;
    cout << "Encrypted Text: " << endl;
    cout << ciphertext << endl
         << endl;

    return 0;
}
