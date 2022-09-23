class A {
};

class B : public A {
};

class C : public B {
};

class F {
};

class G {
};

class Z : public F, private G {
};

// C -> B -> A
int main() {
    A *p = new C; // A, B, C
    B *q = new C; // B, C
    C *r = new C;
    F *u = new Z; // F, Z
    // G *v = new Z; // G, Z
    // Error: F *w = new G;
    return 0;
}