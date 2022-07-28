#include "classes.hpp"
using namespace std;
person::person(string input_name, string input_national_id, string input_address, int input_age) : name(input_name), age(input_age), national_id(input_national_id), address(input_address)
{
}

person::~person()
{
}

person::person(){}

account::account(person input_person,  string input_password,float input_balance):p(input_person),balance(input_balance),password(input_password)
{
    srand(time(0));
    account_id=rand();
}

account::~account() {}

int main()
{
    person p1("karim","aaaaaaaaaaaaaaaaaaaa","bbbbbbbbbb",23);
    account a1(p1 ,"zzzzzzzzzzzzz");
    cout<<a1.account_id<<endl;
        cout<<a1.account_id<<endl;
    cout<<a1.account_id<<endl;
    cout<<a1.account_id<<endl;

}