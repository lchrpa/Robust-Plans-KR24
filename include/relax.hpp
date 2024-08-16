#ifndef __relax__
#define __relax__

#include <vector>
#include <deque>
#include <list>
#include <SAS_problem.hpp>
#include <SAS_plan.hpp>
#include <SAS_operator.hpp>
#include <SAS_event.hpp>
#include <RPG.hpp>

struct search_node{
    //search_node(SAS_State s, SAS_Relaxed_Assignment f,std::vector<std::reference_wrapper<SAS_Operator>> pi) : _s(s), _f(f), _pi(pi){};
    search_node(SAS_Relaxed_Assignment f,std::vector<std::reference_wrapper<SAS_Operator>> pi) : _f(f), _pi(pi){};
    //SAS_State _s;
    SAS_Relaxed_Assignment _f;
    std::vector<std::reference_wrapper<SAS_Operator>> _pi;
};

class relax {
public:
    relax(SAS_Problem prob, SAS_Plan plan) : _problem(prob), _plan(plan){};
    relax(SAS_Problem prob) : _problem(prob), _plan(NULL){};
    bool check_robustness();
    bool generate_robust_plan();
    inline SAS_Plan &get_plan(){return _plan;}

private:

    SAS_Problem _problem;
    SAS_Plan _plan;
    bool is_duplicite(const SAS_Relaxed_Assignment &s, std::list<SAS_Relaxed_Assignment> &states);
    std::set<size_t> only_effect_variables;
    void look_for_only_effect_variables(const std::vector<SAS_Action> &actions);
    bool is_deadend(const SAS_Relaxed_Assignment &s);
};


#endif
