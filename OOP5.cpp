#include <iostream>
#include <string>

class Human {
protected:
    std::string name;
    int age;

public:
    Human(const std::string& n, int a) : name(n), age(a) {}

    std::string getName() const {
        return name;
    }

    void setName(const std::string& n) {
        name = n;
    }

    int getAge() const {
        return age;
    }

    void setAge(int a) {
        age = a;
    }
};

class Employee : public Human {
protected:
    std::string position;

public:
    Employee(const std::string& n, int a, const std::string& pos)
        : Human(n, a), position(pos) {}

    std::string getPosition() const {
        return position;
    }

    void setPosition(const std::string& pos) {
        position = pos;
    }

    virtual void displayInfo() const {
        std::cout << "Employee - Name: " << name << ", Age: " << age << ", Position: " << position;
    }
};

class Cashier : public Employee {
private:
    double cashInDrawer;

public:
    Cashier(const std::string& n, int a, double cash) : Employee(n, a, "Cashier"), cashInDrawer(cash) {}

    double getCashInDrawer() const {
        return cashInDrawer;
    }

    void setCashInDrawer(double cash) {
        cashInDrawer = cash;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << ", Cash in Drawer: $" << cashInDrawer << "\n";
    }
};

class SalesPerson : public Employee {
private:
    int numberOfSales;

public:
    SalesPerson(const std::string& n, int a, int sales) : Employee(n, a, "Sales Person"), numberOfSales(sales) {}

    int getNumberOfSales() const {
        return numberOfSales;
    }

    void setNumberOfSales(int sales) {
        numberOfSales = sales;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << ", Number of Sales: " << numberOfSales << "\n";
    }
};

class Manager : public Employee {
private:
    std::string department;

public:
    Manager(const std::string& n, int a, const std::string& dept) : Employee(n, a, "Manager"), department(dept) {}

    std::string getDepartment() const {
        return department;
    }

    void setDepartment(const std::string& dept) {
        department = dept;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        std::cout << ", Department: " << department << "\n";
    }
};

int main() {
    Cashier cashier("Ivan Ivanich", 25, 1000.0);
    SalesPerson salesPerson("Alisa Pavlovna", 30, 50);
    Manager manager("Andrey Andreevich", 35, "Electronics");

    cashier.displayInfo();
    salesPerson.displayInfo();
    manager.displayInfo();

    return 0;
}

