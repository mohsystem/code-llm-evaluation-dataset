
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_PRIME 1000

int is_prime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int generate_prime(int min_val, int max_val) {
    int prime;
    do {
        prime = rand() % (max_val - min_val + 1) + min_val;
    } while (!is_prime(prime));
    return prime;
}

int mod_inverse(int a, int m) {
    for (int i = 1; i < m; i++) {
        if ((a * i) % m == 1) return i;
    }
    return -1;
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void generate_keypair(int p, int q, int *e, int *d, int *n) {
    *n = p * q;
    int phi = (p - 1) * (q - 1);
    *e = 2;
    while (*e < phi) {
        if (gcd(*e, phi) == 1) break;
        (*e)++;
    }
    *d = mod_inverse(*e, phi);
}

int* encrypt(int e, int n, char* plaintext) {
    int len = strlen(plaintext);
    int* cipher = malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        cipher[i] = (int)pow(plaintext[i], e) % n;
    }
    return cipher;
}

char* decrypt(int d, int n, int* ciphertext, int len) {
    char* plain = malloc((len + 1) * sizeof(char));
    for (int i = 0; i < len; i++) {
        plain[i] = (char)(pow(ciphertext[i], d) % n);
    }
    plain[len] = '\\0';
    return plain;
}

int main() {
    srand(time(NULL));
    
    int p = generate_prime(100, MAX_PRIME);
    int q = generate_prime(100, MAX_PRIME);
    int e, d, n;
    generate_keypair(p, q, &e, &d, &n);
    
    char message[1000];
    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\\n")] = 0;
    
    int len = strlen(message);
    int* encrypted_msg = encrypt(e, n, message);
    
    printf("Encrypted message: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", encrypted_msg[i]);
    }
    printf("\\n");
    
    char* decrypted_msg = decrypt(d, n, encrypted_msg, len);
    printf("Decrypted message: %s\\n", decrypted_msg);
    
    free(encrypted_msg);
    free(decrypted_msg);
    
    return 0;
}
