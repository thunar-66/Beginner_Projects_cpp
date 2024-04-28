//------------------------------------------------------ DOCUMENTATION FOR THE
//UNIVERSITY SYSTEM PROGRAM
//------------------------------------------------------//

// MADE BY  [  BIRINDER SINGH WARRAICH ] ,  [ Bhawan Deep Singh ] BCA STUDENT , PUNJAB TECHNICAL
// UNIVERSITY.
//
// 
// Switch case based Menu for console screen program / Terminal Based program
// access employee menu using the password = qaz8937 { declared as global varibale }

#include <cstring>
#include <iostream>

class university {

public: // The rest of Option messages are in the do while loop in the main
        // function.
  void display_main_menu() {
    std::cout << "                                    "
                 "||-------------------------------------------||\n";
    std::cout << "                              WELCOME TO UNIVERSITY DATABASE "
                 "- PRESS ENTER KEY TO START :-\n";
    std::cout << "                                    "
                 "||-------------------------------------------||\n";
    std::cin.ignore();
  }
};
// x------------------------------------------------x------------------------------------------------------------------------------------------------------x

class student_system {

private:
  std::string student_name; 
  std::string father_name;
  std::string email_id;
  std::string password;

  int total_marks = 0;

  std::string sub_name[100];

  int grades[100];
  long int balance;
  std::string fee[100];
  int fee_payment[100];

  long long int admn_no;

public:
  void
  display_student_menu() { 
                           

    std::cout << "                                 "
                 "||------------------------------------||\n";
    std::cout << "                           WELCOME TO STUDENT MENU - PRESS "
                 "ENTER KEY TO START :-"
              << std::endl;
    std::cout << "                                 "
                 "||------------------------------------||\n";
    std::cin.ignore();
    std::cin.get();
  }

  int input_student_data(int &n, student_system stu[100]) {
   

    std::cout << "NOTE: YOU CAN ENTER DATA WITH SPACES [PRESS ENTER KEY]\n";
    std::cin.ignore();
    std::cin.get();
    std::cout << "How Many Student Data You Want To Register :--\n";
    std::cin >> n;

    for (int i = 0; i < n; i++) {

      std::cout << std::endl;
      std::cout << "Enter Name Of Student :\n";
      std::cin.ignore();
      std::getline(std::cin, stu[i].student_name);
      std::cout << std::endl;

      std::cout << "Enter Father Name of :[" << stu[i].student_name << "]"
                << "\n";
      std::getline(std::cin, stu[i].father_name);
      std::cout << std::endl;

      std::cout << "Enter Email Id of :[" << stu[i].student_name << "]"
                << "\n";
      std::cin >> stu[i].email_id;
      std::cout << std::endl;

      std::cout << "University Student Balance of :[" << stu[i].student_name
                << "]"
                << "\n";
      std::cin >> stu[i].balance;
      std::cout << std::endl;

      std::cout << "Enter Addmission No of :[" << stu[i].student_name << "]"
                << "\n";
      std::cin >> stu[i].admn_no;
      std::cout << std::endl;

      std::cout << "Create A Password [ Make Sure To remeber It ] :\n";
      std::cin >> stu[i].password;
      std::cout << std::endl;

      std::cout << "!! Information has been registered :--||\n";
      std::cout << "--------------------------------------||\n";
    }
    return 0;
  }
 

  int display_student_data(std::string name1, std::string password1, int &n,
                           student_system stu[100]) {
    for (int i = 0; i < n; i++) {

      if (name1 == stu[i].getname()) {
        if (password1 == stu[i].getpassword()) {

          std::cout << "------------------||\n";
          std::cout << "STUDENT INFO OF [" << stu[i].getname() << "] IS :\n";
          std::cout << "------------------||\n";

          std::cout << "NAME :---------[ " << stu[i].student_name << " ]"
                    << std::endl;
          std::cout << std::endl;
          std::cout << "FATHER NAME :---[ " << stu[i].father_name << " ]"
                    << std::endl;
          std::cout << std::endl;
          std::cout << "EMAIL ID :-----[ " << stu[i].email_id << " ]"
                    << std::endl;
          std::cout << std::endl;
          std::cout << "ADMISSION NO :-[ " << stu[i].admn_no << " ]"
                    << std::endl;
          std::cout << std::endl;
          std::cout << "PASSWORD :-----[ " << stu[i].password << " ]"
                    << std::endl;
          std::cout << std::endl;
          std::cout << "UNIVERSITY BALANCE :----[ "
                    << "RS " << stu[i].balance << " ]" << std::endl;
          std::cout << std::endl;
          std::cout << "------------------------------||\n";

          return 1;
        }
      }
    }
    std::cout << "-------------------------------||\n";
    std::cout << "!! Invalid Name Or Password :--||\n";
    std::cout << "-------------------------------||\n";

    return 0;
  }

 

  int grades_registeration(std::string name3, int &n, int &n2,
                           student_system stu[100], std::string password3) {
    for (int i = 0; i < n; i++) {
      if (name3 == stu[i].getname()) {
        if (password3 == stu[i].getpassword()) {

          std::cout << "----------------------------------------------||\n";

          std::cout << "How Many Subjects Were In The Academic Year [ ! CHOOSE "
                       "4 FOR BETTER OUTPUT ]:\n";
          std::cin >> n2;

          for (int j = 0; j < n2; j++) {
            std::cout << "-----------------------------||\n";
            std::cout << "Enter Subject Name :\n";
            std::cin.ignore();
            std::getline(std::cin, stu[i].sub_name[j]);
            std::cout << std::endl;

            std::cout << "Enter Marks Of [" << stu[i].sub_name[j]
                      << "] Out of 80 :" << std::endl;
            std::cin >> stu[i].grades[j];
          }
          std::cout << std::endl;
          std::cout << "MARKS  OF [" << stu[i].getname() << "]"
                    << " HAVE BEEN REGISTERED :--\n";
          std::cout << "------------------------------||\n";
          return 1;
        }
      }
    }
    std::cout << "-------------------------------||\n";
    std::cout << "!! Invalid Name Or Password :--||\n";
    std::cout << "-------------------------------||\n";

    return 0;
  }

  

  int generate_report_card(std::string name4, int &n, int &n2,
                           student_system stu[100], std::string password1) {
    for (int i = 0; i < n; i++) {
      if (name4 == stu[i].getname()) {
        if (password1 == stu[i].getpassword()) {

          std::cout << "-------------------------------------------------------"
                       "-----------||\n";
          std::cout << "GENERATING REPORT OF STUDENT [" << stu[i].getname()
                    << "]" << std::endl;
          std::cout << "-------------------------------------------------------"
                       "-----------||\n";
          for (int j = 0; j < n2; j++) {
            std::cout << "Subject Name : [" << stu[i].sub_name[j] << "]"
                      << ": Marks [" << stu[i].grades[j] << "]" << std::endl;
            std::cout << "-----------------------------------------------------"
                         "-------------||\n";
          }
          if (stu[i].total_marks == 0) {
            for (int j = 0; j < n2; j++) {
              stu[i].total_marks += stu[i].grades[j];
            }
          }
          std::cout << "Total marks: [" << stu[i].total_marks
                    << "]  out of 320 " << std::endl;
          std::cout << std::endl;

          if (stu[i].total_marks < 150) {
            std::cout << "[FAILED]:\n";
          } else {
            std::cout << "[PASSED]:\n";
          }
          std::cout << "-------------------------------------------------------"
                       "-----------||\n";
          return 1;
        }
      }
    }

    std::cout << "-------------------------------||\n";
    std::cout << "!! Invalid Name Or Password :--||\n";
    std::cout << "-------------------------------||\n";
    return 0;
  }

  
  int fee_payments(std::string name5, int &n, int &n1, student_system stu[100],
                   std::string password1) {
    for (int i = 0; i < n; i++) {

      if (name5 == stu[i].getname()) {

        if (password1 == stu[i].getpassword()) {

          std::cout << "----------------------------------\n";
          std::cout << "How Many Payments You Want To Do :\n";
          std::cin >> n1;
          for (int j = 0; j < n1; j++) {

            std::cout << "------------------------\n";
            std::cout << "Fee Being Paid Of what ?\n";
            std::cin.ignore();
            std::getline(std::cin, stu[i].fee[j]);

            std::cout << "--------------------\n";
            std::cout << "Enter The Amount :\n";
            std::cin >> stu[i].fee_payment[j];

            stu[i].balance -= stu[i].fee_payment[j];
            std::cout << "-----------------------\n";
            std::cout << "FEE PAYMENT :[" << stu[i].fee_payment[j] << "]"
                      << std::endl;
            std::cout << ":::::::::::::::::::::::::::::::::::::::::"
                      << std::endl;
            std::cout << "BALANCE NOW :[" << stu[i].balance << "]" << std::endl;
            std::cout << ":::::::::::::::::::::::::::::::::::::::::"
                      << std::endl;
            std::cout << "FEE NAME    :[" << stu[i].fee[j] << "]" << std::endl;
            std::cout << ":::::::::::::::::::::::::::::::::::::::::"
                      << std::endl;
          }
        }
        return 1;
      }
    }
    std::cout << "-------------------------------\n";
    std::cout << "!! Invalid Name Or Password :--\n";
    std::cout << "-------------------------------\n";
    return 0;
  }

  // this function display fee payments of a student if any been done. it uses
  // the value of n passed in the above function to display n amounts of fee
  // payments done by a student.
  int display_payment_history(std::string name6, int &n, int &n1,
                              student_system stu[100], std::string password) {
    for (int i = 0; i < n; i++) {
      if (name6 == stu[i].getname()) {
        if (password == stu[i].getpassword())
          std::cout << "------------------------------------------------||\n";
        std::cout << "FEE PAYMENT HISTORY OF :[" << stu[i].getname() << "]"
                  << std::endl;
        std::cout << "------------------------------------------------||\n";
        for (int j = 0; j < n1; j++) {

          std::cout << "FEE NAME :[" << stu[i].fee[j] << "]"
                    << " FEE AMOUNT :[" << stu[i].fee_payment[j] << "]"
                    << std::endl;
          std::cout << "------------------------------------------------||\n";
        }
        return 1;
      }
    }
    std::cout << "-------------------------------\n";
    std::cout << "!! Invalid Name Or Password :--\n";
    std::cout << "-------------------------------\n";
    return 0;
  }
\
  int delete_student_data(std::string name, int &n, student_system stu[100],
                          std::string password1) {

    for (int i = 0; i < n; i++) {
      if (name == stu[i].getname()) {
        if (password1 == stu[i].getpassword()) {
          std::cout << std::endl;

          std::cout << "Are You sure you want to delete [ Press Enter Key To "
                       "confirm ] \n";
          std::cin.ignore();
          std::cin.get();
          for (int j = i; j < n - 1; j++) {
            stu[j] = stu[j + 1];
          }
          n--;
          return 1;
        }
      }
    }
    std::cout << "-------------------------------\n";
    std::cout << "!! Invalid Name Or Password :--\n";
    std::cout << "-------------------------------\n";
    return 0;
  }

  std::string
  getname() { 
    return student_name;
  }

  std::string
  getpassword() { 
    return password;
  }

}; 

// x-----------------------------x--------------------------------x--------------------------------------------------------------x-----------------------------------------------x-------------------------x

class employee {

private:
  std::string employee_name; 
                             
  std::string job_name;
  std::string password12;

  long int salary;
  long int EMP_ID;
  std::string email_id;
  long int salary_hike;

public:
  void display_employee_menu() { 
    std::cout << "                                 "
                 "------------------------------------\n";
    std::cout << "                           WELCOME TO EMPLOYEE MENU - PRESS "
                 "ENTER KEY TO START :-"
              << std::endl;
    std::cout << "                                 "
                 "------------------------------------\n";
    std::cin.ignore();
    std::cin.get();
  }

  int input_employee_data(
      int &nba,
      employee emp[100]) { 
    std::cout << "NOTE: YOU CAN ENTER DATA WITH SPACES [PRESS ENTER KEY]\n";
    std::cin
        .ignore();  
    std::cin.get(); 

    std::cout << "How many Employee Data You want to register :--\n";
    std::cin >> nba;
    std::cout << std::endl;
    for (int i = 0; i < nba; i++) {

      std::cout << "Enter Name Of The employee : \n";
      std::cin.ignore();
      std::getline(std::cin, emp[i].employee_name);
      std::cout << std::endl;

      std::cout << "Job Name of Employee :[" << emp[i].employee_name << "]"
                << "\n";
      std::getline(std::cin, emp[i].job_name);
      std::cout << std::endl;

      std::cout << "Enter Email of :[" << emp[i].employee_name << "]"
                << "\n";
      std::cin >> emp[i].email_id;
      std::cout << std::endl;

      std::cout << "Monthly Salary of Employee :[" << emp[i].employee_name
                << "]"
                << "\n";
      std::cin >> emp[i].salary;
      std::cout << std::endl;

      std::cout << "Enter Employee ID of :[" << emp[i].employee_name << "]"
                << "\n";
      std::cin >> emp[i].EMP_ID;
      std::cout << std::endl;

      std::cout << "Create A Password [ Make Sure To remeber It ] :\n";
      std::cin >> emp[i].password12;
      std::cout << std::endl;

      std::cout << "!! Information has been registered :--\n";
      std::cout << "--------------------------------------\n";
    }
    return 0;
  }

  int display_employee_info(
      std::string emp_name, int &nba, employee emp[100],
      std::string password) { 
    for (int i = 0; i < nba; i++) {
      if (emp_name == emp[i].get_emp_name()) {
        if (password == emp[i].get_password()) {

          std::cout << "--------------------\n";
          std::cout << "EMPLOYEE INFO OF [" << emp[i].get_emp_name() << "]"
                    << " IS :\n";
          std::cout << "--------------------\n";

          std::cout << "NAME :--- [" << emp[i].employee_name << "]"
                    << std::endl;
          std::cout << std::endl;
          std::cout << "JOB NAME :--- [" << emp[i].job_name << "]" << std::endl;
          std::cout << std::endl;
          std::cout << "MONTHLY SALARY :--- [" << emp[i].salary << "]"
                    << std::endl;
          std::cout << std::endl;
          std::cout << "ID :---[" << emp[i].EMP_ID << "]" << std::endl;
          std::cout << std::endl;
          std::cout << "EMAIL ID :---[" << emp[i].email_id << "]" << std::endl;
          std::cout << std::endl;
          std::cout << "--------------------\n";

          return 1;
        }
      }
    }
    std::cout << "-------------------------------\n";
    std::cout << "!! Invalid Name Or Password :--\n";
    std::cout << "-------------------------------\n";
    return 0;
  }

  std::string get_emp_name() { return employee_name; }

 

  int change_password(std::string name, int &nba, employee emp[100],
                      std::string password) {
    for (int i = 0; i < nba; i++) {
      if (name == emp[i].get_emp_name()) {
        if (password == emp[i].get_password()) {
          std::cout << "--------------------------\n";
          std::cout << "Enter New Password of:[" << emp[i].get_emp_name() << "]"
                    << "\n";
          std::cin >> emp[i].password12;
          std::cout << std::endl;

          std::cout << "PASSWORD HAS BEEN CHANGED:\n";
          std::cout << std::endl;
          return 1;
        }
      }
    }
    std::cout << "-------------------------------\n";
    std::cout << "!! Invalid Name Or Password :--\n";
    std::cout << "-------------------------------\n";
    return 0;
  }

  
  int change_employee_id(std::string name, int &nba, employee emp[100],
                         std::string password) {
    for (int i = 0; i < nba; i++) {
      if (name == emp[i].get_emp_name()) {
        if (password == emp[i].get_password()) {
          std::cout << "----------------------------\n";
          std::cout << "Enter New Employee Id of:[" << emp[i].get_emp_name()
                    << "]"
                    << "\n";
          std::cin >> emp[i].EMP_ID;
          std::cout << std::endl;

          std::cout << "EMPLOYEE ID HAS BEEN CHANGED:\n";
          std::cout << std::endl;
          return 1;
        }
      }
    }
    std::cout << "-------------------------------\n";
    std::cout << "!! Invalid Name Or Password :--\n";
    std::cout << "-------------------------------\n";
    return 0;
  }
  
  int change_employee_email(std::string name, int &nba, employee emp[100],
                            std::string password) {
    for (int i = 0; i < nba; i++) {
      if (name == emp[i].get_emp_name()) {
        if (password == emp[i].get_password()) {
          std::cout << "-------------------------\n";
          std::cout << "Enter New Email Id of:[" << emp[i].get_emp_name() << "]"
                    << "\n";
          std::cin >> emp[i].email_id;
          std::cout << std::endl;

          std::cout << "EMPLOYEE EMAIL HAS BEEN CHANGED:\n";
          std::cout << std::endl;
          return 1;
        }
      }
    }
    std::cout << "-------------------------------\n";
    std::cout << "!! Invalid Name Or Password :--\n";
    std::cout << "-------------------------------\n";
    return 0;
  }

  
  int promotion_salary_hike(std::string name, int &nba, employee emp[100],
                            std::string password) {
    for (int i = 0; i < nba; i++) {
      if (name == emp[i].get_emp_name()) {
        if (password == emp[i].get_password()) {

          std::cout << "---------------------------\n";
          std::cout << "Enter New Job Name :\n";
          std::cin.ignore();
          std::getline(std::cin, emp[i].job_name);
          std::cout << std::endl;

          std::cout << "Enter Monthly Salary Hike :\n";
          std::cin >> emp[i].salary_hike;
          std::cout << std::endl;

          emp[i].salary += emp[i].salary_hike;

          std::cout << "-------------------------------------------------------"
                       "----------\n";
          std::cout << "PROMOTED JOB NAME OF:[" << emp[i].get_emp_name()
                    << "] IS:[" << emp[i].job_name << "]"
                    << "||\n";
          std::cout << ":::::::::::::::::::::::::::::::::::::::::" << std::endl;
          std::cout << "SALARY HIKE :[" << emp[i].salary_hike << "]"
                    << "||\n";
          std::cout << ":::::::::::::::::::::::::::::::::::::::::" << std::endl;

          std::cout << "MONTHLY SALARY NOW :[" << emp[i].salary << "]"
                    << "||\n";
          std::cout << ":::::::::::::::::::::::::::::::::::::::::" << std::endl;
          return 1;
        }
      }
    }
    std::cout << "-------------------------------\n";
    std::cout << "!! Invalid Name Or Password :--\n";
    std::cout << "-------------------------------\n";
    return 0;
  }
  
  int delete_emp_info(std::string name, int &nba, employee emp[100],
                      std::string password) {
    for (int i = 0; i < nba; i++) {
      if (name == emp[i].get_emp_name()) {
        if (password == emp[i].get_password()) {
          std::cout << "Are you sure you want to delete [PRESS ENTER KEY TO "
                       "CONFIRM]\n";
          std::cin.ignore();
          std::cin.get();
          for (int j = i; j < nba - 1; j++) {
            emp[j] = emp[j = 1];
          }
          nba--;
          return 1;
        }
      }
    }
    std::cout << "-------------------------------\n";
    std::cout << "!! Invalid Name Or Password :--\n";
    std::cout << "-------------------------------\n";
    return 0;
  }

  std::string get_password() { return password12; }

}; 
// x------------------------------------------------------------------------x---------------------------------------------------------------------------x-----------------------------------------------------x

std::string employee_password =
    "qaz8937"; // password to access employee menu. this variable has been
               // declared globally

int main() {
  university uni; // Obejct of School_system class - MAIN CLASS.

  student_system stu[100], stu2; // object of student_system class named as stu

  employee emp[100], emp2; // objects of employee class name as emp

  int choice;

  uni.display_main_menu(); // calls the welcome part of the prorgam

  do {
    std::cout << "Choose Any Of The Following Options :\n"
              << std::endl; // This is the display_main_menu other half
                            
    std::cout << "1: Student Menu  :--\n";
    std::cout << "2: Employee Menu  :--\n";
    std::cout << "3: Miscellaneous :--\n";
    std::cout << "4: EXIT:\n";

    std::cout << "--------------------------------------\n"; // ASK for choice.
    std::cout << "ENTER YOUR CHOICE :--\n";
    std::cin >> choice;

    switch (choice) { // outer loop

    case 1: {

      int inner_choice;
      int i, n, n1, n2;

      std::string name; // variable to compare password in stu() arguments here
                        // and then in the class

      int result; 

      std::string password; // variable to compare password in stu() arguments
                            // here and then in the class

      stu2.display_student_menu(); // calls the welcome part of the program

      do {

        std::cout << "Choose Any Of The Following Options :\n"
                  << std::endl; // option menu
        std::cout << "1: Regsiter Student Data:       \n";
        std::cout << "2: Display Student Data:        \n";
        std::cout << "3: Register Marks of A Student:  \n";
        std::cout << "4: Generate Report Card of a Student:\n";
        std::cout << "5: FEE Payments of a student: \n";
        std::cout << "6: Payment History Of Student: \n";
        std::cout << "7: Delete Student Data: \n";
        std::cout << "8: Exit:\n";

        std::cout << "--------------------------------------\n";
        std::cout << "ENTER YOUR CHOICE :--\n";
        std::cin >> inner_choice;
        std::cout << "--------------------------------------\n";

        switch (inner_choice) { // inner switch case of nested switch case

        case 1:
          stu[i].input_student_data(n, stu);
          break;

        case 2:
          std::cout << "ENTER THE NAME OF STUDENT WHOOSE INFORMATION YOU WANT "
                       "TO SEE :--\n";
          std::cin.ignore();
          std::getline(std::cin, name);
          std::cout << std::endl;

          std::cout << "ENTER PASSWORD:\n";
          std::cin >> password;

          result = stu[i].display_student_data(
              name, password, n, stu); // arguments passed here accordingly

          break;

        case 3:
          std::cout << "ENTER THE NAME OF STUDENT WHOOSE MARKS YOU WANT TO "
                       "REGISTER:\n";
          std::cin.ignore();
          std::getline(std::cin, name);
          std::cout << std::endl;

          std::cout << "ENTER PASSWORD:\n";
          std::cin >> password;

          result = stu[i].grades_registeration(
              name, n, n2, stu, password); // arguments passed here accordingly
          if (result == 1) {
            break;
          }
          break;

        case 4:
          std::cout << "ENTER THE NAME OF STUDENT WHOOSE REPORT CARD YOU WANT "
                       "TO MAKE:\n";
          std::cin.ignore();
          std::getline(std::cin, name);
          std::cout << std::endl;

          std::cout << "ENTER PASSWORD:\n";
          std::cin >> password;
          result = stu[i].generate_report_card(
              name, n, n2, stu, password); // arguments passed here accordingly
          if (result == 1) {
            break;
          }
          break;

        case 5:
          std::cout << "ENTER THE NAME OF STUDENT FOR FEE PAYMENT :\n";
          std::cin.ignore();
          std::getline(std::cin, name);
          std::cout << std::endl;

          std::cout << "ENTER PASSWORD:\n";
          std::cin >> password;

          result = stu[i].fee_payments(
              name, n, n1, stu, password); // arguments passed here accordingly
          if (result == 1) {
            break;
          }
          break;

        case 6:
          std::cout << "ENTER THE NAME OF STUDENT WHOOSE PAYMENT HISORY YOU "
                       "WANT TO SEE:\n";
          std::cin.ignore();
          std::getline(std::cin, name);
          std::cout << std::endl;

          std::cout << "ENTER PASSWORD:\n";
          std::cin >> password;

          result = stu[i].display_payment_history(
              name, n, n1, stu, password); // arguments passed here accordingly
          if (result == 1) {
            break;
          }
          break;

        case 7:
          std::cout
              << "ENTER NAME OF THE STUDENT WHOOSE DATA YOU WANT TO DELETE:\n";
          std::cin.ignore();
          std::getline(std::cin, name);
          std::cout << std::endl;

          std::cout << "ENTER PASSWORD:\n";
          std::cin >> password;

          result = stu[i].delete_student_data(
              name, n, stu, password); // arguments passed here accordingly
          if (result == 1) {

            std::cout << "ACCOUNT HAS BEEN DELETED :--\n";
            std::cout << "----------------------------\n";
            break;
          }
          break;

        } // exits the nested switch case 1: { and ask user wheter they want to
          // contine or not, until and till choice = 0 it will continue and you
          // will return to main menu

        std::cout << "PRESS [0] TO RETURN TO MAIN MENU :: PRESS [1] TO "
                     "CONTINUE ON THIS MENU :--\n";
        std::cin >> inner_choice;
        std::cout << "---------------------------------------------------------"
                     "-----------------\n";

        if (inner_choice == 0) {
          std::cout << "RETURNED TO MAIN MENU :-- [PRESS ENTER KEY]"
                    << std::endl;
          std::cin.ignore();
          std::cin.get();
        }
      } while (inner_choice != 0);

      break; // case 1:{ ends here
    }

    case 2: { // case 2: { for employee menu starts here
      int second_choice;

      std::string
          password; // this variable is being used to compare globally decalred
                    // employee_password with password to start employee meny

      std::string password1; // comparison for password

      int n23, i, result;
      std::string name;

      // this below section ask the user to enter the password for employee
      // men which is 3698, the value of 3698 is globally decalred it takes
      // that and the if condtion checks it if it meets the entire employee menu
      // is show otherwise says invalid password
      std::cout << std::endl;
      std::cout << "ENTER PASSWORD FOR EMPLOYE MENU :\n";
      std::cin >> password;

      if (employee_password == password) {
        emp2.display_employee_menu(); // brings the welcome part of the program
        do {

          std::cout << "Choose Any of the following options:\n" << std::endl;
          std::cout << "1: Register Employee Data:\n";
          std::cout << "2: Display Employee Data :\n";
          std::cout << "3: Change Credentials Of Employee:\n";
          std::cout << "4: Promotion of Employee:\n";
          std::cout << "5: Delete Employee Data:\n";
          std::cout << "6: Exit:\n";
          std::cout << "------------------------------------------\n";

          std::cout << "ENTER YOUR CHOICE:\n";
          std::cin >> second_choice;
          std::cout << "------------------------------------------\n";

          switch (second_choice) { // case 2:{ inner switch or nested switch
                                   // begins here

          case 1:

            emp[i].input_employee_data(n23, emp); // calls the function
            break;

          case 2:
            std::cout << "ENTER THE OF EMPLOYEE WHOOSE INFORMATION YOU WANT TO "
                         "SEE:\n";
            std::cin.ignore();
            std::getline(std::cin, name);
            std::cout << std::endl;

            std::cout << "Enter Password:\n";
            std::cin >> password1;
            std::cout << std::endl;

            result = emp[i].display_employee_info(name, n23, emp, password1);
            if (result == 1) {
              break;
            }
            break;

          case 3: { // this here is a nested switch in a switch statement, it
                    // choose the change crednetials option and show you 3 more
                    // options
            int case_3_choice;
            std::string name;
            int result;

            do {
              std::cout << "Change Any Of The Following:\n"
                        << std::endl; // the three more option s
              std::cout << "1: Change Password :\n";
              std::cout << "2: Change Employee ID :\n";
              std::cout << "3: Change Email ID :\n";
              std::cout << "4: Exit : \n";

              std::cout << "------------------------------------\n";
              std::cout << "ENTER YOUR CHOICE :\n";
              std::cin >> case_3_choice;
              std::cout << "-------------------------------------\n";

              switch (case_3_choice) { // choice for this particular nested case

              case 1:
                std::cout << "ENTER THE NAME OF EMPLOYEE WHOOSE PASSWORD YOU "
                             "WANT TO CHANGE :\n";
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << std::endl;

                std::cout << "Enter Password:\n";
                std::cin >> password1;
                std::cout << std::endl;

                result = emp[i].change_password(
                    name, n23, emp,
                    password1); // calls the change password functionm
                if (result == 1) {
                  break;
                }
                break;

              case 2:
                std::cout << "ENTER THE NAME OF EMPLOYEE WHOOSE ID YOU WANT TO "
                             "CHANGE :\n";
                std::cin.ignore();
                std::getline(std::cin, name);

                std::cout << std::endl;

                std::cout << "Enter Password:\n";
                std::cin >> password1;
                std::cout << std::endl;

                result = emp[i].change_employee_id(name, n23, emp, password1);
                if (result == 1) {
                  break;
                }
                break;

              case 3:
                std::cout
                    << "ENTER THE NAME OF EMPLOYEE WHOOSE EMAIL ID YOU WANT TO "
                       "CHANGE :\n"; // calls the change employee email fucntion
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << std::endl;

                std::cout << "Enter Password:\n";
                std::cin >> password1;
                std::cout << std::endl;

                result =
                    emp[i].change_employee_email(name, n23, emp, password1);
                if (result == 1) {
                  break;
                }
                break;
              }

              std::cout
                  << "PRESS [0] TO RETURN TO EMPLOYEE MENU :: PRESS [1] TO "
                     "CONTINUE ON THIS MENU :--\n"; // this section is only for
                                                    // the change menu
              std::cin >> case_3_choice;
              std::cout << "---------------------------------------------------"
                           "-----------------------\n";

              if (case_3_choice == 0) {
                std::cout << "RETURNED TO EMPLOYEE MENU :-- [PRESS ENTER KEY]"
                          << std::endl;
                std::cin.ignore();
                std::cin.get();
              }

            } while (case_3_choice != 0);

            break;
          }
       

          case 4:
            std::cout << "ENTER THE NAME OF EMPLOYEE WHO YOU WANT TO GIVE "
                         "PROMOTION TO:\n"; //  calls the job_promotion function

            std::cin.ignore();
            std::getline(std::cin, name);
            std::cout << std::endl;

            std::cout << "Enter Password:\n";
            std::cin >> password1;
            std::cout << std::endl;

            result = emp[i].promotion_salary_hike(name, n23, emp, password1);
            if (result == 1) {
              break;
            }
            break;

          case 5:
            std::cout << "ENTER THE NAME OF EMPLOYEE WHOOSE DATA YOU WANT TO "
                         "DELETE :\n"; // deletes the information of employee

            std::cin.ignore();
            std::getline(std::cin, name);
            std::cout << std::endl;

            std::cout << "Enter Password:\n";
            std::cin >> password1;
            std::cout << std::endl;

            result = emp[i].delete_emp_info(name, n23, emp, password1);
            if (result == 1) {
              std::cout << "ACCOUNT HAS BEEN DELETED :--\n";
              std::cout << "----------------------------\n";
              break;
            }
            break;
          }
          std::cout
              << "PRESS [0] TO RETURN TO MAIN MENU :: PRESS [1] TO CONTINUE ON "
                 "THIS MENU :--\n"; // ask the user wheter to stay in this menu
                                    // or exit
          std::cin >> second_choice;
          std::cout << "-------------------------------------------------------"
                       "-------------------\n";

          if (second_choice == 0) {
            std::cout << "RETURNED TO MAIN MENU :-- [PRESS ENTER KEY]"
                      << std::endl;
            std::cin.ignore();
            std::cin.get();
          }

        } while (second_choice != 0);

      } else {
        std::cout
            << "!! INVALID PASSWORD:\n"; // the part of if conditon that checks
                                         // if the password for employee menu is
                                         // correct or not
        std::cout << "------------------------------\n";
      }

      break;
    }

    case 3: // joke part of the program it uses infinite loop to crash the
            // program
      for (;;) {
        std::cout << "crash-crash";
      }
    }
    std::cout
        << "PRESS [1] TO CONTINUE MAIN MENU :: PRESS [0] TO EXIT THE PROGRAM "
           ":--\n"; // ask the user to exit the program or continue
    std::cin >> choice;
    std::cout << "-------------------------------------------------------------"
                 "-------------\n";

    if (choice == 0) {
      std::cout << "THANKS FOR USING THE APPLICATION :"
                << std::endl; // exit message
    }

  } while (choice != 0);
  return 0;
}


