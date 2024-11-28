#include "Cockroach.h"
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

Cockroach::Cockroach() {
    SetName("Рыжик");
    SetSize(10);
    SetColor("red");
    SetAfwul(true);
    cockroach_count++;
}

Cockroach::Cockroach(const char* name, int size, string color, bool awful) {

    SetName(name);
    SetSize(size);
    SetColor(color);
    SetAfwul(awful);
    cockroach_count++;
}

Cockroach::Cockroach(const string& name) {
    SetName(name.c_str());
    SetSize(0);
    SetColor("Unknown");
}

Cockroach::Cockroach(int size) { //преобр.
    this->size = size;
    cout << this->size << "\n";
    cockroach_count++;
}


Cockroach::Cockroach(const Cockroach& original) { //к-тор копирования
    SetName(original.name);
    SetSize(original.size);
    SetColor(original.color);
    SetAfwul(original.awful);
  
}

Cockroach::~Cockroach() {
    delete[] this->name;
    cockroach_count--;;
}

void Cockroach::Result() const {
    cout << this->name << "\n";
    cout << this->size << "\n";
    cout << this->color << "\n";
    cout << this->awful << "\n";
    cout << "\n";
}

int Cockroach::GetCount() {
    return cockroach_count;
}

int Cockroach::cockroach_count = 0;

Cockroach::Cockroach(int size) {
    SetSize(size);
    cockroach_count++;
}

Cockroach Cockroach::operator + (const Cockroach& original) const {
    return this->size + original.size;
}

bool Cockroach::operator > (const Cockroach& original) const {
    return this->size > original.size;
}

bool Cockroach::operator < (const Cockroach& original) const {
    return this->size < original.size;
}

bool Cockroach::operator == (const Cockroach& original) const {
    return this->size == original.size;
}
bool Cockroach::operator != (const Cockroach& original) const {
    return this->size != original.size;
}
ostream& operator << (ostream& os, const Cockroach& original) {
    os << "Size: " << original.size << "cm";
    return os;
}
istream& operator >> (istream& is, Cockroach& original) {
    is >> original.size;
    return is;
}

Cockroach& Cockroach::operator=(const Cockroach& original) {
    if (this != &original) {
        delete[] name;
        name = new char[strlen(original.name) + 1];
        strcpy_s(name, strlen(original.name) + 1, original.name);
        name = original.name;
        size = original.size;
        color = original.color;
        awful = original.awful;
    }
    return *this;
}

Cockroach::operator string() const {
    return "Name: " + string(name) + ", Size: " + to_string(size) + ", Color: " + string(color);
}

    void Cockroach::SetName(const char* name) {
        if (this->name != nullptr) {
            delete[] this->name;
        }
        int length = strlen(name) + 1;
        this->name = new char[length];
        strcpy_s(this->name, length, name);
    }
    void Cockroach::SetSize(int s) {
        if (s >= 1 && s <= 30) {
            size = s;
        }
        else {
            throw "Size is unreal\n";
        }
    }
    void Cockroach::SetColor(string color) {
        this->color = color;
    }
    void Cockroach::SetAfwul(bool awful) {
        if (awful) {
            awful = true;
            cout << "Cockroach is awful.\n";
        }
        else {
            awful = false;
            cout << "Cockroach is nice.\n";
        }
    }



string Cockroach::GetName() const { return string(name); }

int Cockroach::GetSize() const {
    return size;
}
string Cockroach::GetColor() const {
    return color;
}
bool Cockroach::GetAwful() const
{
    return awful;
};


void Cockroach::Eat() {
    cout << GetName() << " is eating...\n";
}

void Cockroach::Sleep() {
    cout << GetName() << " is sleeping...\n";
}

void Cockroach::Run() {
    cout << GetName() << " running...";

}
    

    void Cockroach::MakeDisaster() {
        cout << GetName() << " is making a disaster everywhere he appears...\n";
    }

    void Cockroach::Frighten() {
        cout << GetName() << "  frightens everyone in the house...\n";
    }

    void Cockroach::DisplayInfo() const {

        cout << "Cockroach Information:" << "\n";
        cout << "  Name: " << name << "\n";
        cout << "  Size: " << size << " cm" << "\n";
        cout << " Color: " << color << "\n";
        cout << " Is Awful: " << (awful ? "Yes" : "No") << "\n";
    }
