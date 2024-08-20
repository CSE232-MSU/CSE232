struct Thing {
  int x;
  Thing(Thing const &) = delete;
  Thing(int x ) : x(x ) {}
};

int main() {
  Thing t1{4};
  Thing t2{5};
  // Option inserted here
}