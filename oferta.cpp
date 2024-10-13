#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int *prods;
int N;
int K;

double min2(double a, double b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

double min3(double a, double b, double c) {
    if (a < b) {
        if (a < c) {
            return a;
        } else {
            return c;
        }
    } else if (b < c) {
        return b;
    } else {
        return c;
    }
}

// calculeaza oferta de 2 produse grupate
// cu al doilea produs pe locul i
double oferta1(int i) {
    return prods[i] + prods[i - 1] - min2(prods[i], prods[i - 1]) / 2.0;
}

// calculeaza oferta de 3 produse grupate
// cu al trilea produs pe locul i
double oferta2(int i) {
    return prods[i] + prods[i - 1] + prods[i - 2] -
            min3(prods[i], prods[i - 1], prods[i - 2]);
}

int main() {
    FILE *INPUT = fopen("oferta.in", "r");
    ofstream OUTPUT("oferta.out");

    fscanf(INPUT, "%d", &N);
    fscanf(INPUT, "%d", &K);
    prods = new int[N];
    for (int i = 0; i < N; i++) {
        fscanf(INPUT, "%d", prods + i);
    }

    // completarea primelor 3 cazuri
    double *dp = new double[N];
    dp[0] = prods[0];
    dp[1] = oferta1(1);
    dp[2] = min3(dp[1] + prods[2],
                dp[0] + oferta1(2),
                oferta2(2));
    // adaugarea urmatoarelor produse in solutie si
    // gasirea sumei minime
    for (int i = 3; i < N; i++) {
        dp[i] = min3(dp[i - 1] + prods[i],
                    dp[i - 2] + oferta1(i),
                    dp[i - 3] + oferta2(i));
    }
    OUTPUT << fixed << setprecision(1) << dp[N - 1] << "\n";
    OUTPUT.close();
    fclose(INPUT);
}
