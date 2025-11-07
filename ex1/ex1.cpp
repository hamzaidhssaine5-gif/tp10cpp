#include <iostream>
using namespace std;

int main() {
    int taille;
    cout << "Entrez la taille du tableau : ";
    cin >> taille;

    int* tableau = new int[taille];

    cout << "Entrez les " << taille << " valeurs :" << endl;
    for (int i = 0; i < taille; i++) {
        cout << "Valeur " << i + 1 << " : ";
        cin >> tableau[i];
    }

    cout << "\nLes valeurs saisies sont : ";
    for (int i = 0; i < taille; i++) {
        cout << tableau[i] << " ";
    }

    delete[] tableau;

    cout << "\nMémoire libérée avec succès." << endl;
    return 0;
}
