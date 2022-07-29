#include "person.hpp"

person::person(string input_name, string input_national_id, string input_address, int input_age) : name(input_name), age(input_age), national_id(input_national_id), address(input_address)
{
}

person::~person()
{
}

person::person() {}
string person::get_name() { return name; }
string person::get_id() { return national_id; }
string person::get_address() { return address; }
int person::get_age() { return age; }
