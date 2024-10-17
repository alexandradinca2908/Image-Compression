/*DINCA Alexandra-Cristina - 311CD*/

tema2.c:
    In main sunt citite argumentele din linia de comanda. In functie de flag, se trateaza altfel elementele din argv[]. Apoi, in functie de cerinta, se executa una din cele 3 comenzi: statistici, compresie, decompresie. Toate 3 se folosesc de o matrice de pixeli si un arbore cuaternar, care se construiesc similar pe tot parcursul algoritmului.

cerinta1.h:
    Pentru cerinta 1 au fost folosite atat functii principale, cat si cateva ajutatoare. 
        - functia de alocarea a memoriei pentru arbore
        - functia principala de compresie: calculeaza scorul similaritatii conform formulelor date, apoi, daca acesta trece de factorul dat, se apeleaza recursiv copiii nodului curent pana cand mean <= factor, moment in care se creeaza o frunza ce ia valoarea RGB calculata
        - functii max si min, pentru calcularea minimului si al maximului intre 2 numere intregi
        - functia de calculare a nivelurilor arborelui: apeleaza recursiv copiii arborelui pana la intalnirea unei frunze, moment in care se incepe adunarea nodurilor de jos in sus. La final, se calculeaza maximul dintre cele 4 valori obtinute si se returneaza max + 1 (radacina)
        - functia de determinare a nivelului minim: functioneaza la fel ca functia anterioara, folosind min in loc de max
        - functia de calculare a numarului de frunze: prin apel recursiv, aduna cate 1 la suma principala atunci cand ajunge la o frunza
        - functia de aflare a celei mai mari sectiuni: determinand nivelul minim al unei frunze, returneaza cea mai mare latura folosind formula side = size / pow(2, minLevel)
        - functia de eliberare a memoriei

cerinta2.h:
    Fisierul acesta contine doar 2 functii noi, iar restul sunt luate din cerinta1.h:
        - functia de printare recursiva a unui nivel: programul apeleaza recursiv nodurile arborelui pana se ajunge la nivelul dorit, dupa care datele sunt printate in format binar in functie de tipul nodului
        - functia de iteratie: aceasta functie o apeleaza pe cea anterioara pentru toate nivelurile arborelui

cerinta3.h:
    Pentru cerinta3, am rescris cateva din funtiile de la celelalte taskuri:
        - functia de adaugare a valorilor in arbore: algoritmul este identic cu cel de printare, singura diferenta fiind functionalitatea
        - functia de iteratie: aceasta parcurge nivelurile arborelui pana la citirea tuturor datelor din fisierul de intrare
        - functia de decompresie: modul de executie este similar cu algoritmul compresiei, datele fiind stocate intr-o matrice de pixeli inainte de a fi printate


Cerința 1 - Compresia fisierelor
Statistici_Test  0 ................................................. PASS
VALGRIND ........................................................... PASS
Statistici_Test  1 ................................................. PASS
VALGRIND ........................................................... PASS
Statistici_Test  2 ................................................. PASS
VALGRIND ........................................................... PASS
Statistici_Test  3 ................................................. PASS
VALGRIND ........................................................... PASS
Statistici_Test  4 ................................................. FAIL
Statistici_Test  5 ................................................. FAIL
Statistici_Test  6 ................................................. PASS
VALGRIND ........................................................... PASS
Statistici_Test  7 ................................................. PASS
VALGRIND ........................................................... PASS
Statistici_Test  8 ................................................. PASS
VALGRIND ........................................................... PASS
Statistici_Test  9 ................................................. PASS
VALGRIND ........................................................... PASS
Statistici_Test 10 ................................................. FAIL
Statistici_Test 11 ................................................. FAIL
Statistici_Test 12 ................................................. PASS
Statistici_Test 13 ................................................. PASS
Statistici_Test 14 ................................................. PASS
Statistici_Test 15 ................................................. PASS
Statistici_Test 16 ................................................. PASS
Statistici_Test 17 ................................................. PASS
Statistici_Test 18 ................................................. PASS
Statistici_Test 19 ................................................. PASS
Cerința 2 - Compresia fișierelor
Compresia_Test  0 .................................................. PASS
VALGRIND ........................................................... PASS
Compresia_Test  1 .................................................. PASS
VALGRIND ........................................................... PASS
Compresia_Test  2 .................................................. PASS
VALGRIND ........................................................... PASS
Compresia_Test  3 .................................................. PASS
VALGRIND ........................................................... PASS
Compresia_Test  4 .................................................. FAIL
Compresia_Test  5 .................................................. FAIL
Compresia_Test  6 .................................................. PASS
VALGRIND ........................................................... PASS
Compresia_Test  7 .................................................. PASS
VALGRIND ........................................................... PASS
Compresia_Test  8 .................................................. PASS
VALGRIND ........................................................... PASS
Compresia_Test  9 .................................................. PASS
VALGRIND ........................................................... PASS
Compresia_Test 10 .................................................. FAIL
Compresia_Test 11 .................................................. FAIL
Compresia_Test 12 .................................................. PASS
Compresia_Test 13 .................................................. PASS
Compresia_Test 14 .................................................. PASS
Compresia_Test 15 .................................................. PASS
Compresia_Test 16 .................................................. PASS
Compresia_Test 17 .................................................. PASS
Compresia_Test 18 .................................................. PASS
Compresia_Test 19 .................................................. PASS
Cerința 3 - Decompresia fișierelor
Decompresia_Test  0 ................................................ PASS
VALGRIND ........................................................... PASS
Decompresia_Test  1 ................................................ PASS
VALGRIND ........................................................... PASS
Decompresia_Test  2 ................................................ PASS
VALGRIND ........................................................... PASS
Decompresia_Test  3 ................................................ PASS
VALGRIND ........................................................... PASS
Decompresia_Test  4 ................................................ PASS
VALGRIND ........................................................... PASS
Decompresia_Test  5 ................................................ PASS
VALGRIND ........................................................... PASS
Decompresia_Test  6 ................................................ PASS
VALGRIND ........................................................... PASS
Decompresia_Test  7 ................................................ PASS
VALGRIND ........................................................... PASS
Decompresia_Test  8 ................................................ PASS
VALGRIND ........................................................... PASS
Decompresia_Test  9 ................................................ PASS
VALGRIND ........................................................... PASS
Decompresia_Test 10 ................................................ PASS
Decompresia_Test 11 ................................................ PASS
Decompresia_Test 12 ................................................ PASS
Decompresia_Test 13 ................................................ PASS
Decompresia_Test 14 ................................................ PASS
Decompresia_Test 15 ................................................ PASS
Decompresia_Test 16 ................................................ PASS
Decompresia_Test 17 ................................................ PASS
Decompresia_Test 18 ................................................ PASS
Decompresia_Test 19 ................................................ PASS
Cerinta 1 : 16
Cerinta 2 : 24.0
Cerinta 3 : 30.0
Total     : 70.0
Bonus     : 18.0
Ai acumulat 70.0p din maxim 80p! :(
