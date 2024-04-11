#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    string name;
    int age;
    
    string address;
    string occupation;
    
    Person(string n, int a, string addr, string occ) : name(n), age(a), address(addr), occupation(occ) {}
};

void print(Person* person)
{
    cout << person->name << " is " << person->age << " years old" << endl;
    cout << "Address: " << person->address << endl;
    cout << "Occupation: " << person->occupation << endl;
}

int main()
{
    Person person("Harry", 23, "123 Main St", "Software Engineer");

    cout << "Meet " << person.name << endl;
    print(&person);

    return 0;
}