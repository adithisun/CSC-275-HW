/*************************************************************************
** Author : Adithi Sunke
** Program : hw2 q1
** Date Created : Feb 20th, 2025
** Date Last Modified : Feb 20th, 2025
** Usage : No command line arguments
**
** Problem:
 - Implement a Checkbook system where users can write checks, deposit money,
   and track their balance. The system dynamically expands the checkbook size
   as needed.
*************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

//check structure
struct Check {
    int CheckNum;
    string CheckMemo;
    float CheckAmount;
