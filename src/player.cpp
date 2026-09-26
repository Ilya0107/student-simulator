#include "player.h"


int randINT(int a, int b)
{
	return a + rand() % (b - a + 1);
}


bool player::checkEnd()
{
	if (health <= 0) {
		cout << "\n\n\n";
		setColor(BLACK,RED);
		cout << END_health;
		resetColor();
		return true;
	}
	else if (money < 0) {
		cout << "\n\n\n";
		setColor(BLACK, RED);
		cout << END_money;
		resetColor();
		return true;
	}
	return false;
}


void player::applyEffect(Effect e)
{
	health += e.health;
	knowledge += e.knowledge;
	money += e.money;
}


void player::printStats()
{
	setColor(CYAN);
	cout << string(80, '-');
	resetColor();
	cout << "\nТекущее состояние:\nОсновные параметры: ";
	cout << "\n| Здоровье: ";


	if (health <= 40)
		setColor(RED);
	else if (health <= 79)
		setColor(YELLOW);
	else setColor(GREEN);
	cout << health;
	resetColor();


	cout << "| | Знания: ";
	if (knowledge <= 40)
		setColor(RED);
	else if (knowledge <= 79)
		setColor(YELLOW);
	else setColor(GREEN);
	cout << knowledge;
	resetColor();


	cout << "| | Деньги: ";
	if (money <= 200)
		setColor(RED);
	else if (money <= 700)
		setColor(YELLOW);
	else setColor(GREEN);
	cout << money << endl;
	setColor(CYAN);
	cout << string(80, '-')  << endl;
	resetColor();
}


void player::printGradebook(int grade)
{
	ConsoleColor gradeColor;
	setColor(DARK_CYAN);
	cout << "\n\n========== ЗАЧЁТНАЯ КНИЖКА ==========\n";
	cout << "+-----------------------+--------+" << endl;
	setColor(CYAN);
	cout << "| Дисциплина            | Оценка |" << endl;
	setColor(DARK_CYAN);
	cout << "+-----------------------+--------+" << endl;
	setColor(CYAN);
	cout << "| Математика            ";
	setColor(DARK_CYAN);
	setColor(DARK_GRAY);
	cout << "| ? |" << endl;
	setColor(CYAN);
	cout << "| Физика                ";
	setColor(DARK_CYAN);
	setColor(DARK_GRAY);
	cout << "| ? |" << endl;
	setColor(CYAN);
	cout << "| История               ";
	setColor(DARK_CYAN);
	setColor(DARK_GRAY);
	cout << "| ? |" << endl;
	setColor(CYAN);
	cout << "| Английский язык       ";
	setColor(DARK_CYAN);
	setColor(DARK_GRAY);
	cout << "| ? |" << endl;
	setColor(CYAN);
	cout << "| Программирование      ";
	setColor(DARK_CYAN);
	if (grade >= 5) gradeColor = GREEN;
	else if (grade >= 4) gradeColor = YELLOW;
	else if (grade >= 3) gradeColor = RED;
	else gradeColor = DARK_RED;
	setColor(gradeColor);
	cout << "| " << grade << " |" << endl;
	setColor(CYAN);
	cout << "| Физкультура           ";
	setColor(DARK_CYAN);
	setColor(DARK_GRAY);
	cout << "| ? |" << endl;
	setColor(DARK_CYAN);
	cout << "+-----------------------+--------+" << endl;
	resetColor();
}


void player::exam(){
	int grade(2);
	setColor(DARK_CYAN);
	cout << string(30, '~') << "ЭКЗАМЕН НА ВЫЖИВАНИЕ" << string(30, '~');
	resetColor();
	cout << "\nВаши параметры: \n";
	printStats();
	cout << ART_TEACHER << endl;
	cout << "Вы подходите к преподавателю. Преподаватель внимательно смотрит на вас,\nпроверяет ваши знания и записывает что-то в тетрадь.\n" << endl;


	if (health < 10) {
		if (knowledge >= 80) {
			setColor(BLACK, RED);
			cout << END_DEATH_STUDY;
			resetColor();
			return;
		}
		else if (knowledge < 20) {
			setColor(BLACK, RED);
			cout << END_DEATH_SLOB;
			resetColor();
			return;
		}
		else {
			setColor(BLACK, RED);
			cout << END_DEATH_NORMAL;
			resetColor();
			return;
		}
	}


	if (money > 800) {
		cout << "\nУ тебя достаточно денег, чтобы начать своё дело.\n";
		cout << "Твои действия:\n";
		cout << "	1. Открываю своё дело\n";
		cout << "	2. Продолжаю экзамен\n";
		cout << "	3. Позвонить маме\n";
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
		if (b == 1) {
			setColor(BLACK, GREEN);
			cout << END_BIZ;
			resetColor();
			return;
		}
		else if (b == 3) {
			if (knowledge >= 70) {
				cout << "\nМама: Ты же умный, у тебя светлая голова. Иди сдавай, я в тебя верю!\n";
			}
			else {
				cout << "\nМама: Учёба не твоё, это бизнес. Я всегда знала, что ты предприниматель!\n";
				setColor(GREEN);
				cout << END_BIZ;
				resetColor();
				return;
			}
		}
	}

	if (health >= 80) {
		cout << "\nТы в отличной физической форме!\n";
		cout << "Тренер сборной предлагает тебе профессионально заняться спортом.\n";
		cout << "Твои действия:\n";
		cout << "  1. Согласиться — уйти в большой спорт\n";
		cout << "  2. Отказаться — продолжить экзамен\n";
		int b;
		while (true) {
			cout << "Твой выбор: ";
			cin >> b;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(10000, '\n');
				setColor(DARK_RED);
				cout << "Ошибка! Введите 1 или 2.\n";
				resetColor();
			}
			else if (b < 1 || b > 2) {
				setColor(DARK_RED);
				cout << "Неверный ввод. Введите 1 или 2.\n";
				resetColor();
			}
			else break;
		}
		if (b == 1) {
			if (health >= 91) {
				setColor(GREEN);
				cout << END_SPORT;
				resetColor();
			}
			else {
				setColor(BLACK, RED);
				cout << END_SPORT_FAIL;
				resetColor();
			}
			return;
		}
	}
	if ((health <= 20) && (knowledge >= 90)) {
		grade = 3;
		setColor(DARK_YELLOW);
		printGradebook(grade);
		cout << END_AUTO3;
		resetColor();
		return;
	}


	if (health < 30) {
		if (knowledge >= 90) grade = 4;
		else if (knowledge >= 80) grade = 3;
		else grade = 2;
	}
	else {
		if (knowledge >= 85) grade = 5;
		else if (knowledge >= 75) grade = 4;
		else if (knowledge >= 65) grade = 3;
		else grade = 2;
	}


	bool bribed = false;
	if (grade == 2 && money >= 700) {
		cout << END_BRIBE_OFFER_2;
		int b;
		cin >> b;
		if (b == 1) {
			money -= 700;
			bribed = true;
			int r = randINT(1, 100);
			if (r <= 40) { grade = 3; cout << END_BRIBE_UP1; }
			else if (r <= 50) { grade = 4; cout << END_BRIBE_UP2; }
			else if (r <= 80) { grade = 2; cout << END_BRIBE_SAME; }
			else { cout << END_BRIBE_SCANDAL; return; }
		}
		else { cout << END_BRIBE_SKIP; }
	}


	else if ((grade == 3 || grade == 4) && money >= 500) {
		if (grade == 3) cout << END_BRIBE_OFFER_3;
		else cout << END_BRIBE_OFFER_4;
		int b;
		cin >> b;
		if (b == 1) {
			money -= 500;
			bribed = true;
			int r = randINT(1, 100);
			if (grade == 3) {
				if (r <= 50) { grade = 4; cout << END_BRIBE_UP1; }
				else if (r <= 60) { grade = 5; cout << END_BRIBE_UP2; }
				else if (r <= 80) { grade = 2; cout << END_BRIBE_DOWN1; }
				else { cout << END_BRIBE_SAME; }
			}
			else {
				if (r <= 40) { cout << END_BRIBE_SAME; }
				else if (r <= 70) { grade = 5; cout << END_BRIBE_UP1; }
				else if (r <= 90) { grade = 3; cout << END_BRIBE_DOWN1; }
				else { grade = 2; cout << END_BRIBE_DOWN2; }
			}
		}
		else { cout << END_BRIBE_SKIP; }
	}


	printGradebook(grade);
	if (knowledge >= 90 && health >= 40 && money >= 400) {
		setColor(BLACK, GREEN);
		cout << END_SECRET;
		resetColor();
		return;
	}


	if (grade == 2) {
		setColor(BLACK, RED);
		cout << END_EXPELLED;
		resetColor();
		return;
	}
	if (grade == 5) {
		setColor(BLACK, GREEN);
		cout << END_5;
		resetColor();
		return;
	}
	else if (grade == 4) {
		if (health <= 20) {
			setColor(BLACK, DARK_YELLOW);
			cout << END_4_BURNOUT;
			resetColor();
			return;
		}
		else {
			setColor(BLACK, DARK_YELLOW);
			cout << END_4_NORMAL;
			resetColor();
			return;
		}
	}
	else if (grade == 3) {
		if (health <= 20) {
			setColor(BLACK, DARK_YELLOW);
			cout << END_3_STRESS;
			resetColor();
			return;
		}
		else {
			setColor(BLACK, DARK_YELLOW);
			cout << END_3_NORMAL;
			resetColor();
			return;
		}
	}


}


player& player::operator=(player& z){
	health = z.health;
	knowledge = z.knowledge;
	money = z.money;
	name = z.name;
	return *this;
}

