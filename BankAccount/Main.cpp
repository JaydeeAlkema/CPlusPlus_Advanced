#include <iostream>

#include "Transaction.h"
#include "BankAccount.h"

int main()
{
	BankAccount bankAccount = BankAccount("Jaydee", 1215.75, 0);

	Transaction transaction1 = Transaction(-225.34, "10/11/2020");
	Transaction transaction2 = Transaction(-125.63, "11/11/2020");
	Transaction transaction3 = Transaction(450.85, "15/11/2020");
	Transaction transaction4 = Transaction(-230.32, "20/11/2020");

	std::cout << bankAccount.getAccountHolder() << " Account Balance= " << bankAccount.getAccountBalance() << ", Number of Transactions= " << bankAccount.getNumberOfTransactions() << std::endl;
	bankAccount += transaction1;
	bankAccount += transaction2;
	bankAccount += transaction3;
	bankAccount += transaction4;

	std::cout << bankAccount << std::endl;

	std::cout << bankAccount.getAccountHolder() << " Account Balance= " << bankAccount.getAccountBalance() << ", Number of Transactions= " << bankAccount.getNumberOfTransactions() << std::endl;
}
