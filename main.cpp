#define filepath "data"
#include<Windows.h>
#include"Data.h"


using namespace std;
void menu() {
    cout << "\n__________________________________________";
    cout << "\n\n --(Название в разработке)--";
    cout << "\n                --(BIA)--";
    cout << "\n__________________________________________";
    cout << "\n\n1. Вывести список ";
    cout << "\n2. Добавить студента";
    cout << "\n3. Удалить студента";
    cout << "\n4. Изменить студента";
    cout << "\n5. Поиск студента по ФИО";
    cout << "\n6. Сортировать по фамилии";
    cout << "\n7. Сортировать по группе";
    cout << "\n8. Записать изменения";
    cout << "\n9. Найти хорошистов.";
    cout << "\n10. Exit.";
    cout << "\n__________________________________________";
}
void task() {
    cout << endl;
    cout << "\n__________________________________________";
    cout << "\n        --Курсовая работа--";
    cout << "\n        --ОСНОВЫ ПРОГРАММИРОВАНИЯ--";
    cout << "\n        --Студент: Белов А.И.";
    cout << "\n        --Группа: 4932";
    cout << "\n__________________________________________";
    cout << "\n\nПредметная область –«Учет успеваемости студентов».";
    cout << "\nДанные о студенте хранятся в структуре с именем STUDENT,";
    cout << "\nсодержащей следующие поля";
    cout << "\n* фамилия и инициалы;";
    cout << "\n* номер группы;";
    cout << "\n* успеваемость (массив из пяти элементов).";
    cout << "\nЗадание на поиск: найти студентов, чей средний бал не меньше ";
    cout << "\nуказанного пользователем значения.";
    cout << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    task();
    menu();
    DataStudent testData;
    testData.readFromFile(filepath);
    int info;
    while (true) {
        cout << "\n Ваш выбор -- ";
        cin >> info;
        switch (info){
        case 1: testData.showData(); break;
        case 2: testData.insertInData(); break;
        case 3: testData.deleteFromData();  break;
        case 4: testData.changeData(); break;
        case 5: testData.findInData(); break;
        case 6: testData.sortByFullName(); break;
        case 7: testData.sortByGroup(); break;
        case 8: testData.writeToFile(filepath); break;
        case 9: testData.findOtl(); break;
        case 10: exit(0); break;
        default: cout << "Некорректный ввод" << endl; cin.clear(); cin.ignore(cin.rdbuf()->in_avail()); break;
        }
    }
    
    return 1;
}
