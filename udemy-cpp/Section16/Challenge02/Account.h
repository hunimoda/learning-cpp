#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include "IPrintable.h"

class Account : public IPrintable {
 public:
  Account(std::string name, double balance);
  virtual ~Account() = default;

  virtual std::string ToString() const override;
  virtual bool Deposit(double amount) = 0;
  virtual bool Withdraw(double amount) = 0;

 protected:
  std::string name_;
  double balance_;
};

#endif  // ACCOUNT_H_