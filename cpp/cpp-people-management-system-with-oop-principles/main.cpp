// Copyright notice:
// © 2024 Adrian-Gabriel Doaga. All Rights Reserved.
// Email: adriangabrieldoaga@gmail.com
// Website: https://github.com/adriangabrieldoaga/pieces-of-code

#include <iostream>
#include <vector>
#include <memory>

#include "person.h"
#include "student.h"
#include "employee.h"
#include "student-employee.h"

using std::cout;
using std::vector;
using std::unique_ptr;
using std::make_unique;

int main()
{
    // Demonstrate runtime polymorphism by storing objects of class Student, Employee or Student_Employee in a Person* vector
    // unique_ptr is a smart pointer that owns and manages another object through a pointer and disposes of that object when the unique_ptr goes out of scope
    vector<unique_ptr<Person>> people;

    // Adding some people to the system
    people.push_back(make_unique<Student>("Albert", "Lane", "Man", 21, 1000, "ABC University", "School of Computer Science", "Computer Science", 1, 3.8, 500));
    people.push_back(make_unique<Employee>("Camila", "Wolf", "Woman", 28, 2000, "XYZ", "Sales", "Sales consultant", 5000));
    people.push_back(make_unique<Student_Employee>("Jim", "Smith", "Man", 23, 3000, "DEF University", "School of Electrical Engineering", "Electronics", 3, 3.7, 400,
                                                   4000, "XYZ", "Engineering", "Electronics engineer intern", 3500));

    // Displaying information of all people
    for (const auto &person: people) {
        person->display_Info();
    }

/*
    // Explicitly casting to the correct type and using the overloaded << operator
    for (const auto &person: people)
{
    // We check if the person is part of the Student_Employee class first, because it's also part of the Student and Employee classes, but we want the Student_Employee implementation
    if (auto student_employee = dynamic_cast<Student_Employee*>(person.get()))
    {
        cout << *student_employee;
    }
    else if (auto student = dynamic_cast<Student*>(person.get()))
    {
        cout << *student;
    }
    else if (auto employee = dynamic_cast<Employee*>(person.get()))
    {
        cout << *employee;
    }
}
*/

    return 0;
}
