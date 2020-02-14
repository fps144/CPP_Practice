//
//  Common.h
//  exercises
//
//  Created by Songyu on 2020/1/30.
//  Copyright © 2020 Songyu. All rights reserved.
//

#ifndef Common_h
#define Common_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

class Cuboid {
public:
    void inputInfo() {
        cin >> length >> width >> height;
    }
    void calculateVolume() {
        volume = length * width * height;
    }
    void printInfo() {
        cout << "Volume is " << volume << endl;
    }
protected:
    float length, width, height;
private:
    float volume;
};

void Chapter_3_exercise(int number);
void Chapter_4_exercise(int number);
void Chapter_5_exercise(int number);
void Chapter_6_exercise(int number);
void Chapter_7_exercise(int number);
void Chapter_8_exercise(int number);

#endif /* Common_h */
