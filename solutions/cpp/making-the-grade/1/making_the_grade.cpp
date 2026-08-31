#include <array>
#include <string>
#include <vector>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    std::vector<int> results;
    // TODO: Implement round_down_scores
    for(auto itr:student_scores)
    {
        results.emplace_back(static_cast<int>(itr));
    }
    return results;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    // TODO: Implement count_failed_students
    int counter=0;
    for(auto itr:student_scores)
        {
            if(itr <= 40)
            {
                counter++;
            }
        }
    return counter;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    // TODO: Implement letter_grades
    int increment = (highest_score - 40) / 4;
    std::array<int,4> grades;
    grades[0] = 41;
    grades[1] =  grades[0] + increment;
    grades[2] =  grades[1] + increment;
    grades[3] =  grades[2] + increment;
    return grades;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names) {
    // TODO: Implement student_ranking
    int n = student_scores.size();
    std::vector<std::string> match;
    for(int i=0;i<n;i++)
        {
            match.emplace_back(std::to_string(i+1)+". " + student_names[i]+": "+std::to_string(student_scores[i]));
        }
        
    return match;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {
    // TODO: Implement perfect_score
    for (size_t i = 0; i < student_scores.size(); ++i) {
        if (student_scores[i] == 100) {
            return student_names[i];
        }
    }
    return "";
}
