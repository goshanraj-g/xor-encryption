#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <sstream>

using namespace std;

// unsigned integer of 8 bits
vector<uint8_t> key = {0xC8, 0xF8, 0x23, 0xFF};

vector<uint8_t> encryptMessage(string message)
{

    return key;
};

string encryptMessage(vector<uint8_t> message);

int main()
{
    int input;
    cout << "Encrypt [1] or Decrypt [2]" << endl;
    cin >> input;

    if (input == 1)
    {
        string plaintext;

        cout << "Enter plaintext" << endl;
        cin >> plaintext;

        encryptMessage(plaintext);
    }

    else if (input == 2)
    {
        string ciphertext;
        cout << "Enter ciphertext" << endl;
        getline(cin, ciphertext);
        istringstream iss(input);
        string byteStr

            decryptMessage(ciphertext);
    }
    else
    {
        cout << "Invalid Input... Terminating Program..." << endl;
        exit;
    }
    return 0;
}