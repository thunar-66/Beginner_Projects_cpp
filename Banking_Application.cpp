// Documentation // 
// Banking Application with File handling. Developed By [ Birinder singh ] [ Punjab Technical University ] ::



// A cvs file Named "Bank_store.csv will be created automatically in the location of Program save file.
// Menu based banking console screen application with bs secuitry [ options ask only for password which is visible ] 



#include<iostream>
#include<fstream>
#include<sstream>   
#include<ctime>

void display_menu(){
	std::cout <<"||------------------------------------------------------------------||\n";
	std::cout <<"     Welcome To Banking Application [ Press Enter Key To Start ]    \n"; 
	std::cout <<"||------------------------------------------------------------------||\n";
	std::cin.ignore();
}

void custom_line(){
	std::cout <<"------------------------------:\n";
}
void custom_line_2(){
	std::cout <<"-------------------------------------------------------:\n";
}


class bank{ 
	private:
		std::string name;
		std::string password;
		std::string account_no;
		std::string email;
		
		long long int mobile_no;
		double balance;
		int lenght;
	
	
	public:
		
		
// Explanation of Input_data(int n) function -> opens a csv file named bank_store in appened mode, and user is prompted to enter details of bank account holder.
// Along with n which how many bank accounts to register 
// write the data to bank_store.csv.	
// ',' is used to seperate data	
	  
	 int input_data(int n){                                      
	 	
	 	std::fstream myfile;
	 	myfile.open("Bank_store.csv",std::ios::app);
	 	
	 	if(myfile.is_open()){
	 	
			 for(int i=0 ;i<n;i++){
			 	
			 
			 	std::cout <<"Enter The Name Of Bank Account Holder :-- [";
			 	std::getline(std::cin >> std::ws,name);
			 	std::cout <<"\n";
			 	
			 	std::cout <<"Create A Password FOR [ "<<name <<" ] :-- [";
			 	std::cin >> password;
			 	std::cout <<"\n";
			 	
			 	std::cout <<"Enter Lenght For [" <<name <<"] Bank Account [ 10 IS RECOMMENDED ] :-- [";
			 	std::cin >> lenght;
			 	account_no = generate_random(lenght);
			 
			 	std::cout <<"Account No Of [" <<name <<"] is [" <<account_no <<"] :\n";
			 	std::cout <<"\n";
		
			 	
			 	std::cout <<"ENTER Email Id of [" <<name <<"] :-- [";
				std::cin  >> email;
				std::cout <<"\n";
				
				std::cout <<"Enter Mobile No of [" <<name <<"] :-- [";
				std::cin >> mobile_no;
				std::cout <<"\n";
				
				std::cout <<"Intial Deposit of [" <<name <<"] :-- [";
				std::cin >> balance;
				std::cout <<"\n";
				
				custom_line();
				std::cout <<"Data has been Registred :-- \n";
				custom_line();
				
				myfile <<name <<"," <<password <<"," <<account_no <<"," <<email <<"," <<mobile_no <<"," <<balance <<"\n";
			 	
			 }
			 myfile.close();
			 
		 }else{
		 	custom_line_2();
		 	std::cerr <<"!! Unable To open Database For Bank Account Registeration :-- ";
		 	custom_line_2();
		 }
		 return 0;
	 	
	 }
	 
// Explanation of display_bank_info -> opens the same csv file in read mode. A condition is passed to only cout info of a single user instead of all. A boolean flag to track is declare
// ss is the instance of stringstream to treat line as a horizontal stream.
// variables ex: row_account etc are assumptions that this is where the data might be horizonntally 
// once name and password match it display info to the console 


	 int display_bank_info(std::string name, std::string password){
	 	std::ifstream display("Bank_store.csv");
	 	if(display.is_open()){
	 		
	 		bool found = false;
	 		std::string line;
	 		while(std::getline(display,line)){
	 			std::stringstream ss(line);
	 			
	 			std::string row_name,row_password,row_account,row_email,row_mobile_no,row_balance;
	 			std::getline(ss,row_name,',');
	 			std::getline(ss,row_password,',');
	 			
	 			if(row_name == name && row_password == password){
	 				std::getline(ss,row_account,',');
	 				std::getline(ss,row_email,',');
	 				std::getline(ss,row_mobile_no,',');
	 				std::getline(ss,row_balance,',');
	 				
	 				custom_line();
	 				
	 				std::cout <<"ACCOUNT INFORMATION OF [ "<<name <<"] is :-- \n\n";
	 				std::cout <<"Name :-- [ " <<name <<" ]\n";
	 				std::cout <<"Password :-- [ " <<password <<" ]\n";
	 				std::cout <<"Account No :-- [ " <<row_account <<" ]\n";
	 				std::cout <<"Email ID :-- [ " <<row_email <<" ] \n";
	 				std::cout <<"Mobile No :-- [ " <<row_mobile_no <<" ]\n";
	 				std::cout <<"Current Balance :-- [ " <<row_balance <<" ]\n";
					 
					custom_line();  
					found = true;
				 }
			 }
			 display.close();
			 
			 if(!found){
			 	custom_line_2();
			 	std::cerr <<"!! Eror Displaing Information [ Invalid Name or Password ] :--\n";
			 	custom_line_2();
			 	return 1;
			 }
		 }else{
		 	custom_line();
		 	std::cerr <<"!! Unable To Open Database For Bank Information  :-- ";
		 	custom_line();
		 }
		 return 0;
	 }
// random number generator -> setting seed for random number by taking time(0), take lenght as arugument from the user

	 std::string generate_random(int lenght){
	 	std::string random = "";
	 	std::string characters = "qwertyuioplkjhgfdsazxcvbnmMNBVCXZASDFGHJKLPOIUYTREQW1234567890";
	 	
	 	int charsize = characters.size();
	 	int random_index;
	 	srand(time(0));
	 	
	 	for(int i=0;i<lenght;i++){
	 		
	 		random_index = rand() % charsize;
	 		random = random + characters[random_index];		 	 		
		 }
		 return random;
	 }

// explanation of deposit_money -> opens two file in  read and write mode. We assume each fields that this is where the data belong \
// search for each line of conditon name and password.
// we convert row_balance to double
// ask the user to input amount
// we remove the bank_store.csv to indicate value changes
// we rename temp.csv to bank_store.csv so display function works;

	 bool deposit_money(std::string name,std::string password){
	 	double amount;
	 	std::ifstream depo("Bank_store.csv");
	 	std::ofstream depo_2("Temp.csv");
	 	
	 	if(depo.is_open() && depo_2.is_open()){
	 		bool found = false;
	 		std::string line;
	 		
	 		while(std::getline(depo,line)){
	 			std::stringstream ss(line);
	 			std::string row_name,row_password,row_account,row_email,row_mobile_no,row_balance;
	 			
	 			std::getline(ss,row_name,',');
	 			std::getline(ss,row_password,',');
	 			
	 			if(row_name == name && row_password == password){
	 				found = true;
	 				std::getline(ss,row_account,',');
	 				std::getline(ss,row_email,',');
	 				std::getline(ss,row_mobile_no,',');
	 				std::getline(ss,row_balance,',');
	 				
	 				std::cout <<"Enter Credit / Deposit Amount [$] :-- \n";
	 				std::cin >> amount;
	 				
	 				double current_balance = std::stol(row_balance);
	 				current_balance += amount;
	 				
	 				
	 				depo_2 <<row_name <<"," <<row_password <<"," <<row_account <<"," <<row_email <<"," <<row_mobile_no <<"," <<current_balance <<"\n";
	 				
				 }else{
				 
				 depo_2 <<line <<"\n";
			}
	 			
	 			
			 }
	 		depo.close();
	 		depo_2.close();
	 		
	 	if(std::remove("Bank_store.csv")!=0){
	 		custom_line();
		 	std::cerr <<"!! Unable To Make Changes :-- \n";
		 	custom_line();
		 	return false;
		 }
		 if(std::rename("Temp.csv","Bank_store.csv")!= 0){
		 	custom_line();
		 	std::cerr <<"!! Unable To Make Changes :-- \n";
		 	custom_line();
		 	return false;
		 }
		 if(found){
		 	custom_line();
		 	std::cout <<"!! Money Has Been Deposited [" <<amount <<"] :-- \n";
		 	custom_line();
		 	return true;
		 }else{
		 	custom_line_2();
		 	std::cout <<"!! Error Depositing Money [ Invalid Name or Password ]:\n";
		 	custom_line_2();
		 	return false;
		 }
	
		 
 	 }
 	 return true;
  }
// explanation of withdraw money -> opens two file in  read and write mode. We assume each fields that this is where the data belong \
// search for each line of conditon name and password.
// we convert row_balance to double
// ask the user to input amount
// we remove the bank_store.csv to indicate value changes
// we rename temp.csv to bank_store.csv so display function works;
	
  bool withdraw_money(std::string name,std::string password){
  	double amount;
  	std::ifstream with("Bank_store.csv");
  	std::ofstream with_2("Temp_2.csv");
  	
  	if(with.is_open() && with_2.is_open()){
  		bool found = false;
  		
  		std::string line;
  		while(std::getline(with,line)){
  			
  			std::stringstream ss(line);
  			std::string row_name,row_password,row_account,row_email,row_mobile_no,row_balance;
  			
  			std::getline(ss,row_name,',');
  			std::getline(ss,row_password,',');
  			
  			if(row_name == name && row_password == password){
  				found = true;
  				
  				std::getline(ss,row_account,',');
	 			std::getline(ss,row_email,',');
	 			std::getline(ss,row_mobile_no,',');
	 			std::getline(ss,row_balance,',');
	 			
	 			std::cout <<"Enter Debit / Withdraw Amount [$] :-- \n";
	 			std::cin >> amount;
	 			double current_balance = std::stol(row_balance);
	 			current_balance -= amount;
	 			
	 			with_2 <<row_name <<"," <<row_password <<"," <<row_account <<"," <<row_email <<","  <<row_mobile_no <<"," <<current_balance <<"\n";
	 				
			  }else{
			  	with_2 <<line <<"\n";
			  }
  			
		  }
		  with.close();
		  with_2.close();
		  
		  if(std::remove("Bank_store.csv")!= 0){
		  	custom_line();
		  	std::cerr <<"!! Unable To Remove The File :-- \n";
		  	custom_line();
		  	return false;
		  }
		  if(std::rename("Temp_2.csv","Bank_store.csv")!=0){
		  	custom_line();
		  	std::cerr <<"!! Unable to Rename The File :-- \n";
		  	custom_line();
		  	return false;
		  }
		  
		  if(found){
		  	custom_line();
		  	std::cout <<"!! Money Has Been Withdrawn [" <<amount <<"] :-- \n";
		  	custom_line();
			  return true; 
		  }else{
		  	custom_line_2();
		  	std::cout <<"!! Error Withdrawing Money [Invalid Name or Password ]:-- \n";
		  	custom_line_2();
		  	return false;
		  }
	  }
	  return true;
  }
  
// explaintion for delete_bank_info -> again we asuume fields, then pass the condition of name and password. When it finds the password and name it is going to skip it and 
// and add other lines to temp_csv
// we then rename temp_3.csv to bank_store.csv
  int delete_bank_info(std::string name,std::string password){
  	std::ifstream del("Bank_store.csv");
  	std::ofstream del_2("Temp_3.csv");
  	
  	if(del.is_open() && del_2.is_open()){
  		bool found = false;
  		std::string line;
  		
  		while(std::getline(del,line)){
  			std::stringstream ss(line);
  			std::string row_name , row_password;
  			
  			std::getline(ss,row_name,',');
  			std::getline(ss,row_password,',');
  			
  			if(row_name == name && row_password == password){
  				std::cout <<"!! Are You Sure You want To delete Bank Information of [" <<name <<"] [Press Enter KEY ]:-- \n";
  				std::cin.ignore();
  				std::cin.get();
  				found = true;
  				continue;
			  }
			  del_2 << line <<"\n";   
		  }
		  del.close();
		  del_2.close();
		  
		if(std::remove("Bank_store.csv")!=0){
			custom_line();
			std::cerr <<"!! Unable To remove File :-- \n";
			custom_line();
			return 1;
		}
		if(std::rename("Temp_3.csv","Bank_store.csv")!=0){
			custom_line();
			std::cerr <<"!! Unable to remove file :-- \n";
			custom_line();
			return 1;
		}
		
		if(found){
			custom_line_2();
			std::cout <<"Bank Account Of [" <<name <<"] has been deleted :-- \n";
			custom_line_2();
			return 0;
		}else{
			custom_line_2();
			std::cerr <<"!! Error Deleting Bank Information [ Invalid Name or Password :-- \n";
			custom_line_2();
			return 1;
		}
		
	  }
	  return 0;
  }
  

	
	
	
};

int main(){
	
	bank obj;
	display_menu();
	
	int n,choice, inner_choice;
	std::string name,password;
	double amount;
	
	do{
		std::cout <<"\n";
		std::cout <<"Choose Any Of The Following Options :-- \n\n";
		
		std::cout <<"1: Register Bank Account / Accounts :-- \n";
		std::cout <<"2: Display Bank Account Information :-- \n";
		std::cout <<"3: Deposit Money in Bank Account    :-- \n";
		std::cout <<"4: Withdraw Money in Bank Account   :-- \n";
		std::cout <<"5: Delete Bank Account Information  :-- \n";
		std::cout <<"0: Exit The Application             :-- \n";
		std::cout <<"\n";
		
		custom_line();
		
		std::cout <<"Enter Your Desired Choice :-- \n";
		std::cin >> choice;
		std::cout <<"\n";
		
		switch(choice){
			
			case 1:
				std::cout <<"How Many Bank Accounts You want To Register :-- \n";
				std::cin >> n;
				obj.input_data(n);
				break;
				
			case 2:
			 std::cout <<"Enter The Name OF Bank User :-- \n";
			 std::getline(std::cin >> std::ws,name);
			 std::cout <<"\n";
			 
			 std::cout <<"Enter Password :-- \n";
			 std::cin >> password;
			 
			 obj.display_bank_info(name,password);
			 break;
				
				
			case 3:
			 std::cout <<"Enter The Name OF Bank User :-- \n";
			 std::getline(std::cin >> std::ws,name);
			 std::cout <<"\n";
			 
			 std::cout <<"Enter Password :-- \n";
			 std::cin >> password;
			 std::cout <<"\n";
		
			 obj.deposit_money(name,password);
			 break;
			 
			case 4:
			 std::cout <<"Enter The Name OF Bank User :-- \n";
			 std::getline(std::cin >> std::ws,name);
			 std::cout <<"\n";
			 
			 std::cout <<"Enter Password :-- \n";
			 std::cin >> password;
			 std::cout <<"\n";
			
			 
			 obj.withdraw_money(name,password);
			 break;
			 
			 
			case 5:
			std::cout <<"Enter The Name OF Bank User :-- \n";
			 std::getline(std::cin >> std::ws,name);
			 std::cout <<"\n";
			 
			 std::cout <<"Enter Password :-- \n";
			 std::cin >> password;
			 std::cout <<"\n";
			 
			 obj.delete_bank_info(name,password);
			 break;
			 
			
			 	
		}
		std::cout <<"Press [1] to continue || Press [0] to exit :-- \n";
		std::cin >> choice;
		if(choice == 0){
			std::cout <<"Thanks For using The Application :-- \n";
		}
		
	}while(choice != 0);
	
	
	return 0;
}
