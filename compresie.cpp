#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    FILE *INPUT = fopen("compresie.in", "r");
    ofstream OUTPUT("compresie.out");
    int counter = 0;

    int a;
    fscanf(INPUT, "%d", &a);
    int A[a];
    fscanf(INPUT, "%d", A);
    // creare prim vector de sume
    for (int i = 1; i < a; i++) {
        fscanf(INPUT, "%d", A + i);
        A[i] += A[i - 1];
    }

    int b;
    fscanf(INPUT, "%d", &b);
    int B[b];
    fscanf(INPUT, "%d", B);
    // creare al doilea vector de sume
    for (int i = 1; i < b; i++) {
        fscanf(INPUT, "%d", B + i);
        B[i] += B[i - 1];
    }

    // sumele finale nu sunt egale => nu exista solutie
    if (A[a - 1] != B[b - 1]) {
        OUTPUT << -1;
    } else {
        // parcurgere vectori sortati
        // + numarare elemnte egale
        int i = 0, j = 0;
        while (i < a && j < b) {
            if (A[i] == B[j]) {
                i++;
                j++;
                counter++;
            } else if (A[i] < B[j]) {
                i++;
            } else {
                j++;
            }
        }
        OUTPUT << counter;
    }
    OUTPUT.close();
    fclose(INPUT);
}
