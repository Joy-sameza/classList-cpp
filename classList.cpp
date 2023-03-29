#include <iostream>
#include <string>
#include <vector>
#include <ctime>

class Student
{
public:
  std::string getName()
  {
    return name;
  }

  void setName(std::string newName)
  {
    name = newName;
  }

  std::tm getDateOfBirth()
  {
    return dateOfBirth;
  }

  void setDateOfBirth(std::tm newDateOfBirth)
  {
    dateOfBirth = newDateOfBirth;
  }

  std::string getMatricule()
  {
    return matricule;
  }

  void setMatricule(std::string newMatricule)
  {
    matricule = newMatricule;
  }

private:
  std::string name;
  std::tm dateOfBirth;
  std::string matricule;
};

class Classroom
{
public:
  std::vector<Student> students;
};

int main()
{
  // Create a new classroom
  Classroom classroom;

  // Create some students
  Student student1;
  student1.setMatricule("12345");
  student1.setName("John Doe");

  Student student2;
  student2.setMatricule("67890");
  student2.setName("Jane Doe");

  // Add the students to the classroom
  classroom.students.push_back(student1);
  classroom.students.push_back(student2);

  // Print the students in the classroom
  for (auto student : classroom.students)
  {
    std::cout << "Name: " << student.getName() << std::endl;
    std::cout << "Date of Birth: " << student.getDateOfBirth().tm_mday << "/" << student.getDateOfBirth().tm_mon + 1 << "/" << student.getDateOfBirth().tm_year + 1900 << std::endl;
    std::cout << "Matricule: " << student.getMatricule() << std::endl;
    std::cout << std::endl;
  }

  return 0;
}