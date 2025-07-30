/*
Copyright notice:
© 2025 Adrian-Gabriel Doaga. All Rights Reserved.
Email: adriangabrieldoaga@gmail.com
Website: https://github.com/adriangabrieldoaga/pieces-of-code
*/

#include <iostream>
#include <string>

#include "student.h"

using std::cout;
using std::string;

Student::Student()
{
}

Student::Student(string first_name_param, string last_name_param, string gender_param, int age_param, int student_ID_param, string university_param, string school_param,
                 string major_param, int year_param, float GPA_param, float monthly_stipend_param)
: Person(first_name_param, last_name_param, gender_param, age_param), student_ID(student_ID_param), university(university_param), school(school_param),
major(major_param), year(year_param), GPA(GPA_param), monthly_stipend(monthly_stipend_param)
{
}

Student::~Student()
{
}

ostream &operator <<(std::ostream &out, const Student &s)
{
    out << "Name: " << s.first_name + " " + s.last_name << "\n" <<
            "Gender: " << s.gender << "\n" <<
            "Age: " << s.age << "\n" <<
            "Occupation: Student\n" <<
            "Student ID: " << s.student_ID << "\n" <<
            "University: " << s.university << "\n" <<
            "School: " << s.school << "\n" <<
            "Major: " << s.major << "\n" <<
            "Year: " << s.year << "\n" <<
            "GPA: " << s.GPA << "\n" <<
            "Monthly stipend: " << s.monthly_stipend << "$\n\n";
    return out;
}

void Student::display_Info() const
{
    cout << *this;
}
