#include <string>
#include <iostream>
using namespace std;

class Plant {

private:
    char* kind;
    int age;
    int price;
    string color;
    string origin;
    bool alive;
    static int plant_count;

public:

    Plant(); //без пар-ов
    Plant(const char*, int, int, string, string, bool); //с пар-ми
    Plant(const string&); //преобразование
    ~Plant(); //делегирование
    Plant(const Plant& original); //к-тор копирования
    static int GetCount(); //подсчет кол-ва объектов
    void Result() const; //вівод для копирования к-тора
    Plant(int); //перегрузка

    void SetKind(const char* kind);
    void SetAge(int a);
    void SetPrice(int p);
    void SetColor(string c);
    void SetOrigin(string o);
    void SetAliveStatus(bool alive);

    string GetKind() const;
    int GetAge() const;
    int GetPrice() const;
    string GetColor() const;
    string GetOrigin() const;
    bool GetAliveStatus() const;

    Plant operator + (const Plant& original) const;
    bool operator > (const Plant& original) const;
    bool operator < (const Plant& original) const;
    bool operator == (const Plant& original) const;
    bool operator != (const Plant& original) const;

    friend ostream& operator << (ostream& os, const Plant& original);
    friend istream& operator >> (istream& is, Plant& original);
    
    Plant& operator = (const Plant& original);
    explicit operator string() const;

    void Drink();
    void Grow();
    void Give();
    void Joy();
    void DisplayInfo() const;

};
