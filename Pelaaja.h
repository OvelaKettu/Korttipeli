#pragma once
#include <iostream>

using namespace std;
class Pelaaja {
    public:
        string name;
        float balance;
        float starting_balance;
public:
    Pelaaja() {
        name = "";
        balance = 0;
        starting_balance = 0;
    }
};