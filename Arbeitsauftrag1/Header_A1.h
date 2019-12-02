#pragma once
#ifndef _HEADER_H_
#define _HEADER_H_

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#include <stdlib.h>
#include <stdio.h>
#pragma once
#include <iostream>
#include <iomanip> // wird benötigt für die Manipulatoren
//#include <time.h>
#include <string.h>
//#include <numeric>   // std::iota  Iterator
#endif

// C++-Version:
const unsigned char AE = static_cast<unsigned char>(142);
const unsigned char ae = static_cast<unsigned char>(132);
const unsigned char OE = static_cast<unsigned char>(153);
const unsigned char oe = static_cast<unsigned char>(148);
const unsigned char UE = static_cast<unsigned char>(154);
const unsigned char ue = static_cast<unsigned char>(129);
const unsigned char ss = static_cast<unsigned char>(225);
// Verwendungsbeispiel
//cout << UE << "bung macht den Meister!" << endl;


void menu(int* button, int* entry, struct Student* studenten);
int add_person(struct Student* studenten, int** entry);
int show_person(struct Student* studenten, int** entry, char* chr);
void find_student(struct Student* studenten,char* chr);
void delete_entry(struct Student* studenten, int** entry);