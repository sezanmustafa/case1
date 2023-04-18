#include<iostream>
#include<string>
#include<ctime>
#include<fstream>
#include<stdlib.h>
#include<iomanip>


using namespace std;

const char part1[] = "\n\n\nGreetings";
const char part2[] = "\nWe are writing to contact you once again regarding our last correspondence to you, \nposted last on ";
const char part3[] = "It referred to an invoice that is still pending payment. It concerns invoice number\n";
const char part4[] = " issued on the date ";
const char part5[] = " for the amount of ";
const char part6[] = " the expiration date ";
const char part7[] = "as payment for the service ";
const char part8[] = "\n\nWe wish to highlight the immediate urgency of this issue, as our payment terms \ndicatate that your debt amount has increased in accordance with our late payment \nfees. Your outstanding total now stands at ";
const char part9[] = "Please settle this outstanding payment at your earliest convenience: ";
const char part10[] = "Swift Code: ";
const char part11[] = "BIC: ";
const char part12[] = "\n\nWe look forward to receiving your payment receipt in order to avoid any further \nincreases to your late payment charge. \nPlease do not hesitate to contact us with any further questions. ";
const char part13[] = "\nBest wishes, \n\n ";

// Grettings functions to call the gender of the reciever
void Greetings(char chooseGen[])
{
	int choice;

	do {
		cout << "Greetings: \n";
		cout << "\t 1) Mr.\n";
		cout << "\t 2) Ms.\n";
		cout << "\t 3) Other\n";
		cout << "\t 4) Exit\n";
		cout << "Select one: ";
		cin >> choice;
	} while (choice != 1 && choice != 2 && choice != 3 && choice != 4);

	if (choice == 1)
	{
		strcpy(chooseGen, "Mr.");
	}
	else if (choice == 2)
	{
		strcpy(chooseGen, "Ms.");
	}
	else if (choice == 3)
	{
		cout << "Type in your prefix, ex:Dr, Mrs, Miss: ";
		char x[20];
		cin >> x;
		strcpy(chooseGen, x);
			
	}
	else if (choice == 4)
	{
		exit(0);
	}
}

// function holding comapnies info
void companyInfo(string& compName, string& compAddress, string& compTelephone, string& compEmail)
{
	cout << "Company's Name: ";
	getline(cin, compName);
	cout << "Company's Address: ";
	getline(cin, compAddress);
	cout << "Phone Number: ";
	getline(cin, compTelephone);
	cout << "Contact Email: ";
	getline(cin, compEmail);

}

//function holding clients info
void clientInfo(char chooseGen[], string& clientName, string& clientAddress, string& clientTittle)
{
	Greetings(chooseGen);

	getline(cin, clientName);
	cout << "Enter Client's Name: ";
	getline(cin, clientName);
	cout << "Enter Client's Address: ";
	getline(cin, clientAddress);
	cout << "Enter your title: ";
	getline(cin, clientTittle);

}

// we enter all the 
void letter(string& postLast, string& invoiceNumber, string& issuedDate, string& amount, string& expDate, string& paymentService, string& outStandingTotal, string& swiftCode, string& Bic)
{
	cout << "Enter posted last: ";
	getline(cin, postLast);
	cout << "Enter invoice number: ";
	getline(cin, invoiceNumber);
	cout << "Enter Issued on the date: ";
	cin >> issuedDate;
	cout << "Enter the amount: ";
	cin >> amount;
	cout << "Enter the expiration date: ";
	cin >> expDate;
	cout << "Enter payment for service: ";
	cin >> paymentService;
	cout << "Enter outstanding total: ";
	cin >> outStandingTotal;
	cout << "Enter Swift code: ";
	cin >> swiftCode;
	cout << "Enter BIC: ";
	cin >> Bic;

}

int main()
{

	
	time_t t = time(0);
	tm* now = localtime(&t);
	string fileName;
	char chooseGen[10];
	string compName, compAddress, compTelephone, compEmail, clientName, clientAddress, clientTelephone;
	string postLast, invoiceNumber, issuedDate, amount, expDate, paymentService, outStandingTotal, swiftCode, Bic;

	companyInfo(compName, compAddress, compTelephone, compEmail);
	clientInfo(chooseGen, clientName, clientAddress, clientTelephone);
	letter(postLast, invoiceNumber, issuedDate, amount, expDate, paymentService, outStandingTotal, swiftCode, Bic);

	cout << compName + " " << endl;
	cout << setw(120) << (now->tm_year + 1900) << '/' << (now->tm_mon + 1) << '/' << now->tm_mday << "\n";
	cout << setw(120) << compAddress << endl;
	cout << setw(120) << compTelephone << endl;
	cout << setw(120) << compEmail << endl;

	cout << clientName << endl;
	cout << clientAddress << endl << endl;

	cout << part1 << " " << chooseGen << clientName << endl;
	cout << part2 << postLast << "." << endl;
	cout << part3 << invoiceNumber;
	cout << ", " << part4 << issuedDate << ", " << part5 << amount + "$";
	cout << ", " << part6 << expDate << " " << part7 << paymentService + "$" << ".\n";
	cout << part8 << outStandingTotal + "$" << ".\n" <<endl << endl;
	cout << part9 << endl;
	cout << part10 << swiftCode << endl;
	cout << part11 << Bic << endl;
	cout << part12 << endl;
	cout << part13 << endl;

	cout << clientName << "\t" << clientTelephone << endl;
	cout << compName << endl;


	cout << "Name of file: ";
	cin >> fileName;

	ofstream saveInfo;
	saveInfo.open(fileName + ".txt");
	

	saveInfo << compName << endl;
	saveInfo << setw(120) << compTelephone << endl;
	saveInfo << setw(120) << (now->tm_year + 1900) << '-' << (now->tm_mon + 1) << '-' << now->tm_mday << "\n";
	saveInfo << setw(120) << compEmail << endl;
	saveInfo << setw(120) << compAddress << endl;

	saveInfo << clientName << endl;
	saveInfo << clientAddress << endl;

	saveInfo << part1 << " " << chooseGen << clientName + "," << endl;
	saveInfo << part2 << postLast + "." << endl;
	saveInfo << part3 << invoiceNumber;
	saveInfo << ", " << part4 << issuedDate + ", " << part5 << amount + "$";
	saveInfo << ", " << part6 << expDate + " " << part7 << paymentService + "$" + ".\n";
	saveInfo << part8 << outStandingTotal + "$" + "." << endl << endl;
	saveInfo << part9 << endl;
	saveInfo << part10 << swiftCode << endl;
	saveInfo << part11 << Bic << endl;
	saveInfo << part12 << endl;
	saveInfo << part13 << endl;

	saveInfo << clientName << "\t" << clientTelephone << endl;
	saveInfo << compName << endl;

	saveInfo.close();

	return 0;
}