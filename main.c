#include <stdio.h>

struct imnum {
    double re, im;
};

struct imnum newNum(double re, double im) {
    struct imnum ret;
    ret.re = re;
    ret.im = im;
    return ret;
}

struct imnum add(struct imnum n0, struct imnum n1) {
    struct imnum ret;
    ret.im = n0.im + n1.im;
    ret.re = n0.re + n1.re;
    return ret;
}

struct imnum neg(struct imnum n) {
    struct imnum ret = newNum(-n.re, -n.im);
    return ret;
}

struct imnum sub(struct imnum n0, struct imnum n1) {
    return add(n0, neg(n1));
}

struct imnum mul(struct imnum n0, struct imnum n1) {
    struct imnum ret;
    ret.re = n0.re * n1.re - n0.im * n1.im;
    ret.im = n0.re * n1.im + n0.im * n1.re;
    return ret;
}

struct imnum powi(struct imnum n, int pow) {
    struct imnum ret = newNum(1, 0);
    struct imnum temp = n;
    while (pow) {
        if (pow & 1) {
            ret = mul(ret, temp);
        }
        pow = pow >> 1;
        temp = mul(temp, temp);
    }
    return ret;
}

struct imnum rooti(struct imnum n, int i) {

}

struct imnum pow(struct imnum n, double pow) {

}



int main() {
    struct imnum myNum0 = newNum(3, 5);;
    struct imnum myNum1 = newNum(1, 2);
    struct imnum fin = powi(myNum0, 12);
    printf("%f+%fi\n", fin.re, fin.im);
    return 0;
}
