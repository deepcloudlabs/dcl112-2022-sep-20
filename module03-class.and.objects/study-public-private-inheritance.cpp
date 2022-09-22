class Precious {
public:
    void fun(){}
};

class YourClass : public Precious {
public:
    void gun(){
        fun();
    }
};

class AnotherClass {
    Precious p; // composition
public:
    void gun(){
        p.fun();
    }
};

class A {
public:
    int x;
};
class B : public A {
public:

};
class C : private A {

};
int main(){
    A a;
    a.x = 42;
    B b;
    b.x = 108; // ✔: Public inheritance
    C c;
    // c.x=549; // ✘: private inheritance

    return 0;
}