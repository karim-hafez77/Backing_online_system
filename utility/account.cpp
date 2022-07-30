#include "account.hpp"

account::account() {}

account::account(person input_person, string input_password) : account_owner(input_person), password(input_password)
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
    if (output_amount <= balance)
    {
        balance -= output_amount;
        transactions t("withdraw", output_amount);
        transactions_list.push_back(t);
    }
    else
    {
        transactions t("unavailable transaction", 0);
        transactions_list.push_back(t);
    }
}

float account::show_account_balance(void)
{
    return balance;
}

int account::get_account_id() { return account_id; }

float account::get_balance() { return balance; }

vector<transactions> account::get_transaction_list() { return transactions_list; }

person account::get_account_owner() { return account_owner; }

string account::get_password() { return password; }

