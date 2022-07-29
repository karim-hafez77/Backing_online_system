#pragma once

#include <iostream>
#include "string"
#include <cstdlib>
#include <time.h>
#include "string"
#include <vector>
using namespace std;


class transactions
{
private:
    string operation;
    float amount_of_money;

public:
    transactions(string input_operation, float input_amout_of_money);
    string get_operation();
    float get_amount_of_money();
};
