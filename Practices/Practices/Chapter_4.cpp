//
//  Chapter_4.cpp
//  exercises
//
//  Created by Songyu on 2020/1/30.
//  Copyright © 2020 Songyu. All rights reserved.
//

#include "Common.h"

#define triangle_s(a,b,c) (a+b+c)/2
#define triangle_area(a,b,c) sqrt(triangle_s(a,b,c)*(triangle_s(a,b,c)-a)*(triangle_s(a,b,c)-b)*(triangle_s(a,b,c)-c))

static void exercise_1(void);
static void exercise_2(float, float, float);
static bool exercise_3(int);
static void exercise_4(double, double, double);
static void exercise_5(void);
static void exercise_6(void);
static void exercise_7(int);
static void exercise_8(int, double);
static void exercise_9(void);
static void exercise_10(void);
static void exercise_11(int);
static void exercise_12(void);

void Chapter_4_exercise(int number) {
    switch (number) {
        case 1: {
            exercise_1();
        } break;
        case 2: {
            exercise_2(2, 4, 3);
        } break;
        case 3: {
            exercise_3(17);
        } break;
        case 4: {
            exercise_4(4, 5, 6);
        } break;
        case 5: {
            exercise_5();
        } break;
        case 6: {
            exercise_6();
        } break;
        case 7: {
            exercise_7(20);
        } break;
        case 8: {
            exercise_8(3, 4);
        } break;
        case 9: {
            exercise_9();
        } break;
        case 10: {
            exercise_10();
        } break;
        case 11: {
            exercise_11(5);
        } break;
        case 12: {
            exercise_12();
        } break;
        default: {
            cout << "Shit exercise number!" << endl;
        } break;
    }
}

void exercise_1(void) {
    int gcd(int a, int b);
    int a, b, n, m;
    cout << "Input a & b:" << endl;
    cin >> a >> b;
    if (a < b) {
        b = a + b;
        a = b - a;
        b = b - a;
    }
    if (a == 0 && b == 0) {
        cout << "最大公约数：无" << endl;
        cout << "最小公倍数：无" << endl;
    } else if (a == 0 || b == 0) {
        cout << "最大公约数： " << (a == 0 ? b : a) << endl;
        cout << "最小公倍数：无" << endl;
    } else {
        n = gcd(a, b);
        m = a * b / n;
        cout << "最大公约数： " << n << endl;
        cout << "最小公倍数： " << m << endl;
    }
}

int gcd(int a, int b) {
    return b == 0 ? a : (gcd(b, a % b));
}

void exercise_2(float a, float b, float c) {
    void doubleRoots(float, float, float);
    void oneRoot(float, float, float);
    void noRoot(float, float, float);
    float i = pow(b, 2) - 4 * a * c;
    
    if (i > 0) {
        doubleRoots(a, b, c);
    } else if (i == 0) {
        oneRoot(a, b, c);
    } else {
        noRoot(a, b, c);
    }
}

void doubleRoots(float a, float b, float c) {
    float r1, r2, i = pow(b, 2) - 4 * a * c;
    r1 = (-b+sqrt(i)) / (2*a);
    r2 = (-b-sqrt(i)) / (2*a);
    cout << "r1 = " << r1 << '\t' << "r2 = " << r2 << endl;
}

void oneRoot(float a, float b, float c) {
    cout << "r1 = " << -b/(2*a) << '\t' << endl;
}

void noRoot(float a, float b, float c) {
    cout << "No root!" << endl;
}

bool exercise_3(int a) {
    if (a <= 1) {
        cout << "Wrong number." << endl;
        return false;
    }
    if (a % 2 == 0) {
        cout << "合数" << endl;
        return false;
    }
    int sqa = sqrt(a);
    for (int i = 3; i <= sqa; ++i) {
        if (a % i == 0) {
            cout << "合数" << endl;
            return false;
        }
    }
    cout << "素数" << endl;
    return true;
}

void exercise_4(double a, double b, double c) {
    double fac(double);
    cout << a << "! + " << b << "! + " << c << "! = " << fac(a) + fac(b) + fac(c) << endl;
}

double fac(double n) {
    return n == 1 ? 1 : n * fac(n-1);
}

void exercise_5(void) {
    double e(double);
    double x, sinh;
    cout << "Input x:" << endl;
    cin >> x;
    sinh = (e(x) - e(-x)) / 2;
    cout << sinh << endl;
}

double e(double x) {
    return exp(x);
}

void exercise_6(void) {
    double solut(double, double, double, double);
    double a, b, c, d;
    cout << "Input a & b & c & d:" << endl;
    cin >> a >> b >> c >> d;
    cout << solut(a, b, c, d) << endl;
}

double solut(double a, double b, double c, double d) {
    double x = 1, x0, f, f1;
    do {
        x0 = x;
        f = ((a*x0+b) * x0 + c) * x0 + d;
        f1 = ((3*a*x0 + 2*b)) * x0 + c;
        x = x0 - f/f1;
    } while (fabs(x-x0)>=1e-5);
    return x;
}

void exercise_7(int a) {
    if (a < 6 || a % 2 != 0) {
        cout << "Wrong number!" << endl;
        return;
    }
    bool find = false;
    for (int i = 3; i < a / 2; ++i) {
        if (exercise_3(i) && exercise_3(a - i)) {
            cout << "a = " << i << " + " << a-i << endl;
            find = true;
        }
    }
    if (!find) cout << "Shit Gotbaha." << endl;
}

void exercise_8(int n, double x) {
    double lrd(int, double);
    cout << lrd(n, x) << endl;
}

double lrd(int n, double x) {
    if (n == 0) return 1;
    if (n == 1) return x;
    return ((2*n-1)*x - lrd(n-1, x) - (n-1)*lrd(n-2, x)) / n;
}

void exercise_9(void) {

}

void exercise_10(void) {
    void convert(int);
    int n;
    cout << "Input n:" << endl;
    cin >> n;
    convert(n);
    cout << endl;
}

void convert(int a) {
    int i = a / 10;
    char c;
    if (i != 0) {
        convert(i);
    }
    c = a % 10 + '0';
    cout << c << ' ';
}

void exercise_11(int a) {
    long long add(long long);
    cout << add(a) << endl;
}

long long add(long long a) {
    return a == 0 ? 0 : add(a - 1) + a * a;
}

void exercise_12(void) {
    cout << triangle_area(3,4,5) << endl;
}
