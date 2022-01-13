#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(void)
{
    srand(time(NULL));

    long double x, y;
    long int successo = 0;
    long double risultato;
    long long unsigned totale_lanci;

    cout << "Inserisci un numero di lanci: ";
    cin >> totale_lanci;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Errore! \nInserisci un numero di lanci: ";
        cin >> totale_lanci;
    }

    clock_t start, end;
    double tempo;
    start = clock();

    for (int i = 0; i < totale_lanci; i++)
    {
        x = ((long double)rand()) / RAND_MAX * 2.0 - 1.0;
        y = ((long double)rand()) / RAND_MAX * 2.0 - 1.0;

        if (((x * x) + (y * y)) <= 1)
        {
            successo++;
            //cout << x << ' ' << y << endl;
        }
    }

    end = clock();
    tempo = ((double)(end - start)) / CLOCKS_PER_SEC;

    risultato = ((long double)successo / totale_lanci) * 4; //approssimazione del pi greco

    cout << endl
         << "Il risultato e': " << risultato << endl
         << "Totale successi: " << successo << endl
         << "Totale lanci: " << totale_lanci << endl
         << "\nTempo impiegato: " << tempo << " secondi!\n\n\n";
}
