// author: Danila "akshin_" Axyonov

#ifndef CONTESTPARTICIPANT__HPP
#define CONTESTPARTICIPANT__HPP

#include <cstdlib>
#include <iostream>

namespace algoses {
namespace lab1 {



class ContestParticipant
{
private:
    static int next_id;

    const int SOLVED_MIN = 0;
    const int SOLVED_MAX = 5;
    const int TIME_MIN   = 60;
    const int TIME_MAX   = 300;
    const int SCORE_MIN  = 0;
    const int SCORE_MAX  = 25;
    const int FAILS_MIN  = 0;
    const int FAILS_MAX  = 20;

public:
    static int randint(int l, int r) {
        return l + rand() % (r - l + 1);
    }

    int id;
    int solved;
    int time;
    int score;
    int fails;

    ContestParticipant();
    bool operator==(const ContestParticipant& obj) const;
    bool operator!=(const ContestParticipant& obj) const;
    bool operator<(const ContestParticipant& obj) const;
    bool operator<=(const ContestParticipant& obj) const;
    bool operator>(const ContestParticipant& obj) const;
    bool operator>=(const ContestParticipant& obj) const;

    friend std::ostream& operator<<(std::ostream& out, const ContestParticipant& obj);

    static void print_header();
    static void print_footer();
};



}}

#endif
