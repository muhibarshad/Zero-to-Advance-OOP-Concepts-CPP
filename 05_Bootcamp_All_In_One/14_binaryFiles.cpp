#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

class Student
{
    int id; 
    char name[20];
    float marks; 

    friend ostream& operator<< (ostream&, const Student&);
    friend  istream& operator>> (istream& , Student&);

public:
    //constructor
    Student(int id , char* name , float marks );

    
    void addStudent(ofstream&);
    bool findStudent(ifstream&);
    void deleteStudent(ifstream&);
    void updateMarks(ifstream&, float);

 
    static void displayAllStudents(ifstream&);
};


istream& operator>> (istream& in, Student& s)
{
    cout << "Enter student id: ";
    in >> s.id;
    cout << "Enter student name: ";
    in >> s.name;
    cout << "Enter student marks: ";
    in >> s.marks;
    return in;
}


ostream& operator<< (ostream& out, const Student& s)
{
    out << "Student id: " << s.id << endl;
    out << "Student name: " << s.name << endl;
    out << "Student marks: " << s.marks << endl;
    return out;
}

//constructor implementation
Student::Student(int id=0, char* name=NULL, float marks = 0.0f)
{
    this->id = id;
    strcpy_s(this->name, name);
    this->marks = marks;
}

void Student::addStudent(ofstream& out)
{
    if (!out)
    {
        cout << "Error in opening file" << endl;
        exit(0);

    }

    out.write(reinterpret_cast<char*>(this), sizeof(*this));
    cout << "Student is added successfully" << endl;
  
}
 void Student::displayAllStudents(ifstream& ifs)
{
     if (!ifs)
     {
         cout << "Error in opening file/file does not exist" << endl;
         exit(0);

     }

     char ar1[] = "haider ali";
      Student temp(1,ar1,1); //Note here if try to do it with default constructotr,then in default constructor for char* name i have set default value NULL which causess program to crash when is going to be copying in strcpy😢



     ifs.read(reinterpret_cast<char*>(&temp), sizeof(Student)); 
     while(!ifs.eof())
     {
         cout << temp;
         ifs.read(reinterpret_cast<char*>(&temp), sizeof(Student));
     }

   

}


bool Student::findStudent(ifstream& ifs)
{
    if (!ifs)
    {
        cout << "Error in opening file/file does not exist" << endl;
        exit(0);

    }

    char ar1[] = "haider ali";
    Student temp(1, ar1, 1); //Note here if try to do it with default constructotr,then in default constructor for char* name i have set default value NULL which causess program to crash when is going to be copying in strcpy😢

    bool found = false;

    while (ifs.read(reinterpret_cast<char*>(&temp), sizeof(Student)))
    {
        if (id == temp.id && strcmp(name,temp.name) == 0, marks == temp.marks)
        {

            ifs.close();
            found = true;
            return found;
        }
        
    }

   
    if (found == false)
    {
        cout << "Student does not exist" << endl;
        return found;
    }

}



void Student::deleteStudent(ifstream& inFile)
{
    if (!inFile)
    {
        cout << "Error in opening file/file does not exist" << endl;
        exit(0);

    }
    bool found = false;
    char ar1[] = "haider ali";


    Student temp(1, ar1, 1);

    ofstream out("temp.txt", ios::binary);
    inFile.read(reinterpret_cast<char*>(&temp), sizeof(Student));
    while (!inFile.eof()) //here problem comes this loop does not work
    {
        if(! (id == temp.id && strcmp(name,temp.name) == 0&& marks == temp.marks))
        {
            found = true;
            out.write(reinterpret_cast<char*>(&temp), sizeof(Student));
        }
        inFile.read(reinterpret_cast<char*>(&temp), sizeof(Student));
       
    }
    

  /*  out.close();
    inFile.close();*/

    remove("student.dat");
    rename("temp.txt","student.dat");
    

    if (found == false)
    {
        cout << "Student does not exist" << endl;
    }
  


}

void Student::updateMarks(ifstream& file, float newMarks)
{
    if (!file)
    {
        cout << "Error in opening file/file does not exist" << endl;
        exit(0);

    }

   
    char ar1[] = "haider ali";
 Student temp(1, ar1, 1);


    bool found = false;
    ofstream out("student.dat", ios::binary);
    while (file.read(reinterpret_cast<char*>(&temp), sizeof(Student)))
    {
        if (id == temp.id) //here problem comes,bcz in temp obj we i set id value 1,then i use temp obj to read obj from file but values of temp does not change,for that reasin this check does not work
        {    
             temp.marks = newMarks;
             int location = file.tellg();
             int size = sizeof(temp);

             out.seekp((location - size), ios::beg);
             out.write(reinterpret_cast<char*>(&temp), sizeof(Student));
             found = true;
        }
    }
    
    //file.close();
  //  out.close();
    if (found == false)
    {
        cout << "Student with this rollno does not exist" << endl;
    }
}

int main()
{

    char ar1[] = "haider ali";

    char ar2[] = "Muhib Arshad";

    char ar3[] = "Waleed Adnan";

    Student s1(531, ar1, 1052);
    Student s2(540, ar2, 1052);
    Student s3(546, ar3, 1052);

    ofstream out;
    out.open("student.dat", ios::app | ios::binary);

    s1.addStudent(out);
    out.close();

    //out.open("student.dat", ios::app | ios::binary);
    //s2.addStudent(out); 
    //out.close();
    // 
    //ifstream in;
    //in.open("student.dat", ios::binary);
    //Student::displayAllStudents(in);
    //in.close();
   /* char ar6[] = "haider ali";
    ifstream in;
    Student s4(44,ar6,555);
    in.open("student.dat", ios::binary);

    s4.findStudent(in);
    in.close();*/

    //ifstream in;
    //in.open("student.dat", ios::binary);
    //s1.updateMarks(in, 1053);
    //in.close();
    //
    //
    //in.open("student.dat", ios::binary);
    //Student::displayAllStudents(in);
    //in.close();

}