 #include<iostream>
 #include<fstream>
 #include<string.h>
 
 using namespace std;
 
 void login();
 void resistration();
 void forgot();
 
 int main()
 {
 	int c;
 	cout<<"\t\t\t______________________________________________________\n\n\n";
 	cout<<"\t\t\t                      Welcome to the Login Page        \n\n\n";
 	cout<<"\t\t\t_______________________        Menu   _________________ \n\n";
 	cout<<"                                                               \n\n";
 	cout<<"\t| Press 1 TO LOGIN                   |"<<endl;  
 	cout<<"\t| Press 2 TO REGISTER                |"<<endl;
 	cout<<"\t| Press 3 TO FORGOT YOUR PASSWORD    |"<<endl;
 	cout<<"\t| Press 4 TO EXIT                    |"<<endl;
 	cout<<"\n\t\t\t Please Enter Your Choice : ";
 	cin>>c;
 	cout<<endl;
 	
 	switch(c)
 	{
 		case 1:
 			login();
 			break;
 			
 		case 2:
 			resistration();
 			break;
 				
 		case 3:
 			forgot();
 			break;
 					
 		case 4:
 			cout<<"\t\t\t THANKYOU!  \n\n";
 			break;
 			
 		default:
 			system("cls");
 			cout<<"\t\t\t Please select from the option given above  \n"<<endl;
 			main();
 				
	 }
 }
 
 void login()
 {
 	int count;
 	string userId,password,id,pass;
 	system("cls");
 	cout<<"\t\t\t Please Enter the UserName And Password : "<<endl;
 	cout<<"\t\t\t USERNAME  ";
 	cin>>userId;
 	cout<<"\t\t\t PASSWORD ";
 	cin>>password;
 	
 	ifstream input("records.txt");
 	
 	while(input>>id>>pass)
 	{
 		if(id==userId && pass==password)
 		{
 			count=1;
 			system("cls");
		 }
	 }
	 input.close();
	 
	 if(count==1)
	 {
	 	cout<<userId<<"\n YOUR LOGIN SUCCESSFULL \n THANK FOR LOGINING ! \n";
	 }
	 else
	 {
	 	cout<<"\n LOGIN ERROR \n PLEASE CHECK YOUR USERNAME AND PASSWORD \n";
	 }
 	
 }
 
 void resistration()
 {
 	string ruserId, rpassword, rid,rpass;
 	system("cls");
 	cout<<"\t\t\t Enter the Username :";
 	cin>>ruserId;
 	cout<<"\t\t\t Enter the Password : ";
 	cin>>rpassword;
 	
 	ofstream f1("records.txt", ios:: app);
 	f1<<ruserId<<' '<<rpassword<<endl;
 	system("cls");
 	cout<<"\n\t\t\t REGISTERATUON IS SUCCESSFULL! \n"; 
 	main();
 }
 
 void forgot()
 {
 	int option;
 	system("cls");
 	cout<<"\t\t\t YOU FORGOT THE PASSWORD? NO WORRIES \n";
 	cout<<"Press 1 TO SERACH YOUR ID BY USERNAME "<<endl;
 	cout<<"Press 2 To GO BACK TO THE MAIN MENU "<<endl;
 	cout<<"\t\t\t ENTER YOUR CHOICE :";
 	cin>>option;
 	
 	switch(option)
 	{
 		case 1:
 		{
		 
 			int count=0;
 			string suserId,sId,spass;
 			cout<<"\n\t\t\t ENTER THE USERNAME WHIC YOU REMEMBERED : ";
 			cin>>suserId;
 			
 			ifstream f2("records.txt");
 			while(f2>>sId>>spass)
 			{
 				if(sId==suserId)
 				{
 					count=1;
				 }
				 
			 }
			 f2.close();
			 if(count==1)
			 {
			 	cout<<"\n\n YOUR ACCOUNT IS FOUND! \n";
			 	cout<<"\n\n YOUR PASSWORD IS : "<<spass;
			 	main();
			 }
			 else{
			 	cout<<"\n\t SORRY! YOUR ACCOUNT IS NOT FOUND \n ";
			 }
			 break;
   			}
	    case 2:
	  	    {
	  		main();
	  		
		    }
		     
		  default:
		  	cout<<"\t\t\t WRONG CHOICE ! PLEASE TRY AGAIN "<<endl;
		  	forgot();
       }
       
 }
