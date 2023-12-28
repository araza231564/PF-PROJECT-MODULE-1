#include<iostream>//header file for input&output functions
#include<fstream>//header file for file handling functions
#include<stdio.h>//header file for standard input&output functions
#include<string>//header file for string functions
using namespace std;//as a standard to not write std:: multiple times
void addvehicles();//functio-prototype
void viewvehicles();//functio-prototype
void search(); //functio-prototype
void menu(); //functio-prototype
void update(); //functio-prototype
void remove(); //functio-prototype
int main() //Main function from where the execution started
{
	cout << "\n------------------------------------" << endl;// formated output
	cout << "---CAR SHOWROOM MANAGEMENT SYSTEM---" << endl; //Project-Heading
	cout << "------------------------------------" << endl; //formated output
	while (true)//repeatedly execution of called function
	{
		menu(); //calling menu function
	}
	cout << "\n*Good Bye*";//to show that the program is terminated
}
void menu()//calling menu function
{
	int option;//integer data type variable used to hold 32 bit for user input as option
	cout << "\n1 -Add Vehicle in Record\n2 -View Vehicle from record\n3 -Search Vehicle from record\n4 -UpdateVehicle Record\n5 -Delete Vehicle from Record\n6 -Exit the program" << endl << endl;
	cin >> option;//taking input from user
	switch (option)// we used it to check equality...so that accordingly the case will execute
	{
	case 1://if option matches 1 it will execute statements below
		cout << "\nAdd Vehicle in Record" << endl;
		addvehicles();//calling function to add data
		break;//if this case is exuted then it will stop here and exit from the body of switch statament
	case 2://if option matches 2 it will execute statements below
		cout << "\nView Vehicles in Record" << endl;
		viewvehicles();//calling function to add data
		break;//if this case is exuted then it will stop here and exit from the body of switch statament
	case 3://if option matches 3 it will execute statements below
              cout << "\nSearch a Vehicle in Record" << endl;
		search();//calling function to add data
		break;//if this case is exuted then it will stop here and exit from the body of switch statament
	case 4://if option matches 4 it will execute statements below
		cout << "\nUpdate a Vehicle in Record" << endl;
		update();//calling function to add data
		break;//if this case is exuted then it will stop here and exit from the body of switch statament
	case 5://if option matches 5 it will execute statements below
		cout << "\nRemove a Vehicle from Record" << endl;
		remove();//calling function to add data
		break;//if this case is exuted then it will stop here and exit from the body of switch statament
	case 6://if option matches 6 it will execute statements below
		cout << "\n*program terminates*" << endl;
		exit(0);//calling function to exit the program
		break;//if this case is exuted then it will stop here and exit from the body of switch statament
	default://when no case is matched default will be executed
		cout << "\nGOOD BYE";
		break;//if this case is exuted then it will stop here and exit from the body of switch statament
	}
}
void viewvehicles() // function name with function definition ahead
{
	try //exceptional handling
	{
		ifstream fin;//object for reading from file
		fin.open("vehicles.txt");//opening a file
		if (fin.fail())//checking whether the file is opened or not
		{
			throw 1;//throws error if file not opened
		}
		else//if above condition is fale this part will be executed
		{
			string name, registrationnum;//string data type variables that reserve 24 bytes of memory
			int price, model;//integer data type variables used to hold 32 bit for each user input as price and model
while (fin >> name >> price >> model >> registrationnum)//reading data fromwhile until the end of file
				{
				cout << "\nCar Name : " << name;//making us able to view data (car name) from file
				cout << "\nPRICE : " << price;//making us able to view data (price) from file
				cout << "\nModel : " << model;//making us able to view data (model) from file
				cout << "\nReg no. : " << registrationnum << endl << endl;//making us able to view data	(registration no) from file
				}
			fin.close();//closing file
		}
	}
	catch (int error)//it cathes what is thrown from try block
	{
		cout << "\nAccess denied ";
		cout << "\nError number: " << error;//sends message on output screen
	}
}
void addvehicles() // function name with function definition ahead
{
	string name, registration;//string data type variables that reserve 24 bytes of memory for name and for registration number
		int price, model;//integer data type variables used to hold 32 bit for each user input as price and model
	char check;//character data type variableto reserve 1 byte in memory for check
	ofstream fout;//object for writing to file
	fout.open("vehicles.txt", ios::app);//opening a file on append mode
	do//do-while loop to ask your to enter data multiple time as far as user want to enter we may use while here
	{
		cout << "\nEnter car name : ";//ask the user to enter car name
		cin >> name;//taking name as input from user
		cout << "\nEnter the price : ";//ask the user to enter car price
		cin >> price;//taking price as input from user
		cout << "\nEnter the model : ";//ask the user to enter car model
		cin >> model;//taking model as input from user
		cout << "\nEnter the registration number : ";//ask the user to enter registration number
		cin >> registration;//taking registration number as input from user
		fout << name << "\t" << price << "\t" << model << "\t" << registration << endl;//writing entered data into  the file with proper formatting
			cout << "\nEnter y or Y to input again otherwise program will terminates: ";//asking user whether he want more execution or not
 	cin >> check;//taking check as input from user that will check will this loop will be continued or not
		cout << endl;//to move cursor to beginning of next line
	} while ((check == 'y') || (check == 'Y'));//checks for whther user want to input again or not
	fout.close();//closing file
}
void search()//function name with function definition ahead
{
	int search;//integer data type variables used to hold 32 bit for user input as search
	bool found = false;//flag value(base false)
	string name, carname, registrationnum, registrationno;//string data type variables that reserve 24 bytes of memory for name, car name, registration& registration number
		int price, model;//integer data type variables used to hold 32 bit for each user input as price and model
	char check;//character data type variableto reserve 1 byte in memory for check
	do//do-while loop to ask your to enter data multiple time as far as user want to enter we may use while here
	{
		cout << "----How you want to search by-----" << endl;
		cout << "\nBy Name (Press 1) \nBy Registration number (Press 2) ";//giving choice to user whether he wants to search by name or by registration number
cin >> search;//input choice from user for letting him option of according to which method he wants to search record by
			switch (search)// we used it to check equalitywhther case 1 or case 2 is to be executed...so that accordingly the case will execute
			{
			case 1://if user enter choice as 1 this case will be executed
			{
			try//exceptional handling
			{
			ifstream fin;//object for reading from file
			fin.open("vehicles.txt");//opening a file for reading
			if (fin.fail())//checking whether the file is opened or not
			{
			throw 3;//throws error if file not opened
			}
			else//if above condition is fale this part will be executed
			{
			cout << "Enter car name : ";//asking user the name of car to be searched
			cin >> carname;//taking input of carname
			while (fin >> name >> price >> model >> registrationno)//reading data fromwhile until the end of file
			{
			if (name == carname)//check whether the entered data is present in the or not
			{
			found = true;//flag value (true)
			break;//to exit from the body of if statement
			}
			else if (name != carname) // check whether the entered data is present	 in the or not
			{
			found = false;//flag value (false)
			}
			}
			if (found == true)//checking flag value
			{ //displaying the search results
			cout << "\nCAR NAME : " << name;//displaying the search results
			cout << "\nPRICE : " << price;//displaying the search results
			cout << "\nMODEL : " << model;//displaying the search results
			cout << "\nREGISTRATION NUMBER : " << registrationno << endl <<
			endl;//displaying the search results
			}
			else//if above condition is fale this part will be executed
			{
			cout << endl << "RECORD NOT FOUND" << endl;//displaying the message record not found

			}
			break;//to exit from body of else
			}
			fin.close();//closing file
			}
			catch (int error)//it cathces what is thrown from try block
			{
			cout << "\nAccess denied-File not found ";
			cout << "\nError : " << error;//sends message on output screen
			}
			}
			case 2://if user enter choice as 2 this case will be executed
			{
			try//exceptional handling
			{
			ifstream fin;//object for reading from file
			fin.open("vehicles.txt");//opening a file for reading
			if (fin.fail())//checking whether the file is opened or no
			{
			throw 3;//throws error if file not opened
			}
			else//if above condition is fale this part will be executed
			{
			cout << "Enter car Registration number : ";//asking user to enter the registration no of car to be searched
			cin >> registrationnum;//taking input of registration number
			while (fin >> name >> price >> model >> registrationno)//reading data fromwhile until the end of file
			{
			if (registrationno == registrationnum)// check whether the entered data is present in the or not
			{
			found = true;//flag value (false)
			break;//to exit from body of if
			}
			else if (registrationno != registrationnum) // check whether the entered data is present in the or not
			{
			found = false;//flag value (false)
			}
			}
			if (found == true)// checking flag value
			{
			cout << "\nCAR NAME : " << name; //displaying the search results
			cout << "\nPRICE : " << price; // displaying the search results
			cout << "\nMODEL : " << model; //displaying the search results
			cout << "\nREGISTRATION NUMBER : " << registrationno << endl <<

			endl; //displaying the search results
			}
			else//if above condition is fale this part will be executed
			{
			cout << endl << "RECORD NOT FOUND" << endl;//displaying themessage record not found
			}
			}
			fin.close();//closing file
			}
			catch (int error)//it cathces what is thrown from try block
			{
			cout << "\nAccess denied-File not found ";
			cout << "\nError : " << error;//sends message on output screen
			}
			}
			}
		cout << "\nWant to Search Again Press 'y' or 'Y otherwise program will be terminated'";//checks for whether user want to input again or not
			cin >> check;
	} while (check == 'y' || check == 'Y');//asking user whether he want more execution or not
}
void update() // function name with function definition ahead
{
	bool found = false;
	int price, new_price, model, new_model;//integer data type variables used to hold 32 bit for each user input as price, new price, modeland new model
	string name, new_name, name_to_update, new_registration, registration;//string data type variables that reserve 24 bytes of memory for each name, name to update, registrationand for registration number
		ofstream fout;//creating ofstream object
	fout.open("temp.txt");//opening a file for writing
	try//exceptional handling
	{
		ifstream fin;//object for reading from file
		fin.open("vehicles.txt");//opening a file for reading
		if (fin.fail())//checking whether the file is opened or not
		{
			throw 4;//throws error if file not opened
		}
		else//if above condition is fale this part will be executed
		{
			cout << "\nEnter the name of vehicle you want to update : ";//asking user tio enter name of	record you want to update
				cin >> name_to_update;//getting input of the name to update
			while (fin >> name >> price >> model >> registration)//reading data fromwhile until the end of	file
			{
			if (name != name_to_update)//check whether the entered data is present in the or not
			{
			fout << name << "\t" << price << "\t" << model << "\t" << registration <<
			endl;//writing entered data into the file with proper formatting
			}
			if (name == name_to_update)//cheching if the record exist
			{
			cout << "\nEnter New name : ";//asking using to enter new name to store in file	(by updating)
			cin >> new_name;//read new name entered by user
			cout << "\nEnter New price : ";//asking using to enter new name to store in file	(by updating)
			cin >> new_price;//read new price entered by user
			cout << "\nEnter New model : ";//asking using to enter new name to store in file	(by updating)
			cin >> new_model;//read new model entered by user
			cout << "\nEnter New registration number : ";//asking using to enter new name	to store in file(by updating)
			cin >> new_registration;//read new registration number entered by user
			fout << new_name << "\t" << new_price << "\t" << new_model << "\t" <<
			new_registration << endl;//writing entered data into the file with proper formatting
			break;//used to exit from body of if (if condition is true
			}
			}
			fin.close();//closing file
			fout.close();//closing file
			cout << "\nThe record with the name " << name_to_update << " has been updated if it existed"<< endl;//shows message on screen of update confirmed
			remove("vehicles.txt");
			if (!rename(("temp.txt"), ("vehicles.txt")))//renaming temp file to vehicles file
			{
				cout << "\n=**************************************";// just to show that file is	renamed
			}
			else//if above condition is fale this part will be executed
			{
				cout << "\nCheck for error in renaming file";//runs if file is not renamed
			}
		}
	}
	catch (int error)//it cathces what is thrown from try block
	{
		cout << "\nAccess denied-File not found ";
		cout << "\nError : " << error;//sends message on output screen
	}
}
void remove() // function name with function definition ahead
{

	int price, model;//integer data type variables used to hold 32 bit for each user input as price and model
	string name_to_del, name, registration;//string data type variables that reserve 24 bytes of memory for each name, name to delete and for registration number
	cout << "\nPlease Enter the name of vehicle you want to delete: ";//ask user to enter the name of vehicle you want to delete
		cin >> name_to_del;//reads the name entered by user
	ofstream fout;//object for writing to file
	fout.open("temp.txt");//opening a file for writing
	try//exceptional handling
	{
		ifstream fin;//object for reading from file
		fin.open("vehicles.txt");//opening a file for reading
		if (fin.fail()) //checking whether the file is opened or not
		{
			throw 5;//throws error if file not opened
		}
		else//if above condition is fale this part will be executed
		{
			while (fin >> name >> price >> model >> registration)//reading data fromwhile until the end of file
			{
			if (name != name_to_del)//check whether the entered data is present in the or 	not
			{
			fout << name << "\t" << price << "\t" << model << "\t" << registration <<
			endl;//writing entered data into the file with proper formatting
			}
			}
				cout << "\nThe record with the name " << name_to_del << " has been deleted if it	existed" << endl;//displaying message if record has been deleted
				fin.close();//closing file
			fout.close();//closing file
			remove("vehicles.txt");//removing/deleting file
			if (!rename(("temp.txt"), ("vehicles.txt")))//renaming temp file to vehicles file
			{
				cout <<
					"*************************************************************************************";// to show	that file is renamed
			}
			else//if above condition is false this part will be executed
			{
				cout << "\nCheck for error";// to show that file is not-renamed
			}
		}
	}
	catch (int error)//it cathces what is thrown from try block
	{
		cout << "\nAccess denied-File not found ";
		cout << "\nError : " << error;//sends message on output screen
	}
}