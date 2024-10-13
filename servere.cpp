#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

double mod(double a) {
    if (a < 0) {
        return -a;
    } else {
        return a;
    }
}

double apply(double *C, double *P, int size, double current) {
    double min = 1e9;
    double val;
    for (int i = 0; i < size; i++) {
        val = P[i] - mod(C[i] - current);
        if (val < min) min = val;
    }
    return min;
}

int main() {
    FILE *INPUT = fopen("servere.in", "r");
    ofstream OUTPUT("servere.out");
    int size;
    fscanf(INPUT, "%d", &size);
    double C[size];
    double P[size];

    for (int i = 0; i < size; i++) {
        fscanf(INPUT, "%lf", P + i);
    }
    for (int i = 0; i < size; i++) {
        fscanf(INPUT, "%lf", C + i);
    }

    // puterea maxima gasita pana la momentul actual
    double max = -1e9 - 1;
    double left = -1e9;
    double right = 1e9;
    double middle;
    double crtPower;

    while (1) {
        middle = (left + right) / 2;
        crtPower = apply(C, P, size, middle);

        // conditie de oprire
        if (mod(crtPower - max) <= 1e-3) {
            break;
        }
        if (crtPower > max) {
            max = crtPower;
        }

        // solutia optima este mai aproape de capatul "right"
        if (apply(C, P, size, right) > apply(C, P, size, left)) {
            left = middle;
        } else {
            right = middle;
        }
    }
    OUTPUT << fixed << setprecision(1) << max << "\n";
    OUTPUT.close();
    fclose(INPUT);
}
