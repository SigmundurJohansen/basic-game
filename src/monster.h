#pragma once

class Monster{
    public:
    Monster(std::string _name){m_name = _name;};
    std::string GetName(){return m_name;}
    private:
    std::string m_name = "no name";
};