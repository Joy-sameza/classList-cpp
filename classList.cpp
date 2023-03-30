#include <iostream>
#include <vector>
#include <string>
class Date
{
public:
  int day;
  int month;
  int year;
};
class Student
{
private:
  std::string family_name;
  std::string given_name;
  Date date_of_birth;

public:
  std::string matricule;

  void setFamilyName(std::string name)
  {
    family_name = name;
  }

  std::string getFamilyName()
  {
    return family_name;
  }

  void setGivenName(std::string name)
  {
    given_name = name;
  }

  std::string getGivenName()
  {
    return given_name;
  }

  void setDateOfBirth(Date dob)
  {
    date_of_birth = dob;
  }

  Date getDateOfBirth()
  {
    return date_of_birth;
  }
};
class Classroom
{
public:
  std::vector<Student> students;

  void addStudent(Student student)
  {
    students.push_back(student);
  }

  void removeStudent(std::string matricule)
  {
    for (int i = 0; i < students.size(); i++)
    {
      if (students[i].matricule == matricule)
      {
        students.erase(students.begin() + i);
        break;
      }
    }
  }

  void modifyStudent(std::string matricule, Student new_student)
  {
    Student old_student;
    for (int i = 0; i < students.size(); i++)
    {
      old_student = students[i];
      if (students[i].matricule == matricule)
      {
        if (new_student.getFamilyName() != "")
        {
          old_student.setFamilyName(new_student.getFamilyName());
        }
        if (new_student.getGivenName() != "")
        {
          old_student.setGivenName(new_student.getGivenName());
        }
        if (new_student.getDateOfBirth().day && new_student.getDateOfBirth().month && new_student.getDateOfBirth().year)
        {
          old_student.setDateOfBirth(new_student.getDateOfBirth());
        }
        students[i] = old_student;
        break;
      }
    }
  }

  void displayStudents()
  {
    for (int i = 0; i < students.size(); i++)
    {
      std::cout << "Student " << i + 1 << ":" << std::endl;
      std::cout << "Family name: " << students[i].getFamilyName() << std::endl;
      std::cout << "Given name: " << students[i].getGivenName() << std::endl;
      std::cout << "Matricule: " << students[i].matricule << std::endl;
      Date dob = students[i].getDateOfBirth();
      std::cout << "Date of birth: " << dob.day << "/" << dob.month << "/" << dob.year << std::endl;
    }
  }
};

std::vector<std::string> split(std::string s, std::string delimiter)
{
  size_t pos_start = 0, pos_end, delim_len = delimiter.length();
  std::string token;
  std::vector<std::string> res;

  while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos)
  {
    token = s.substr(pos_start, pos_end - pos_start);
    pos_start = pos_end + delim_len;
    res.push_back(token);
  }

  res.push_back(s.substr(pos_start));
  return res;
}

int main()
{ // Your code here
  Date date;
  Student student;
  Classroom classroom;
  int dd, mm, yy, choice = -25;
  std::string familyName, matricule, givenName, dateOfBirth;

  std::cout << "\tClassroom\t\n--------" << std::endl;
  while (choice > 0)
  {
    std::cout << "\n1. Add student" << std::endl;
    std::cout << "2. Remove student" << std::endl;
    std::cout << "3. Modify student" << std::endl;
    std::cout << "4. Display Class List" << std::endl;
    std::cout << "5. Exit\n" << std::endl;

    std::cin >> choice;
    switch (choice)
    {
    case 1:
      std::cout << "\nEnter student's INFO" << std::endl;
      std::cout << "FAMILY Name: ";
      std::cin >> familyName;
      std::cout << "GIVEN Name: ";
      std::cin >> givenName;
      std::cout << "matricule: ";
      std::cin >> matricule;
      std::cout << "Date of birth (dd/mm/yy): ";
      std::cin >> dateOfBirth;
      for (int i = 0; i < split(dateOfBirth, "/").size(); i++)
      {
        switch (i)
        {
        case 0:
          if (split(dateOfBirth, "/")[0].length() == 1)
            dd = stoi("0" + split(dateOfBirth, "/")[0]);
          dd = stoi(split(dateOfBirth, "/")[0]);
          break;
        case 1:
          if (split(dateOfBirth, "/")[0].length() == 1)
            mm = stoi("0" + split(dateOfBirth, "/")[1]);
          mm = stoi(split(dateOfBirth, "/")[1]);
          break;
        case 2:
          if (split(dateOfBirth, "/")[2].length() == 2)
            yy = stoi("20" + split(dateOfBirth, "/")[2]);
          yy = stoi(split(dateOfBirth, "/")[2]);
          break;
        default:
          break;
        }
      }
      date.day = dd;
      date.month = mm;
      date.year = yy;
      student.setFamilyName(familyName);
      student.setGivenName(givenName);
      student.matricule = matricule;
      student.setDateOfBirth(date);

      classroom.addStudent(student);
      break;
    case 2:
      std::cout << "\nEnter student's matricule ";
      std::cin >> matricule;
      classroom.removeStudent(matricule);
      break;
    case 3:
      std::cout << "\nEnter student's matricule ";
      std::cin >> matricule;
      std::cout << "\nUpdate student's INFO" << std::endl;
      std::cout << "FAMILY Name (leave empty to use the default): ";
      std::cin >> familyName;
      std::cout << "GIVEN Name (leave empty to use the default): ";
      std::cin >> givenName;
      std::cout << "Date of birth ('dd/mm/yy', leave empty to use the default): ";
      std::cin >> dateOfBirth;
      if (dateOfBirth != "") {
      for (int i = 0; i < split(dateOfBirth, "/").size(); i++)
      {
        switch (i)
        {
        case 0:
          if (split(dateOfBirth, "/")[0].length() == 1)
            dd = stoi("0" + split(dateOfBirth, "/")[0]);
          dd = stoi(split(dateOfBirth, "/")[0]);
          break;
        case 1:
          if (split(dateOfBirth, "/")[0].length() == 1)
            mm = stoi("0" + split(dateOfBirth, "/")[1]);
          mm = stoi(split(dateOfBirth, "/")[1]);
          break;
        case 2:
          if (split(dateOfBirth, "/")[2].length() == 2)
            yy = stoi("20" + split(dateOfBirth, "/")[2]);
          yy = stoi(split(dateOfBirth, "/")[2]);
          break;
        default:
          break;
        }
      }
      date.day = dd;
      date.month = mm;
      date.year = yy;
      student.setDateOfBirth(date);
      }
      student.setFamilyName(familyName);
      student.setGivenName(givenName);
      classroom.modifyStudent(matricule, student);
      break;
    case 4:
      classroom.displayStudents();
      break;
    case 5:
      exit(EXIT_SUCCESS);
      break;
    default:
      exit(EXIT_FAILURE);
      break;
    }
  }
  return 0;
}