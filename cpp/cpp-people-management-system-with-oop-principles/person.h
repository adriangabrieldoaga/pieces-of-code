/*
Copyright notice:
© 2025 Adrian-Gabriel Doaga. All Rights Reserved.
Email: adriangabrieldoaga@gmail.com
Website: https://github.com/adriangabrieldoaga/pieces-of-code
*/

#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

#include <string>

using std::string;

class Person
{
protected:
    string first_name;
    string last_name;
    string gender;
    int age;

public:
    // Constructors
    Person();
    Person(string first_name_param, string last_name_param, string gender_param, int age_param);

    // Destructor
    virtual ~Person();

    // Encapsulation
    // Getters
    string get_First_Name() const;
    string get_Last_Name() const;
    string get_Full_Name() const;
    string get_Gender() const;
    int get_Age() const;

    // Setters
    void set_First_Name(string first_name_param);
	void set_Last_Name(string last_name_param);
    void set_Gender(string gender_param);
    void set_Age(int age_param);

    // Polymorphism: Pure virtual function to be implemented by derived classes
    // Because of this, we can't create Person objects
    virtual void display_Info() const = 0;
};

#endif // PERSON_H_INCLUDED
