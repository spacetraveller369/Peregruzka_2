#include <string>
#include <iostream>
using namespace std;

class Cockroach {

private:
    char* name;
    int size;
    string color;
    bool awful;
    static int cockroach_count;


public:

    Cockroach(); //��� ���-��
    Cockroach(const char*, int, string, bool); //� ���-��
    Cockroach(const string&); //��������������
    ~Cockroach(); //�������������
    Cockroach(const Cockroach& original); //�-��� �����������
    static int GetCount(); //������� ���-�� ��������
    void Result() const; //���� ��� ����������� �-����
    Cockroach(int); //����������

    void SetName(const char* kind);
    void SetSize(int s);
    void SetColor(string c);
    void SetAfwul(bool afwul);

    string GetName() const;
    int GetSize() const;
    string GetColor() const;
    bool GetAwful() const;

    Cockroach operator + (const Cockroach& original) const;
    bool operator > (const Cockroach& original) const;
    bool operator < (const Cockroach& original) const;
    bool operator == (const Cockroach& original) const;
    bool operator != (const Cockroach& original) const;

    friend ostream& operator << (ostream& os, const Cockroach& original);
    friend istream& operator >> (istream& is, Cockroach& original);

    Cockroach& operator = (const Cockroach& original);
    explicit operator string() const;

    void Eat();
    void Sleep();
    void Run();
    void MakeDisaster();
    void Frighten();

    void DisplayInfo() const;

  
};

