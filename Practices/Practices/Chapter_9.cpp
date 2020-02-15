//
//  Chapter_9.cpp
//  Practices
//
//  Created by Songyu on 2020/2/15.
//  Copyright © 2020 Songyu. All rights reserved.
//

#include "Common.h"

void exercise_4(void);
void exercise_5(void);
void exercise_6(void);
void exercise_9(void);
void exercise_10(void);

void Chapter_9_exercise(int number) {
    switch (number) {
        case 4: exercise_4(); break;
        case 5: exercise_5(); break;
        case 6: exercise_6(); break;
        case 9: exercise_9(); break;
        case 10: exercise_10(); break;
        default: cout << "Shit exercise number!" << endl; break;
    }
}

class Student {
public:
    int number;
    float score;
    Student(int n, float s): number(n), score(s) {}
    Student();
    void init() {
        cin >> number >> score;
    }
    void change(int n, float s) {
        number = n;
        score = s;
    }
    void display() {
        cout << number << ':' << score << endl;
    }
};


void exercise_4(void) {
    Student students[5], *p = students;
    for (int i = 0; i < 5; ++i) {
        cout << "Input No." << i + 1 << " student's info:" << endl;
        (*(p+i)).init();
    }
    (*(p)).display();
    (*(p+2)).display();
    (*(p+4)).display();
}

void max_student(Student *p) {
    int max = (*p).score, index = 0;
    for (int i = 1; i < 5; ++i) {
        if ((*(p+i)).score > max) {
            max = (*(p+i)).score;
            index = i;
        }
    }
    (*(p+index)).display();
}

void exercise_5(void) {
    Student students[5], *p = students;
    for (int i = 0; i < 5; ++i) {
        cout << "Input No." << i + 1 << " student's info:" << endl;
        (*(p+i)).init();
    }
    max_student(p);
}

void fun(Student &stud, int n, float s) {
    stud.display();
    stud.change(n, s);
    stud.display();
}

void exercise_6(void) {
    Student stud(101, 78.5);
    Student *p = &stud;
    fun(*p, 10, 123);
    //    p->display();
    //    p->change(10, 10);
    //    p->display();
    //    stud.display();
    //    stud.change(50, 50);
    //    stud.display();
}

class Product {
public:
    Product(int num, int quantity, float price): num(num), quantity(quantity), price(price) {}
    void total();
    static float average();
    static void display();
private:
    int num;
    int quantity;
    float price;
    static int n;
    static float discount;
    static float sum;
};

void Product::total() {
    sum += price * quantity * (quantity > 10 ? 0.98 : 1) * (1 - discount);
    n += quantity;
}

float Product::average() {
    return sum / n;
}

void Product::display() {
    cout << sum << endl << average() << endl;
}

float Product::discount = 0.05;
float Product::sum = 0;
int Product::n = 0;
void exercise_9(void) {
    Product products[3] = {
        Product(101, 5, 23.5),
        Product(102, 12, 24.56),
        Product(103, 100, 21.5)
    };
    for (int i = 0; i < 3; ++i) {
        products[i].total();
    }
    Product::display();
}

class Time;
class Date {
public:
    Date(int, int, int);
    friend Time;
private:
    int month, day, year;
};
Date::Date(int m, int d, int y): month(m), day(d), year(y) {}

class Time {
public:
    Time(int, int, int);
    void display(const Date &);
private:
    int hour, minute, sec;
};
Time::Time(int h, int m, int s): hour(h), minute(m), sec(s) {}
void Time::display(const Date &d) {
    cout << d.month << '/' << d.day << '/' << d.year << endl;
    cout << hour << ':' << minute << ':' << sec << endl;
}

void exercise_10(void) {
    Time t1(10, 13, 56);
    Date d1(12, 25, 2004);
    t1.display(d1);
}

