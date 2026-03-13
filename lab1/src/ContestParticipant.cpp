// author: Danila "akshin_" Axyonov

#include "../include/ContestParticipant.hpp"

#include <iostream>
#include <iomanip>

namespace algoses {
namespace lab1 {



int ContestParticipant::next_id = 0;

ContestParticipant::ContestParticipant() {
    id = next_id++;
    solved = randint(SOLVED_MIN, SOLVED_MAX);
    time = randint(TIME_MIN, TIME_MAX);
    score = randint(SCORE_MIN, SCORE_MAX);
    fails = randint(FAILS_MIN, FAILS_MAX);
}

bool ContestParticipant::operator==(const ContestParticipant& obj) const {
    return solved == obj.solved
       and time   == obj.time
       and score  == obj.score
       and fails  == obj.fails;
}

bool ContestParticipant::operator!=(const ContestParticipant& obj) const {
    return not (*this == obj);
}

bool ContestParticipant::operator<(const ContestParticipant& obj) const {
    if (score != obj.score)
        return score < obj.score;
    if (solved != obj.solved)
        return solved < obj.solved;
    if (time != obj.time)
        return time < obj.time;
    return fails > obj.fails;
}

bool ContestParticipant::operator<=(const ContestParticipant& obj) const {
    return *this < obj or *this == obj;
}

bool ContestParticipant::operator>(const ContestParticipant& obj) const {
    return not (*this <= obj);
}

bool ContestParticipant::operator>=(const ContestParticipant& obj) const {
    return not (*this < obj);
}

std::ostream& operator<<(std::ostream& out, const ContestParticipant& obj) {
    out << '|' << std::setw(2 + 2) << obj.id
        << '|' << std::setw(6 + 2) << obj.solved
        << '|' << std::setw(4 + 2) << obj.time
        << '|' << std::setw(5 + 2) << obj.score
        << '|' << std::setw(5 + 2) << obj.fails
        << '|' << std::endl;
    return out;
}

void ContestParticipant::print_header() {
    std::cout << "--------------------------------------" << std::endl
              << "| id | solved | time | score | fails |" << std::endl
              << "--------------------------------------" << std::endl;
}

void ContestParticipant::print_footer() {
    std::cout << "--------------------------------------" << std::endl;
}



}}
