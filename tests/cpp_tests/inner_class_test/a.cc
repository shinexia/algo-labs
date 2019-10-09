#include <string>

#include <string>

class Student {
   public:
    std::string foo() { return "from a"; }
};

namespace {
class Student2 {
   public:
    std::string foo() { return "from a with namespace"; }
};
}  // namespace

std::string foo_a() {
    Student s;
    return s.foo();
}

std::string foo_a_with_namespace() {
    Student2 s;
    return s.foo();
}
