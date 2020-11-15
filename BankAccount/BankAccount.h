#pragma once
#include <iostream>
#include <list>

#include "Transaction.h"

class BankAccount
{
public:
	BankAccount(std::string _accountHolder, double _balance, int _numberOfTransactions);
	BankAccount(std::string _accountHolder, double _balance, int _numberOfTransactions, Transaction transaction);
	virtual ~BankAccount();

	const std::string& getAccountHolder() const;
	const double getAccountBalance() const;
	const int getNumberOfTransactions() const;

	std::list<Transaction> getTransactionHistory();

	BankAccount operator+(const Transaction& transaction) const;
	BankAccount operator-(const Transaction& transaction) const;
	BankAccount& operator+=(const Transaction& transaction);

	BankAccount& operator=(const BankAccount&);

	friend std::ostream& operator<<(std::ostream& os, const BankAccount& bankAccount);

private:
	std::string accountHolder;
	double accountBalance;
	int numberOfTransactions;

	std::list<Transaction> transactionHistory;
};