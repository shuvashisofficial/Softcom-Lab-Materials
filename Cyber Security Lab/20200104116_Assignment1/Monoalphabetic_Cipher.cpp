#include<bits/stdc++.h>
using namespace std;

int main()
{
	string plainText;
    string key;
    string key2="abcdefghijklmnopqrstuvwxyz";

	cout << "Enter the plain text: ";
	cin >> plainText;

    cout << "Enter the key: ";
    cin >> key;

    int n = plainText.length(), temp=0;

	string ency;
	for(int i=0;i<n;++i){
		temp = plainText[i]-'a';
		ency+=key[temp];
	}

	cout << "Monoalphabetic_Cipher_encryption: " << ency << endl;

    temp = 0;
    string dency;
	for(int i=0;i<n;++i){
		for(int j=0; j<key.length(); j++)
        {
            if(ency[i] == key[j])
            {
                temp = j;
                break;
            }
        }

		dency += key2[temp];
	}
	cout << "Monoalphabetic_Cipher_decryption: " << dency << endl;

	return 0;
}
//key=QWERTYUIOPASDFGHJKLZXCVBNM
//plain_text=attack
