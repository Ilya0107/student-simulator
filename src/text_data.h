#pragma once
#include <string>
using namespace std;

struct Effect {
    int health;
    int knowledge;
    int money;
};

struct Choice {
    string text;
    Effect effect;
};

struct DayData {
    string title;
    string location;
    string description;
    Choice choices[4];
};

extern const string WELCOME_TEXT;
extern const DayData DAYS[10];


extern const string ART_person;
extern const string ART_TEACHER;

struct Dream {
    string text;
    Effect effect;
};

extern const Dream DREAMS[6];
extern const string LOGO_ART;

extern string END_money;
extern string END_health;

extern const string END_DEATH_NORMAL;
extern const string END_DEATH_STUDY;
extern const string END_DEATH_SLOB;



extern const string END_BIZ;
extern const string END_SPORT;
extern const string END_SPORT_FAIL;


extern const string END_AUTO3;
extern const string END_5;
extern const string END_4_BURNOUT;
extern const string END_4_NORMAL;
extern const string END_3_STRESS;
extern const string END_3_NORMAL;



extern const string END_BRIBE_OFFER_3;
extern const string END_BRIBE_OFFER_4;
extern const string END_BRIBE_OFFER_2;
extern const string END_BRIBE_UP1;
extern const string END_BRIBE_UP2;
extern const string END_BRIBE_SAME;
extern const string END_BRIBE_DOWN1;
extern const string END_BRIBE_DOWN2;
extern const string END_BRIBE_SCANDAL;
extern const string END_BRIBE_SKIP;



extern const string END_EXPELLED;
extern const string END_SECRET;