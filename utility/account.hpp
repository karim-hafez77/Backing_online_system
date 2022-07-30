#pragma once

#include <iostream>
#include "string"
#include <cstdlib>
#include <time.h>
#include "string"
#include <vector>
using namespace std;
#include "person.hpp"
#include "transaction.hpp"

class account
{
private:
    person account_owner;
    int account_id;
    float balance = 0;
    string password;
    vector<transactions> transactions_list;

public:
    account();
    account(person input_person, string input_password);
    void deposit(float input_amount);
    float show_account_balance(void);
    void withdraw(float output_amount);
    int get_account_id();
    float get_balance();
    person get_account_owner();
    string get_password();
    vector<transactions> get_transaction_list();
    ~account();

};
