#include <iostream>
#include <stdlib.h>
#include <string>
#include "employeeFile.h"

using namespace std;

class client
{
	protected:
		string phoneNumber;
		string clientName;
		string clientAddress;
	public:
		void setPhoneNumber(string phoneNmbr){
			phoneNumber = phoneNmbr;
		}
		void setClientName(string clientNm){
			clientName = clientNm;
		}
		void setClientAddress(string clientAddr){
			clientAddress = clientAddr;
		}
		string getClientName(){
			return clientName;
		}
		string getClientAddress(){
			return clientAddress;
		}
		string getPhoneNumber(){
			return phoneNumber;
		}
};
class bankTranscation : client
{
	private: 
		double Amount;
	public:
			
		bankTranscation(double amount)
		{
			Amount = amount;
		}
		
		void depositTranscation(double amount)
		{
			Amount += amount;
		}
		
		string withdrawalTranscation(double amount)
		{
			Amount -= amount;
			return "Witdrawal Successfully"; 
		}
		
		double getAmount()
		{
			return Amount;
		}
		string sendMoney(double sendAmount)
		{
			if (Amount > sendAmount){
				if(sendAmount < 1000){
					Amount -= sendAmount;
					return "Sent Successfully";	
				}	
				else if(sendAmount <= 10000 && sendAmount >= 100000) {
				
					if(Amount < (sendAmount + 200))
						return "Unefficient Balance";
					else{
						Amount = Amount - (sendAmount + 200);
						return "Sent Successfully";
					}
				}		
				else {
					if(Amount < (sendAmount + 200))
						return "Unefficient Balance";
					else{
						Amount = Amount - (sendAmount + 1000);
						return "Sent Successfully";
					}
				}
			}
			else
				return "Unefficient Balance";
		}
		
		// Client Information.
		void setclientName()
		{
			cout << "Enter client Name: ";
			cin >> clientName;
		}
		void setClientNumber()
		{
			cout << "Enter client Phone Number: ";
			cin >> phoneNumber;
		}
		void setClientAddress()
		{
			cout << "Enter client Address: ";
			cin >> clientAddress;
		}
};
int main() {
	
	bankTranscation newTranscation(1000.00);
	
	int choice = 0;
	
	double amount;
	do {
		
		cout << endl << endl;
		cout << "Choice according to your action you want to take: " ;
		cout << endl << endl;
		cout << "\t 1: For Deposit. " << endl;
		cout << "\t 2. For Withdrawal. " << endl;
		cout << "\t 3. For Send Money. " << endl;
		cout << "\t 4. For Balance Check. " << endl;
		cout << "\t 0. to exit" << endl << endl;
		
		cout << "Enter your choice: ";
		cin >> choice;
	
		system("CLS");
		
		switch(choice) {
			case 1:
				cout << "Enter your amount to deposit: ";
				cin >> amount;
				newTranscation.depositTranscation(amount);
				cout << "Deposit Successfully. " << "Your new balance: "
					 << newTranscation.getAmount();
			break; 
			case 2:
				cout << "Enter your amount to withdrawal: ";
				cin >> amount;
				if(amount >= newTranscation.getAmount())
					cout << "unefficient Balance.";
				else 
				{
					cout << "Withdrawal Successfully. " << "Your new balance: "
						 << newTranscation.getAmount();
				}
			break;
			case 3:
				cout << "Enter your amount to send: ";
				cin >> amount;
				
				cout << newTranscation.sendMoney(amount);
			break;
			case 4:
				cout << "Your balance: " << newTranscation.getAmount();
			break;
			case 0:
				cout << "Existing System!";
			break;
			default:
				cout << "Invalid Choice!";
		}
	}while(choice != 0);

	return 0;
}
