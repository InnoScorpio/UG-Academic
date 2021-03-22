// XORBinaryEncryption.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
 
bool encrypt(bool a, bool key) {
	return a ^ key;
}

bool decrypt(bool a, bool key) {
	return a ^ key;
}


int main() {
	bool p_text[8] = { 0,0,0,0,0,0,0,0 };
	bool c_text[8] = { 0,0,0,0,0,0,0,0 };
	bool e_key[8] = { 0,0,0,0,0,0,0,0 };

	//Get plain text
	for (int i = 0; i < 8; i++) {
		cout << "Enter plain text bit #" << i + 1 << " ";
		cin >> p_text[i];
	}
	cout << endl;
	//Get Key
	for (int i = 0; i < 8; i++) {
		cout << "Enter secret key bit #" << i + 1 << " ";
		cin >> e_key[i];
	}

	cout << "Encryption ..." << endl;
	for (int j = 0; j < 8; j++) {
		c_text[j] = encrypt(p_text[j], e_key[j]);
	}
	cout << "Plain Text :   ";
	for (int i = 0; i < 8; i++) {
		cout << p_text[i] << " ";
	}
	cout << endl;
	cout << "Secret Key:   ";
	for (int i = 0; i < 8; i++) {
		cout << e_key[i] << " ";
	}
	cout << endl;
	cout << "Ciphered Text: ";
	for (int i = 0; i < 8; i++) {
		cout << c_text[i] << " ";
	}

	cout << endl;

	cout << "XOR Decryption ..." << endl;
	cout << "Ciphered Text: ";
	for (int i = 0; i < 8; i++) {
		cout << c_text[i] << " ";
	}
	cout << endl;

	cout << "Secret Key :   ";
	for (int i = 0; i < 8; i++) {
		cout << e_key[i] << " ";
	}
	cout << endl;

	cout << "Plain Text :   ";
	for (int j = 0; j < 8; j++) {
		cout << decrypt(c_text[j], e_key[j]) << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}