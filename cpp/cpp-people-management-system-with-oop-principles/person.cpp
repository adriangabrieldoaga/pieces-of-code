/*
Copyright notice:
© 2025 Adrian-Gabriel Doaga. All Rights Reserved.
Email: adriangabrieldoaga@gmail.com
Website: https://github.com/adriangabrieldoaga/pieces-of-code
*/

#include <string>

#include "person.h"

using std::string;

Person::Person()
{
}

Person::Person(string first_name_param, string last_name_param, string gender_param, int age_param)
: first_name(first_name_param), last_name(last_name_param), gender(gender_param), age(age_param)
{
}

Person::~Person()
{
}

string Person::get_First_Name() const
{
    return first_name;
}

string Person::get_Last_Name() const
{
    return last_name;
}

string Person::get_Full_Name() const
{
    return first_name + " " + last_name;
}

string Person::get_Gender() const
{
    return gender;
}

int Person::get_Age() const
{
    return age;
}

void Person::set_First_Name(string first_name_param)
{
    first_name = first_name_param;
}

void Person::set_Last_Name(string last_name_param)
{
    last_name = last_name_param;
}

void Person::set_Gender(string gender_param)
{
    gender = gender_param;
}

void Person::set_Age(int age_param)
{
    age = age_param;
}
