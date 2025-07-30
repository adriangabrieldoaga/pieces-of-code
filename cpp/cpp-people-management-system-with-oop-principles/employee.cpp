/*
Copyright notice:
© 2025 Adrian-Gabriel Doaga. All Rights Reserved.
Email: adriangabrieldoaga@gmail.com
Website: https://github.com/adriangabrieldoaga/pieces-of-code
*/

#include <iostream>
#include <string>

#include "employee.h"

using std::cout;
using std::string;

Employee::Employee()
{
}

Employee::Employee(string first_name_param, string last_name_param, string gender_param, int age_param, int employee_ID_param, string employer_param, string department_param,
                   string job_title_param, float monthly_salary_param)
: Person(first_name_param, last_name_param, gender_param, age_param), employee_ID(employee_ID_param), employer(employer_param), department(department_param),
job_title(job_title_param), monthly_salary(monthly_salary_param)
{
}

Employee::~Employee()
{
}

ostream &operator <<(std::ostream &out, const Employee &e)
{
    out << "Name: " << e.first_name + " " + e.last_name << "\n" <<
            "Gender: " << e.gender << "\n" <<
            "Age: " << e.age << "\n" <<
            "Occupation: " << e.job_title << "\n" <<
            "Employee ID: " << e.employee_ID << "\n" <<
            "Employer: " << e.employer << "\n" <<
            "Department: " << e.department << "\n" <<
            "Monthly salary: " << e.monthly_salary << "$\n\n";
    return out;
}

void Employee::display_Info() const
{
    cout << *this;
}
