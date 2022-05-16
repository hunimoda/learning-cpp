#include "IPrintable.h"

std::ostream &operator<<(std::ostream &os, const IPrintable &obj) {
  return os << "{ " << obj.ToString() << " }";
}