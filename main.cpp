#include <iostream>
#include <fstream>
#include <vector>
#include "student.h"
#include "courseRegistration.h"

using namespace std;

void student_driver()
{
    Student s;
    cout << "student_driver test\n";
    cout << "------------------------";
    cout << "입력 값 : \n";
    cin >> s;

    cout << "------------------------";
    cout << "입력받은 값 : \n";
    cout << s;
}

// CourseRegistration객체를 파일 스트림에 쓰는 driver
void cr_write_driver(const CourseRegistration& ori)
{

    ofstream ofst("courseTest.bin", std::ios::out | std::ios::binary);

    if(ofst.is_open())
    {
        ofst << ori;
    }
    else
    {
        cerr << "ofstream error";
    }
}

// 파일 스트림의 binary정보로 CourseRegistration객체를 업데이트 하는 driver
void cr_get_driver(CourseRegistration& target){
    ifstream ifst("courseTest.bin", std::ios::in | std::ios::binary);

    if(ifst.is_open())
    {
        ifst >> target;
    }
    else
    {
        cerr << "ifstream error";
    }
}

void set_circum(vector<Student>& students, vector<CourseRegistration>& courses)
{
    // student data setting
    for(int i = 0; i < 15; i++)
    {
        string name = "student" + to_string(i);
        string address = "address" + to_string(i);
        Date date(i + 1, i + 5);
        int cchours = i + 10;

        Student s(i, name, address, date, cchours);
        students.push_back(s);
    }

    // course data setting
    for(int i = 0; i < 10; i++)
    {
        int cID = i + 100;
        int ch = (i % 4) + 1;
        CourseRegistration c(cID, ch);
        courses.push_back(c);
    }

    string grade[5] = {"A+", "A0", "B0", "C+", "F"};
    // register course
    for(int i = 0; i < students.size(); i++)
    {
        int ci = i % courses.size();
        courses[ci].addStudent(students[i]);
        courses[ci].setCourseGrade(students[i].getID(), grade[(i*3)%5]);

        courses[(ci + 2) % 10].addStudent(students[i]);
        courses[(ci + 2) % 10].setCourseGrade(students[i].getID(), grade[(i*2)%5]);

        courses[(ci + 4) % 10].addStudent(students[i]);
        courses[(ci + 4) % 10].setCourseGrade(students[i].getID(), grade[(i*4)%5]);
    }
    
}

void print_data(vector<Student>& students, vector<CourseRegistration>& courses)
{
    cout << "--------------------------------------\n";
    cout << "Student Data : \n";
    for(int i = 0; i < students.size(); i++)
    {

        cout << "ID : " << students[i].getID() << "\n";
        cout << "Name : " << students[i].getName() << "\n";
        cout << "Address : " << students[i].getAddress() << "\n";
        cout << "number of credit hours : " << students[i].getCch() << "\n";
    }

    cout << "--------------------------------------\n";
    cout << "course Data : \n";
    cout << "--------------------------------------\n";
    for(int i = 0; i < courses.size(); i++)
    {
        cout << "course " << i << "\n";
        cout << "course ID : " << courses[i].getCourseID() << "\n";
        cout << "course Credit hours : " << courses[i].getCreditHours() << "\n";

        cout << "students : \n";
        
        vector<int> sIdList = courses[i].getStudentID();
        vector<string> sGradeList = courses[i].getCourseGrade();
        for(int k = 0; k < sIdList.size(); k++)
        {
            cout << "student ID : " << sIdList[k] << ", Grade : " << sGradeList[k] << "\n";
        }

            cout << "--------------------------------------\n";
    }
}

int main(void)
{
    // student data
    vector<Student> students;

    // course data
    vector<CourseRegistration> courses;

    set_circum(students, courses);
    
    vector<CourseRegistration> coursesTest(10);
    for(int i = 0; i < 10; i++)
    {
        cr_write_driver(courses[i]);
        cr_get_driver(coursesTest[i]);
    }
    
    print_data(students, coursesTest);
    
    
    student_driver();
}

