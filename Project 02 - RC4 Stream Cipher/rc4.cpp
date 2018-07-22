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

using namespace std;

unsigned char S[256];
unsigned int i, j;

void KSA(unsigned char *key)
{
    unsigned int key_length;

    key_length = key.length();

    for (int i = 0; i < 256; i++)
    {
        S[i] = i; //S[i] := i
    }

    int j = 0; //j := 0

    for (int i = 0; i < 256; i++)
    {
        j = (j + S[i] + key[i % key_length]) % 256; // j:=(j+S[i]+key[i%key_length])%256

        // swap values of S[i] and S[j]
        swap(S, i, j);
    }
}

char PRGA(unsigned char *S)
{
    int i = 0; // i := 0
    int j = 0; // j := 0

    // while GeneratingOutput:
    i = (i + 1) % 256;    // i := (i + 1) % 256
    j = (j + S[i]) % 256; // j := (j + S[i]) % 256

    //swap values of S[i] and S[j]
    swap(S, i, j);

    //output K
    return S[(S[i] + S[j]) % 256]; //K := S[(S[i] + S[j]) % 256]
}

// Created a swap function for less redundancy
void swap(unsigned char *S, unsigned int i, unsigned int j){
    int temp_i = 0;
    int temp_j = 0;

    // Assign temp values for swapping
    temp_i = S[i];
    temp_j = S[j];

    // Reassign values
    S[i] = temp_j;
    S[j] = temp_i;
}

// This function encrypts the Caesar Cipher
string encrypt(string plaintext, char key)
{
    string result[];
    char keystream;

    S[] = KSA(key);
    keystream = PRGA(S);

    return result;
}

// This function decrypts the ciphertext
string decrypt(string ciphertext, char S)
{
    string result = "";

    return result;
}

int main()
{
    ifstream inputFile;
    string fileName;
    char userKey;
    char key[userKey.lenght()];

    // Get the file name of the plaintext
    cout << "Enter the plaintext file name: " << endl;
    cin >> fileName;
    cout << endl;

    // User declared key between 5 bytes to 32 bytes long
    cout << "Enter any key between 5 bytes to 32 bytes: " << endl;
    cin >> userKey;
    cout << endl;

    // Open the designated plaintext file
    inputFile.open(fileName.c_str(), ios::in);
}
