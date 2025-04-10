//
// Created by Adithi Sunke on 4/4/25.
//

#ifndef ASUNKE_HW4_Q1_SOCIALMEDIAACCOUNT_H
#define ASUNKE_HW4_Q1_SOCIALMEDIAACCOUNT_H

#include <iostream>
using namespace std;

//global constants
const int maxFollowers = 100;
const int maxFollowed = 100;

//template class
template <typename T>
class SocialMediaAccount {
private:
    T handler;
    T followers[maxFollowers];
    T followed[maxFollowed];
    int followerCount;
    int followedCount;
    bool isPrivate;

public:
    //default constructor
    SocialMediaAccount() : followerCount(0), followedCount(0), isPrivate(true) {}

    //parametrized constructor
    SocialMediaAccount(T handler, bool isPrivate = true)
            : handler(handler), isPrivate(isPrivate), followerCount(0), followedCount(0) {}

    //setters and getters
    void setHandler(T h) { handler = h; }
    T getHandler() const { return handler; }

    void setPrivacy(bool privacy) { isPrivate = privacy; }
    bool getPrivacy() const { return isPrivate; }

    int getFollowerCount() const { return followerCount; }
    int getFollowedCount() const { return followedCount; }

    //add follower
    void addFollower(T user) {
        if (followerCount < maxFollowers) {
            followers[followerCount++] = user;
        }
    }

    //add followed account
    void addFollowed(T user) {
        if (followedCount < maxFollowed) {
            followed[followedCount++] = user;
        }
    }

    //display followers
    void displayFollowers() const {
        if (!isPrivate) {
            cout << "Followers:\n";
            for (int i = 0; i < followerCount; ++i) {
                cout << followers[i] << endl;
            }
        } else {
            cout << "Account is protected. Followers cannot be displayed.\n";
        }
    }

    //display followed accounts
    void displayFollowed() const {
        if (!isPrivate) {
            cout << "Followed Accounts:\n";
            for (int i = 0; i < followedCount; ++i) {
                cout << followed[i] << endl;
            }
        } else {
            cout << "Account is protected. Followed accounts cannot be displayed.\n";
        }
    }
};

#endif //ASUNKE_HW4_Q1_SOCIALMEDIAACCOUNT_H
