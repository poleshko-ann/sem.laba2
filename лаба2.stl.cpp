#include <iostream>
#include <map>
# include <string>
# include <algorithm>

using namespace std;


typedef pair<string, string> NameSurnamePair;
typedef pair<int, NameSurnamePair> ElementPair;
bool customSort(const ElementPair& a, const ElementPair& b) {
    return a.second.second < b.second.second;
}
//не уверена
struct LessLength
{
    bool operator()(const   int& lhs, const int& rhs) const
    {
        return  rhs - 1 < lhs - 1;
    }
};

void show(map <int, NameSurnamePair, LessLength>& a) {
    for (const auto& element : a ) {
        cout << element.first << ": " << element.second.first << " " << element.second.second << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    int choice;
    map<int, NameSurnamePair, LessLength> mymap;
    mymap[1] = make_pair("abc1", "dfg2");
    mymap[2] = make_pair("abc3", "dfg4");
    mymap[3] = make_pair("abc5", "dfg6");

    do {
        cout << "Меню:" << endl;
        cout << "1. Добавить  элемент" << endl;
        cout << "2. Удалить элементы из заданного диапазона" << endl;
        cout << "3. Поиск элементов больших заданного ключа" << endl;
        cout << "4. Обменивает значения двух объектов (отображений)" << endl;
        cout << "5. Замена значения элемента" << endl;
        cout << "6. Выход из программы" << endl;
        cout << "Введите команду (1-6): ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int key;
            string firstName, lastName;
            cout << "Введите ключ: ";
            cin >> key;
            cout << "Введите имя и фамилию: ";
            cin >> firstName >> lastName;
            mymap[key] = make_pair(firstName, lastName);
            cout << "Ваш map:" << endl;
            show(mymap);
            break;
        }

        case 2: {
            int start, end;
            cout << "Введите начало диапазона: ";
            cin >> start;
            cout << "Введите конец диапазона: ";
            cin >> end;
            for (auto it = mymap.begin(); it != mymap.end();) {
                if (it->first >= start && it->first <= end) {
                    it = mymap.erase(it);
                }
                else {
                    ++it;
                }
            }
            cout << "Ваш map:" << endl;
            show(mymap);
            break;
        }

        case 3: {
            int searchKey;
            cout << "Введите ключ для поиска: ";
            cin >> searchKey;
            map<int, NameSurnamePair>::iterator it;
            it = mymap.lower_bound(searchKey);
            it++;
            cout << "Элементы больше заданного ключа:" << endl;
            while (it != mymap.end()) {
                cout << (*it).first << " : " << (*it).second.first <<" "<< (*it).second.second << endl;
                it++;
            }
            //тоже работает, но она захотела с баундом
            /*for (const auto& element : mymap) {
                if (element.first > searchKey) {
                    cout << element.first << ": " << element.second.first << " " << element.second.second << endl;
                }
            }*/
            break;
        }

        case 4: {
            int key1, key2;
            cout << "Введите ключи двух объектов для обмена значений: ";
            cin >> key1 >> key2;
            swap(mymap[key1], mymap[key2]);
            cout << "Ваш map:" << endl;
            show(mymap);
            break;
        }

        case 5: {
            int key;
            string newFirstName, newLastName;
            cout << "Введите ключ элемента для замены значения: ";
            cin >> key;
            cout << "Введите новое имя и фамилию: ";
            cin >> newFirstName >> newLastName;
            mymap[key] = make_pair(newFirstName, newLastName);
            cout << "Ваш map:" << endl;
            show(mymap);
            break;
        }

        case 6: {
            cout << "Выход из программы" << endl;
            break;

        default:
            cout << "Неверный выбор, попробуйте еще раз." << endl;
        }
        }

    } while (choice != 6);
    
    return 0;
}
