#include <iostream>
#include <iomanip>

using namespace std;

class student
{
private:
    int regNo;
    string firstName;
    string lastName;
    string program;
    float cgpa;

public:
    // CONSTRUCTORS
    student();
    student(const student &);
    student(int, string, string);
    student(int, string, string, string);
    student(int, string, string, string, float);

    // MUTATORS
    void setRegno(int);
    void setCgpa(float);
    void setFirstName(string);
    void setLastName(string);
    void setProgram(string);

    // ACCESSORS
    int getRego() const;
    float getCgpa() const;
    string getFirstName() const;
    string getLastName() const;
    string getProgram() const;

    // SET_DATA,GET_DATA,PUT_DATA
    void set(int, string, string, string, float);
    void read();
    void write() const;

    // FUNCTIONALITY_MEMBER_FUNCTIONS
    bool isFirstSemester() const;
    float getPercentage() const;
    bool isPromoted() const;

    // DESTRUCTOR
    ~student();
};

// CONSTRUCTORS
student::student()
{
    setRegno(0);
    setFirstName("");
    setLastName("");
    setProgram("");
    setCgpa(-1);
}
student ::student(int regNo, string firstName, string lastName, string program)
{
    setRegno(regNo);
    setFirstName(firstName);
    setLastName(lastName);
    setProgram(program);
    setCgpa(-1);
}
student ::student(int regNo, string firstName, string program)
{
    setRegno(regNo);
    setFirstName(firstName);
    setProgram(program);
    setLastName("");
    setCgpa(-1);
}
student ::student(int regNo, string firstName, string lastName, string program, float cgpa)
{
    setRegno(regNo);
    setFirstName(firstName);
    setLastName(lastName);
    setProgram(program);
    setCgpa(cgpa);
}
student ::student(const student &cpyStudent)
{
    regNo = cpyStudent.regNo;
    cgpa = cpyStudent.cgpa;
    firstName = cpyStudent.firstName;
    lastName = cpyStudent.lastName;
    program = cpyStudent.program;
}

// MUTATORS
void student ::setRegno(int regNo)
{
    this->regNo = regNo >= 501 && regNo <= 565 ? regNo : 0;
}
void student ::setCgpa(float cgpa)
{
    this->cgpa = cgpa >= 0.00 && cgpa <= 4.00 ? cgpa : -1;
}
void student ::setFirstName(string firstName) { this->firstName = firstName; }
void student ::setLastName(string lastName) { this->lastName = lastName; }
void student ::setProgram(string program) { this->program = program; }

// ACCESSORS
int student ::getRego() const { return regNo; }
float student ::getCgpa() const { return cgpa; }
string student ::getFirstName() const { return firstName; }
string student ::getLastName() const { return lastName; }
string student ::getProgram() const { return program; }

// SET_DATA,GET_DATA,PUT_DATA
void student ::set(int regNo, string firstName, string lastName, string program, float cgpa)
{
    setRegno(regNo);
    setFirstName(firstName);
    setLastName(lastName);
    setProgram(program);
    setCgpa(cgpa);
}
void student ::read()
{
    cout << "Enter the registration number of the student : ";
    cin >> regNo;
    cout << "Enter the first name of the student : ";
    cin >> firstName;
    cout << "Enter the last name of the student : ";
    cin >> lastName;
    cout << "Enter the program degree of the student : ";
    cin >> program;
    cout << "Enter the cgpa of the student : ";
    cin >> cgpa;
}
void student ::write() const
{
    cout << "The registration number of the student : " << regNo << "\n";
    cout << "The first name of the student : " << firstName << "\n";
    cout << "The last name of the student : " << lastName << "\n";
    cout << "The program degree of the student : " << program << "\n";
    cout << "The cgpa of the student : " << cgpa << "\n";
}

// FUNCTIONALITY_MEMBER_FUNCTIONS
bool student ::isFirstSemester() const
{
    return cgpa == -1 ? true : false;
}

float student ::getPercentage() const
{
    return cgpa >= 0.00 && cgpa <= 4.00 ? (cgpa / 4.00) * 100 : -1;
}
bool student ::isPromoted() const
{
    return cgpa >= 2.00 && cgpa <= 4.00 ? true : false;
}

// DESTRUCTOR
student ::~student()
{
    cout << "Destructor executed"
         << "\n";
}

int main()
{

    // INITLIZING_STUDENT(_Testing_Constructors)
    student st[4]={student(),student(516, "Waleed", "BSCYS"),student(500, "Saad", "Haider", "BSAI"),student(515, "Salik", "Ali", "BSIT", 2.00)};

    // DECLARING_STUDENT
    st[0].set(502, "Muhib", "Arshad", "BSSE", 3.5);
    st[1].set(530, "Ali", "Abdullah", "BSCS", 4.00);
    st[2] = st[0]; // calling_Copy_Constructor
    st[3].set(2, "Bilal", "Sharafat", "BSDS", -1);
    
    // FORMATTING_DATA
    cout << left;
    cout << setw(15) << "REG_NO" << setw(20) << "FIRST_NAME" << setw(20) << "LAST_NAME" << setw(17) << "PROGRAM" << setw(15) << "CGPA" << setw(26) << "IS_FIRSTSEMISTER" << setw(23) << "PRECENTAGE" << setw(26) << "IS_PROMOTED"
         << "\n";

    // DISPLAYING_STUDENT(_Testing_Member_Functions)
    for (const auto &st : st)
    {
        cout << setw(15) << st.getRego() << setw(20) << st.getFirstName() << setw(20) << st.getLastName() << setw(17) << st.getProgram() << setw(15) << st.getCgpa() << setw(26) << st.isFirstSemester() << setw(23) << st.getPercentage() << setw(26) << st.isPromoted()
             << "\n";
    }
    return 0;
}