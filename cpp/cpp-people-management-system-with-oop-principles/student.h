/*
Copyright notice:
© 2025 Adrian-Gabriel Doaga. All Rights Reserved.
Email: adriangabrieldoaga@gmail.com
Website: https://github.com/adriangabrieldoaga/pieces-of-code
*/

#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <string>

#include "person.h"

using std::string;
using std::ostream;

class Student : virtual public Person // Virtual inheritance to solve diamond inheritance problem
{
protected:
    int student_ID;
    string university;
    string school;
    string major;
    int year;
    float GPA;
    float monthly_stipend;

public:
    Student();
    Student(string first_name_param, string last_name_param, string gender_param, int age_param, int student_ID_param, string university_param, string school_param,
            string major_param, int year_param, float GPA_param, float monthly_stipend_param);
    ~Student();

    // Overload the << operator
    friend ostream &operator <<(ostream &out, const Student &s);

    void display_Info() const override;
};

#endif // STUDENT_H_INCLUDED
