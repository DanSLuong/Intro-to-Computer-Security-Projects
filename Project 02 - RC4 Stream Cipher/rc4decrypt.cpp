// Danny Luong
// Project 02 - RC4
// CS 3318 - Introduction to Computer Security

// Implement the RC4 stream cipher in C++.
// User should be able to enter any key that is 5 bytes to 32 bytes long.
// Be sure to discard the first 3072 bytes of the pseudo random numbers.
// THE KEY OR THE INPUT TEXT MUST NOT BE HARD CODED IN THE PROGRAM.
// You should write TWO separate programs: encryption and decryption.
// The encryption program should input the ciphertext file and output a
// cipher text in hex. The decryption program should input the cipher
// text file in hex and output the ciphertext.

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
    char *encrypt(char *ciphertext);

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

// Encrypt the ciphertext
char *RC4::encrypt(char *ciphertext)
{
    char stream;
    int ciphertext_len;
    ciphertext_len = strlen(ciphertext);
    for (int i = 0; i <= ciphertext_len; i++)
    {
        stream = PRGA();
        ciphertext[i] = ciphertext[i] ^ stream;
    }
    return ciphertext;
}

int main()
{

    ifstream inputFile;
    string fileName;
    string userkey;
    string ciphertext_str;

    cout << "Enter the file name  you wish to decrypt: " << endl;
    cin >> fileName;
    cout << endl;

    cout << "Enter a 5 byte to 32 byte long key to decrypt with: " << endl;
    cin >> userkey;
    cout << endl;

    // Open the file
    inputFile.open(fileName.c_str(), ios::in);

    if (inputFile.is_open())
    {
        getline(inputFile, ciphertext_str);
    }

    char ciphertext[1000];

    for (int i = 0; i <= ciphertext_str.length(); i++)
    {
        ciphertext[i] = ciphertext_str[i];
    }

    char key[32];
    for (int i = 0; i <= userkey.length(); i++)
    {
        key[i] = userkey[i];
    }

    // Declare two objects for encryption and decryption
    RC4 Decode;

    /*
    int ciphertext_len = strlen(ciphertext);
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

    // Print the ciphertext that is going to be decrypted
    cout << "Ciphertext being decrypted: " << endl;
    cout << ciphertext << endl
         << endl;

    Decode.KSA(key);
    // Print the decrypted ciphertext found with the key
    char *newplaintext = Decode.encrypt(ciphertext);
    cout << "Decrypted plaintext: " << endl;
    cout << newplaintext << endl
         << endl;

}
