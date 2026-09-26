#include <iostream>
#include <windows.h>
#include <random>
#include <ctime>
#include "player.h"
#include "text_data.h"
#include "color.h"
player choosePlayer();

void waitForEnter() {
	cout << "\nНажмите Enter, чтобы продолжить...";
	cin.ignore(10000, '\n');
	cin.get();
}


void tryDream(player& A, int& chance) {
	if (randINT(1, 100) <= chance) {
		cout << "\nТы видишь сон: \n";
		setColor((ConsoleColor)randINT(1, 12));
		int d = randINT(0, 5);
		cout << string(80, '-') << endl;
		cout << DREAMS[d].text << endl;
		cout << string(80, '-') << endl;
		resetColor();
		cout << "Эффекты сна: \n";
		if (DREAMS[d].effect.health < 0)
		{
			setColor(RED);
			cout << "Здоровье " << DREAMS[d].effect.health;
		}
		else if (DREAMS[d].effect.health > 0)
		{
			setColor(GREEN);
			cout << "Здоровье +" << DREAMS[d].effect.health;
		}
		else {
			resetColor();
			cout << "Здоровье " << DREAMS[d].effect.health;
		}
		if (DREAMS[d].effect.knowledge < 0)
		{
			setColor(RED);
			cout << "| Знания " << DREAMS[d].effect.knowledge;
		}
		else if (DREAMS[d].effect.knowledge > 0)
		{
			setColor(GREEN);
			cout << "| Знания +" << DREAMS[d].effect.knowledge;
		}
		else {
			resetColor();
			cout << "| Знания " << DREAMS[d].effect.knowledge;
		}
		if (DREAMS[d].effect.money < 0)
		{
			setColor(RED);
			cout << "| Деньги " << DREAMS[d].effect.money << endl;
		}
		else if (DREAMS[d].effect.money  > 0)
		{
			setColor(GREEN);
			cout << "| Деньги +" << DREAMS[d].effect.money << endl;
		}
		else {
			resetColor();
			cout << "| Деньги " << DREAMS[d].effect.money  << endl;
		}
		resetColor();
		waitForEnter();

		A.applyEffect(DREAMS[d].effect);
		chance = max(10, chance - 15);
	}
	else {
		chance = min(45, chance + 10);
	}
}

int main(){
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	SetConsoleTitleW(L"Я учусь в УУНИТ");
	srand((unsigned)time(NULL));
	player A = choosePlayer();
	static int dreamChance = 25;

	for (int i = 0; i < 10; i++) {
		cout << "\n\n\n";
		setColor(MAGENTA);
		cout << string(30, '-') << DAYS[i].title << string(30, '-') << endl;
		resetColor();
		if (i == 1) cout << LOGO_ART << endl;
		
		A.printStats();
		cout << DAYS[i].location << endl;
		cout << DAYS[i].description << endl;
		for (int j = 0; j < 3; j++) {
			cout << "	" << j + 1 << '.' << DAYS[i].choices[j].text << endl;
		}
		int choice;
		while (true) {
			cout << "Ваш выбор: ";
			cin >> choice;

			if (cin.fail()) {
				cin.clear();
				cin.ignore(10000, '\n');
				setColor(DARK_RED);
				cout << "Ошибка! Введите число 1, 2 или 3.\n";
				resetColor();
			}
			else if (choice < 1 || choice > 3) {
				setColor(DARK_RED);
				cout << "Неверный ввод. Введите 1, 2 или 3.\n";
				resetColor();
			}
			else				
				break;
		}
		cout << "Эффекты дня: \n";
		if (DAYS[i].choices[choice - 1].effect.health < 0)
		{
			setColor(RED);
			cout << "Здоровье " << DAYS[i].choices[choice - 1].effect.health;
		}
		else if (DAYS[i].choices[choice - 1].effect.health > 0)
		{
			setColor(GREEN);
			cout << "Здоровье +" << DAYS[i].choices[choice - 1].effect.health;
		}
		else {
			resetColor();
			cout << "Здоровье " << DAYS[i].choices[choice - 1].effect.health;
		}
		if (DAYS[i].choices[choice - 1].effect.knowledge < 0)
		{
			setColor(RED);
			cout << "| Знания " << DAYS[i].choices[choice - 1].effect.knowledge;
		}
		else if (DAYS[i].choices[choice - 1].effect.knowledge > 0) 
		{
			setColor(GREEN);
			cout << "| Знания +" << DAYS[i].choices[choice - 1].effect.knowledge;
		}
		else {
			resetColor();
			cout << "| Знания " << DAYS[i].choices[choice - 1].effect.knowledge;
		}
		if (DAYS[i].choices[choice - 1].effect.money - 20 < 0)
		{
			setColor(RED);
			cout << "| Деньги " << DAYS[i].choices[choice - 1].effect.money - 20 << endl;
		}
		else if (DAYS[i].choices[choice - 1].effect.money - 20 > 0)
		{
			setColor(GREEN);
			cout << "| Деньги +" << DAYS[i].choices[choice - 1].effect.money - 20 << endl;
		}
		else {
			resetColor();
			cout << "| Деньги " << DAYS[i].choices[choice - 1].effect.money - 20 << endl;
		}

		A.applyEffect(DAYS[i].choices[choice - 1].effect);
		A.applyEffect({ 0, 0, -20 });
		resetColor();

		if (A.checkEnd()) {
			return 0;

		}
		tryDream(A, dreamChance);
	}
	A.exam();
}


player choosePlayer() {
	int h;
	cout << WELCOME_TEXT << endl;
	cout << ART_person;
	cout << "\nТвой выбор: ";
	while (true) {
		cin >> h;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			setColor(DARK_RED);
			cout << "Ошибка! Введите число 1 или 2.\n";
			resetColor();
		}
		else if (h != 1 && h != 2) {
			setColor(DARK_RED);
			cout << "Неверный ввод. Введите 1 или 2.\n";
			resetColor();
		}
		else
			break;
	}

	int startHealth = (h == 1) ? 40 : 80;
	int startKnowledge = (h == 1) ? 55 : 5;
	int startMoney = (h == 1) ? 300 : 600;
	string startName = (h == 1) ? "Василий Щукин" : "Анастасия Олеговна";
	player A(startHealth, startKnowledge, startMoney, startName);

	// Выбор бонуса
	cout << "\n\nВыбери бонус перед началом:\n";
	cout << "1. Бабушка прислала перевод — +200 денег, -5 здоровья (стресс от разговора)\n";
	cout << "2. Конспекты однокурсника — +10 знаний, -100 денег\n";
	cout << "3. Поход в спортзал с другом — +10 здоровья, -3 знания (пропустил лекцию)\n";
	int b;
	while (true) {
		cout << "Твой выбор: ";
		cin >> b;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			setColor(DARK_RED);
			cout << "Ошибка! Введите 1, 2 или 3.\n";
			resetColor();
		}
		else if (b < 1 || b > 3) {
			setColor(DARK_RED);
			cout << "Неверный ввод. Введите 1, 2 или 3.\n";
			resetColor();
		}
		else
			break;
	}

	if (b == 1) A.applyEffect({ -5, 0, 200 });
	else if (b == 2) A.applyEffect({ 0, 10, -100 });
	else A.applyEffect({ 10, -3, 0 });

	return A;
}