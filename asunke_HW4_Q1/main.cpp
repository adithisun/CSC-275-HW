/*************************************************************************
** Author: Adithi Sunke
** Program: HW4, Q1
** Date Created: April 4, 2025
** Date Last Modified: April 9, 2025
**
** Problem:
- Create a class template to manage followers and
  followed accounts with privacy controls
*************************************************************************/

#include <iostream>
#include "Twitter.h"
#include "Instagram.h"

using namespace std;

struct Profile {
    int userId;
    string username;

    friend ostream& operator<<(ostream& os, const Profile& p) {
        os << "[" << p.userId << "] " << p.username;
        return os;
    }
};

