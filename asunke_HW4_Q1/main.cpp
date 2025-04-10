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

//struct for profile
struct Profile {
    int userId;
    string username;

    //for printing
    friend ostream& operator<<(ostream& os, const Profile& p) {
        os << "[" << p.userId << "] " << p.username;
        return os;
    }
};

int main() {
    //twitter string account
    Twitter<string> TS("TechGuru", false);
    TS.addFollower("Alice");
    TS.addFollowed("Bob");
    TS.RT();
    TS.displayFollowers();
    TS.displayFollowed();
    cout << "Retweets: " << TS.getRetweetCount() << endl << endl;

    //twitter profile account
    Profile p1 = {1, "cooldev"};
    Profile p2 = {2, "coder123"};

    Twitter<Profile> TP(p1, false);
    TP.addFollower(p2);
    TP.displayFollowers();
    TP.RT();
    cout << "Retweets: " << TP.getRetweetCount() << endl << endl;

    //instagram string account
    Instagram<string> IS("PhotoQueen", false);
    IS.addFollower("ShutterBug");
    IS.Like();
    IS.displayFollowers();
    cout << "Likes: " << IS.getLikeCount() << endl << endl;

    // instagram profile account
    Profile p3 = {3, "snapguy"};
    Instagram<Profile> IP(p3, true); //private account
    Profile p4 = {4, "lenslady"};
    IP.addFollower(p4);
    IP.displayFollowers(); //will show protected message
    IP.Like();
    cout << "Likes: " << IP.getLikeCount() << endl;

    return 0;
}
