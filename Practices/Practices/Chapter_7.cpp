//
//  Chapter_7.cpp
//  Practices
//
//  Created by Songyu on 2020/2/11.
//  Copyright © 2020 Songyu. All rights reserved.
//

#include "Chapter_7.h"

static void practice_1(void);
static void practice_2(void);
static void practice_3(void);
static void practice_4(void);
static void practice_5(void);
static void practice_6(void);
static void practice_7(void);
static void practice_8(void);
static void practice_9(void);
static void practice_10(void);
static void practice_11(void);

void Chapter_7_practice(int number) {
    switch (number) {
        case 1: {
            practice_1();
        } break;
        case 2: {
            practice_2();
        } break;
        case 3: {
            practice_3();
        } break;
        case 4: {
            practice_4();
        } break;
        case 5: {
            practice_5();
        } break;
        case 6: {
            practice_6();
        } break;
        case 7: {
            practice_7();
        } break;
        case 8: {
            practice_8();
        } break;
        case 9: {
            practice_9();
        } break;
        case 10: {
            practice_10();
        } break;
        case 11: {
            practice_11();
        } break;
        default: {
            cout << "Shit practice number!" << endl;
        } break;
    }
}

struct date {
    int year;
    int month;
    int day;
} testDate;

static void practice_1(void) {
    bool isLeapYear(int year);
    
    cout << "Input year, month and day:" << endl;
    cin >> testDate.year >> testDate.month >> testDate.day;
    if (testDate.year < 0 || testDate.month < 0 || testDate.month > 12 || testDate.day < 0 || testDate.day > 31) {
        cout << "Fucking date." << endl;
        return;
    }
    int dayOfMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, total = 0;
    if (isLeapYear(testDate.year)) dayOfMonth[1] = 29;
    for (int i = 0; i < testDate.month; ++i)
        total += dayOfMonth[i];
    total += testDate.day;
    cout << testDate.year << '/' << testDate.month << '/' << testDate.day << " is the " << total << "th day of the year." << endl;
}

bool isLeapYear(int year) {
    bool result = false;
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) result = true;
    return result;
}

static void practice_2(void) {
    int days(int year, int month, int day);
    
    cin >> testDate.year >> testDate.month >> testDate.day;
    days(testDate.year, testDate.month, testDate.day);
}

int days(int year, int month, int day) {
    cout << "Input year, month and day:" << endl;
    if (year < 0 || month < 0 || month > 12 || day < 0 || day > 31) {
        cout << "Fucking date." << endl;
        return -1;
    }
    int dayOfMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, total = 0;
    if (isLeapYear(year)) dayOfMonth[1] = 29;
    for (int i = 0; i < month; ++i)
        total += dayOfMonth[i];
    total += day;
    cout << year << '/' << month << '/' << day << " is the " << total << "th day of the year." << endl;
    return total;
}

struct Student {
    int num;
    string name;
    float score[3];
} s, *p;

static void practice_3(void) {
    void print(Student s);
    
    cin >> s.num >> s.name >> s.score[0] >> s.score[1] >> s.score[2];
    print(s);
}

void print(Student s) {
    cout << endl << s.num << endl << s.name << endl << s.score[0] << ' ' << s.score[1] << ' ' << s.score[2] << endl;
}

static void practice_4(void) {
    void input(Student *p);
    
    input(p);
    print(*p);
}

void input(Student *p) {
    cout << endl << (*p).num << endl << (*p).name << endl << (*p).score[0] << ' ' << (*p).score[1] << ' ' << (*p).score[2] << endl;
}

static void practice_5(void) {
    Student a[10];
    int maxIndex = 0;
    float average[] = {0.f, 0.f, 0.f}, maxScore = 0.f;
    for (int i = 0; i < 10; ++i) {
        int score = 0;
        cout << "Input No." << i + 1 << " student's infomation:" << endl;
        cin >> a[i].num >> a[i].name >> a[i].score[0] >> a[i].score[1] >> a[i].score[2];
        score += a[i].score[0] + a[i].score[1] + a[i].score[2];
        average[0] += a[i].score[0];
        average[1] += a[i].score[1];
        average[2] += a[i].score[2];
        if (score > maxScore) {
            maxScore = score;
            maxIndex = i;
        }
    }
    average[0] /= 10;
    average[1] /= 10;
    average[2] /= 10;
    cout << "Averages of 3 subjects: " << endl;
    cout << average[0] << endl << average[1] << endl << average[2] << endl;
    cout << "Best student:" << endl;
    print(a[maxIndex]);
}

struct Node {
    int value;
    Node *next = NULL;
};

static void practice_6(void) {
    Node * create(void);
    
    Node *p = create();
    while (p != NULL) {
        cout << p->value << endl;
        p = p->next;
    }
    cout << "End" << endl;
}

Node * create(void) {
    cout << "Input linked list(-1 to quit):" << endl;
    Node *head = NULL, *p = new Node;
    while (true) {
        Node *next = new Node;
        cin >> next->value;
        if (next->value == -1) {
            p->next = NULL;
            break;
        }
        if (head == NULL) {
            head = next;
            p = next;
        } else {
            p->next = next;
            p = next;
        }
    }
    return head;
}

static void practice_7(void) {
    void printLinkedList(Node *head);
    
    Node *head = create(), *p;
    p = head;
    printLinkedList(p);
}

void printLinkedList(Node *head) {
    while (head != NULL) {
        cout << head->value << endl;
        head = head->next;
    }
    cout << "End" << endl;
}

static void practice_8(void) {
    Node *del(Node *head ,int value);
    
    Node *head = create();
    head = del(head, 4);
    printLinkedList(head);
}

Node *del(Node *head, int value) {
    if (head == NULL) {
        cout << "Empty list!" << endl;
        return head;
    }
    Node *p = head, *pre = NULL;
    while (p != NULL) {
        if (p->value == value) {
            Node *tmp;
            if (p == head) {
                tmp = head;
                head = head->next;
                p = head;
            } else {
                tmp = p;
                p = p->next;
                if (pre != NULL) pre->next = p;
            }
            delete tmp;
            continue;
        }
        pre = p;
        p = p->next;
    }
    return head;
}

static void practice_9(void) {
    Node *insert(Node *head, int value);
    
    Node *head = create();
    head = insert(head, 10);
    printLinkedList(head);
}

Node *insert(Node *head, int value) {
    /* 升序插入 */
    Node *p = head, *pre = NULL;
    if (head == NULL) {
        cout << "Empty list!" << endl;
        return head;
    }
    while (p != NULL) {
        Node *n = new Node;
        n->value = value;
        if (p->value >= value) {
            if (p == head) { // 比表头小
                n->next = head;
                head = n;
            } else {
                n->next = p;
                pre->next = n;
            }
            break;
        } else {
            if (p->next == NULL) { // 比表尾大
                p->next = n;
                break;
            }
        }
        pre = p;
        p = p->next;
    }
    return head;
}

static void practice_10(void) {
    Node *head = create();
    head = insert(head, 10);
    printLinkedList(head);
    head = del(head, 10);
    printLinkedList(head);
}

typedef enum {
    Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday
} WEEKDAY;

static void practice_11(void) {
    WEEKDAY weekday = *new WEEKDAY; // 不初始化不行？
    char ch = 'A';
    int a, b, c, d, e, f, g, loop;
    f = Thursday;
    for (a = Sunday; a <= Saturday; ++a) {
        if (a != f) { // A的条件
            for (b = Sunday; b <= Saturday; ++b) {
                if (b != a && f > b) { // B的条件
                    for (c = Sunday; c <= Saturday; ++c) {
                        if (c != a && c != b && c != f && (a == c + 1)) { // C的条件
                            for (d = Sunday; d <= Saturday; ++d) {
                                if (d != a && d != b && d != f && (c == d + 3)) { // D的条件
                                    for (e = Sunday; e <= Saturday; ++e) {
                                        if (e != a && e != b && e != c && e != d && e != f && (d == e + 2)) { // E的条件
                                            for (g = Sunday; g <= Saturday; ++g) {
                                                if (g != a && g != b && g != c && g != d && g != e && g != f && (g == b + 2)) { // G的条件
                                                    for (loop = 0; loop < 7; ++loop) { // 全满足时输出结果
                                                        cout << "Doctor " << char(ch + loop) << ": ";
                                                        switch (loop) { // 先强制类型转换为 WEEKDAY 枚举型
                                                            case 0: weekday = WEEKDAY(a); break;
                                                            case 1: weekday = WEEKDAY(b); break;
                                                            case 2: weekday = WEEKDAY(c); break;
                                                            case 3: weekday = WEEKDAY(d); break;
                                                            case 4: weekday = WEEKDAY(e); break;
                                                            case 5: weekday = WEEKDAY(f); break;
                                                            case 6: weekday = WEEKDAY(g); break;
                                                        }
                                                        switch (weekday) { // 再转为字符串输出
                                                            case Sunday: cout << "Sunday" << endl; break;
                                                            case Monday: cout << "Monday" << endl; break;
                                                            case Tuesday: cout << "Tuesday" << endl; break;
                                                            case Wednesday: cout << "Wednesday" << endl; break;
                                                            case Thursday: cout << "Thursday" << endl; break;
                                                            case Friday: cout << "Friday" << endl; break;
                                                            case Saturday: cout << "Saturday" << endl; break;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
