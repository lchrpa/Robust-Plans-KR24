#include "SAS_relaxed_assignment.hpp"

SAS_Relaxed_Assignment::SAS_Relaxed_Assignment(SAS_Assignment assignment, const std::vector<SAS_Variable_Info> varinfo){

    for (auto var : varinfo){
        _assignment[var.get_id()]=std::vector<bool>(var.get_range(),false);
    }

    for (auto assgn : assignment){
        _assignment[assgn.first][assgn.second]=true;
    }

}

void SAS_Relaxed_Assignment::set(size_t variable, size_t value)
{
    _assignment[variable][value]=true;
}

const std::vector<bool> SAS_Relaxed_Assignment::get(size_t variable) const
{
    auto it = _assignment.find(variable);
    if (it != _assignment.end())
    {
        return it->second;
    }
    else
    {
        throw std::out_of_range("Assignment does not contain given key " + std::to_string(it->first) + ".");
    }
}


bool SAS_Relaxed_Assignment::empty() const
{
    return _assignment.empty();
}

bool SAS_Relaxed_Assignment::contains(size_t variable) const
{
    auto it = _assignment.find(variable);
    return it != _assignment.end();
}

void SAS_Relaxed_Assignment::apply(const SAS_Assignment &a)
{
    for (auto &it : a)
    {
        set(it.first, it.second);
    }
}

void SAS_Relaxed_Assignment::strict_apply(const SAS_Assignment &a)
{
    for (auto &it : a)
    {
        _assignment[it.first].assign(_assignment[it.first].size(),false);
        set(it.first, it.second);
    }
}

size_t SAS_Relaxed_Assignment::size() const
{
    return _assignment.size();
}

bool SAS_Relaxed_Assignment::satisfy(size_t variable, size_t value) const
{
    auto it = _assignment.find(variable);
    if (it != _assignment.end())
    {
        return it->second[value];
    }
    else
    {
        return false;
    }
}

bool SAS_Relaxed_Assignment::satisfy_all(const SAS_Assignment &assignment) const
{
    for (auto &it : assignment)
    {
        if (!satisfy(it.first, it.second))
        {
            return false;
        }
    }
    return true;
}

bool SAS_Relaxed_Assignment::satisfied_by(const SAS_Assignment &other_assignment) const
{
    return satisfy_all(other_assignment);
}

bool SAS_Relaxed_Assignment::multiple_values(size_t variable) const
{
    auto it = _assignment.find(variable);
    if (it != _assignment.end())
    {
        bool someval=false;
        for (auto it2 : it->second){
            if (it2){
                if (someval) return true;
                    else someval=true;
            }
        }
    }

    return false;

}

bool SAS_Relaxed_Assignment::exist_multiple_value_variable(const SAS_Assignment& assignment) const
{
    for (auto ass: assignment){
        if (multiple_values(ass.first)) return true;
    }
    return false;
}

bool SAS_Relaxed_Assignment::match_all(const SAS_Relaxed_Assignment& rass) const
{
    for (auto ass: _assignment){
        if (ass.second!=rass.get(ass.first)) return false;
    }
    return true;

}


