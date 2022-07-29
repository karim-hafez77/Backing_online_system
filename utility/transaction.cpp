#include "transaction.hpp"
transactions::transactions(string input_operation, float input_amout_of_money) : operation(input_operation), amount_of_money(input_amout_of_money) {}
float transactions::get_amount_of_money() { return amount_of_money; }
string transactions::get_operation() { return operation; }
