#include <iostream> 
#include <string> 

using namespace std;

class Person
{
public:
    string name;
    int age;
    double weight;
    string occupation;

public:
    Person()
    {
        name = "NONE";
        age = 0;
        weight = 0.0;
        occupation = "NONE";
    }

    Person(string name, int age, double weight, string occupation)
    {
        this->name = name;
        this->age = age;
        this->weight = weight;
        this->weight = weight;
    }

    string getName() const { return name; }
    int getAge() const { return age; }
    double getWeight() const { return weight; }
    string getOccupation() const { return occupation; }

    void setName(string name) { this->name = name; }
    void setAge(int age) { this->age = age; }
    void setWeight(double weight) { this->weight = weight; }
    void setOccupation(string occupation) { this->occupation = occupation; }

    void printInfo() const
    {
        cout << "Имя: " << name << endl;
        cout << "Возраст: " << age << endl;
        cout << "Вес: " << weight << endl;
        cout << "Род занятий: " << occupation << endl;
    }
};

void sortByAge(Person people[], int count)
{
    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            if (people[j].age > people[j + 1].age) {
                swap(people[j], people[j + 1]);
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Ru");

    const int MAX_PEOPLE = 100;
    Person people[MAX_PEOPLE];
    int count = 0;
    int choice;

    while (true)
    {
        cout << "1. Добавить человека\n"
            << "2. Редактировать человека\n"
            << "3. Показать всех людей\n"
            << "4. Сортировать по возрасту\n"
            << "5. Выход\nВаш выбор: ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Неверный ввод. Пожалуйста, введите число от 1 до 5." << endl;
            continue;
        }

        switch (choice)
        {
        case 1:
        {
            if (count >= MAX_PEOPLE) {
                cout << "Достигнуто максимальное количество людей." << endl;
                break;
            }
            string name, occupation;
            int age;
            double weight;

            cout << "Введите имя: ";
            cin >> name;
            cout << "Введите возраст: ";
            cin >> age;
            cout << "Введите вес: ";
            cin >> weight;
            cout << "Введите род занятий: ";
            cin >> occupation;


            people[count++] = Person(name, age, weight, occupation);
            break;
        }
        case 2:
        {
            if (count == 0) {
                cout << "Нет людей для редактирования." << endl;
                break;
            }
            int index;
            cout << "Введите индекс человека для редактирования (0-" << count - 1 << "): ";
            cin >> index;

            if (index < 0 || index >= count) {
                cout << "Неверный индекс." << endl;
                break;
            }

            int fieldChoice;
            cout << "Что хотите изменить?\n"
                << "1. Возраст\n"
                << "2. Вес\n"
                << "3. Род занятий\n"
                << "Ваш выбор: ";
            cin >> fieldChoice;

            switch (fieldChoice)
            {
            case 1: {
                int newAge;
                cout << "Введите новый возраст: ";
                cin >> newAge;
                people[index].setAge(newAge);
                break;
            }
            case 2: {
                double newWeight;
                cout << "Введите новый вес: ";
                cin >> newWeight;
                people[index].setWeight(newWeight);
                break;
            }
            case 3: {
                string newOccupation;
                cout << "Введите новый род занятий: ";
                people[index].setOccupation(newOccupation);
                break;
            }
            default:
                cout << "Неверный выбор." << endl;
                break;
            }
            break;
        }
        case 3: {
            if (count == 0) {
                cout << "Нет людей для отображения." << endl;
                break;
            }
            for (int i = 0; i < count; ++i) {
                cout << "Человек #" << i + 1 << ":" << endl;
                people[i].printInfo();
                cout << endl;
            }
            break;
        }
        case 4: {
            sortByAge(people, count);
            cout << "Люди отсортированы по возрасту." << endl;
            break;
        }
        case 5:
            cout << "Выход из программы." << endl;

        default:
            cout << "Неверный выбор. Пожалуйста, попробуйте снова." << endl;
        }
    }

}