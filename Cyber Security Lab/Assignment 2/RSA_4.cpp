#include<bits/stdc++.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
using namespace std;

long int p, q, n, t, flag, e, d, temp[100], j, m[100], en[100], i;
string msg; // Change the data type of msg to string

int prime(long int);
void encrypt();
void decrypt();
void printValues();
void printPossibleValues();

int main()
{
    cout << "\nEnter the value of p: ";
    cin >> p;
    flag = prime(p);
    if (flag == 0)
    {
        cout << "\nWRONG INPUT\n";
        getch();
        exit(1);
    }

    cout << "\nEnter the value of q: ";
    cin >> q;
    flag = prime(q);
    if (flag == 0 || p == q)
    {
        cout << "\nWRONG INPUT\n";
        getch();
        exit(1);
    }

    cin.ignore(); // Clear the input buffer
    cout << "\nEnter the message: ";
    getline(cin, msg); // Read the entire line

    n = p * q;
    t = (p - 1) * (q - 1);

    // Calculate e and d directly
    for (i = 2; i < t; i++)
    {
        if (t % i == 0)
            continue;
        flag = prime(i);
        if (flag == 1 && i != p && i != q)
        {
            e = i;
            d = 1;
            while ((d * e) % t != 1)
            {
                d++;
            }
            break;
        }
    }

    printValues();
    printPossibleValues();
    encrypt();
    decrypt();

    return 0;
}

void printValues()
{
    cout << "\nThe number e should be less than " << t;
    cout << "\nand greater than 1.";
    cout << "\nThus, (i * e) %% lambda_n = 1, (" << d << " * " << e << ") %% " << t << " = 1";
    cout << "\nThe value of n is " << n;
    cout << "\nThe value of lambda_n is " << t;
    cout << "\nThe value of e is " << e;
    cout << "\nThe value of d is " << d;
    cout << "\nEnter the message: " << msg << endl;
}

void printPossibleValues()
{
    // Print e and d directly, as there is no array to store multiple values
    cout << "\nPOSSIBLE VALUES OF e AND d ARE\n";
    cout << "\n" << e << "\t" << d;
}

int prime(long int pr)
{
    int i;
    j = sqrt(pr);
    for (i = 2; i <= j; i++)
    {
        if (pr % i == 0)
            return 0;
    }
    return 1;
}

void encrypt()
{
    long int pt, ct, key = e, k, len;
    i = 0;
    len = msg.length();
    while (i != len)
    {
        pt = m[i];
        pt = pt - 96;
        k = 1;
        for (j = 0; j < key; j++)
        {
            k = k * pt;
            k = k % n;
        }
        temp[i] = k;
        ct = k + 96;
        en[i] = ct;
        i++;
    }
    en[i] = -1;
    cout << "\nThe encrypted message is: ";
    for (i = 0; en[i] != -1; i++)
        cout << (char)en[i];
    cout << endl;
}

void decrypt()
{
    long int pt, ct, key = d, k;
    i = 0;
    while (en[i] != -1)
    {
        ct = temp[i];
        k = 1;
        for (j = 0; j < key; j++)
        {
            k = k * ct;
            k = k % n;
        }
        pt = k + 96;
        m[i] = pt;
        i++;
    }
    m[i] = -1;
    cout << "\nThe decrypted message is: ";
    for (i = 0; m[i] != -1; i++)
        cout << (char)m[i];
    cout << endl;
}

