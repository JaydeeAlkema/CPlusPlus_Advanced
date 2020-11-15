#pragma once
#include <string>

class Transaction
{
public:
	Transaction(double _balanceChange, std::string _date);
	~Transaction();

	double getBalanceChange() const;
	const std::string& getDate() const;

private:
	double balanceChange = 0;
	std::string date = "";
};