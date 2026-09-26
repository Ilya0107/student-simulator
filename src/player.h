#pragma once
#include <string>
#include <windows.h>
#include <iostream>
#include "text_data.h"
#include "color.h"
using namespace std;

class player {
private:
    int health;    
    int knowledge; 
    int money;     
    string name;
public:
    player(int h, int k, int m, const string& n) : health(h), knowledge(k), money(m), name(n){};
    bool checkEnd();
    void applyEffect(Effect e); 
    void printStats();
    void printGradebook(int grade);
    void exam();
    player& operator=(player& z);
};

int randINT(int a, int b);