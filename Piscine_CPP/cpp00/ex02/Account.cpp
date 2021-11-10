#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    std::cout << "[" << 1900 + ltm->tm_year << std::setfill ('0') << std::setw (2) << 1 + ltm->tm_mon\
                << std::setfill ('0') << std::setw (2) << ltm->tm_mday << "_" << std::setfill ('0')\
                << std::setw (2) << 5+ltm->tm_hour << std::setfill ('0') << std::setw (2)\
                << 30+ltm->tm_min << std::setfill ('0') << std::setw (2) << ltm->tm_sec << "] ";
}

void Account::displayStatus() const{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount\
                << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::displayAccountsInfos(){
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::_nbAccounts << ";total:" << Account::_totalAmount << ";deposits:"\
                << Account::_totalNbDeposits << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

Account::Account(){
    this->_amount = 0;
    this->_accountIndex = Account::_nbAccounts;
    Account::_nbAccounts++;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::Account( int initial_deposit ){
    this->_accountIndex = Account::_nbAccounts;
    Account::_nbAccounts++;
    this->_amount = initial_deposit;
    Account::_totalAmount += initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << initial_deposit << ";created" << std::endl;
}

Account::~Account(){
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

void Account::makeDeposit( int deposit ){
    this->_amount += deposit;
    this->_nbDeposits++;
    this->_totalAmount += deposit;
    this->_totalNbDeposits++;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount-deposit << ";deposit:"\
                << deposit << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal( int withdrawal ){
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:";
    if(this->_amount - withdrawal < 0){
        std::cout << "refused" << std::endl;
        return false;
    }
    this->_amount -= withdrawal;
    this->_totalAmount -= withdrawal;
    this->_totalNbWithdrawals++;
    this->_nbWithdrawals++;
    std::cout << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return true;
}