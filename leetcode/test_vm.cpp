

#include <iostream>
#include <vector>
#include <stack>
#include <cstdint>

enum Opcode { Sub, Mul, Push, Store, Load, Bnez, Halt };

class VM {
 public:
  VM(std::initializer_list<std::int8_t> code) : code_(code) {}

  std::int64_t Run() {
    for (int pc = 0;; ++pc) {
      switch (code_[pc]) {
        case Sub: stack_.push(-PopValue() + PopValue()); break;
        case Mul: stack_.push(PopValue() * PopValue()); break;
        case Push: stack_.push(code_[++pc]); break;
        case Store: value_ = PopValue(); break;
        case Load: stack_.push(value_); break;
        case Bnez: pc += PopValue() ? code_[pc + 1] - 1 : 1; break;
        case Halt: return PopValue();
      }
    }
  }

 private:
  std::int64_t PopValue() {
    auto top = stack_.top();
    stack_.pop();
    return top;
  }

  std::vector<std::int8_t> code_;
  std::stack<std::int64_t> stack_;
  std::int64_t value_;
};

int main(int argc, const char *argv[]) {
  VM vm = {
    Push, 10, Store, Push, 1,
    Load, Mul,
    Load, Push, 1, Sub, Store,
    Load, Bnez, -8,
    Halt,
  };
  std::cout << vm.Run() << std::endl;
  return 0;
}