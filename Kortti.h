#pragma once
#include <iostream>
#include <ctime>
using namespace std;
class Kortti {
    private:
        int rank;
        int suit;

    public:
        Kortti() {
        srand(time(NULL));
        rank = (1 + (std::rand() % (int)(13)));
        suit = (1 + (std::rand() % (int)(4)));
    }
    int get_rank() {
        return rank;
    }
    string get_rank_string() {
        if (rank == 1) return "Ässä";
        if (rank == 2) return "2";
        if (rank == 3) return "3";
        if (rank == 4) return "4";
        if (rank == 5) return "5";
        if (rank == 6) return "6";
        if (rank == 7) return "7";
        if (rank == 8) return "8";
        if (rank == 9) return "9";
        if (rank == 10) return "10";
        if (rank == 11) return "11";
        if (rank == 12) return "12";
        if (rank == 13) return "13";
    }
    int get_suit() {
        return suit;
    }
    string get_suit_string() {
        if (suit == 1) return "Ruutu";
        if (suit == 2) return "Hertta";
        if (suit == 3) return "Pata";
        if (suit == 4) return "Risti";
    }
};