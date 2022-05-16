#ifndef I_PRINTABLE_H_
#define I_PRINTABLE_H_

#include <iostream>
#include <string>

class IPrintable {
 public:
  virtual ~IPrintable() = default;
  friend std::ostream &operator<<(std::ostream &os, const IPrintable &obj);
  virtual std::string ToString() const = 0;
};

#endif  // I_PRINTABLE_H_