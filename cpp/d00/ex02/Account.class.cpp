#include <iostream>

#include "Account.class.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts() {
	return _nbAccounts;
}

int Account::getTotalAmount() {
	return _totalAmount;
}

int Account::getNbDeposits() {
	return _totalNbDeposits;
}

int Account::getNbWithdrawals() {
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos() {
	Account::_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
	          << ";total:" << _totalAmount
	          << ";deposits:" << _totalNbDeposits
	          << ";withdrawals:" << _totalNbWithdrawals
	          << std::endl;
}

Account::Account(int initial_deposit)
	: _accountIndex(getNbAccounts()), _amount(initial_deposit), _nbDeposits(0),
	  _nbWithdrawals(0) {
	++_nbAccounts;
	_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex
	          << ";amount:" << _amount
	          << ";created" << std::endl;
}

Account::~Account() {
	_nbAccounts--;

	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex
	          << ";amount:" << _amount
	          << ";closed" << std::endl;
}

void Account::makeDeposit(int deposit) {
	Account::_displayTimestamp();

	_nbDeposits++;
	_totalNbDeposits++;
	_amount += deposit;
	_totalAmount += deposit;

	std::cout << "index:" << _accountIndex
	          << ";p_amount:" << _amount - deposit
	          << ";deposit:" << deposit
	          << ";amount:" << _amount
	          << ";nb_deposits:" << _nbDeposits
	          << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
	Account::_displayTimestamp();

	if (withdrawal > _amount) {
		std::cout << "index:" << _accountIndex
		          << ";p_amount:" << _amount
		          << ";withdrawal:refused" << std::endl;
		return false;
	}

	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;

	std::cout << "index:" << _accountIndex
	          << ";p_amount:" << _amount + withdrawal
	          << ";withdrawal:" << withdrawal
	          << ";amount:" << _amount
	          << ";nb_withdrawals:" << _nbWithdrawals
	          << std::endl;

	return true;
}

int Account::checkAmount() const {
	return _amount;
}

void Account::displayStatus() const {
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex
	          << ";amount:" << _amount
	          << ";deposits:" << _nbDeposits
	          << ";withdrawals:" << _nbWithdrawals
	          << std::endl;
}

void Account::_displayTimestamp() {
	time_t theTime = time(nullptr);
	char s[32];

	strftime(s, sizeof(s), "[%Y%d%m_%H%M%S] ", localtime(&theTime));
	std::cout << s;
}

Account::Account()
	: _accountIndex(getNbAccounts()), _amount(0), _nbDeposits(0),
	  _nbWithdrawals(0) {
	++_nbAccounts;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex
	          << ";amount:" << _amount
	          << ";created" << std::endl;
}
