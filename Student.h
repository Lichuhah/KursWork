#include<iostream>
using namespace std;
const int n = 5;

class Student {
private:
	int amounnotes = n;
	char* fullname;
	int group;
	int notes[n];
	void cinfullname();
	void cingroup();
	void cinnotes();
public:
	Student();
	Student(char* fullname, int group, int notes[n]);
	~Student();
	void newStudent();
	char* getFullname();
	int getGroup();
	int getNote(int index);
	void changeStudent();
	void showStudent();
};

Student::Student() {
	
}

Student::Student(char* fullname, int group, int notes[n]) {
	this->fullname = fullname;
	this->group = group;
	for (int i = 0; i < n; i++) {
		this->notes[i] = notes[i];
	}
}

Student::~Student() {

}

void Student::cinfullname() {
	cin.clear(); cin.ignore(INT_MAX, '\n');
	bool check = true;
	while (check) {
		check = false;
	
		cout << "Введите ФИО:";
		char* temp = new char[255];
		cin.getline(temp, 255);
		fullname = new char[strlen(temp) + 1];
		int tempint = 0;
		while (temp[tempint]) {
			if (temp[tempint] >= '0' && temp[tempint] <= '9') {
				cout << endl << "Ошибка ввода: В ФИО недопустимы цифры" << endl;
				check = true;
				break;
			}
			fullname[tempint] = temp[tempint];
			tempint++;
		}
		fullname[tempint] = '\0';
		delete temp;
	}
	
}

void Student::cingroup() {
	
	bool check = true;
	while (check) {
		check = false;
		group = 0;
		cout << "Введите номер группы:";
		char* temp = new char[255];
		cin.getline(temp, 255);
		int tempint = 0;
		while (temp[tempint]) {
			if (temp[tempint] < '0' || temp[tempint] > '9') {
				cout << endl << "Ошибка ввода: В группы недопустимы нецифры" << endl;
				check = true;
				break;
			}
			group *= 10;
			group += temp[tempint] - '0';
			tempint++;
		}
		if (group > 9999 || group < 1111) {
			check = true;
			cout << endl << "Ошибка ввода: Не соблюден формат группы" << endl;
		}
		delete temp;
	}
}

void Student::cinnotes() {
	bool check=true;
	int temp;
	for (int i = 0; i < n; i++) {
		check = true;
		while (check) {
			check = false;
			cout << "Введите оценку n" << i << ":";
			cin >> temp;
			if (cin.fail()) {
				cout << endl << "Ошибка ввода: введено не число" << endl;
				cin.clear(); cin.ignore(cin.rdbuf()->in_avail());
				check = true;
			}
			if (temp > 5 || temp < 2) {
				cout << endl << "Ошибка ввода: не соблюден формат оценки" << endl;
				check = true;
			}
		}

		notes[i] = temp;
	}
}

void Student::newStudent() {
	cinfullname();
	cingroup();
	cinnotes();
	
	
}
char* Student::getFullname() {
	return fullname;
}

int Student::getGroup() {
	return group;
}

int Student::getNote(int index){
	return notes[index];
}

void Student::showStudent() {

	cout << "ФИО:" << fullname<<endl;
	cout << "Группа:" << group << endl;
	cout << "Оценки:";
	for (int i = 0; i < n; i++) {
		cout << " " << notes[i];
	}
	cout << endl;
}