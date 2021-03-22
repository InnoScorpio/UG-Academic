// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

int main(int argc, const char * argv[])
{
	    string plaintext;
	    cout << "Enter the plain text. :" << endl;
		cin >> plaintext;
		char   secretkey;
		cout << "Enter the secret key. :" << endl;
		cin >> secretkey;

		for (int temp = 0; temp < plaintext.size(); temp++)
			plaintext[temp] ^= secretkey;
		cout << "The encrypted data    = " << plaintext << endl;

		for (int temp = 0; temp < plaintext.size(); temp++)
			plaintext[temp] ^= secretkey; //notice we're using the exact same key, to unencrypt the data.
		cout << "The unencrypted data  = " << plaintext << endl;
		system("pause");
		return 0;
}
