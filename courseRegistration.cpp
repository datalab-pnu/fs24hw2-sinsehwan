#include "courseRegistration.h"

void CourseRegistration::addStudent(Student s)
{
    studentID.push_back(s.getID());
    courseGrade.push_back("F");
}

void CourseRegistration::addStudent(int sID, string grade)
{
    studentID.push_back(sID);
    courseGrade.push_back(grade);
}

void CourseRegistration::setCourseGrade(int sID, string grade)
{
    int index = 0;
    for(index = 0; index < studentID.size(); index++)
    {
        if(studentID[index] == sID)
            break;
    }
    courseGrade[index] = grade;
}

ostream& operator<<(ostream& ostr, const CourseRegistration& c)
{
    ostr << c.getCourseID() << endl; 
    ostr << c.getStudentID().size() << endl;
    for(int i = 0; i < c.getStudentID().size(); i++)
    {
        ostr << c.getStudentID()[i] << endl;
        ostr << c.getCourseGrade()[i] << endl;
    }

    ostr << c.getCreditHours() << endl;
    return ostr;
}

istream& operator>>(istream& istr, CourseRegistration& c)
{
    int id;
    int studentNum = 0;
    int creditHours = 0;

    // 입력 받을때마다 스트림 상태 체크
    // 과목 id
    if(!(istr >> id)){
        return istr;
    }
    c.setCourseID(id);

    // 학생 수
    if(!(istr >> studentNum)){
        return istr;
    }

    c.getStudentID().clear();
    c.getCourseGrade().clear();
    cout << "size:" << c.getStudentID().size() << endl;
    // 학생 정보
    for(int i = 0; i < studentNum; i++)
    {
        int sID;
        string grade;

        if(!(istr >> id)){
            return istr;
        }

        if(!(istr >> grade)){
            return istr;
        }

        c.addStudent(id, grade);
    }

    // 수업 시수
    if(!(istr >> creditHours))
    {
        return istr;
    }
    c.setCreditHours(creditHours);

    return istr;
}