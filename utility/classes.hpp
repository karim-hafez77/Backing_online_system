#include <iostream>
#include "string"
#include <cstdlib>
#include <time.h>
#include "string"
#include <vector>
using namespace std;

struct transactions
{
string operation;
float amount_of_money;
transactions(string input_operation , float input_amout_of_money):operation(input_operation),amount_of_money(input_amout_of_money)
{}
};


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
    float balance=0;
    string password;
    vector<transactions>transactions_list;
    account();
    account(person input_person,string input_password);
    void deposit(float input_amount);
    float show_account_balance(void);
    void withdraw(float output_amount);

    ~account();
};


