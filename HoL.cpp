#include "Pelaaja.h"
#include "Kortti.h"
#include <iostream>
using namespace std;
int main()
{
    int dealer_rank;
    int player_rank;
    float panos = 0.0;
    char valinta;
    Kortti kortti;
    Pelaaja pelaaja = Pelaaja();

    cout << "Anna nimi: ";
    cin >> pelaaja.name;
    cout << "Kuinka paljon rahaa haluat? ";
    cin >> pelaaja.starting_balance;

    pelaaja.balance = pelaaja.starting_balance;
    while (pelaaja.balance > 0 && (pelaaja.balance < pelaaja.starting_balance * 5)) {
        cout << pelaaja.name << ", Sinulla on $"
            << pelaaja.balance << ". ";

        while (panos == 0 || panos > pelaaja.balance) {
            cout << "Kuinka paljon haluat antaa panosta: ";
            cin >> panos;

            if (panos > pelaaja.balance) {
                cout << "Sinulla ei ole tarpeeksi rahaa\n";
            }
        }

        kortti = Kortti();
        dealer_rank = kortti.get_rank();
        cout << "Sait " << kortti.get_suit_string()
            << " " << kortti.get_rank_string() << ".\n";
        cout << "Suurempi vai pienempi? "
            << "Laita \"s\" jos kortti on suurempi tai \"p\" jos kortti on pienempi: ";
        cin >> valinta;

        kortti = Kortti();
        player_rank = kortti.get_rank();
        cout << "Sait: " << kortti.get_suit_string()
            << " " << kortti.get_rank_string() << ".\n";

        if ((valinta == 's' && dealer_rank > player_rank) ||
            (valinta == 'p' && dealer_rank < player_rank)) {
            pelaaja.balance -= panos;

            cout << "Arvasit vaarin " + pelaaja.name
                << ". Havisit $" << panos << ".\n";
        }
        else {
            pelaaja.balance += panos;

            cout << "Arvasit oikein " + pelaaja.name
                << ". Voitit $" << panos << "!\n";
        }
        panos = 0;
    }
    if (pelaaja.balance <= 0) {
        cout << "Harmillista " + pelaaja.name << ". "
            << "Rahat loppuivat.\n";
    }
    else {
        cout << "Voitit pelin " + pelaaja.name << "!";
    }

    return 0;
}

