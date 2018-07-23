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
#include <sstream>

using namespace std;

class RC4
{
  public:
    RC4();
    void swap(int *S, int i, int j);
    void KSA(char *key);
    char PRGA();
    char *encrypt(char *plaintext);

  private:
    int S[256];
};

// Constructor
RC4::RC4() {}

void RC4::swap(int *S, int i, int j)
{
    int temp_i, temp_j = 0;
    // Assign temp values for swapping
    temp_i = S[i];
    temp_j = S[j];
    // Reassign values
    S[i] = temp_j;
    S[j] = temp_i;
}

// RC4 input
void RC4::KSA(char *key)
{
    int key_length;

    for (int i = 0; i < 256; i++)
    {
        S[i] = i; // S[i] := i
    }

    int j = 0; // j := 0

    key_length = strlen(key);

    for (int i = 0; i < 256; i++)
    {
        j = (j + S[i] + key[i % key_length]) % 256; // j:=(j+S[i]+key[i%key_length])%256

        // swap values of S[i] and S[j]
        swap(S, i, j);
    }
}

// RC4 Output
char RC4::PRGA()
{
    int i = 0; // i := 0
    int j = 0; // j := 0

    // while GeneratingOutput:
    i = (i + 1) % 256;    // i := (i + 1) % 256
    j = (j + S[i]) % 256; // j := (j + S[i]) % 256

    // swap values of S[i] and S[j]
    swap(S, i, j);

    // output K
    return S[(S[i] + S[j]) % 256]; //K := S[(S[i] + S[j]) % 256]
}

// Encrypt the plaintext
char *RC4::encrypt(char *plaintext)
{
    char stream;
    int plaintext_len;
    plaintext_len = strlen(plaintext);
    for (int i = 0; i <= plaintext_len; i++)
    {
        stream = PRGA();
        plaintext[i] = plaintext[i] ^ stream;
    }
    return plaintext;
}

int main()
{

    ifstream inputFile;
    string fileName;
    string userkey;
    string plaintext_str;

    cout << "Enter the file name  you wish to encrypt: " << endl;
    cin >> fileName;
    cout << endl;

    cout << "Enter a 5 byte to 32 byte long key to encrypt with: " << endl;
    cin >> userkey;
    cout << endl;

    // Open the file
    inputFile.open(fileName.c_str(), ios::in);

    if (inputFile.is_open())
    {
        getline(inputFile, plaintext_str);
    }

    char plaintext[1000];

    for (int i = 0; i <= plaintext_str.length(); i++)
    {
        plaintext[i] = plaintext_str[i];
    }

    char key[32];
    for (int i = 0; i <= userkey.length(); i++)
    {
        key[i] = userkey[i];
    }

    // Declare two objects for encryption and decryption
    RC4 Encode;
    RC4 Decode;

    Encode.KSA(key);

    // Print the original plaintext from the file
    cout << "Plaintext being encrypted: " << plaintext << endl
         << endl;
    char *ciphertext = Encode.encrypt(plaintext);
    // Print the encrypted ciphertext that was created form the key
    cout << "Encrypted Ciphertext: " << endl;

    /*
    int ciphertext_len = strlen(plaintext);
    // Convert to hex and stores in new string
    stringstream ss;
    string newValue;
    for (int i = 0; i < ciphertext_len; i++)
    {
            ss << hex << (int)ciphertext[i];
            newValue += ss.str();
    }
    cout << newValue << endl
         << endl;
    */

    cout << ciphertext << endl
         << endl;
    cout << endl
         << endl;
}
