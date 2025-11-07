#include <iostream>
#include <string>
using namespace std;

class Livre {
    string titre;
    float prix;
public:
    Livre() {}
    Livre(string t, float p) {
        titre = t;
        prix = p;
    }
    void saisir() {
        cout << "Titre : ";
        cin.ignore();
        getline(cin, titre);
        cout << "Prix : ";
        cin >> prix;
    }
    void afficher() {
        cout << "Titre : " << titre << ", Prix : " << prix << " DH" << endl;
    }
};

int main() {
    int n;
    cout << "Combien de livres voulez-vous creer ? ";
    cin >> n;

    Livre* tab = new Livre[n];

    for (int i = 0; i < n; i++) {
        cout << "\nLivre " << i + 1 << " :" << endl;
        tab[i].saisir();
    }

    cout << "\nListe des livres :" << endl;
    for (int i = 0; i < n; i++) {
        tab[i].afficher();
    }

    delete[] tab;
    return 0;
}
