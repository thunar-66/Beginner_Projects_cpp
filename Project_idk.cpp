// Csv File Based Data Storage / Mimics an Employee Registry To Some Extent [Made By Birinder singh]
// echoing enabled 

 





#include<iostream>
#include<fstream>
#include<sstream>
#include<ctime>
#include<cstring>
#include<termios.h>
#include<unistd.h>


void display(){
    std::cout <<"\n";
    std::cout <<          ":|--------------------------------------------------------:|"<<"\n";
    std::cout <<          "    Welcome To Employee Regsitery [Press Enter To Start]    "<<"\n";
    std::cout <<          ":|--------------------------------------------------------:|"<<"\n";
    std::cin.ignore();
    std::cin.get();
}
void custom_line(){
    std::cout <<"---------------------------------:\n";
}
void custom_line_2(){
    std::cout <<"-----------------------------------------------:\n";
}
void new_line(){
    std::cout <<"\n";
}

class employee{
    private:
     std::string name;
     std::string password;
     std::string emp_id;
     std::string mobile_no;
     std::string job_name;
     std::string email;
     
     long int salary;
     int lenght,lenght_2;
     int class_choice;

     int choice;



    public:
     void setecho(bool enable){
        struct termios tty;
        tcgetattr(STDIN_FILENO, &tty);
        if(!enable){
            tty.c_lflag &= ~ECHO;

        }
        else{
            tty.c_lflag |= ECHO;
        }
        (void) tcsetattr(STDIN_FILENO,TCSANOW, &tty);
     }
     
     void input_data(int &n){
        std::fstream myfile("Emp.csv",std::ios::app);
        if(myfile.is_open()){

            for(int i=0;i<n;i++){
                
                new_line();
                std::cout <<"Enter The Name Of Employee :-- [ ";
                std::getline(std::cin >> std::ws,name);
                new_line();
 
                //------------------------------------------------------------------------------------------------//
                std::cout <<"::-- Enter [1] For Custom Passowrd || [2] For Automatic Password :-- [ ";
                std::cin >> class_choice;
                new_line();
                switch(class_choice){
                    case 1:
                     std::cout <<"::-- Create Password For Employee [" <<name <<"] :--[ ";
                     setecho(false);
                     std::cin >> password;
                     setecho(true);
                     new_line();
                     break;

                    case 2:
                     do{
                        std::cout <<"::-- Enter Lenght For Password Of Employee [" <<name <<"] :-- [ ";
                        setecho(false);
                        std::cin >> lenght;
                        setecho(true);
                        new_line();
                        if(lenght < 7 ){
                            std::cerr <<"::-- !! Lenght Should Be Greater Than or 7 :-- \n";
                            new_line();
                        }else{
                            password = random_gen(lenght);
                            std::cout <<"::-- Password For Employee [" <<name <<"] IS :-- [ " <<password <<"\n";
                            new_line();
                        }

                     }while(lenght < 7);
                      
                }
                //------------------------------------------------------------------------------------------------//
                

                std::cout <<"Enter Email Id of Employee [" <<name <<"] :-- [ ";
                std::cin >> email;
                new_line();

                do{
                    std::cout <<"::-- Enter Lenght For Employee [" <<name <<"] ID :-- [ ";
                    std::cin >> lenght_2;
                    new_line();

                    if(lenght_2 < 10){
                        std::cerr <<"::-- !! Lenght Should Be Greater Than or 10 :-- \n\n";
                    }else{
                        emp_id = random_gen(lenght_2);
                        std::cout <<"::-- Employee ID of [" <<name <<"] IS :--[ " <<emp_id <<"\n";
                        new_line();
                    }

                }while(lenght_2 < 10);
                //------------------------------------------------------------------------------------------------//

                std::cout <<"Enter Mobile No of Employee [" <<name <<"] :-- [ ";
                std::cin >> mobile_no;
                new_line();

                std::cout <<"Enter Job Title of Employee [" <<name <<"] :-- [ ";
                std::getline(std::cin >> std::ws,job_name);
                new_line();

                std::cout <<"Enter Current Annual Salary of Employee [" <<name <<"] :-- [ ";
                std::cin >> salary;
                new_line();
                
                custom_line_2();
                std::cout <<"!! Employee Information Has Been Registered :-- \n";
                custom_line_2();


                myfile <<name <<',' <<password <<"," <<email <<"," <<emp_id <<',' <<mobile_no <<',' <<job_name <<',' <<salary <<"\n";
                myfile.close();

            }


        }
     }

    //------------------------------------------------------------------------------------------------------------//
     std::string random_gen(int &lenght){
        std::string random = "";
        std::string character = "qwertyuioplkjhgfdsazxcvbnmqwertyuioplkjhgfdsazxcvbnm1234567890?@!";

        int char_size = character.size();
        int random_index;

        srand(time(0));

        for(int i=0;i<lenght;i++){
            random_index = rand() % char_size;
            random = random + character[random_index];
        }
        return random;
     }
    //------------------------------------------------------------------------------------------------------------//


     int display_emp_info(std::string &name,std::string &password){
        std::ifstream myfile("Emp.csv");
        std::ofstream myfile_2("Temp.csv");

        if(myfile.is_open() && myfile_2.is_open()){
            std::string line;
            bool found = false;
            while(std::getline(myfile,line)){
                
                std::stringstream ss(line);
                std::string row_name,row_password,row_email,row_id,row_mobile,row_job,row_salary;

                std::getline(ss,row_name,',');
                std::getline(ss,row_password,',');

                if(row_name == name && row_password == password){
                    found = true;

                   
                     std::getline(ss,row_email,',');
                     std::getline(ss,row_id,',');
                     std::getline(ss,row_mobile,',');
                     std::getline(ss,row_job,',');
                     std::getline(ss,row_salary,',');
                    

                     custom_line();
                     std::cout <<"Employee Infomation OF ["<<name <<" ] IS : \n";
                     new_line();
                     std::cout <<"Employee Name :-- [ " <<name <<" ] : \n";
                     std::cout <<"Employee PassKey :-- [ " <<password <<" ] : \n";
                     std::cout <<"Employee Email :-- [ " <<row_email <<" ] : \n";
                     std::cout <<"Employee Id :-- [ " <<row_email <<" ] : \n";
                     std::cout <<"Employee Mobile No :--  [ " <<row_mobile <<" ] :\n";
                     std::cout <<"Employee Job :-- [ " <<row_job <<" ] : \n";
                     std::cout <<"Employee Salary :-- [ " <<row_salary <<" ] :\n";
                    
                     custom_line();
                     new_line();
                }

            }
            myfile.close();
            myfile_2.close();

            if(!found){
                custom_line();
                std::cerr <<"!! Wrong Name Or Password :-- \n";
                custom_line();
            }

           }else{
            custom_line();
            std::cerr <<"!! Unable To Open Database :-- \n";
            custom_line();
           }
           return 0;
        }


    //------------------------------------------------------------------------------------------------//
    int delete_employee_info(std::string &name,std::string &password){
        std::ifstream myfile("Emp.csv");
        std::ofstream myfile_2("Temp.csv");

        if(myfile.is_open() && myfile_2.is_open()){
            std::string line;
            bool done = false;

            while(std::getline(myfile,line)){
                std::stringstream ss(line);
                std::string row_name,row_password;

                std::getline(ss,row_name,',');
                std::getline(ss,row_password,',');
                
    
                if(row_name == name && row_password == password){
                    new_line();
                    new_line();
                    std::cout <<"! ARE YOUR SURE TO DELETE INFORMATION PERMANENTLY [ Press Enter Key ] \n";
                    std::cin.ignore();
                    std::cin.get();

                    done = true;
                    continue;
                }
                myfile_2 <<line <<"\n";
            }
            myfile.close();
            myfile_2.close();


            if(std::remove("Emp.csv")!=0){
                custom_line();
                std::cerr <<"!! Unable To Make Changes :-- \n";
                custom_line();
                return 1;
            }
            if(std::rename("Temp.csv","Emp.csv")!=0){
                custom_line();
                std::cerr <<"!! Unable To Make Changes :-- \n";
                custom_line();
                return 1;
            }

            if(!done){
                custom_line();
                std::cerr <<"!! Wrong Name Or Password :-- \n";
                custom_line();
                return 1;
            }else{
                custom_line_2();
                std::cout <<"Employee Information Deleted SuccessFully :-- \n";
                custom_line_2();
                return 0;
            }
            
        }
        return 0;
    }


    int promotion_emp(std::string &name,std::string &password){
        double add_salary;
        std::ifstream file("Emp.csv");
        std::ofstream file2("Temp.csv");


        if(file.is_open() && file2.is_open()){
            std::string line;
            bool found = false;
            while(std::getline(file,line)){
                std::stringstream ss(line);
                std::string row_name,row_password,row_email,row_id,row_mobile,row_job,row_salary;

                std::getline(ss,row_name,',');
                std::getline(ss,row_password,',');

                if(row_name == name && row_password == password){
                    found = true;

                   
                     std::getline(ss,row_email,',');
                     std::getline(ss,row_id,',');
                     std::getline(ss,row_mobile,',');
                     std::getline(ss,row_job,',');
                     std::getline(ss,row_salary,',');
                     new_line();
                     std::cout <<"Change Job Name [Promotion] :-- [ ";
                     std::getline(std::cin>>std::ws,row_job);
                     new_line();

                     std::cout <<"Enter New  Annual Salary :-- [ ";
                     std::cin >> add_salary;
                     new_line();
                     

                     double current_salary = std::stol(row_salary);
                     current_salary += add_salary;

                     file2 <<row_name <<',' <<row_password <<"," <<row_email <<"," <<row_id <<',' <<row_mobile <<',' <<row_job <<',' <<current_salary <<"\n";
                     



            }else{
                file2 <<line <<"\n";
            }
        }
        file.close();
        file2.close();

        if(std::remove("Emp.csv")!=0){
            custom_line();
            std::cerr <<"!! Unable to Make Changes :-- \n";
            custom_line();
            return 1;
        }
        if(std::rename("Temp.csv","Emp.csv")!=0){
            custom_line();
            std::cerr <<"!! Unable To Make Changes :-- \n";
            custom_line();
            return 1;

        }

        if(!found){
            custom_line();
            std::cerr <<"!! Wrong Name Or Password :-- \n";
            custom_line();
            return 1;
        }else{
            custom_line_2();
            std::cout <<"Employee Promotion Details Have Been Regsitered :-- \n";
            custom_line_2();
            return 0;
        }
    }
    return 0;

        
 }


  int change_credentials(std::string &name,std::string &password){
    std::ifstream myfile ("Emp.csv");
    std::ofstream myfile2("Temp.csv");

    if(myfile.is_open() && myfile2.is_open()){
        std::string line;
        bool found = false;
        while(std::getline(myfile,line)){
            std::stringstream ss(line);
            std::string row_name,row_password,row_email,row_id,row_mobile,row_job,row_salary;

                std::getline(ss,row_name,',');
                std::getline(ss,row_password,',');

                if(row_name == name && row_password == password){
                    found = true;

                   
                     std::getline(ss,row_email,',');
                     std::getline(ss,row_id,',');
                     std::getline(ss,row_mobile,',');
                     std::getline(ss,row_job,',');
                     std::getline(ss,row_salary,',');

                     do{
                        new_line();
                        std::cout <<"1 Change Email Id  :-- \n";
                        std::cout <<"2 Change Password  :-- \n";
                        std::cout <<"3 Change Mobile No :-- \n\n";
 
                        std::cout <<"Enter Your Choice :-- \n";
                        std::cout <<"-> ";
                        std::cin >> choice;

                        switch(choice){

                            case 1:
                            new_line();
                            std::cout <<"Enter New Email Id of [" <<name <<"] : [ ";
                            std::cin >> row_email;
                            new_line();
                            std::cout <<"Employee Information Changed :-- ";
                            new_line();
                            myfile2 <<row_name <<',' <<row_password <<"," <<row_email <<"," <<row_id <<',' <<row_mobile <<',' <<row_job <<',' <<row_salary<<"\n";
                            break;

                            case 2:
                            new_line();
                             std::cout <<"Enter New Password For ["<<name <<"] : [ ";
                             std::cin >> row_password;
                             new_line();
                             std::cout <<"Employee Information Changed :-- \n";
                             new_line();
                             myfile2 <<row_name <<',' <<row_password <<"," <<row_email <<"," <<row_id <<',' <<row_mobile <<',' <<row_job <<',' <<row_salary<<"\n";
                             break;

                            case 3:
                            new_line();
                             std::cout <<"Enter New Mobile No Of Employee [" <<name <<"] : [ ";
                             std::cin >> row_mobile;
                             new_line();
                             std::cout <<"Employee Information Changed :-- ";
                             new_line();
                             myfile2 <<row_name <<',' <<row_password <<"," <<row_email <<"," <<row_id <<',' <<row_mobile <<',' <<row_job <<',' <<row_salary<<"\n";
                             break; 

                             
                        }
                        new_line();
                        std::cout <<"[1] Return To Main Menu || [0] To Change Credential Menu :-- \n";
                        std::cout <<"-> ";
                        std::cin >> choice;
                        if(choice == 0){
                            new_line();
                            std::cout <<"Returned To Change Credential Menu :-- \n";
                        }
                     }while(choice != 1);
        }else{
            myfile2 <<line <<"\n";
        }
        break;
    }
    myfile.close();
    myfile2.close();

    if(std::remove("Emp.csv")!=0){
            custom_line();
            std::cerr <<"!! Unable to Make Changes :-- \n";
            custom_line();
            return 1;
        }
        if(std::rename("Temp.csv","Emp.csv")!=0){
            custom_line();
            std::cerr <<"!! Unable To Make Changes :-- \n";
            custom_line();
            return 1;

        }

        if(!found){
            custom_line();
            std::cerr <<"!! Wrong Name Or Password :-- \n";
            custom_line();
            return 1;
        }
    

    }
  return 0;
  }



};


int main(){
    employee emp;
    int choice,inner_choice,n;
    std::string name,password;
    
    do{
    std::cout <<"[1] To Login || [2] To Sign Up :\n";
    std::cout <<"-> ";
    std::cin >> choice;

    switch(choice){

        case 1:{
            std::ifstream read_file("Admn.csv");
            if(read_file.is_open()){
                std::string line;
                std::string name_3;
                std::string password_3;
                while(std::getline(read_file,line)){
                    std::stringstream ss(line);
                    std::string row_name,row_password;

                    std::getline(ss,row_name,',');
                    std::getline(ss,row_password,',');

                    custom_line();
                    std::cout <<"Enter Registered Adminstrator Name :-- [ ";
                    std::getline(std::cin>>std::ws,name);
                    new_line();
     
                    std::cout <<"Enter Password for Adminstrator [" <<name <<"] :For Secuity Reason Password Will Not Be Visible :-\n";
                    std::cout <<"-> ";
                    emp.setecho(false);
                    std::cin >> password;
                    emp.setecho(true);

                    if(name == row_name && password == row_password){

                        display();

                        do{
                            std::cout <<"Choose Any Of the Following Options :-- \n\n";
                            std::cout <<"0: Exit                              :--\n";
                            std::cout <<"1: Register New Employee Information :-- \n";
                            std::cout <<"2: Display Employee Information      :-- \n";
                            std::cout <<"3: Promotion / Bonus To a Employee   :-- \n";
                            std::cout <<"4: Change Credentials of a Employee  :-- \n";
                            std::cout <<"5: Delete Employee Information       :-- \n\n";

                            std::cout <<"Enter Your Choice :-- \n";
                            std::cout <<"-> ";
                            std::cin >> inner_choice;

                            switch(inner_choice){

                                case 1:
                                 new_line();
                                 std::cout <<"How Many Employee Information you want to Resgiter :-- \n";
                                 std::cout <<"-> ";
                                 std::cin >> n;
                                 emp.input_data(n);
                                 break;

                                case 2:
                                 new_line();
                                 std::cout <<"Enter Employee Name Whoose Information is to be Displayed :-- [ ";
                                 std::getline(std::cin >> std::ws,name_3);
                                 new_line();

                                 std::cout <<"Enter Password Of Employee [ " <<name_3 <<"] :-- [ ";
                                 emp.setecho(false);
                                 std::cin >> password_3;
                                 emp.setecho(true);
                                 emp.display_emp_info(name_3,password_3);
                                 break; 


                                case 3:
                                 new_line();
                                 std::cout <<"Enter Employee Name For Promotion Information Registeration :-- [ ";
                                 std::getline(std::cin >> std::ws,name_3);
                                 new_line();

                                 std::cout <<"Enter Password Of Employee [ " <<name_3 <<"] :-- [ ";
                                 emp.setecho(false);
                                 std::cin >> password_3;
                                 emp.setecho(true);
                                 emp.promotion_emp(name_3,password_3);
                                 break;

                                case 4:
                                 new_line();
                                 std::cout <<"Enter Employee Name For Credential Change :-- [ ";
                                 std::getline(std::cin >> std::ws,name_3);
                                 new_line();

                                 std::cout <<"Enter Password Of Employee [ " <<name_3 <<"] :-- [ ";
                                 emp.setecho(false);
                                 std::cin >> password_3;
                                 emp.setecho(true);

                                 emp.change_credentials(name_3,password_3);
                                 break;


                                case 5:
                                new_line();
                                std::cout <<"Enter Employee Name Whoose Information You want To Delete :-- [ ";
                                std::getline(std::cin >> std::ws,name_3);
                                new_line();

                                std::cout <<"Enter Password Of Employee [ " <<name_3 <<"] :-- [ ";
                                emp.setecho(false);
                                std::cin >> password_3;
                                emp.setecho(true);
                                emp.delete_employee_info(name_3,password_3);
                                break;
                                  


                            }
                            new_line();
                            std::cout <<"[1] Return To Main Menu || [0] To Exit To Login/Sign up Menu :-- \n";
                            std::cout <<"-> ";
                            std::cin >> inner_choice;
                            new_line();
                            if(inner_choice == 1){
                                std::cout <<"Returned To Main Option Menu :-- \n\n";
                            }
                        }while(inner_choice != 0);
                        
                    
                        
                        

                    }else{
                        custom_line_2();
                        std::cerr <<"!! Wrong Passowrd|Name Or Admin User Does Not Exsit :-- \n";
                        custom_line_2();
                        new_line();
                    }
                    break;
                }
                read_file.close();

            }
            

        }break;

        case 2:{
            std::fstream myfile("Admn.csv",std::ios::app);
            if(myfile.is_open()){
                custom_line();
                std::cout <<"Enter Name For Admin Sign Up :-- [ ";
                std::getline(std::cin >> std::ws,name);
                new_line();

                std::cout <<"Create A Secure Password For Admin [" <<name <<"] :--[ ";
                emp.setecho(false);
                std::cin >> password;
                emp.setecho(true);
                new_line();

                myfile <<name <<',' <<password <<"\n";
                myfile.close();

                
            }

        }break;
    }
    std::cout <<"[1] To Return To Login/Sign Up Menu || [0] To Exit :-- \n";
    std::cout <<"-> ";
    std::cin >> choice;
    new_line();
    if(choice == 0){
        std::cout <<":- Thanks For using The Program : Done Exiting :-- \n";
    }
    }while(choice != 0);
    return 0;
}
