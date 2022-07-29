#include "classes.hpp"
using namespace std;
person::person(string input_name, string input_national_id, string input_address, int input_age) : name(input_name), age(input_age), national_id(input_national_id), address(input_address)
{
}

person::~person()
{
}

person::person() {}
account::account() {}

account::account(person input_person, string input_password) : p(input_person), password(input_password)
{
    srand(time(0));
    account_id = rand();
}

account::~account() {}
void account::deposit(float input_amount)
{
    this->balance += input_amount;
    transactions t("deposit", input_amount);
    transactions_list.push_back(t);
}
void account::withdraw(float output_amount)
{
    balance -= output_amount;
    transactions t("withdraw", output_amount);
    transactions_list.push_back(t);
}
float account::show_account_balance(void)
{
    return balance;
}
