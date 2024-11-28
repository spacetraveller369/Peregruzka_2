#include "Plant.h"
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

Plant::Plant() {
    SetKind("Алоэ");
    SetAge(1);
    SetPrice(1000);
    SetColor("green");
    SetOrigin("Ukraine");
    SetAliveStatus(true);
    plant_count++;

}

Plant::Plant(const char* kind, int age, int price, string color, string origin, bool alive) {

    SetKind(kind);
    SetPrice(price);
    SetAge(age);
    SetOrigin(origin);
    SetColor(color);
    SetAliveStatus(alive);
    plant_count++;
}

Plant::Plant(const string& kind) {
    SetKind(kind.c_str());
    SetAge(0);
    SetPrice(0);
    SetColor("Unknown");
    SetOrigin("Unknown");
    SetColor("Unknown");
    SetAliveStatus(true);
}

Plant::Plant(int age) { //преобр.
    this->age = age;
    cout << this->age << "\n";
    plant_count++;
}


Plant::Plant(const Plant& original) { //к-тор копирования
    SetKind(original.kind);
    SetAge(original.age);
    SetPrice(original.price);
    SetColor(original.color);
    SetOrigin(original.origin);
    SetAliveStatus(original.alive);
}

Plant::~Plant() {
    delete[] this->kind;
    plant_count--;;
}

void Plant::Result() const {
    cout << this->kind << "\n";
    cout << this->price << "\n";
    cout << this->age << "\n";
    cout << this->origin << "\n";
    cout << this->color << "\n";
    cout << this->alive << "\n";
    cout << "\n";
}

int Plant::GetCount() {
    return plant_count;
}

int Plant::plant_count = 0;

Plant::Plant(int p) {
    SetPrice(p);
    plant_count++;
}

Plant Plant::operator + (const Plant& original) const {
    return this->price + original.price;
}

bool Plant::operator > (const Plant& original) const {
    return this->price > original.price;
}

bool Plant::operator < (const Plant& original) const {
    return this->price < original.price;
}

bool Plant::operator == (const Plant& original) const {
    return this->price == original.price;
}
bool Plant::operator != (const Plant& original) const {
    return this->price != original.price;
}
ostream& operator << (ostream& os, const Plant& original) {
    os << original.price << "Гривны";
    return os;
}
istream& operator >>(istream& is, Plant& original) {
    is >> original.price;
    return is;
}

Plant& Plant::operator=(const Plant& original) {
    if (this != &original) {
        delete[] kind;
        kind = new char[strlen(original.kind) + 1];
        strcpy_s(kind, strlen(original.kind) + 1, original.kind);
        price = original.price;
        age = original.age;
        origin = original.origin;
        color = original.color;
        alive = original.alive;
    }
    return *this;
}

Plant::operator string() const {
    return "Kind: " + string(kind) + ", Age: " + to_string(age) + ", Price: " + to_string(price) + ", Color: " + string(color) + ", Origin: " + string(origin);
}

    void Plant::SetKind(const char* kind) 
        {
        this->kind = new char[100];
        strcpy_s(this->kind, 99, kind);
        }
    

    void Plant::SetPrice(int price) {
        this->price = price;
    }

    void Plant::SetAge(int a) {
        if (age >= 1) this->age = age;
        else throw "Unreal age!\n";
    }

    void Plant::SetOrigin(string o) {
        this->origin = origin;
    }

    void Plant::SetColor(string c) {
        this->color = color;
    }
    void Plant::SetAliveStatus(bool alive) {
        this->alive = alive;
    }


    string Plant::GetKind() const {
        return string(kind);
    }
    int Plant::GetPrice() const {
        return price;
    }
    int Plant::GetAge() const {
        return age;
    }
    string Plant::GetOrigin() const {
        return origin;
    }
    string Plant::GetColor() const {
        return color;
    }
    bool Plant::GetAliveStatus() const {
        if (alive) {
            cout << "Это растение живо" << "\n";
        }
    };


    void Plant::Drink() {
        cout << GetKind() << " is drinking...\n";

    }

    void Plant::Grow() {
        cout << GetKind() << " is growing...\n";

    }

    void Plant::Give() {
        cout << GetKind() << " is giving me an oxygen to breathe...\n";
    }

    void Plant::Joy() {
        cout << GetKind() << " is giving a joy to my cat...\n";
    }

    void Plant::DisplayInfo() const {

        cout << "Plant Information:" << "\n";
        cout << "  Kind: " << kind << "\n";
        cout << "  Age: " << age << " years" << "\n";
        cout << " Color: " << color << "\n";
        cout << " Is Alive: " << (alive ? "Yes" : "No") << "\n";

    }