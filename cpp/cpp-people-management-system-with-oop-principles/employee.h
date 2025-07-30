/*
Copyright notice:
© 2025 Adrian-Gabriel Doaga. All Rights Reserved.
Email: adriangabrieldoaga@gmail.com
Website: https://github.com/adriangabrieldoaga/pieces-of-code
*/

#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include <string>

#include "person.h"

using std::string;
using std::ostream;

class Employee : virtual public Person // Virtual inheritance to solve diamond inheritance problem
{
protected:
    int employee_ID;
    string employer;
    string department;
    string job_title;
    float monthly_salary;

public:
    Employee();
    Employee(string first_name_param, string last_name_param, string gender_param, int age_param, int employee_ID_param, string employer_param, string department_param,
             string job_title_param, float monthly_salary_param);
    ~Employee();
    friend ostream &operator <<(ostream &out, const Employee &e);
    void display_Info() const override;
};

#endif // EMPLOYEE_H_INCLUDED
