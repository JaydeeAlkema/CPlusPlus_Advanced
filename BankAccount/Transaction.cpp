#include "Transaction.h"

Transaction::Transaction(double _balanceChange, std::string _date)
{
	date = _date;
	balanceChange = _balanceChange;
}

Transaction::~Transaction()
{
	
}

double Transaction::getBalanceChange() const
{
	return balanceChange;
}

const std::string& Transaction::getDate() const
{
	return date;
}

