#include "BankAccount.h"

BankAccount::BankAccount(std::string _accountHolder, double _balance, int _numberOfTransactions)
{
	this->accountHolder = _accountHolder;
	this->accountBalance = _balance;
	this->numberOfTransactions = _numberOfTransactions;
}

BankAccount::BankAccount(std::string _accountHolder, double _balance, int _numberOfTransactions, Transaction transaction)
{
	this->accountHolder = _accountHolder;
	this->accountBalance = _balance;
	this->numberOfTransactions = _numberOfTransactions;
	this->transactionHistory.push_back(transaction);
}

BankAccount::~BankAccount()
{

}

const std::string& BankAccount::getAccountHolder() const
{
	return this->accountHolder;
}

const double BankAccount::getAccountBalance() const
{
	return this->accountBalance;
}

const int BankAccount::getNumberOfTransactions() const
{
	return this->numberOfTransactions;
}

std::list<Transaction> BankAccount::getTransactionHistory()
{
	return this->transactionHistory;
}

BankAccount BankAccount::operator+(const Transaction& transaction) const
{
	return BankAccount(this->accountHolder, this->accountBalance + transaction.getBalanceChange(), this->numberOfTransactions + 1, transaction);
}

BankAccount BankAccount::operator-(const Transaction& transaction) const
{
	return BankAccount(this->accountHolder, this->accountBalance - transaction.getBalanceChange(), this->numberOfTransactions + 1, transaction);
}

BankAccount& BankAccount::operator+=(const Transaction& transaction)
{
	this->accountBalance += transaction.getBalanceChange();
	this->numberOfTransactions++;
	this->transactionHistory.push_back(transaction);
	return *this;
}

BankAccount& BankAccount::operator=(const BankAccount& transaction)
{
	if (this != &transaction)
	{
		this->accountHolder = transaction.accountHolder;
		this->accountBalance = transaction.accountBalance;
		this->numberOfTransactions = transaction.numberOfTransactions;
		this->transactionHistory = transaction.transactionHistory;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const BankAccount& bankAccount)
{
	std::list<Transaction> transactions = bankAccount.transactionHistory;
	os << "\nTransactions= " << std::endl;
	for (std::list<Transaction>::iterator it = transactions.begin(); it != transactions.end(); it++)
	{
		Transaction t = *it;
		os << "Balance Change= " << t.getBalanceChange() << ", Date= " << t.getDate() << std::endl;
	}

	return os;
}
