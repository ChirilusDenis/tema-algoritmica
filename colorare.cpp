#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

long MOD = 1000000007;
int fastPow(long base, long exp) {
    if (exp == 0) {
        return 1;
    }
    int tmp = 1;
    while (exp != 1) {
        if (exp % 2 == 0) {
            base = (int)((1L * base * base) % MOD);
            exp /= 2;
        } else {
            tmp = (int)((1L * tmp * base) % MOD);
            exp--;
        }
    }
    return (int)((1L * base * tmp) % MOD);
}

int main() {
    FILE *INPUT = fopen("colorare.in", "r");
    ofstream OUTPUT("colorare.out");
    int size;
    fscanf(INPUT, "%d", &size);

    unsigned long counter;  // numararea tuturor posibilitatilor
    long nrTwo = 0;
    long nrThree = 0;
    int crt;
    char crtSymbol;
    char prevSymbol;
    fscanf(INPUT, "%d", &crt);
    fscanf(INPUT, "%c", &crtSymbol);
    while (crtSymbol == ' ') {
        fscanf(INPUT, "%c", &crtSymbol);
    }

    if (crtSymbol == 'H') {
        counter = 6;  // posibilitati de colorare a grupului orizontal
                    // initial
        nrThree += crt - 1;
    } else {
        counter = 3;  // posibilitati de colorare a grupului vertical
                    // initial
        nrTwo += crt - 1;
    }

    for (int i = 1; i < size; i++) {
        prevSymbol = crtSymbol;
        fscanf(INPUT, "%d", &crt);
        fscanf(INPUT, "%c", &crtSymbol);
        while (crtSymbol == ' ') {
            fscanf(INPUT, "%c", &crtSymbol);
        }

        if (crtSymbol == 'H') {
            if (prevSymbol == 'H') {
                nrThree += crt;
            } else {
                nrTwo++;
                nrThree += crt - 1;
            }
        } else {
            if (prevSymbol == 'H') {
                nrTwo += crt - 1;
            } else {
                nrTwo += crt;
            }
        }
    }
    counter = (counter * fastPow(2, nrTwo)) % MOD;
	counter = (counter * fastPow(3, nrThree)) % MOD;
    OUTPUT << counter;
    OUTPUT.close();
    fclose(INPUT);
}
