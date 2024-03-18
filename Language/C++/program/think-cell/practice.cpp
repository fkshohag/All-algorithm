# include <iostream>
# include <cstdio>
# include <cstdio>

template <class T>
class C {
 private:
    T value;
 public:
    C(T v) {
        value = v;
    }
    void show() {
        std::cout<< value << std::endl;
    }
};

int main() {
    C<int> obj(23);
    C<double> obj2(3.4);
    obj.show();
    obj2.show();
}