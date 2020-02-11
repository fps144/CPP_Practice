//
//  Chapter_3.cpp
//  exercises
//
//  Created by Songyu on 2020/2/11.
//  Copyright © 2020 Songyu. All rights reserved.
//
// - Chapter 3 -

#include "Common.h"

static void exercise_2(void);
static void exercise_3(void);
static void exercise_4(void);
static void exercise_9(void);
static void exercise_10(void);
static void exercise_11(void);
static void exercise_12(void);
static void exercise_13(void);
static void exercise_14(void);
static void exercise_15(void);
static void exercise_16(void);
static void exercise_17(void);
static void exercise_18(void);
static void exercise_19(void);
static void exercise_20(void);
static void exercise_21(void);
static void exercise_22(void);
static void exercise_23(void);
static void exercise_24(void);
static void exercise_25(void);

void Chapter_3_exercise(int number) {
    switch (number) {
        case 2: {
            exercise_2();
        } break;
        case 3: {
            exercise_3();
        } break;
        case 4: {
            exercise_4();
        } break;
        case 9: {
            exercise_9();
        } break;
        case 10: {
            exercise_10();
        } break;
        case 11: {
            exercise_11();
        } break;
        case 12: {
            exercise_12();
        } break;
        case 13: {
            exercise_13();
        } break;
        case 14: {
            exercise_14();
        } break;
        case 15: {
            exercise_15();
        } break;
        case 16: {
            exercise_16();
        } break;
        case 17: {
            exercise_17();
        } break;
        case 18: {
            exercise_18();
        } break;
        case 19: {
            exercise_19();
        } break;
        case 20: {
            exercise_20();
        } break;
        case 21: {
            exercise_21();
        } break;
        case 22: {
            exercise_22();
        } break;
        case 23: {
            exercise_23();
        } break;
        case 24: {
            exercise_24();
        } break;
        case 25: {
            exercise_25();
        } break;
        default: {
            cout << "Shit exercise number!" << endl;
        } break;
    }
}

static void exercise_2(void) {
    cout << "Input radius & height:" << endl;
    float r, h;
    const float pi = 3.14;
    cin >> r >> h;
    cout << setiosflags(ios::fixed) << setprecision(2);
    cout << "圆周长 = " << 2*pi*r << endl;
    cout << "圆面积 = " << pi*r*r << endl;
    cout << "球面积 = " << 4*pi*r*r << endl;
    cout << "球体积 = " << 4.0/3*pi*r*r*r << endl;
    cout << "圆柱体积 = " << pi*r*r*h << endl;
}

static void exercise_3(void) {
    cout << "Input F:" << endl;
    float f, c;
    cin >> f;
    c = 5.0/9*(f-32);
    cout << setiosflags(ios::fixed) << setprecision(2);
    cout << "华氏度为: " << f << endl;
    cout << "摄氏度为: " << c << endl;
}

static void exercise_4(void) {
    cout << "Input char c1 & c2:" << endl;
    int c1 = getchar();
    int c2 = getchar();
    cout << "Putchar: ";
    putchar(c1); putchar(c2); putchar('\n');
    cout << "Cout: ";
    cout << "c1 = " << c1 << " c2 = " << c2 << endl;
}

static void exercise_9(void) {
    cout << "Input a & b & c:" << endl;
    int a, b, c, m;
    cin >> a >> b >> c;
    m = a;
    if (m < b) m = b;
    if (m < c) m = c;
    cout << "Max number is " << m << endl;
}

static void exercise_10(void) {
    cout << "Input x:" << endl;
    float x, y;
    cin >> x;
    if (x < 1) {
        y = x;
    } else if (x >= 1 && x < 10) {
        y = 2 * x - 1;
    } else {
        y = 3 * x - 11;
    }
    cout << "y = " << y << endl;
}

static void exercise_11(void) {
    cout << "Input score:" << endl;
    float score;
    int mark = 'A';
    cin >> score;
    if (score >= 90) mark += 0;
    else if (score < 90 && score >= 80) mark += 1;
    else if (score < 80 && score >= 70) mark += 2;
    else if (score < 70 && score >= 60) mark += 3;
    else mark += 4;
    putchar(mark); putchar('\n');
}

static void exercise_12(void) {
    cout << "Input number:" << endl;
    int i = 1;
    unsigned int n, b = 0;
    cin >> n;
    if (n > 99999 || n < 0) {cout << "Shit number.\n"; return;}
    b = n;
    while (b /= 10) {
        i += 1;
    }
    cout << "Total bit: " << i << endl << "Each bit:" << endl;
    for (int j = i - 1; j >= 0; --j) {
        b = n;
        for (int k = 0; k < j; ++k) {
            b /= 10;
        }
        cout << b % 10 << endl;
    }
    cout << "Inverse: \n";
    b = n;
    for (int j = 0; j < i; ++j) {
        cout << b % 10;
        b /= 10;
    }
    cout << endl;
}

static void exercise_13(void) {
    cout << "Input money:" << endl;
    double m, n, sum = 0;
    cin >> m;
    n = m;
    if (m <= 100000) {
        sum += m * 0.1;
    } else {
        sum += 10000;
        m -= 100000;
        if (m <= 100000) {
            sum += m * 0.075;
        } else {
            sum += 7500;
            m -= 100000;
            if (m <= 200000) {
                sum += m * 0.05;
            } else {
                sum += 10000;
                m -= 200000;
                if (m <= 200000) {
                    sum += m * 0.03;
                } else {
                    sum += 6000;
                    m -= 200000;
                    if (m <= 400000) {
                        sum += m * 0.015;
                    } else {
                        sum += 6000;
                        m -= 400000;
                        if (m > 0) {
                            sum += m * 0.01;
                        }
                    }
                }
            }
        }
    }
    cout << "Total = " << sum << endl;
}

static void exercise_14(void) {
    cout << "Input 4 numbers:" << endl;
    long a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a > b) {
        b = a + b;
        a = b - a;
        b = b - a;
    }
    if (a > c) {
        c = a + c;
        a = c - a;
        c = c - a;
    }
    if (a > d) {
        d = a + d;
        a = d - a;
        d = d - a;
    }
    if (b > c) {
        c = b + c;
        b = c - b;
        c = c - b;
    }
    if (b > d) {
        d = b + d;
        b = d - b;
        d = d - b;
    }
    if (c > d) {
        d = c + d;
        c = d - c;
        d = d - c;
    }
    cout << a << " < " << b << " < " << c << " < " << d << endl;
}

static void exercise_15(void) {
    cout << "Input a & b:" << endl;
    unsigned int a, b, p = 0, r, temp;
    cin >> a >> b;
    if (a < b) {
        b = a + b;
        a = b - a;
        b = b - a;
    }
    temp = a;
    for (int i = a/2; i > 0; --i) {
        if (b % i == 0) { p = i; break; }
    }
    while (1) {
        if (temp % a == 0 && temp % b == 0) {
            r = temp;
            break;
        }
        temp += 1;
    }
    cout << "最大公约数 = " << p << endl << "最小公倍数 = " << r << endl;
}

static void exercise_16(void) {
    cout << "Input string:" << endl;
    char c;
    int letter = 0, number = 0, space = 0, other = 0;
    while ((c = getchar()) != '\n') {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) letter += 1;
        else if (c >= '0' && c <= '9') number += 1;
        else if (c == ' ') space += 1;
        else {
            cout << c << endl;
            other += 1;
        }
    }
    cout << "Letter = " << letter << endl;
    cout << "Number = " << number << endl;
    cout << "Space = " << space << endl;
    cout << "Other = " << other << endl;
}

static void exercise_17(void) {
    cout << "Input a & n" << endl;
    int a, n;
    long sum = 0, total = 0;
    cin >> a >> n;
    for (int i = 0; i < n; ++i) {
        sum += a * pow(10, i);
        total += sum;
    }
    cout << "Sum = " << total << endl;
}

static void exercise_18(void) {
    double sum = 0;
    for (int i = 1; i <= 20; ++i) {
        double t = 1;
        for (int j = 1; j <= i; ++j) {
            t *= j;
        }
        sum += t;
    }
    cout << "Sum = " << sum << endl;
}

static void exercise_19(void) {
    for (int i = 100; i < 1000; ++i) {
        int t = i % 10, p = i % 100 / 10, q = i / 100;
        if (pow(t, 3) + pow(p, 3) + pow(q, 3) == i) {
            cout << i << '\t';
        }
    }
    cout << endl;
}

static void exercise_20(void) {
    int a[10], index = 0;
    for (int i = 2; i <= 1000; ++i) {
        for (int j = 1; j < i; ++j) {
            if (i % j == 0) {
                a[index] = j;
                ++index;
            }
        }
        int sum = 0;
        for (int j = 0; j < index; ++j) {
            sum += a[j];
        }
        if (sum == i) {
            cout << i << " is a 完数 \nits factors are:";
            for (int j = 0; j < index; ++j) {
                cout << a[j] << ' ';
            }
            cout << endl;
        }
        index = 0;
        memset(a, 0, 11);
    }
}

static void exercise_21(void) {
    float a = 2, b = 1, sum = a/b;
    for (int i = 1; i <= 19; ++i) {
        a = a + b;
        b = a - b;
        sum += a/b;
    }
    cout << "Sum = " << sum << endl;
}

static void exercise_22(void) {
    int sum = 1;
    for (int i = 0; i < 9; ++i) {
        sum = (sum + 1) * 2;
    }
    cout << "Sum = " << sum << endl;
}

static void exercise_23(void) {
    float a, x0, x1;
    cout << "Input a:" << endl;
    cin >> a;
    x0 = a/2;
    x1 = (x0 + a/x0)/2;
    do {
        x0 = x1;
        x1 = (x0 + a/x0)/2;
    } while (fabs(x1 - x0) >= 1e-5); // 注意 >=
    cout << "The square root of " << a << " is " << x1 << endl;
}

static void exercise_24(void) {
    for (int i = 0; i < 4; ++i) {
        for (int k = 1; k <= 2*i+1; ++k) {
            cout << '*';
        }
        cout << endl;
    }
    for (int i = 0; i < 3; ++i) {
        for (int k = 1; k <= 5-2*i; ++k) {
            cout << '*';
        }
        cout << endl;
    }
}

static void exercise_25(void) {
    char q, w, e;
    for (q = 'X'; q <= 'Z'; ++q) {
        for (w = 'X'; w <= 'Z'; ++w) {
            if (q == w) continue;
            for (e = 'X'; e <= 'Z'; ++e) {
                if (q == e || w == e) continue;
                if (q != 'X' && e != 'X' && e != 'Z') {
                    cout << "A vs " << q << endl << "B vs " << w << endl << "C vs " << e << endl;
                }
            }
        }
    }
}
