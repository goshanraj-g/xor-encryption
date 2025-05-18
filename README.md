# XOR Encryption CLI Tool

A simple command-line tool written in C++ that encrypts and decrypts text using XOR encryption with a fixed key.

Before encryption or decryption, the program allows you to enter your own key.  
The key must be entered as space-separated hex values.  
Example:  
`vector<uint8_t> key = {0xC8, 0xF8, 0x23, 0xFF}`  
- The key can be of any length (1 byte or more)  
- It's also used cyclically when encrypting/decrypting
