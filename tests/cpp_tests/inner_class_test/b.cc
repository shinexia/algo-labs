#include <string>

class Student {
   public:
    std::string foo() { return "from b"; }
};

namespace {
class Student2 {
   public:
    std::string foo() { return "from b with namespace"; }
};
}  // namespace

std::string foo_b() {
    Student s;
    return s.foo();
}

std::string foo_b_with_namespace() {
    Student2 s;
    return s.foo();
}
