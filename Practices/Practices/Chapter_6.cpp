//
//  Chapter_6.cpp
//  exercises
//
//  Created by Songyu on 2020/2/3.
//  Copyright © 2020 Songyu. All rights reserved.
//

#include "Common.h"

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
static void exercise_18(void);
static void exercise_19(void);
static void exercise_20(void);

void Chapter_6_exercise(int number) {
    switch (number) {
        case 1: {
            exercise_1();
        } break;
        case 2: {
            exercise_2();
        } break;
        case 3: {
            exercise_3();
        } break;
        case 4: {
            exercise_4();
        } break;
        case 5: {
            exercise_5();
        } break;
        case 6: {
            exercise_6();
        } break;
        case 7: {
            exercise_7();
        } break;
        case 8: {
            exercise_8();
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
        default: {
            cout << "Shit exercise number!" << endl;
        } break;
    }
}

static void exercise_1(void) {
    void p_swap(int *, int *);
    cout << "Input 3 integers:" << endl;
    int a, b, c, *i = &a, *j = &b, *k = &c;
    cin >> a >> b >> c;
    if (*i > *j) p_swap(i, j);
    if (*j > *k) p_swap(j, k);
    cout << *i << " < " << *j << " < " << *k << endl;
}

void p_swap(int *a, int *b) {
    int tmp;
    if (*a > *b) {
        tmp = *b;
        *b = tmp;
        *a = *b;
    }
}

static void exercise_2(void) {
    void swapString(string &, string &);
    
    cout << "Input 3 strings:" << endl;
    char *p_a, *p_b, *p_c;
    string a = "                    ", b = "                    ", c = "                    ";
    p_a = &a[0];
    p_b = &b[0];
    p_c = &c[0];
    gets(p_a);
    gets(p_b);
    gets(p_c);
    if (a > b) swapString(a, b);
    if (a > c) swapString(a, c);
    if (b > c) swapString(b, c);
    cout << p_a << " < " << p_b << " < " << p_c << endl;
}

void swapString(string &s1, string &s2) {
    string tmp = s1;
    s1 = s2;
    s2 = tmp;
}

static void exercise_3(void) {
    void inputTenNumbers(int *);
    void processTenNumbers(int *);
    void printTenNumbers(int *);
    
    int a[10];
    inputTenNumbers(a);
    processTenNumbers(a);
    printTenNumbers(a);
}

void inputTenNumbers(int *a) {
    cout << "Input 10 numbers:" << endl;
    for (int i = 0; i< 10; ++i) {
        cin >> a[i];
    }
}

void processTenNumbers(int *a) {
    int *p_max = a, *p_min = a, tmp;
    for (int i = 1; i < 10; ++i) {
        if (a[i] > *p_max) p_max = &a[i];
        if (a[i] < *p_min) p_min = &a[i];
    }
    if (*p_min != *a) {
        tmp = a[0];
        a[0] = *p_min;
        *p_min = tmp;
    }
    if (*p_max != a[9]) {
        tmp = a[9];
        a[9] = *p_max;
        *p_max = tmp;
    }
}

void printTenNumbers(int *a) {
    for (int i = 0; i < 10; ++i) {
        cout << a[i] << '\t';
    }
    cout << endl;
}

static void exercise_4(void) {
    void move(int *arr, int n, int m);
    
    int n, m, a[20];
    cout << "How many numbers?" << endl;
    cin >> n;
    cout << "How many places do u want to move?" << endl;
    cin >> m;
    cout <<"Input " << n << " numbers:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    move(a, n, m);
    cout << "After moving:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
    cout << endl;
}

void move(int *a, int n, int m) {
    for (int i = 0; i < m; ++i) {
        int tmp = a[0];
        a[0] = a[n-1];
        for (int j = n - 1; j > 0; --j) {
            a[j] = a[j - 1];
        }
        a[1] = tmp;
    }
}

static void exercise_5(void) {
    cout << "Number of people:" << endl;
    int n;
    cin >> n;
    int a[n], *p = a, total = n, count = 0, index = 0;
    for (int i = 0; i < n; ++i) {
        *(p+i) = i + 1;
    }
    while (total != 1) {
        if (index == n) index = 0;
        if (*(p + index) != 0) ++count;
        if (count == 3) {
            count = 0;
            *(p+index) = 0;
            --total;
        }
        ++index;
    }
    while (*p == 0) ++p;
    cout << "余下的人排第 " << *p << " 号。" << endl;
}

static void exercise_6(void) {
    int countString(char *a);
    int count = 0;
    char a[50], *p = a;
    cout << "Input a string:" << endl;
    cin >> a;
    count = countString(p);
    cout << "共 " << count << " 个字符。" << endl;
}

int countString(char *a) {
    int count = 0;
    while (*a++ != '\0') ++count;
    return count;
}

static void exercise_7(void) {
    char a[50], b[50], *p = a;
    int n;
    cout << "Input a string:" << endl;
    cin >> a;
    cout << "Input begin index:" << endl;
    cin >> n;
    p += n-1;
    strcpy(b, p);
    cout << b << endl;
}

static void exercise_8(void) {
    char a[20], *p = a;
    int capital = 0, small = 0, space = 0, digit = 0, other = 0, index = 0;
    cout << "Input string:" << endl;
    while ((a[index] = getchar()) != '\n') ++index;
    while (*p != '\n') {
        if (*p >= 'a' && *p <= 'z') ++small;
        else if (*p >= 'A' && *p <= 'Z') ++capital;
        else if (*p >= '0' && *p <= '9') ++digit;
        else if (*p == ' ') ++space;
        else ++other;
        ++p;
    }
    cout << "大写字母数：" << capital << endl;
    cout << "小写字母数：" << small << endl;
    cout << "数字数：" << digit << endl;
    cout << "空格数：" << space << endl;
    cout << "其他字符数：" << other << endl;
}

static void exercise_9(void) {
    void matrix_T(int *);
    
    int a[3][3], *p = &a[0][0];
    cout << "Input a 3x3 matrix:" << endl;
    for (int i = 0; i < 3; ++i) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    matrix_T(p);
    cout << "-------" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << a[i][0] << ' ' << a[i][1] << ' ' << a[i][2] << endl;
    }
}

void matrix_T(int *a) {
    for (int i = 1; i < 3; ++i) {
        for (int j = 0; j < (i == 1 ? 2 : 3); ++j) {
            int tmp = *(a+3*j+i);
            *(a+3*j+i) = *(a+3*i+j);
            *(a+3*i+j) = tmp;;
        }
    }
}

static void exercise_10(void) {
    void matrix_Fix(int *a);
        
    cout << "Input a 5x5 matrix:" << endl;
    int a[5][5], *p = &a[0][0];
    for (int i = 0; i < 5; ++i) {
        cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4];
    }
    matrix_Fix(p);
    cout << "New matrix:" << endl;
        for (int i = 0; i < 5; ++i) {
        cout << setw(2) << a[i][0] << ' ' << a[i][1] << ' ' << a[i][2] << ' ' << a[i][3] << ' ' << a[i][4] << endl;
    }
    cout << endl;
}

void matrix_Fix(int *a) {
    void swapMatrixItem(int *a, int *b);
    void resortMinArray(int *min, int *a);
    
    int min[] = {0, 1, 2, 3}, max = 0;
    resortMinArray(min, a);
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            int index = 5*i+j;
            int current = *(a+index);
            if (current < *(a+min[0]) || current < *(a+min[1]) || current < *(a+min[2]) || current < *(a+min[3])) {
                min[3] = index;
                resortMinArray(min, a);
            }
            if (current > *(a+max)) max = index;
        }
    }
    swapMatrixItem(a, a+min[0]);
    if (max == 0) max = min[0];
    else if (min[1] == 0) min[1] = min[0];
    else if (min[2] == 0) min[2] = min[0];
    else if (min[3] == 0) min[3] = min[0];
    swapMatrixItem(a+4, a+min[1]);
    if (max == 4) max = min[1];
    else if (min[2] == 4) min[2] = min[1];
    else if (min[3] == 4) min[3] = min[1];
    swapMatrixItem(a+20, a+min[2]);
    if (max == 20) max = min[2];
    else if (min[3] == 20) min[3] = min[2];
    swapMatrixItem(a+24, a+min[3]);
    if (max == 24) max = min[3];
    swapMatrixItem(a+12, a+max);
}

void resortMinArray(int *min, int *a) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3 - i; ++j) {
            if (*(a+min[j]) > *(a+min[j+1])) {
                int temp = min[j];
                min[j] = min[j+1];
                min[j+1] = temp;
            }
        }
    }
}
 
void swapMatrixItem(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

static void exercise_11(void) {
    void sortStr(string *);
    
    string str[10], *p = str;
    cout << "Input 10 strings(each 3 character):" << endl;
    for (int i = 0; i < 10; ++i) {
        cin >> str[i];
    }
    sortStr(p);
    cout << "Sorted strings:" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << str[i] << endl;
    }
}

void sortStr(string *str) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9 - i; ++j) {
            if (str[j + 1] > str[j]) {
                string tmp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = tmp;
            }
        }
    }
}

static void exercise_12(void) {
    void sortStr_2(string *[]);
    
    string str[10], *p[10];
    cout << "Input 10 strings(each 3 character):" << endl;
    for (int i = 0; i < 10; ++i) {
        cin >> str[i];
        p[i] = &str[i];
    }
    sortStr_2(p);
    cout << "Sorted strings:" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << str[i] << endl;
    }
}

void sortStr_2(string *str[]) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9 - i; ++j) {
            if (*str[j + 1] > *str[j]) {
                string tmp = *str[j];
                *str[j] = *str[j + 1];
                *str[j + 1] = tmp;
            }
        }
    }
}

static void exercise_13(void) {
    //TODO: 定积分
}

static void exercise_14(void) {
    void p_reverse(int *, int);
    
    int n;
    cout << "Input n:" << endl;
    cin >> n;
    int a[n];
    cout << "Input " << n << " numbers:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    p_reverse(a, n);
    cout << "New numbers:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
    cout << endl;
}

void p_reverse(int *a, int n) {
    for (int i = 0; i < n/2; ++i) {
        int tmp = *(a+i);
        *(a+i) = *(a+n-i-1);
        *(a+n-i-1) = tmp;
    }
}

static void exercise_15(void) {
    void averageOfFirstSubject(string, int *);
    void findOutAllFuckingStudents(string[], int *, float [][6]);
    void findOutAllGoodStudents(string[], int *, float [][6]);
    
    cout << "Input 5 subjects:" << endl;
    string subjects[5];
    for (int i = 0; i < 5; ++i) {
        cin >> subjects[i];
    }
    cout << "Enter student numbers and grades for each course for 4 students:" << endl;
    int numbers[4], first[4];
    float score[4][6];
    for (int i = 0; i < 4; ++i) {
        cin >> numbers[i];
        int total = 0;
        for (int j = 0; j < 5; ++j) {
            cin >> score[i][j];
            total += score[i][j];
            if (j == 4) score[i][j+1] = total/5.0;
        }
    }
    for (int i = 0; i < 4; ++i) {
        first[i] = score[i][0];
    }
    averageOfFirstSubject(subjects[0], first);
    findOutAllFuckingStudents(subjects, numbers, score);
    findOutAllGoodStudents(subjects, numbers, score);
}

void averageOfFirstSubject(string subject, int *scores) {
    int total = 0;
    for (int i = 0; i < 4; ++i) {
        total += scores[i];
    }
    cout << "First subject: " << subject << " Average：" << total/4.0 << endl;
}

void findOutAllFuckingStudents(string subjects[], int *numbers, float score[][6]) {
    int fuckingCount, indexOfFuckingStudent[4], index = 0;
    for (int i = 0; i < 4; ++i) {
        fuckingCount = 0;
        for (int j = 0; j < 5; ++j) {
            if (score[i][j] < 60) ++fuckingCount;
            if (fuckingCount == 2) {
                indexOfFuckingStudent[index++] = i;
                break;
            }
        }
    }
    for (int i = 0; i < index; ++i) {
        cout << "Fucking students:" << endl;
        cout << numbers[indexOfFuckingStudent[i]] << " : " << endl;
        for (int j = 0; j < 6; ++j) {
            if (j != 5) cout << subjects[i] << ": " << score[indexOfFuckingStudent[i]][j] << endl;
            else cout << "Average: " << score[indexOfFuckingStudent[i]][j] << endl;
        }
    }
}

void findOutAllGoodStudents(string subjects[], int *numbers, float score[][6]) {
    cout << "Good students:" << endl;
    int goodCount, indexOfGoodStudent[4], index = 0;
    bool everyOver85;
    for (int i = 0; i < 4; ++i) {
        if (score[i][5] >= 90) {
            indexOfGoodStudent[index++] = i;
            continue;
        }
        goodCount = 0;
        everyOver85 = true;
        for (int j = 0; j < 5; ++j) {
            if (score[i][j] < 85) everyOver85 = false;
        }
        if (everyOver85) {
            indexOfGoodStudent[index++] = i;
            continue;
        }
    }
    for (int i = 0; i < index; ++i) {
        cout << numbers[indexOfGoodStudent[i]] << " : " << endl;
        for (int j = 0; j < 6; ++j) {
            if (j != 5) cout << subjects[i] << ": " << score[indexOfGoodStudent[i]][j] << endl;
            else cout << "Average: " << score[indexOfGoodStudent[i]][j] << endl;
        }
    }
}

static void exercise_16(void) {
    cout << "Input a string:" << endl;
    int index = 0, total = -1, number = 0, a[10];
    char str[50], *wp = str;
    while ((str[index] = getchar()) != '\n') ++index;
    for (int i = 0; i <= index; ++i) {
        if (str[i] >= '0' && str[i] <= '9') {
            if (total == -1) {
                total = *wp - 48;
            }
            else {
                total = total*10 + *wp - 48;
            }
        } else {
            if (total != -1) {
                a[number++] = total;
                total = -1;
            }
        }
        ++wp;
    }
    cout << "Seperated numbers are:" << endl;
    for (int i = 0; i < number; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

static void exercise_17(void) {
    void p_strcmp(char *s1, char*s2);
        
    cout << "Input 2 strings:" << endl;
    char a[20], b[20];
    gets(a);
    gets(b);
    p_strcmp(a, b);
}

void p_strcmp(char *s1, char*s2) {
    int i = 0;
    while (*(s1 + i) == *(s2 + i)) {
        if (*(s1 + i) == '\0') break;
        ++i;
    }
    cout << "Result:" << *(s1 + i) - *(s2 + i) << endl;
}

static void exercise_18(void) {
    cout << "Input month:" << endl;
    int month;
    cin >> month;
    string nameOfMonths[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    if (month < 1 || month > 12) cout << "Fucking month." << endl;
    else cout << *(nameOfMonths+month-1) << endl;
}

static void exercise_19(void) {
    void sortStrings(char **strings);
    
    cout << "Input 5 strings:" << endl;
    char a[5][20], *pa[5], **p = pa;
    for (int i = 0; i < 5; ++i) {
        pa[i] = a[i];
        cin >> pa[i];
    }
    sortStrings(p);
    for (int i = 0; i < 5; ++i) {
        cout << pa[i] << endl;
    }
}

void sortStrings(char **strings) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4 - i; ++j) {
            if (strcmp(*(strings + j), *(strings + j + 1)) > 0) {
                char *tmp = *(strings + j);
                *(strings + j) = *(strings + j + 1);
                *(strings + j + 1) = tmp;
            }
        }
    }
}

static void exercise_20(void) {
    void sortNumbers(int **numbers, int n);
    
    cout << "Input n:" << endl;
    int n;
    cin >> n;
    int *p_numbers[n], numbers[n], **p;
    cout << "Input " << n << " numbers:" << endl;
    for (int i = 0; i < n; ++i) {
        p_numbers[i] = &numbers[i];
        cin >> *p_numbers[i];
    }
    p = p_numbers;
    sortNumbers(p, n);
    cout << "Sorted numbers:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << *p_numbers[i] << ' ';
    }
    cout << endl;
}

void sortNumbers(int **numbers, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (**(numbers + j) > **(numbers + j + 1)) {
                int *tmp = *(numbers + j);
                *(numbers + j) = *(numbers + j + 1);
                *(numbers + j + 1) = tmp;
            }
        }
    }
}
