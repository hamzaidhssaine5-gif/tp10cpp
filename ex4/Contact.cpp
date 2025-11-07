#include <iostream>
#include <string>
using namespace std;

class Contact {
    string nom;
    string telephone;
    string email;

public:
    Contact(string n = "", string t = "", string e = "") {
        nom = n;
        telephone = t;
        email = e;
    }

    string getNom() const { return nom; }

    void afficher() const {
        cout << "Nom : " << nom << " | Tel : " << telephone << " | Email : " << email << endl;
    }
};

// Fonction pour supprimer un contact par nom
void supprimerContact(Contact** carnet, int& taille, string nom) {
    int index = -1;
    for (int i = 0; i < taille; i++) {
        if (carnet[i]->getNom() == nom) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Contact introuvable." << endl;
        return;
    }

    delete carnet[index];

    for (int i = index; i < taille - 1; i++) {
        carnet[i] = carnet[i + 1];
    }

    taille--;
    cout << "Contact supprime avec succes." << endl;
}

int main() {
    int n;
    cout << "Combien de contacts voulez-vous creer ? ";
    cin >> n;
    cin.ignore();

    Contact** carnet = new Contact*[n];
    int taille = 0;

    for (int i = 0; i < n; i++) {
        string nom, tel, email;
        cout << "\nContact " << i + 1 << " :" << endl;
        cout << "Nom : ";
        getline(cin, nom);
        cout << "Telephone : ";
        getline(cin, tel);
        cout << "Email : ";
        getline(cin, email);

        carnet[i] = new Contact(nom, tel, email);
        taille++;
    }

    cout << "\nListe des contacts :" << endl;
    for (int i = 0; i < taille; i++) {
        carnet[i]->afficher();
    }

    string nomSup;
    cout << "\nEntrez le nom du contact a supprimer : ";
    getline(cin, nomSup);
    supprimerContact(carnet, taille, nomSup);

    cout << "\nCarnet apres suppression :" << endl;
    for (int i = 0; i < taille; i++) {
        carnet[i]->afficher();
    }

    for (int i = 0; i < taille; i++) {
        delete carnet[i];
    }
    delete[] carnet;

    cout << "\nMemoire liberee avec succes." << endl;
    return 0;
}
