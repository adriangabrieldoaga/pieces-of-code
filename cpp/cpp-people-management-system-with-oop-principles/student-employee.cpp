/*
Copyright notice:
© 2025 Adrian-Gabriel Doaga. All Rights Reserved.
Email: adriangabrieldoaga@gmail.com
Website: https://github.com/adriangabrieldoaga/pieces-of-code
*/

#include <iostream>
#include <string>

#include "student-employee.h"

using std::cout;
using std::string;

Student_Employee::Student_Employee()
{
}

Student_Employee::Student_Employee(string first_name_param, string last_name_param, string gender_param, int age_param, int student_ID_param, string university_param,
                                   string school_param, string major_param, int year_param, float GPA_param, float monthly_stipend_param, int employee_ID_param,
                                   string employer_param, string department_param, string job_title_param, float monthly_salary_param)
: Person(first_name_param, last_name_param, gender_param, age_param), Student(first_name_param, last_name_param, gender_param, age_param, student_ID_param,
university_param, school_param, major_param, year_param, GPA_param, monthly_stipend_param), Employee(first_name_param, last_name_param, gender_param, age_param,
employee_ID_param, employer_param, department_param, job_title_param, monthly_salary_param)
{
}

Student_Employee::~Student_Employee()
{
}

ostream &operator <<(std::ostream &out, const Student_Employee &s_e)
{
    out << "Name: " << s_e.first_name + " " + s_e.last_name << "\n" <<
            "Gender: " << s_e.gender << "\n" <<
            "Age: " << s_e.age << "\n" <<
            "Occupation: Student, " << s_e.job_title << "\n" <<
            "Student ID: " << s_e.student_ID << "\n" <<
            "University: " << s_e.university << "\n" <<
            "School: " << s_e.school << "\n" <<
            "Major: " << s_e.major << "\n" <<
            "Year: " << s_e.year << "\n" <<
            "GPA: " << s_e.GPA << "\n" <<
            "Employee ID: " << s_e.employee_ID << "\n" <<
            "Employer: " << s_e.employer << "\n" <<
            "Department: " << s_e.department << "\n" <<
            "Monthly income: " << s_e.monthly_stipend + s_e.monthly_salary << "$\n\n";
    return out;
}

void Student_Employee::display_Info() const
{
    cout << *this;
}
