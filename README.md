## 1. Servere
        Pentru gasirea nivelului de alimentare optim, se realizeaza o cautare binara intre marginele minime si maxime pe care le poate lua curentul. 
        Jumatatea in care se continua cautarea la fiecare pas este data de puterea finala a cluster-ului calculata in valorile din capete: daca marginea inferioara are puterea finala mai mare, inseamna ca alimentarea optima este mai aproape de margine inferiroara si se ignora jumatatea superioara. La fel si vice versa.
        Cautarea se face pana cand puterea finala a mijlocului este egala cu puterea maxima gasita pana in acel moment, cu o marja de eroare de 0.001.
* Complexitate fiecare pas de cautare (3 parcurgeri ale vectorilor pentru
determinarea minimului pentru left, right si middle) : O(3n)
* Complexitate cautare binara: O(log n)
* Complexiate finala: O(n  * log n)
## 2. Colorare
        Fiecare grupa de dreptunghiuri (Horizintal sau Vertical) adaugate la un mode deja existent, alaturi de ultimul grup din modelul existent, va genera un numar de posibilitati de colorare ale noului grup:
            * H H => 3 posibilitati 
            * H V => 1 posibilitate
            * V H => 2 posibilitati
            * V V => 2 posibilitati
        Fiecare nou grup va multiplica numarul de moduri de colorare ale modelului precedent.
* Complexitate parcurgere grupuri: O(n), n = numar de perechi din fisierul de intrare
* Complexitate calculare numar posibilitati: O(2log c*n), c = numarul maxim dintr-o pereche de intrare
* Complexiate finala: O(2log c*n + n) = O(n)
## 3. Compresie
        Se conrtuiesc 2 vectori (1 pentru fiecare vector original) in care elementul i este suma elementelor 0..i din vectorul corespunzator.
        Daca sumele tuturor elementelor din fiecare vector original nu sunt egale, inseamna ca nu exista o modalitate de compresie a vectorilor astfel incat ei sa devina egali.
        In caz contrar, se numara numarul de elemnte egale din cei 2 vectori de sume. Fiecare element din vectorii de sume reprezinta compresia tuturor elemntelor pana la acel indice din vectorii orginali. 2 elemnte egale reprezinta 2 compresii ale elemntelor egale. Urmatoarele elemente din vectorii de sume vor contine compresia gasita precedent plus restul de elemnte pana la indicele curent din vectorii originali. Daca se gaseste alta pereche de sume egale, inseamna ca am gasit inca o pereche de compresii egale, pe langa cele gasite precedent.
        Vectorii de sume sunt sortati (la fiecare pas, la suma precedenta, se adauga un numar pozitiv din vectorii originali) si numararea sumelor egale se realizeaza prin incrementarea indicelui curent din vectorul de sume cu elemntul curent mai mic. 
* Complexitate creare vectori de sume partiale: O(n + m)
* Complexitate parcurgere vectori:
    * O(1) daca problema nu are solutie
    * O(n + m) daca problema are solutie
* Complexitate finala: O(n + m)

## 4. Criptat
        Pentru gasirea parolei de lungime maxima cu o litera dominanta, se gaseste intai litera cu cele mai multe aparitii in toate cuvintele. Apoi cuvintele sunt sortate dupa proportia din intregul cuvant a literei cu cele mai multe aparitii.
        Se adauga cuvinte in solutie pana cand pondered literei cu cele mai multe aparitii scade sub 1/2.
* Complexitate citire: O(n)
* Complexitate sortare: O(nlog n)
* Complexitate adaugare cuvant in solutie: O(n)
* Complexitate finala: O(nlog n)
 
## 5. Oferta
        Pentru calcularea costului minim final, produsele sunt luate secvential. La adaugarea fiecarui produs in solutie, se verifica pretul total curent:
        - produsul curent este lasat singur si se ia suma minima a produselor precedent;
        - produsul curent este grupat cu produsul precedent si se ia suma minima a produselor precedente produsului precedent;
        - produsul curent este grupat cu ultimele 2 produse si se ia suma minima a produselor in afara ultimelor 2 ultime produse;
        In solutie se adauga suma minima din cele 3 situatii descrise mai sus.
* Complexitate parcurgere produse: O(n)
* Complexiate decidere oferta: O(3)
* Complexitate finala: O(n)