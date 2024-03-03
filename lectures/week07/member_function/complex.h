class complex {
  double re, im;
public:
  complex(double r, double i) :re{r}, im{i} {}
  complex(double r) :re{r}, im{0} {}
  complex() :re{0}, im{0} {}
  complex(complex const & z) :re{z.re}, im{z.im} {}

  double real() const { return re; }
  void real(double d) { re = d; }
  double imag() const { return im; }
  void imag(double d) { im = d; }

  bool operator<(complex const & b);
};

