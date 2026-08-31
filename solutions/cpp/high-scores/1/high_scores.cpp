#include "high_scores.h"

#include <algorithm>

namespace arcade {

std::vector<int> HighScores::list_scores() {
    // TODO: Return all scores for this session.
    return scores;
}

int HighScores::latest_score() {
    // TODO: Return the latest score for this session.
    return scores[scores.size()-1];
}

int HighScores::personal_best() {
    // TODO: Return the highest score for this session.
    int max=0;
    for(auto it : scores)
        if(it>max) max=it;
    return max;
}

std::vector<int> HighScores::top_three() {
    // TODO: Return the top 3 scores for this session in descending order.
    int first=-1,second=-1,third=-1;
    for(auto x : scores)
    {
        if(x>=first)
        {
            third=second;
            second=first;
            first=x;
        }
        else if(x>=second)
        {
            third=second;
            second=x;
        }
        else if(x>=third)
            third=x;
    }
    std::vector<int> result;
    if(first>-1) result.push_back(first);
    if(second>-1) result.push_back(second);
    if(third>-1) result.push_back(third);
    return result;
}

}  // namespace arcade
