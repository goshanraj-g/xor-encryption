#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <sstream>
#include <cstdio>

using namespace std;

// unsigned integer of 8 bits
vector<uint8_t> key = {0xC8, 0xF8, 0x23, 0xFF};

// can do a modulus of N (where n is the size of the key), and we can associate each remainder with a value in N

vector<uint8_t> encryptMessage(string plaintext)
{
    vector<uint8_t> ciphertext;
    for (int i = 0; i < plaintext.size(); i++)
    {
        ciphertext.push_back(plaintext[i] ^ key[i % key.size()]);
    }
    return ciphertext;
};

string decryptMessage(vector<uint8_t> ciphertext)
{
    string plaintext = "";

    for (int i = 0; i < ciphertext.size(); i++)
    {
        plaintext += (ciphertext[i] ^ key[i % key.size()]);
    }
    return plaintext;
};

int main()
{
    int input;
    cout << "Encrypt [1] or Decrypt [2]" << endl;
    cin >> input;
    cin.ignore();

    if (input == 1)
    {
        string plaintext;

        cout << "Enter plaintext" << endl;
        cin >> plaintext;

        vector<uint8_t> ciphertext = encryptMessage(plaintext);

        cout << "Encrypted Message: ";
        for (uint8_t byte : ciphertext) // for each element in cipher text, copy it to byte
        {
            printf("%02x ", byte);
        };
        cout << endl;
    }
    else if (input == 2)
    {
        string message;
        string inputCiphertext;
        cout << "Enter ciphertext" << endl;
        getline(cin, inputCiphertext);      // get the whole line
        istringstream iss(inputCiphertext); // extract each hex 'word' in input
        string byteStr;                     // temp var to write to
        vector<uint8_t> ciphertext;

        while (iss >> byteStr) // while iss is not empty (word bank)
        {
            ciphertext.push_back(static_cast<uint8_t>(stoi(byteStr, nullptr, 16))); // adds the hexadecimal value to vector
        };

        message = decryptMessage(ciphertext);
        cout << message << endl;
    }
    else
    {
        cout << "Invalid Input... Terminating Program..." << endl;
        exit;
    }
    return 0;
}