//
// Created by Adithi Sunke on 4/6/25.
//

#ifndef ASUNKE_HW4_Q1_TWITTER_H
#define ASUNKE_HW4_Q1_TWITTER_H

#include "SocialMediaAccount.h"

template <typename T>
class Twitter : public SocialMediaAccount<T> {
private:
    int retweetCount;

public:
    Twitter() : SocialMediaAccount<T>(), retweetCount(0) {}

    Twitter(T handler, bool isPrivate = true)
            : SocialMediaAccount<T>(handler, isPrivate), retweetCount(0) {}

    void RT() { retweetCount++; }

    void setRetweetCount(int count) { retweetCount = count; }

    int getRetweetCount() const { return retweetCount; }
};

#endif //ASUNKE_HW4_Q1_TWITTER_H
