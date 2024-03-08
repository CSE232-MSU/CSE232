class Node {
 public:
  char letter;
  Node* down;
  Node(char c) : letter(c), down(nullptr) {}
};

class Stack {
 private:
  Node* top_ = nullptr;

 public:
  Stack() = default;
  void push(char c) {
    Node* new_top = new Node(c);
    new_top->down = top_;
    top_ = new_top;
  }
  char top() { return top_->letter; }
  void pop() {
    Node* new_top = top_->down;
    delete top_;
    top_ = new_top;
  }
};