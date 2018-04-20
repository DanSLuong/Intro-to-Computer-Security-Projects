/**
* @author danny
*/

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;


// Function to check if value is prime or not
static bool prime(int n) {
    if (n % 2 == 0)
    {
        return false;
    }
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

// Function to check limits of g and p
static bool gpLimits(int n) {
	if (0 < n && n < 10001) {
		return true;
	}
	return false;
}

// Function to check the limist of a and b
static bool abLimits(int n) {
	if (0 < n && n < 101) {
		return true;
	}
	return false;
}


int main(){
	int a1,a2, b1, b2, g, p;
	int publicA, publicB, secretA, secretB;

    cout << "Prime value for g between 1 to 10000" << endl;
    cin >> g;
	// Checks if the value is prime and between 1 to 10000
	while (!gpLimits(g)||!prime(g)) {
		cout << "Not a prime value between 1 to 10000. Try again" << endl;
		cin >> g;
	}
	

    cout << "Prime value for p between 1 to 10000" << endl;
    cin >> p;
	// Checks if the value is prime and between 1 to 10000
	while (!gpLimits(g) || !prime(g)) {
		cout << "Not a prime value between 1 to 10000. Try again" << endl;
		cin >> g;
	}

    cout << "User A, enter a number a in the range of 1 to 100" << endl;
    cin >> a1;
	// Checks if the value is between 1 to 100
	while (!abLimits(a1)) {
		cout << "Not a value between 1 to 100. Try again" << endl;
		cin >> a1;
	}
	a2 = a1;

    cout << "User B, enter a number b in the range of 1 to 100" << endl;
    cin >> b1;
	// Checks if the value is between 1 to 100
	while (!abLimits(b1)) {
		cout << "Not a value between 1 to 100. Try again" << endl;
		cin >> b1;
	}
	b2 = b1;


	// public key of A by publicA = (g^a)mod(p)
	publicA = g;
	while (a1 > 1) {
		publicA *= g;
		publicA %= p;
		a1--;
	}
	cout << "public key of A: " << publicA << endl;


	// public key of B by publicB = (g^b)mod(p)
	publicB = g;
	while (b1 > 1) {
		publicB *= g;
		publicB %= p;
		b1--;
	}
	cout << "public key of B: " << publicB << endl;


	// Secret key for A using public key of B
	secretA = publicB;
	while (a2 > 1) {
		secretA *= publicB;
		secretA %= p;
		a2--;
	}
	cout << "secret key computed using public key of B: " << secretA << endl;


	// Secret key for B using public key of A
	secretB = publicA;
	while (b2 > 1) {
		secretB *= publicA;
		secretB %= p;
		b2--;
	}
	cout << "secret key computed using public key of A: " << secretB << endl;
    
	// Compare to see if the two secret keys match
	if (secretA == secretB) {
		cout << "the two users share a common secret key" << endl;
	}
	else {
		cout << "they do not match" << endl;
	}

	system("pause");
}