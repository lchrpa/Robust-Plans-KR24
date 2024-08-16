#ifndef __RPG__
#define __RPG__

#include <vector>

#include "SAS_relaxed_assignment.hpp"
#include "SAS_assignment.hpp"
#include "SAS_variable_info.hpp"
#include "SAS_operator.hpp"

class RPG {

public:
    RPG(SAS_Relaxed_Assignment& init, std::vector< SAS_Operator >& ops);
    void buildRPG();

    std::vector<std::reference_wrapper<SAS_Operator>> getLastOpLayer();
    inline SAS_Relaxed_Assignment getLastAtomLayer() {return _atom_layer.back();};

    void debug_print_layers();

private:
    std::vector<SAS_Operator> _ops;
    std::vector<SAS_Relaxed_Assignment> _atom_layer;
    std::vector<std::vector<bool>> _op_layer;
    bool _fixed_point;

    std::vector<bool>  applicableOps();
    bool expandLayer(); //returns true if fixed point is reached
};


#endif
