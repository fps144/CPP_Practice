//
//  Chapter_8.cpp
//  Practices
//
//  Created by Songyu on 2020/2/14.
//  Copyright © 2020 Songyu. All rights reserved.
//

#include "Common.h"

static void exercise_1(void);
static void exercise_2(void);
static void exercise_3(void);
static void exercise_4(void);
static void exercise_5(void);
static void exercise_6(void);

void Chapter_8_exercise(int number) {
    switch (number) {
        case 1: exercise_1(); break;
        case 2: exercise_2(); break;
        case 3: exercise_3(); break;
        case 4: exercise_4(); break;
        case 5: exercise_5(); break;
        case 6: exercise_6(); break;
        default: cout << "Shit exercise number!" << endl; break;
    }
}

class Time {
public:
    void set_time(void);
    void show_time(void);
    void p_set_time(void) {
        cin >> hour >> minute >> sec;
    }
    void p_show_time(void) {
        cout << hour << '-' << minute << '-' << sec << endl;
    }
    void p_test_method_1();
    void init() {
        hour = minute = sec = -1;
    }
private:
    int hour, minute, sec;
};

void Time::set_time(void) {
    cin >> hour >> minute >> sec;
}

void Time::show_time(void) {
    cout << hour << ":" << minute << ":" << sec << endl;
}

void exercise_1(void) {
    Time t;
    t.set_time();
    t.show_time();
}

static void exercise_2(void) {
    Time t;
    t.p_set_time();
    t.p_show_time();
}

void Time::p_test_method_1() {
    cout << "p_test_method_1" << endl;
}

static void exercise_3(void) {
    Time t;
    t.p_test_method_1();
}

static void exercise_4(void) {
    Time t;
    t.show_time();
    t.init();
    t.show_time();
}

static void exercise_5(void) {
    cout << "omitted." << endl;
}

static void exercise_6(void) {
    Cuboid cuboid1, cuboid2, cuboid3;
    cout << "Cuboid 1:" << endl;
    cuboid1.inputInfo();
    cout << "Cuboid 2:" << endl;
    cuboid2.inputInfo();
    cout << "Cuboid 3:" << endl;
    cuboid3.inputInfo();
    cuboid1.calculateVolume();
    cuboid2.calculateVolume();
    cuboid3.calculateVolume();
    cuboid1.printInfo();
    cuboid2.printInfo();
    cuboid3.printInfo();
}
