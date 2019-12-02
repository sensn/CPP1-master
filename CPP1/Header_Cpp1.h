#pragma once
#ifndef _HEADER_H_
#define _HEADER_H_

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <iomanip> // wird benötigt für die Manipulatoren
#include <time.h>
#include <string.h>

#include <numeric>   // std::iota  Iterator
#endif

#define MAX(A,B) ( (A) > (B) ? (A) : (B) )

using namespace std;
void  Person_main();

void ausgabe();
void eingabe();

void eingabe_string();
void eingabe_string_getline();

void test_iota();

void vorfunc();
void show(int = 1, float = 2.3, long = 4);

void scope_main();


void test_inline_func();
inline int max(int, int);

void test_const();

void test_enum();

void test_overload();
void DisplayTime(const struct tm*);
void DisplayTime(const time_t*);

void test_overload_strcopy();
inline void stringcopy(char*, const char*);
inline void stringcopy(char*, const char*, int);

//QSORT Array of char pointers
void test_extern_C();
extern "C" int comp(const void*, const void*);

void test_referenz();