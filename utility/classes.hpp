#include <iostream>
#include "string"
#include <cstdlib>
#include <time.h>
#include "string"
using namespace std;

class person
{
private:

public:
    string name;
    string national_id;
    string address;
    int age;
    person();
    person(string input_name, string input_national_id, string input_address, int input_age);
    ~person();
};

class account
{
private:


public:
    person p;
    int account_id;
    float balance;
    string password;
    account();
    account(person input_person,string input_password,float input_balance=0);

    ~account();
};


