/*
ИДЗ 4
Закрятин Касьян
Б9120-09.03.04прогин, подгруппа 4
Вариант 3

Предметная область: 
Университет. Обязательные сущности: студент, группа, расписание занятий, предмет. 
*/

#include <iostream>
#include <list>
#include <string>

using namespace std;

class Person
{

    protected:
        string name; 
        string surname; 
        string patronymic; 

    public:
        
        Person() :name("Ivan"), surname("Ivanov")
        { 
        }

        Person(string surname, string name, string patronymic = "") :name(name),
            surname(surname), patronymic(patronymic)
        {
        }

        string GetName() { return name; }
        string GetSurname() { return surname; }
        string GetPatronymic() { return patronymic; }
        virtual std::string to_string()
        {
            return surname + " " + name + " " + patronymic;
        }

};

class Student: public Person
{

    private:
        int u_id; 

    public:
        static int U_ID;
        
        Student():Person()
        {
            U_ID++;
            u_id = U_ID;
        }
        
        Student(string surname, string name,  string patronymic="") :Person(surname, name,  patronymic)
        {
            U_ID++;
            u_id=U_ID;
        }
        
        Student(const Student& student) :Person(student.surname, student.name,  student.patronymic)
        {
            U_ID++;
            u_id=U_ID;
        }

        
        string to_string() override
        {
            return std::to_string(u_id) + " " + Person::to_string();
        }

        bool operator ==(const Student& student) const
        {
            bool res = name == student.name;
            res = res && surname == student.surname;
            res = res && patronymic == student.patronymic;
            res = res && u_id == student.u_id;
            return res;
        }

        bool operator !=(const Student& student) const {return !operator==(student);}

        Student& operator=(const Student& student)
        {
            
            if (this == &student)
                return *this;

            name = student.name;
            surname = student.surname;
            patronymic = student.patronymic;

            return *this;
        }

};

int Student::U_ID = 0;

template <class A>
class UniverPersonGroup
{

    private:
        list <A*> members;
    public:
        void Pin_Person(A &person)
        {
            members.push_back(&person);
            members.unique();
        }

        void Unpin_Person(A &person)
        {
            members.remove(&person);
        }

        string to_string()
        {
            string output = "";
            for (A* s : members) output = output + s->to_string() + "\n";
            return output;
        }

};

class Un_Group
{

    private:
        
        UniverPersonGroup<Student> students;
        string groupNum;
    public:
        Un_Group() :groupNum("A1234")
        {
        }
        
        Un_Group(string groupNum) :groupNum(groupNum)
        { 
        }
        
        string GetAllStudentsAsString()
        {
            return students.to_string();
        }

        
        void Pin_Student(Student &student)
        {
            students.Pin_Person(student);
        }

        
        void Unpin_Student(Student& student)
        {
            students.Unpin_Person(student);
        }

        
        void set_groupNum(string groupNum) { this->groupNum = groupNum; }

        
        string get_groupNum() { return groupNum; }
        
};

class Subject
{

    private:
        
        string discipline;
        string time;
        
        Un_Group* subjectUn_Group;

    public:
        Subject() : discipline("standart_discipline"), time("8:30"), subjectUn_Group(nullptr)
        {
        }

        Subject(string discipline, string time, Un_Group* group) : discipline(discipline), time(time), subjectUn_Group(group)
        {
        }

        
        Subject(const Subject& subject) : discipline(subject.discipline), time(subject.time), subjectUn_Group(subject.subjectUn_Group)
        {
        }

        void set_time(string time) { this->time = time; }
        void set_discipline(string discipline) { this->discipline = discipline; }
        void set_subjectUn_Group(Un_Group* group) { subjectUn_Group = group; }
        
        string to_string()
        {
            return " " + time + " " + subjectUn_Group -> get_groupNum() + " " + discipline;
        }
        string get_Un_GroupNum() { return subjectUn_Group -> get_groupNum(); }
        
};

class Schedule
{

    private:
        list <Subject*> subjects;

    public:
        Schedule() {}

        
        void AddSubject(Subject& subject)
        {
            subjects.push_back(&subject);
        }

        
        void RemoveSubject(Subject& subject)
        {
            subjects.remove(&subject);
        }

        
        string GetUn_GroupScheduleAsString(string groupNum)
        {
            string output = "";
            for (Subject* s : subjects)
            {
                if (s->get_Un_GroupNum() == groupNum)
                    output = output + s->to_string() + "\n";
            }
            return output;
        }

        string to_string()
        {
            string output = "";
            for (Subject* s : subjects)
            {
                output = output + s->to_string() + "\n";
            }
            return output;
	    }

};

    int main()
{

    setlocale(0, "");
    Un_Group group1("B9120");
    Un_Group group2("E1234");

    Student student_1("Закрятин", "Касьян", "Дмитриевич");
    Student student_2("Цаль", "Виталий", "Богданович");

    group1.Pin_Student(student_1);
    group2.Pin_Student(student_2);

    Schedule schedule;

    Subject sbj1("Философия", "10:10", &group1);
    Subject sbj2(sbj1);
    sbj2.set_discipline("Матлогика");
    sbj2.set_time("11:50");
    schedule.AddSubject(sbj1);
    schedule.AddSubject(sbj2);

    Subject sbj3("Матанализ", "8:30", &group2);
    Subject sbj4("Матанализ", "15:10", &group2);
    schedule.AddSubject(sbj3);
    schedule.AddSubject(sbj4);


    cout << "Расписание группы: " << group1.get_groupNum() << "\n";
    cout << schedule.GetUn_GroupScheduleAsString(group1.get_groupNum());
    cout << "\n Студенты:\n";
    cout << group1.GetAllStudentsAsString() << "\n";

    cout << "Расписание группы: " << group2.get_groupNum() << "\n";
    cout << schedule.GetUn_GroupScheduleAsString(group2.get_groupNum());
    cout << "\n Студенты:\n";
    cout << group2.GetAllStudentsAsString() << "\n\n";

}


