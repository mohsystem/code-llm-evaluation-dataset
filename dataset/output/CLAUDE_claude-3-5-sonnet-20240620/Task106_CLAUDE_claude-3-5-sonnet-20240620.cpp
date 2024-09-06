
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int generate_prime(int min_val, int max_val) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(min_val, max_val);
    int prime = dis(gen);
    while (!is_prime(prime)) {
        prime = dis(gen);
    }
    return prime;
}

int mod_inverse(int a, int m) {
    for (int i = 1; i < m; i++) {
        if ((a * i) % m == 1) return i;
    }
    return -1;
}

pair<pair<int, int>, pair<int, int>> generate_keypair(int p, int q) {
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int e = 2;
    while (e < phi) {
        if (__gcd(e, phi) == 1) break;
        e++;
    }
    int d = mod_inverse(e, phi);
    return make_pair(make_pair(e, n), make_pair(d, n));
}

vector<int> encrypt(pair<int, int> pk, string plaintext) {
    int key = pk.first;
    int n = pk.second;
    vector<int> cipher;
    for (char c : plaintext) {
        cipher.push_back(pow(int(c), key) % n);
    }
    return cipher;
}

string decrypt(pair<int, int> pk, vector<int> ciphertext) {
    int key = pk.first;
    int n = pk.second;
    string plain;
    for (int c : ciphertext) {
        plain += char(pow(c, key) % n);
    }
    return plain;
}

int main() {
    int p = generate_prime(1000, 5000);
    int q = generate_prime(1000, 5000);
    auto keypair = generate_keypair(p, q);
    auto public_key = keypair.first;
    auto private_key = keypair.second;

    string message;
    cout << "Enter a message to encrypt: ";
    getline(cin, message);

    auto encrypted_msg = encrypt(public_key, message);
    cout << "Encrypted message: ";
    for (int c : encrypted_msg) cout << c << " ";
    cout << endl;

    string decrypted_msg = decrypt(private_key, encrypted_msg);
    cout << "Decrypted message: " << decrypted_msg << endl;

    return 0;
}
