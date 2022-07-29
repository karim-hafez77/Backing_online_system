#pragma once
#include <iostream>
#include "string"
#include <cstdlib>
#include <time.h>
#include "string"
#include <vector>
using namespace std;

class person
{
private:
    string name;
    string national_id;
    string address;
    int age;

public:
    person();
    person(string input_name, string input_national_id, string input_address, int input_age);
    ~person();
    string get_name();
    string get_id();
    string get_address();
    int get_age();
};
