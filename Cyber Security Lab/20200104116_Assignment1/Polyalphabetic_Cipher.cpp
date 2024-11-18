#include<bits/stdc++.h>
using namespace std;

int main()
{
    string pt, ct, key, rt;
    int i,j;

    cout << "enter the plain text: ";
    cin >> pt;
    cout << "enter the key: ";
    cin >> key;

    //length of plaintext equal to length of key
    j=0;

    for(i=key.length();i<pt.length();i++)
    {
        if(j==key.length())
            {
                j=0;
            }
        key+=key[j];
        j++;
    }
    //cout << "new key is: " << key;
    cout << endl;

    //converting plain text to cipher text (encryption)
    for(i=0;i<pt.length();i++)
    {
        ct += (((pt[i]-'a')+(key[i]-'a'))%26)+'a';
    }
    cout << "cipher text is: " << ct << endl;

    //converting cipher text to plain text (decryption)
    for(i=0;i<ct.length();i++)
    {
        if(ct[i]<key[i])
        {
            rt += 26+((ct[i]-'a')-(key[i]-'a'))+'a';
        }
        else
            rt += (((ct[i]-'a')-(key[i]-'a'))%26)+'a';
    }

    cout << "plain text is: " << rt << endl;
}
//qwertyuiopasdfghjklzxcvbnm
