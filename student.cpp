#include "student.h"

Student::Student(int i, string n, string a, Date f, int c)
 : id(i), name(n), address(a), firstDate(f), completedCreditHours(c)
{}

Student& Student::operator=(const Student& rvalue)
{
	if(this != &rvalue)
	{
		id = rvalue.getID();
		name = rvalue.getName();
		address = rvalue.getAddress();
		firstDate.setDate(rvalue.getFirstDate().getDate());
		firstDate.setMonth(rvalue.getFirstDate().getMonth());
	}

	return *this;
}

ostream& operator<<(ostream& ostr, const Student& s)
{
	cout << "ID : " << s.getID() << endl;
	cout << "이름 : " << s.getName() << endl;
	cout << "주소 : " << s.getAddress() << endl;
	// Date클래스도 <<연산자 오버로딩 완료
	cout << "첫 수강 날짜 : " << s.getFirstDate() << endl;
	cout << "이수학점 : " << s.getCch() << endl;
	return ostr;
}
		

istream& operator>>(istream& istr, Student& s)
{	
	printf("id : ");
	istr >> s.id;
	printf("이름 : ");
	istr >> s.name;
	printf("주소 : ");
	istr >> s.address;
	printf("날짜 : ");
	istr >> s.firstDate;
	printf("이수학점 : ");
	istr >> s.completedCreditHours;
	return istr;
}