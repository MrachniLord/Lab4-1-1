#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Employee {
public:
  std::string surname;
  int birthYear;
  std::string position;
  std::string group;
};

int main() {
  setlocale(LC_ALL, "RUS");
  std::vector<Employee*> employees;

  // Открытие файла ввода
  std::ifstream inputFile("employees.txt");
  if (!inputFile) {
    std::cerr << "Не удалось открыть файл ввода\n";
    return 0;
  }

  // Загрузка данных из файла
  std::string surname, position, group;
  int birthYear;
  while (inputFile >> surname >> birthYear >> position >> group) {
    Employee* employee = new Employee;
    employee->surname = surname;
    employee->birthYear = birthYear;
    employee->position = position;
    employee->group = group;
    employees.push_back(employee);
  }
  for (Employee* emple : employees) {
      if (emple->position == "инженер") {
          std::cout << emple->surname << ", " << emple->birthYear << ", " << e->position << ", " << "группа:" << e->group << "\n";
      }
  }
  
  // Вывод информации обо всех инженерах
  std::cout << "Инженеры:\n";
  std::sort(employees.begin(), employees.end(),
      [](Employee* e1, Employee* e2) { return e1->birthYear < e2->birthYear; });
  std::for_each(employees.begin(), employees.end(), [](Employee* e) {
    if (e->position == "инженер") {
      std::cout << e->surname << ", " << e->birthYear << ", " << e->position << ", " << "группа:" << e->group << "\n";
    }
  });

  // Вывод информации о не председателях в порядке возрастания года рождения
  std::cout << "\nНе председатели:\n";
  std::sort(employees.begin(), employees.end(),
            [](Employee* e1, Employee* e2) { return e1->birthYear < e2->birthYear; });
  std::for_each(employees.begin(), employees.end(), [](Employee* e) {
    if (e->position != "председатель") {
      std::cout << e->surname << ", " << e->birthYear << ", " << e->position << ", " << "группа:" << e->group << "\n";
    }
  });

  // Освобождение памяти
  std::for_each(employees.begin(), employees.end(),
                [](Employee* e) { delete e; });
  employees.clear();
  return 0;
}
