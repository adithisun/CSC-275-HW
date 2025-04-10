//
// Created by Adithi Sunke on 4/9/25.
//

#ifndef ASUNKE_HW4_Q1_INSTAGRAM_H
#define ASUNKE_HW4_Q1_INSTAGRAM_H

#include "SocialMediaAccount.h"

template <typename T>
class Instagram : public SocialMediaAccount<T> {
private:
    int likeCount;

public:
    Instagram() : SocialMediaAccount<T>(), likeCount(0) {}

    Instagram(T handler, bool isPrivate = true)
            : SocialMediaAccount<T>(handler, isPrivate), likeCount(0) {}

    void Like() { likeCount++; }

    void setLikeCount(int count) { likeCount = count; }

    int getLikeCount() const { return likeCount; }
};

#endif //ASUNKE_HW4_Q1_INSTAGRAM_H
