#ifndef I_PRINTABLE_H_
#define I_PRINTABLE_H_

#include <iostream>

class IPrintable {
 public:
  friend std::ostream &operator<<(std::ostream &os, const IPrintable &obj);
  virtual ~IPrintable() = default;
  virtual void Print(std::ostream &os) const = 0;
};

#endif  // I_PRINTABLE_H_