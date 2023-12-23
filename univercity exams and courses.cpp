#include <iostream>
#include<string>
#include<string.h>
#include <conio.h>

using namespace std;

#pragma warning(disable: 4996);

int std_loc, course_num, teacher_num, teacher_loc, std_num, temp_switchs, temp_teacherphonenum, temp_stdphonenum, teacherscourses, temp_teachernum, temp_teacher, courses_count, teachers_count, temp_teachersc, temp_coursec = 0, i, j, main_input, temp_studentsc = 0, students_count, studentscourses = 0, temp_std, temp_coursenum, temp_stdnum;
char temp_hasexam, temp_stdpresent, temp_stdpasschck, temp_teacherpasschck;
bool temp_check, temp_ecpasschck;
string temp_stdpass, temp_teacherpass, temp_ecpass, temp_ecuser;

void studentsinfo_collector();
void teachersinfo_collector();
void change_stdinfo(int student_id);
void change_teacherinfo(int teach_num);
void courses();
void add_coursestd(int course_num, int student_id);
void add_courseteacher(int course_num, int teacher_id);
void remove_courseteacher(int course_num, int teacher_id);
void remove_coursestd(int course_num, int student_id);
void student_courses(int student_loc);
void teacher_courses(int teach_num);
bool course_existance(int course_code);
string course_name(int course_num);
bool student_existance(int student_id);
bool teacher_existance(int teacher_num);
void exam_schedule();
void change_examdate(int course_num);
bool student_checker(int student_id, int course_num);
bool teacher_checker(int teacher_id, int course_num);
bool exam_existance(int course_num);
void student_exam_presentance(int student_id);
void hozor_ghiab();
void entering_grades(int course_num);
bool grade_existance(int student_id, int course_num);
float grade_collector(int student_id, int course_num);
void student_grades(int student_id);
void students_panel();
void teachers_panel();
void ec_panel();

class c_ec {
public:
    bool ec_login() {
        cout << "\nenter the ec username : ";
    ecchecker:
        cin >> temp_ecuser;
        for (i = 0; i < 100; i++) {
            if (temp_ecuser == ec_user) {
                temp_check = true;
                break;
            }
            else
                temp_check = false;
        }
        if (temp_check == true) {
            if (password_ec())
                return true;
            else
                return false;
        }
        else {
            cout << "\nthe ec username is incorrect! try again : ";
            goto ecchecker;
        }
    }
private:
    string ec_user = "admin", ec_pass = "admin";
    bool password_ec() {
        temp_check = false;
        cout << "\nenter the password : ";
    ecpassfirst:
        cin >> temp_ecpass;
        if (temp_ecpass != ec_pass) {
            cout << "\nthe password is incorrect ! try again : ";
            goto ecpassfirst;
        }
        else
            temp_check = true;
        return temp_check;
    }
}ec;

class c_darsha {
public:
    bool exam[100];
    string exam_date[100];
    string name[100];
    string teacher[100];
    int course_num[100];
}course;

class c_daneshjoyan {
public:
    bool pass_reset(int student_id) {
        if (student_existance(student_id)) {
            for (i = 0; i < 100; i++) {
                if (student_id == student.id[i]) {
                    student.password[i] == to_string(student.id[i]);
                    return true;
                }
            }
        }
        else
            return false;
    }
    bool students_login() {
        cout << "\nenter you student id : ";
    stdchecker:
        cin >> temp_stdnum;
        for (i = 0; i < 100; i++) {
            if (temp_stdnum == student.id[i]) {
                temp_check = true;
                std_num = temp_stdnum;
                std_loc = i;
                break;
            }
            else
                temp_check = false;
        }
        if (temp_check == true) {
            if (password_students())
                return true;
            else
                return false;
        }
        else {
            cout << "\nthe student id is incorrect! try again : ";
            goto stdchecker;
        }
    }
    string fname[100];
    string lname[100];
    int id[100];
    int course_num[100][24];
    bool presentence[100][24];
    float grade[100][24];
    int phone_num[100];
private:
    string password[100];
    bool password_students() {
        temp_check = false;
    passfirst:
        cout << "\nenter your password : ";
        cin >> temp_stdpass;
        if (temp_stdpass != student.password[i]) {
            cout << "\nthe password is incorrect ! do you want to reser your password? (y-yes / n-no) : ";
        stdpasschceck2:
            cin >> temp_stdpasschck;
            if (temp_stdpasschck == 'y') {
                cout << "\nenter your phone number : ";
            phonenumtaker:
                cin >> temp_stdphonenum;
                if (temp_stdphonenum == student.phone_num[i]) {
                    cout << "\nenter your new password: ";
                passcheck:
                    cin >> student.password[i];
                    cout << "\nyour new password is : " << student.password[i] << "\nis this correct? (y-yes / n-no) :";
                stdpasscheck:
                    cin >> temp_stdpasschck;
                    if (temp_stdpasschck == 'y') {
                        cout << "\nmoving to the panel...";
                        temp_check = true;
                    }
                    else if (temp_stdpasschck == 'n') {
                        cout << "\nenter your password : ";
                        goto passcheck;
                    }
                    else {
                        cout << "\nwrong input. try again : ";
                        goto stdpasscheck;
                    }
                }
                else {
                    cout << "\nyour phone number is incorrect! try again : ";
                    goto phonenumtaker;
                }
            }
            else if (temp_stdpasschck == 'n') {
                goto passfirst;
            }
            else {
                cout << "\nwrong input. try again : ";
                goto stdpasschceck2;
            }
        }
        else {
            temp_check = true;
        }
        return temp_check;
    }
}student;

class c_ostadan {
public:
    bool pass_reset(int teacher_num) {
        if (teacher_existance(teacher_num)) {
            for (i = 0; i < 100; i++) {
                if (teacher_num == student.id[i]) {
                    teacher.password[i] == to_string(teacher.id[i]);
                    return true;
                }
            }
        }
        else
            return false;
    }
    bool teacher_login() {
        cout << "\nenter you teaching id : ";
    teacherchecker:
        cin >> temp_teachernum;
        for (i = 0; i < 100; i++) {
            if (temp_teachernum == teacher.id[i]) {
                temp_check = true;
                teacher_num = teacher.id[i];
                teacher_loc = i;
                break;
            }
            else
                temp_check = false;
        }
        if (temp_check == true) {
            if (password_teachers())
                return true;
            else
                return false;
        }
        else {
            cout << "\nthe teaching id is incorrect! try again : ";
            goto teacherchecker;
        }
    }
    string fname[100];
    string lname[100];
    int id[100];
    char course[100][24];
    int phone_num[100];
private:
    string password[100];
    bool password_teachers() {
        temp_check = false;
    tpassfirst:
        cout << "\nenter your password : ";
        cin >> temp_teacherpass;
        if (temp_teacherpass != teacher.password[i]) {
            cout << "\nthe password is incorrect ! do you want to reser your password? (y-yes / n-no) : ";
        teacherpasschceck2:
            cin >> temp_teacherpasschck;
            if (temp_teacherpasschck == 'y') {
                cout << "\nenter your phone number : ";
            tphonenumtaker:
                cin >> temp_teacherphonenum;
                if (temp_teacherphonenum == teacher.phone_num[i]) {
                    cout << "\nenter your new password: ";
                tpasscheck:
                    cin >> teacher.password[i];
                    cout << "\nyour new password is : " << teacher.password[i] << "\nis this correct? (y-yes / n-no) :";
                teacherpasscheck:
                    cin >> temp_teacherpasschck;
                    if (temp_teacherpasschck == 'y') {
                        cout << "\nmoving to the panel...";
                        temp_check = true;
                    }
                    else if (temp_teacherpasschck == 'n') {
                        cout << "\nenter your password again : ";
                        goto tpasscheck;
                    }
                    else {
                        cout << "\nwrong input. try again : ";
                        goto teacherpasscheck;
                    }
                }
                else {
                    cout << "\nyour phone number is incorrect! try again : ";
                    goto tphonenumtaker;
                }
            }
            else if (temp_teacherpasschck == 'n') {
                goto tpassfirst;
            }
            else {
                cout << "\nwrong input. try again : ";
                goto teacherpasschceck2;
            }
        }
        else {
            temp_check = true;
        }
        return temp_check;
    }
}teacher;

int main() {
    cout << "\n1-teachers panel\n2-student panel\n3-education sector panel\n4-exam schedule\nEnter your choice : ";
inputt:
    cin >> main_input;
    switch (main_input) {
    case 1:
        teachers_panel();
        break;
    case 2:
        students_panel();
        break;
    case 3:
        ec_panel();
        break;
    case 4:
        exam_schedule();
        break;
    default:
        cout << "\nwrong input! try again : ";
        goto inputt;
    }
    return 0;
}
//completed
void studentsinfo_collector() {
    cout << "\nenter the number of the students : ";
    cin >> students_count;
    for (i = 0; i < students_count; i++) {
        cout << "\nenter the first name of the " << ++i << "th student : ";
        cin >> student.fname[i];
        cout << "\nenter the last name : ";
        cin >> student.lname[i];
        cout << "\nenter the student id : ";
        cin >> student.id[i];
        cout << "\nenter the student phone-number : ";
        cin >> student.phone_num[i];
        cout << "\nenter the number of courses for this student (max=24) : ";
        cin >> studentscourses;
        for (j = 0; j < studentscourses; j++) {
            cout << "\nenter the course number : ";
        coursecode:
            cin >> temp_std;
            if (!course_existance(temp_std)) {
                cout << "\ncourse does not exist! try again : ";
                goto coursecode;
            }
            else
                student.course_num[i][j] = temp_std;
        }
    }
    cout << "\ninformations inserted sucessfully!\nmoving back to panel...";
}
//completed
void teachersinfo_collector() {
    cout << "\nenter the number of the teachers : ";
    cin >> teachers_count;
    for (i = 0; i < teachers_count; i++) {
        cout << "\nenter the first name of the " << ++i << "th teacher : ";
        cin >> teacher.fname[i];
        cout << "\nenter the last name : ";
        cin >> teacher.lname[i];
        cout << "\nenter the teacher's id : ";
        cin >> teacher.id[i];
        cout << "\nenter the teacher's phone-number : ";
        cin >> teacher.phone_num[i];
        cout << "\nenter the number of courses for this teacher (max=24) : ";
        cin >> teacherscourses;
        for (j = 0; j < teacherscourses; j++) {
            cout << "\nenter the course number : ";
        coursecode:
            cin >> temp_teacher;
            if (!course_existance(temp_teacher)) {
                cout << "\ncourse does not exist! try again : ";
                goto coursecode;
            }
            else
                teacher.course[i][j] = temp_teacher;
        }
    }
    cout << "\ninformations inserted sucessfully!\nmoving back to panel...";
}
//completed (*)
void change_stdinfo(int student_id) {
    if (student_existance(student_id)) {
        for (i = 0; i < 100; i++) {
            if (student.id[i] == student_id) {
            changestdinfo:
                cout << "\n1-phone number (" << student.phone_num[i] << ")\n2 - first name (" << student.fname[i] << ")\n3 - last name (" << student.lname << ")\n4-student id (" << student.id[i] << ")\n5-deleting a course\n6-adding a course\n7-change login password\nenter your choice : ";
            stdinfo:
                cin >> temp_switchs;
                switch (temp_switchs) {
                case 1:
                    cout << "\nenter the new phone number : ";
                    cin >> student.phone_num[i];
                    cout << "\nsuccesfull!";
                    goto changestdinfo;
                    break;
                case 2:
                    cout << "\nenter the first name : ";
                    cin >> student.fname[i];
                    cout << "\nsuccesfull!";
                    goto changestdinfo;
                    break;
                case 3:
                    cout << "\nenter the last name : ";
                    cin >> student.lname[i];
                    cout << "\nsuccesfull!";
                    goto changestdinfo;
                    break;
                case 4:
                    cout << "\nenter the new student id : ";
                    cin >> student.id[i];
                    cout << "\nsuccesfull!";
                    goto changestdinfo;
                    break;
                case 5:
                    cout << "\nenter the course number to add : ";
                    cin >> temp_coursenum;
                    add_coursestd(temp_coursenum, student.id[i]);
                    break;
                case 6:
                    cout << "\nenter the course number to remove : ";
                    cin >> temp_coursenum;
                    remove_coursestd(temp_coursenum, student.id[i]);
                    break;
                case 7:
                    if (student.pass_reset(student.id[i]))
                        cout << "\npassword reset seccusfully!";
                    else
                        cout << "something went wrong! ";
                    goto changestdinfo;
                    cin >> temp_stdpass;
                    break;
                default:
                    cout << "wrong input! try agian : ";
                    goto stdinfo;
                    break;
                }
            }
        }
    }
    else
        cout << "student id not valid!";
}
//completed
void change_teacherinfo(int teacher_id) {
    if (teacher_existance(teacher_id)) {
        for (i = 0; i < 100; i++) {
            if (teacher.id[i] == teacher_id) {
            changeteacherinfo:
                cout << "\n1-phone number (" << teacher.phone_num[i] << ")\n2 - first name (" << teacher.fname[i] << ")\n3 - last name (" << teacher.lname << ")\n4-teacher's id (" << teacher.id[i] << ")\n5-deleting a course\n6-adding a course\n7-change login password\nenter your choice : ";
            teacherinfo:
                cin >> temp_switchs;
                switch (temp_switchs) {
                case 1:
                    cout << "\nenter the new phone number : ";
                    cin >> teacher.phone_num[i];
                    cout << "\nsuccesfull!";
                    goto changeteacherinfo;
                    break;
                case 2:
                    cout << "\nenter the first name : ";
                    cin >> teacher.fname[i];
                    cout << "\nsuccesfull!";
                    goto changeteacherinfo;
                    break;
                case 3:
                    cout << "\nenter the last name : ";
                    cin >> teacher.lname[i];
                    cout << "\nsuccesfull!";
                    goto changeteacherinfo;
                    break;
                case 4:
                    cout << "\nenter the new teacher's id : ";
                    cin >> teacher.id[i];
                    cout << "\nsuccesfull!";
                    goto changeteacherinfo;
                    break;
                case 5:
                    cout << "\nenter the course number to add : ";
                    cin >> temp_coursenum;
                    add_courseteacher(temp_coursenum, teacher.id[i]);
                    break;
                case 6:
                    cout << "\nenter the course number to remove : ";
                    cin >> temp_coursenum;
                    remove_courseteacher(temp_coursenum, teacher.id[i]);
                    break;
                case 7:
                    if (student.pass_reset(student.id[i]))
                        cout << "\npassword reset seccusfully!";
                    else
                        cout << "something went wrong! ";
                    goto changeteacherinfo;
                    break;
                default:
                    cout << "wrong input! try agian : ";
                    goto teacherinfo;
                    break;
                }
            }
        }
    }
    else
        cout << "student id not valid!";
}
//completed
bool teacher_existance(int teacher_num) {
    for (i = 0; i < 100; i++) {
        if (teacher.id[i] == teacher_num) {
            temp_check = true;
            break;
        }
        else
            temp_check = false;
    }
    return temp_check;
}
//completed
void add_coursestd(int course_num, int student_id) {
    if (course_existance(course_num) && student_existance(student_id) && (!student_checker(student_id, course_num))) {
        for (i = 0; i < 100; i++) {
            if (student_id == student.id[i]) {
                for (j = 0; j < 100; j++) {
                    if (!student.course_num[i][j]) {
                        course_num = student.course_num[i][j];
                        break;
                    }
                }
            }
        }
    }
    else
        cout << "\nsomething went wrong!";
}
//completed
void add_courseteacher(int course_num, int teacher_id) {
    if (course_existance(course_num) && student_existance(teacher_id) && (!teacher_checker(teacher_id, course_num))) {
        for (i = 0; i < 100; i++) {
            if (teacher_id == teacher.id[i]) {
                for (j = 0; j < 100; j++) {
                    if (!teacher.course[i][j]) {
                        course_num = teacher.course[i][j];
                        break;
                    }
                }
            }
        }
    }
    else
        cout << "\nsomething went wrong!";
}
//completed
void remove_coursestd(int course_num, int student_id) {
    if (course_existance(course_num) && student_existance(student_id) && (student_checker(student_id, course_num))) {
        for (i = 0; i < 100; i++) {
            if (student_id == student.id[i]) {
                for (j = 0; j < 100; j++) {
                    if (course_num == student.course_num[i][j]) {
                        student.course_num[i][j] = 0;
                        break;
                    }
                }
            }
        }
    }
    else
        cout << "\nsomething went wrong!";
}
//completed
void remove_courseteacher(int course_num, int teacher_id) {
    if (course_existance(course_num) && student_existance(teacher_id) && (teacher_checker(teacher_id, course_num))) {
        for (i = 0; i < 100; i++) {
            if (teacher_id == teacher.id[i]) {
                for (j = 0; j < 100; j++) {
                    if (course_num == teacher.course[i][j]) {
                        teacher.course[i][j] = 0;
                        break;
                    }
                }
            }
        }
    }
    else
        cout << "\nsomething went wrong!";
}
//completed
void courses() {
    cout << "\nenter the number of courses : ";
    cin >> courses_count;
    for (i = 0; i < courses_count; i++) {
        cout << "\nenter the code of the " << ++i << "th course : ";
        cin >> course.course_num[i];
        cout << "\nenter the title of this course : ";
        cin >> course.name[i];
        cout << "\nenter the teacher of this course : ";
        cin >> course.teacher[i];
        cout << "\ndoes this course has exam ? (y-yes / n-no) : ";
    hasexam:
        cin >> temp_hasexam;
        if (temp_hasexam == 'y') {
            course.exam[i] = true;
            cout << "\nenter the date that this exam will be taken ( format : dd.mm.yyyy ) : ";
            cin >> course.exam_date[i];
        }
        else if (temp_hasexam != 'n') {
            cout << "\nwrong input, try again : ";
            goto hasexam;
        }
        else
            course.exam[i] = false;
    }
}
//completed
void student_courses(int student_loc) {
    student_loc = std_loc;
    for (j = 0; j < 24; j++) {
        if (student.course_num[student_loc][j]) {
            if (course_existance(student.course_num[student_loc][j]))
                cout << "\n" << (++j) << "- " << (course_name(student.course_num[student_loc][j])) << " (" << student.course_num[student_loc][j] << ")";
        }
    }
}
//completed (*)
void teacher_courses(int teach_loc) {
    teach_loc = teacher_loc;
    for (j = 0; j < 100; j++) {
        if (teacher.course[teacher_loc][j]) {
            if (course_existance(teacher.course[teacher_loc][j]))
                cout << "\n" << (++j) << "- " << (course_name(teacher.course[teacher_loc][j])) << " (" << teacher.course[teacher_loc][j] << ")";
        }
    }
}
//completed (*)
bool course_existance(int course_num) {
    for (i = 0; i < 100; i++) {
        if (course.course_num[i] == course_num) {
            temp_check = true;
            break;
        }
        else
            temp_check = false;
    }
    return temp_check;
}
//completed
string course_name(int course_num) {
    for (i = 0; i < 100; i++) {
        if (course_num == course.course_num[i]) {
            return course.name[i];
        }
    }
}
//completed
bool student_existance(int student_id) {
    for (i = 0; i < 100; i++) {
        if (student.id[i] == student_id) {
            temp_check = true;
            break;
        }
        else
            temp_check = false;
    }
    return temp_check;
}
//completed
void exam_schedule() {
    for (i = 0; i < 100; i++) {
        if (course.exam[i]) {
            cout << ++i << "- " << course.name[i] << " (" << course.course_num[i] << ") : " << course.exam_date[i] << endl;
        }
    }
}
//completed
void change_examdate(int course_num) {
    for (i = 0; i < 100; i++) {
        if (course_num == course.course_num[i]) {
            cout << "\n enter the new exam date in this format (dd.mm.yyyy) : ";
            cin >> course.exam_date[i];
        }
    }
}
//completed
bool student_checker(int student_id, int course_num) {
    for (i = 0; i < 100; i++) {
        if (student.id[i] == student_id)
            break;
    }
    for (j = 0; j < 100; j++) {
        if (student.course_num[i][i] == course_num)
            temp_check = true;
        else
            temp_check = false;
    }
    return temp_check;
}
//completed
bool teacher_checker(int teacher_id, int course_num) {
    for (i = 0; i < 100; i++) {
        if (teacher.id[i] == teacher_id)
            break;
    }
    for (j = 0; j < 100; j++) {
        if (teacher.course[i][i] == course_num)
            temp_check = true;
        else
            temp_check = false;
    }
    return temp_check;
}
//completed
bool exam_existance(int course_num) {
    for (i = 0; i < 100; i++) {
        if (course.course_num[i] == course_num) {
            if (course.exam[i] == true) {
                temp_check = true;
                break;
            }
            else
                temp_check = false;
        }
    }
    return temp_check;
}
//completed (*)
void hozor_ghiab() {
    cout << "\nenter the course number : ";
checker:
    cin >> temp_coursenum;
    if (course_existance(temp_coursenum)) {
        for (i = 0; i < 24; i++) {
            for (j = 0; j < 100; j++) {
                if (temp_coursenum == student.course_num[j][i]) {
                    cout << "is " << student.fname[j] << " " << student.lname[j] << " present? (y-yes / n-no) : ";
                presentencechk:
                    cin >> temp_stdpresent;
                    if (temp_stdpresent == 'y')
                        student.presentence[j][i] = true;
                    else if (temp_stdpresent == 'n')
                        student.presentence[j][i] = false;
                    else {
                        cout << "wrong input! try again : ";
                        goto presentencechk;
                    }
                }
            }
        }
    }
    else {
        cout << "wrong input! try again : ";
        goto checker;
    }
}
//completed
void entering_grades(int course_num) {
    for (i = 0; i < 100; i++) {
        for (j = 0; j < 24; j++) {
            if (course_num == student.course_num[i][j]) {
                cout << "\nenter the grade of " << student.fname[i] << " " << student.lname[i] << " : ";
                cin >> student.grade[i][j];
            }
        }
    }
}
//completed (*)
bool grade_existance(int student_id, int course_num) {
    for (i = 0; i < 100; i++) {
        if (student_id == student.id[i]) {
            for (j = 0; j < 24; j++) {
                if (course_num == student.course_num[i][j]) {
                    temp_check = true;
                    break;
                }
                else
                    temp_check = false;
            }
        }
    }
    return temp_check;
}
//completed
float grade_collector(int student_id, int course_num) {
    for (i = 0; i < 100; i++) {
        if (student_id == student.id[i]) {
            for (j = 0; j < 24; j++) {
                if (course_num == student.course_num[i][j])
                    return student.grade[i][j];
            }
        }
    }
}
//completed
void student_grades(int student_id) {
    for (i = 0; i < 100; i++) {
        if (student_id == student.id[i]) {
            for (j = 0; j < 24; j++) {
                if (student.course_num[i][j] && course_existance(student.course_num[i][j]) && grade_existance(std_num, student.course_num[i][j])) {
                    cout << "\n" << course_name(student.course_num[i][j]) << " : " << grade_collector(std_num, student.course_num[i][j]);
                }
            }
        }
    }
}
//completed (*)
void student_exam_presentance(int student_id) {
    for (i = 0; i < 100; i++) {
        if (student.id[i] == student_id) {
            for (j = 0; j < 24; j++) {
                if (student.presentence[j])
                    cout << "\n" << student.course_num[j];
            }
        }
    }
}
//completed (*)
void students_panel() {
    if (student.students_login()) {
    stdpanel:
        cout << "\n1-courses\n2-grades\n3-exam schedule\nenter your choice : ";
    stdswitch:
        cin >> temp_switchs;
        switch (temp_switchs) {
        case 1:
            student_courses(std_loc);
            goto stdpanel;
            break;
        case 2:
            student_grades(std_num);
            goto stdpanel;
            break;
        case 3:
            exam_schedule();
            goto stdpanel;
            break;
        default:
            cout << "\nwrong input! try again : ";
            goto stdswitch;
            break;
        }
    }
}
//completed
void teachers_panel() {
    if (teacher.teacher_login()) {
    teacherspanel:
        cout << "\n1-courses\n2-entering grades\n3-exam schedule\nenter your choice : ";
    teacherswitch:
        cin >> temp_switchs;
        switch (temp_switchs) {
        case 1:
            teacher_courses(teacher_loc);
            goto teacherspanel;
            break;
        case 2:
            teacher_courses(teacher_loc);
            cout << "\nenter the course number to get into the grades page : ";
            cin >> course_num;
            entering_grades(course_num);
            cout << "\ngrades have taken succesfully. moving back to the panel...\n";
            goto teacherspanel;
            break;
        case 3:
            exam_schedule();
            goto teacherspanel;
            break;
        default:
            cout << "\nwrong input! try again : ";
            goto teacherswitch;
            break;
        }
    }
}
//completed
void ec_panel() {
ec:
    if (ec.ec_login()) {
    ecpanel:
        cout << "\n1-enter courses\n2-enter students list with thier courses\n3-teacher list with thier courses\n4-change exam schedule\n5-student grade list\n6-student presentance in exams\n7-changing students info\n8-changing teachers info\nenter your choice : ";
    ecswitch:
        cin >> temp_switchs;
        switch (temp_switchs) {
        case 1:
            courses();
            goto ecpanel;
            break;
        case 2:
            studentsinfo_collector();
            goto ecpanel;
            break;
        case 3:
            teachersinfo_collector();
            goto ecpanel;
            break;
        case 4:
            cout << "\nenter the course number for changing the date of exam : ";
            cin >> temp_coursenum;
            if (course_existance(temp_coursenum))
                change_examdate(temp_coursenum);
            else
                cout << "\nwrong course number! ";
            goto ecpanel;
            break;
        case 5:
            cout << "\nenter the student id : ";
            cin >> temp_stdnum;
            student_grades(temp_stdnum);
            goto ecpanel;
            break;
        case 6:
            cout << "\nenter the student id : ";
            cin >> temp_stdnum;
            cout << "\nstudent was present on these exams : ";
            student_exam_presentance(temp_stdnum);
            goto ecpanel;
            break;
        case 7:
            cout << "\nenter the student's id : ";
            cin >> temp_stdnum;
            change_stdinfo(temp_stdnum);
            goto ecpanel;
            break;
        case 8:
            cout << "\nenter the teacher's id : ";
            cin >> temp_stdnum;
            change_teacherinfo(temp_stdnum);
            goto ecpanel;
            break;
        default:
            cout << "\nwrong input! try again : ";
            goto ecswitch;
            break;
        }
    }
    else {
        cout << "\nsomething went wrong! try again.";
        goto ec;
    }
}
//completed