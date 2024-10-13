#include <algorithm>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

int N;
char **words;
int frecv[27];
char maxf_char;

void find_maxf_char() {
    for (int i = 0; i < 26; i++) {
        if (frecv[i] > frecv[maxf_char]) {
            maxf_char = i;
        }
    }
}

bool compare_words(char *a, char *b) {
    double size_a = 0, size_b = 0;
    double aparitions_a = 0, aparitions_b = 0;
    double rating_a, rating_b;
    int j;
    for (j = 0; a[j] != '\0'; j++) {
        if (a[j] == maxf_char + 97) {
            aparitions_a++;
        }
    }
    size_a = j;
    rating_a = aparitions_a / size_a;

    for (j = 0; b[j] != '\0'; j++) {
        if (b[j] == maxf_char + 97) {
            aparitions_b++;
        }
    }
    size_b = j;
    rating_b = aparitions_b / size_b;

    return rating_a > rating_b;
}

int main() {
    FILE *INPUT = fopen("criptat.in", "r");
    ofstream OUTPUT("criptat.out");

    fscanf(INPUT, "%d", &N);
    words = new char*[N];
    // citire cuvinte si inregistrarea literelor intr-un vector
    // de frecventa
    for (int i = 0; i < N; i++) {
        words[i] = new char[1000];
        fscanf(INPUT, "%s\n", words[i]);
        int j = 0;
        while (words[i][j] != '\0') {
            frecv[words[i][j++] - 97] += 1;
        }
    }
    // gasirea literei cu cele mai multe aparitii
    find_maxf_char();
    // sortare dupa ponderea literei cu cele mai multe aparitii
    // din lungimea cuvantului
    std::sort(words, words + N, compare_words);

    double total_len = 0, prev_len;
    double num_maxf_char = 0, prev_num_maxf;
    // adaugare prim cuvant in solutie
    for (int j = 0; words[0][j] != '\0'; j++) {
        total_len++;
        if (words[0][j] == maxf_char + 97) {
            num_maxf_char++;
        }
    }

    // adaugare cuvant in solutie si verificarea conditiei de
    // litera dominanta
    for (int i = 1; i < N  && (num_maxf_char / total_len) > 0.5; i++) {
        prev_len = total_len;
        prev_num_maxf = num_maxf_char;
        for (int j = 0; words[i][j] != '\0'; j++) {
            total_len++;
            if (words[i][j] == maxf_char + 97) {
                num_maxf_char++;
            }
        }
    }

    OUTPUT << (int)prev_len << "\n";

    fclose(INPUT);
    OUTPUT.close();
}
