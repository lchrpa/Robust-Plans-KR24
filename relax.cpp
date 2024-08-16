#include<deque>

#include "relax.hpp"

bool relax::check_robustness(){

    //get events into ops (vector of SAS_Operator)
    std::vector<SAS_Event> events=_problem.get_events();
    std::vector<SAS_Operator> ops;
    for (std::vector<SAS_Event>::iterator it=events.begin();it!=events.end();it++){
        //std::cout << it->get_name() << ", ";
        ops.push_back(SAS_Operator(*it));
    }

     //RPG
    SAS_Relaxed_Assignment f(_problem.get_init().get_assignment(),_problem.get_variables());
    //RPG rpg(rinit,ops);
    //SAS_Relaxed_Assignment f=rinit;

   //check actions
    for (auto a : _plan){
        RPG rpg(f,ops);
        rpg.buildRPG();
        //rpg.debug_print_layers();
        SAS_Assignment pre=a.get().get_preconditions();
        f=rpg.getLastAtomLayer();
        if (!f.satisfy_all(pre)||f.exist_multiple_value_variable(pre)) return false;
        f.strict_apply(a.get().get_minimal_effects());
    }
    //check goal
     RPG rpg(f,ops);
        rpg.buildRPG();
        //rpg.debug_print_layers();
        f=rpg.getLastAtomLayer();
        if (!f.satisfy_all(_problem.get_goal().get_assignment())||f.exist_multiple_value_variable(_problem.get_goal().get_assignment())) return false;

    return true;
}

void relax::look_for_only_effect_variables(const std::vector<SAS_Action>& actions)
{
    for (auto act : actions){
        for (auto e : act.get_minimal_effects()){
            if (!act.get_preconditions().contains(e.first)) only_effect_variables.insert(e.first);
        }
    }
}


bool relax::is_duplicite(const SAS_Relaxed_Assignment& s, std::list<SAS_Relaxed_Assignment>& states)
{
    for (auto st : states){
        if (s.match_all(st)) return true;
    }
    return false;
}

bool relax::is_deadend(const SAS_Relaxed_Assignment& s)
{
    for (auto g : _problem.get_goal().get_assignment()){
        if (only_effect_variables.find(g.first)==only_effect_variables.end() && s.multiple_values(g.first)) return true;
    }
    return false;
}


bool relax::generate_robust_plan()
{
        //get events into ops (vector of SAS_Operator)
    std::vector<SAS_Event> events=_problem.get_events();
    std::vector<SAS_Operator> ops;
    for (std::vector<SAS_Event>::iterator it=events.begin();it!=events.end();it++){
        //std::cout << it->get_name() << ", ";
        ops.push_back(SAS_Operator(*it));
    }

    //actions
    std::vector<SAS_Action> actions=_problem.get_actions();
    look_for_only_effect_variables(actions);

     //RPG
    SAS_Relaxed_Assignment init(_problem.get_init().get_assignment(),_problem.get_variables());

    std::deque<search_node> search_queue;
    std::list<SAS_Relaxed_Assignment> expanded;
    search_queue.push_back(search_node(init,std::vector<std::reference_wrapper<SAS_Operator>>()));
    while (!search_queue.empty()){
        search_node s=search_queue.front();
        search_queue.pop_front();
        if (is_deadend(s._f) || is_duplicite(s._f,expanded)) continue;
        expanded.push_back(s._f);
         RPG rpg(s._f,ops);
        rpg.buildRPG();

        SAS_Relaxed_Assignment f=rpg.getLastAtomLayer();


        //check goal
        if (f.satisfy_all(_problem.get_goal().get_assignment())&&!f.exist_multiple_value_variable(_problem.get_goal().get_assignment())){
            //debug
            for (auto a : s._pi){
                std::cout << a.get().get_name() << std::endl;
            }

            _plan=SAS_Plan(&_problem,s._pi);
            return true;
        }

        //expanding
        for (auto a : actions){

            //check applicability
            if (f.satisfy_all(a.get_preconditions())&&!f.exist_multiple_value_variable(a.get_preconditions())){
                /*
                std::vector<std::reference_wrapper<SAS_Operator>> seq=s._pi;
                seq.emplace_back(a);
                SAS_Relaxed_Assignment fx=f;
                fx.strict_apply(a.get_minimal_effects());
                search_queue.push_back(search_node(fx,seq));
                std::cout << search_queue.back()._pi.front().get().get_name() << std::endl;
                */

                search_node node(f,s._pi);
                node._f.strict_apply(a.get_minimal_effects());
                //node._s.apply(a.get_minimal_effects());
//                std::cout << "depth: " << s._pi.size() << ", action: " << a.get_name() << std::endl;
                node._pi.emplace_back(_problem.find_operator_by_name(a.get_name()));
                //std::cout << node._pi.back().get().get_name() << std::endl;
                search_queue.push_back(node);

                //debug
  /*
                for (auto x : search_queue.back()._pi){
                  std::cout << x.get().get_name() << ", ";
                }
                std::cout << std::endl;
                //std::cout << search_queue.back()._pi.front().get().get_name() << std::endl;
*/
            }

        }

    }
    return false;
}

