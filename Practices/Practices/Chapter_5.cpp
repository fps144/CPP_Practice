//
//  Chapter_5.cpp
//  exercises
//
//  Created by Songyu on 2020/1/31.
//  Copyright © 2020 Songyu. All rights reserved.
//

#include "Common.h"
#include <random>
#include <ctime>
#include <cstdlib>

static void exercise_1(void);
static void exercise_2(void);
static void exercise_3(void);
static void exercise_4(void);
static void exercise_5(void);
static void exercise_6(void);
static void exercise_7(void);
static void exercise_8(void);
static void exercise_9(void);
static void exercise_10(void);
static void exercise_11(void);
static void exercise_12(void);
static void exercise_13(void);
static void exercise_14(void);
static void exercise_15(void);
static void exercise_16(void);
static void exercise_17(void);

void Chapter_5_exercise(int number) {
    switch (number) {
        case 1: exercise_1(); break;
        case 2: exercise_2(); break;
        case 3: exercise_3(); break;
        case 4: exercise_4(); break;
        case 5: exercise_5(); break;
        case 6: exercise_6(); break;
        case 7: exercise_7(); break;
        case 8: exercise_8(); break;
        case 9: exercise_9(); break;
        case 10: exercise_10(); break;
        case 11: exercise_11(); break;
        case 12: exercise_12(); break;
        case 13: exercise_13(); break;
        case 14: exercise_14(); break;
        case 15: exercise_15(); break;
        case 16: exercise_16(); break;
        case 17: exercise_17(); break;
        default: {
            cout << "Shit exercise number!" << endl;
        } break;
    }
}

static void exercise_1(void) {
    int numbers[100];
    for (int i = 0; i < 100; ++i) {
        numbers[i] = i == 0 ? 0 : i+1;
    }
    for (int i = 1; i < 100; ++i) {
        if (numbers[i] == 0) continue;
        for (int j = i + 1; j < 100; ++j) {
            if (numbers[j] % numbers[i] == 0) {
                numbers[j] = 0;
            }
        }
    }
    for (int i = 0; i < 100; ++i) {
        if (numbers[i] != 0) {
            cout << numbers[i] << ' ';
        }
    }
    cout << endl;
}


static void exercise_2(void) {
    int a[10];
    cout << "Input 10 numbers:" << endl;
    for (int i = 0; i < 10; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < 9; ++i) {
        for (int j = i + 1; j <= 9; ++j) {
            int temp = a[i];
            if (a[i] > a[j]) {
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    for (int i = 0; i < 10; ++i) {
        cout << a[i] << ' ';
    }
    cout << endl;
}

static void exercise_3(void) {
    float matrix[][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    float s1 = 0, s2 = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == j)     s1 += matrix[i][j];
            if (i + j == 2) s2 += matrix[i][j];
        }
    }
    cout << "正对角线和 = " << s1 << endl << "副对角线和 = " << s2 << endl;
}

static void exercise_4(void) {
    float arr[6] = {-1, 2, 10, 14, 234}, a;
    int index = -1;
    cout << "Old array is [-1, 2, 10, 14, 234]\nInput a new number you want to insert:" << endl;
    cin >> a;
    for (int i = 0; i < 6; ++i) {
        if (arr[i] > a) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        arr[5] = a;
    } else {
        for (int i = 5; i > index; --i) {
            arr[i] = arr[i - 1];
        }
        arr[index] = a;
    }
    cout << "New array is ";
    for (int i = 0; i < 6; ++i) {
        if (i == 0) cout << "[" << arr[i] << ", ";
        else if (i == 5) cout << arr[i] << "]";
        else cout << arr[i] << ", ";
    }
    cout << endl;
}

static void exercise_5(void) {
    int a[] = {8, 6, 5, 4, 1};
    cout << "Old array is [8, 6, 5, 4, 1]" << endl;
    for (int i = 0; i < 5/2; ++i) {
        int temp = a[i];
        a[i] = a[4-i];
        a[4-i] = temp;
    }
    for (int i = 0; i < 5; ++i) {
        cout << a[i] << ' ';
    }
    cout << endl;
}

static void exercise_6(void) {
    int a[10][10] = {{1}, {1}};
    for (int i = 1; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (j == 0 || i == j) {
                a[i][j] = 1;
                continue;
            }
            a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
        }
    }
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << setw(5) << a[i][j];
            if (i == j) {
                cout << '\n';
                break;
            }
        }
    }
}

static void exercise_7(void) {
    /*
     52 87 44  8 56 51
     78 41 26  2 73 55
     16 58 54 56 49 86
     19 46  9 16 48 23
     89 31 92 40 80 31
     92 45 26 49 53 87
     
     找到鞍点: (3, 4) -> 48
     */
    const int number = 6;
    int a[number][number], max_r[2][36], max_c[2][36];
    srand((unsigned)time(NULL));
    cout << "Random array is:" << endl;
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            a[i][j] = rand()%100;
            cout << setw(3) << a[i][j];
            if (j == 5) cout << endl;
        }
    }
    
    int temp, index_r = 0, index_c = 0;
    for (int i = 0; i < number; ++i) {
        temp = a[i][0];
        for (int j = 0; j < number; ++j) {
            if (a[i][j] > temp) temp = a[i][j];
        }
        for (int j = 0; j < number; ++j) {
            if (a[i][j] == temp) {
                max_r[0][index_r] = i;
                max_r[1][index_r] = j;
                ++index_r;
            }
        }
        
        temp = a[0][i];
        for (int j = 0; j < number; ++j) {
            if (a[j][i] < temp) temp = a[j][i];
        }
        for (int j = 0; j < number; ++j) {
            if (a[j][i] == temp) {
                max_c[0][index_c] = j;
                max_c[1][index_c] = i;
                ++index_c;
            }
        }
    }
    bool find = false;
    for (int i = 0; i < index_r; ++i) {
        for (int j = 0; j < index_c; ++j) {
            if (max_r[0][i] == max_c[0][j] && max_r[1][i] == max_c[1][j]) {
                find = true;
                cout << "找到鞍点: (" << i << ", " << j << ") -> " << a[i][j] << endl;
            }
        }
    }
    if (!find) cout << "没有鞍点。" << endl;
}

static void exercise_8(void) {
    int a[15] = {-10, -2, 0, 2, 14, 23, 35, 53, 66, 77, 77, 77, 102, 134, 1245}, n, indexes[15]={-1}, index = 0;
    cout << "Input n:" <<endl;
    cin >> n;
    int i = 15/2;
    bool find = false;
    while (true) {
        if (a[i] == n) {
            find = true;
            indexes[index++] = i;
            for (int j = i-1; j >= 0; --j) {
                if (a[j] == n) indexes[index++] = j;
                else break;
            }
            for (int k = i+1; k < 15; ++k) {
                if (a[k] == n) indexes[index++] = k;
                else break;
            }
            break;
        } else if (a[i] > n) {
            i /= 2;
            if (i == 0 && a[i] != n) break;
        } else {
            i += (15-i)/2;
            if (i == 14 && a[i] != n) break;
        }
    }
    if (indexes[0] == -1) cout << "无此数" << endl;
    else {
        for (int i = 0; i < index; ++i) {
            cout << n << "是第" << indexes[i] << "个数的值。" << endl;
        }
    }
}

static void exercise_9(void) {
    int daysOfMonths[12] = {31,28,31,30,31,30,31,31,30,31,30,31}, year, month, day, total = 0;
    cout << "Input year, month, day:" << endl;
    cin >> year >> month >> day;
    if (year < 0 || month < 0 || month > 12 || day < 0 || day > 31) {
        cout << "Shit time." << endl;
        return;
    }
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) daysOfMonths[1] = 29;
    for (int i = 0; i < month - 1; ++i) {
        total += daysOfMonths[i];
    }
    total += day;
    cout << year << "年" << month << "月" << day << "日" << "是当年的第" << total << "天。" << endl;
}

static void exercise_10(void) {
    int capitalLetter = 0, smallLetter = 0, number = 0, space = 0, other = 0;
    char a[80];
    cout << "Input 3 lines:" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 80; ++j) {
            char c = getchar();
            if (c == '\n') break;
            a[j] = c;
            if (c >= '0' && c <= '9') ++number;
            else if (c >= 'a' && c <= 'z') ++smallLetter;
            else if (c >= 'A' && c <= 'Z') ++capitalLetter;
            else if (c == ' ') ++space;
            else ++other;
        }
    }
    cout << "大写字母数：" << capitalLetter << endl;
    cout << "小写字母数：" << smallLetter << endl;
    cout << "数字数：" << number << endl;
    cout << "空格数：" << space << endl;
    cout << "其他字符数：" << other << endl;
}

static void exercise_11(void) {
    char a[5] = {'*','*','*','*','*'};
    string s = "*****";
    cout << "Char array:" << endl;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j <= i - 1; ++j) {
            cout << ' ';
        }
        for (int j = 0; j < 5; ++j) {
            cout << a[j];
        }
        cout << endl;
    }
    cout << "-----------" << endl;
    cout << "String:" << endl;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j <= i - 1; ++j) {
            cout << ' ';
        }
        cout << s << endl;
    }
}

static void exercise_12(void) {
    char o[100], n[100], c;
    int count = 0;
    cout << "Input password:" << endl;
    for (int i = 0; i < 100; ++i) {
        if ((c = getchar()) && c == '\n') break;
        ++count;
        o[i] = c;
        if (c >= 'a' && c <= 'z') c = 'a'*2+25-c;
        if (c >= 'A' && c <= 'Z') c = 'A'*2+25-c;
        n[i] = c;
    }
    cout << "Password is:" << endl << o << endl;
    cout << endl << "Original is:" << endl << n << endl;
}

static void exercise_13(void) {
    string s1, s2;
    char a[160], b[80];
    //    int i = 0, j = 0;
    cout << "Input stringA and stringB:" << endl;
    
    //    // string
    //    cin >> s1 >> s2;
    //    s1 += s2;
    //    cout << s1 << endl;
    
    cin >> a >> b;
    //    // Char array
    //    while (a[i] != '\0') {
    //        ++i;
    //    }
    //    while (b[j] != '\0') {
    //        a[i++] = b[j++];
    //    }
    //    a[i] = '\0';
    
    // strcat
    strcat(a, b);
    cout << a << endl;
}

static void exercise_14(void) {
    string a[5];
    cout << "Input 5 strings:" << endl;
    for (int i = 0; i < 5; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4 - i; ++j) {
            if (a[j] > a[j + 1]) {
                string temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    cout << endl;
    for (int i = 0; i < 5; ++i) {
        cout << a[i] << endl;
    }
}

static void exercise_15(void) {
    string a[5];
    cout << "Input 5 strings:" << endl;
    for (int i = 0; i < 5; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < 5; ++i) {
        if (a[i].at(0) == 'A') cout << a[i] << ' ';
    }
    cout << endl;
}

static void exercise_16(void) {
    char a[20];
    //    string s;
    int index = 0;
    cout << "Input string:" << endl;
    
    // Char array
    cin >> a;
    while (a[index] != '\0') ++index;
    for (int i = index; i >= 0; --i) {
        cout << a[i];
    }
    cout << endl;
    
    //    // string
    //    cin >> s;
    ////    // reverse
    ////    reverse(s.begin(), s.end());
    ////    cout << s << endl;
    //    // index
    //    for (long i = s.size() - 1; i >= 0; --i) { // 此处定义i的时候不能用unsigned long，否则在执行到0的时候再-1，就会变为unsigned long可取值范围的最大值。
    //        cout << s[i];
    //    }
    cout << endl;
}

static void exercise_17(void) {
    const int count = 10;
    string name[count];
    int score[count], id[count];
    for (int i = 0; i < count; ++i) {
        cout << "请输入第" << i+1 << "个学生的姓名、学号和成绩：" << endl;
        cin >> name[i] >> id[i] >> score[i];
    }
    cout << "不及格的学生有：" << endl;
    for (int i = 0; i < count; ++i) {
        if (score[i] < 60) cout << name[i] << '\t' << id[i] << '\t' << score[i] << endl;
    }
}
