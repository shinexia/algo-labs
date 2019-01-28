#include "util.h"
#include <sstream>

namespace util {

std::string stringify(const int A[], int N) {
  std::ostringstream oss;
  oss << "[";
  for (int i=0; i<N; i++) {
    if (i != 0) {
      oss << ",";
    }
    oss << A[i];
  }
  oss << "]";
  return oss.str();
}

} // namespace util
