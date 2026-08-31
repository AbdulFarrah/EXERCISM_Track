#pragma once
#include <atomic>
#include <stdexcept>
using namespace std;
namespace Bankaccount {
class Bankaccount {
    public:
    Bankaccount();
    void open();
    void close();
    int balance();
    void deposit(int);
    void withdraw(int);
    atomic_int current_balance;
    atomic_bool is_open;
};  // class Bankaccount

}  // namespace Bankaccount
