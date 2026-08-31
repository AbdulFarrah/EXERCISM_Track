#include "bank_account.h"

namespace Bankaccount {
Bankaccount::Bankaccount()
{
        is_open=false;
}
void Bankaccount::open()
{
    if(!is_open)
    {
    is_open=true;
    current_balance=0;
    }
    else
        throw::runtime_error("unopened");
}
void Bankaccount::deposit(int money)
{
    if(money>=0 && is_open)
        current_balance+=money;
    else
        throw::runtime_error("unopened");
}
void Bankaccount::withdraw(int money)
{
    if(money>=0 && is_open && money <= current_balance)
        current_balance-=money;
    else
        throw::runtime_error("unopened");
}
void Bankaccount::close()
{
    if(is_open)
        is_open=false;
    else
        throw::runtime_error("unopened");
}
int Bankaccount::balance()
{
    if (is_open) return current_balance; 
    throw::runtime_error("unopened");
}
}
