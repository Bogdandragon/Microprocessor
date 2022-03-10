# Microprocessor
First assignment for Computer Programming class - 2021

TASK 1: 
    Considerand numarul introdus, se analizeaza bit cu bit pornind de la cel mai semnificativ: primii 3 dau valoarea lui N, urmatorii 2*N dau operatorii, iar urmatorii 4 dau dimensiunea operanzilor.
    Bitii se analizeaza cu ajutorul unei masti. Operatorii se stocheaza drept caractere intr-un vector.
    
TASK 2:
    Se cer de la tastatura numere dupa formula data in enunt, care se analizeaza pe rand pana se gasesc N+1 operanzi de dimensiunea data.
    Se executa in ordine operatiile si si se actualizeaza al doilea termen cu rezultatul obtinut. Se procedeaza analog pentru toate operatiile.
    Raspunsul final se afla in vectorul de operanzi, pe pozitia N+1.

TASK 3:
    Se calculeaza analog TASK 1 numarul operatorilor si dimensiunea operanzilor. Analog TASK 2, se cer numere corespunzator formulei.
    Se ia fiecare numar in parte si se adauga intr-o variabila temporara valorile corespunzatoare: se adauga i * 2 ^ k, unde k < dim si k >= 0, si i = valoarea bitului curent.
    k se actualizeaza pentru fiecare bit analizat, astfel incat se adauga un numar in vectorul operanzilor cand au fost analizati dim biti.
    Se calculeaza analog TASK 2 raspunsul final folosind N+1 numere din vectorul de operanzi.

TASK 4:
    Se folosesc TASK 1 si TASK 3 pentru a se citi datele necesare. Se cauta mai intai operatiile de inmultire si impartire.
    Pentru fiecare operatie de inmultire sau impartire, se efectueaza calculul si se salveaza rezultatul in cel de-al doilea operand de indice i, apoi se cauta inapoi toti operanzii legati de operandul i printr-o inmultire sau impartire si se actualizeaza cu rezultatul.
    Se analizeaza apoi toate operatiile. Daca se gaseste o adunare sau scadere, se realizeaza si se salveaza rezultatul in cel de-al doilea operand.
    Daca se gaseste o inmultire sau impartire, se copiaza primul operand in cel de-al doilea.
    Analog TASK 2, rezultatul se afla pe pozitia N+1 in vectorul de operanzi.
