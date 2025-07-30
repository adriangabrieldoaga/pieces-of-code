/*
Copyright notice:
© 2025 Adrian-Gabriel Doaga. All Rights Reserved.
Email: adriangabrieldoaga@gmail.com
Website: https://github.com/adriangabrieldoaga/pieces-of-code
*/

#ifndef STUDENT_EMPLOYEE_H_INCLUDED
#define STUDENT_EMPLOYEE_H_INCLUDED

#include <string>

#include "student.h"
#include "employee.h"

using std::string;

class Student_Employee : public Student, public Employee
{
public:
    Student_Employee();
    Student_Employee(string first_name_param, string last_name_param, string gender_param, int age_param, int student_ID_param, string university_param, string school_param,
                     string major_param, int year_param, float GPA_param, float monthly_stipend_param, int employee_ID_param, string employer_param, string department_param,
                     string job_title_param, float monthly_salary_param);
    ~Student_Employee();
    friend ostream &operator <<(ostream &out, const Student_Employee &s_e);
    void display_Info() const override;
};

#endif // STUDENT_EMPLOYEE_H_INCLUDED
