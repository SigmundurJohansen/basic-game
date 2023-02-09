#pragma once

#include <string>
#include <vector>

enum item_type
{
    empty = 0,
    helmet,
    armor,
    amulet,
    cloak,
    ring,
    belt,
    weapon,
    shield,
    boots,
    arrow,
    bolt,
    bullet,
    book,
    potion,
    scroll,
    crossbow,
    sling,
    container,
    wand,
    misc
};

enum Ability
{
    none = 0,
    strength,
    dexterity,
    constitution,
    intelligence,
    wisdom,
    charisma,
    saves,
    crit_immunity,
    damage,
    thac0
};

std::vector<std::string> abilityToString = { "none", "strength", "dexterity", "constitution", "intelligence", "wisdom", "charisma", "saves", "crit_immunity", "damage", "thac0"};

struct ItemEnchantment
{
    Ability m_ability = none;
    int m_modifier = 0;
    std::string m_item_info = "item info";

    ItemEnchantment(Ability _ability, int _modifier)
    {
        m_ability = _ability;
        m_modifier = _modifier;
    }
};

struct Item
{
    item_type m_type;
    std::string m_name = "unknown item";
    std::vector<ItemEnchantment> m_bonuses;

    void AddEnchantment(ItemEnchantment _enchantment) { m_bonuses.emplace_back(_enchantment); }
    void PrintStats()
    {        
        std::cout << m_name << "\n";
        for(int i = 0; i<m_bonuses.size(); i++)
            std::cout << "Enchantment "<< i+1 << " : " << abilityToString[m_bonuses[i].m_ability] << " +" << m_bonuses[i].m_modifier << "\n";
    }
    //void RemoveEnchantments() { m_bonuses.empty(); }
};

struct EmptySpace : Item
{
    item_type m_type = empty;
    //EmptySpace(item_type _type) { m_item.m_type = _type; }
};

struct Helmet : Item
{
    item_type m_type = helmet;
    std::vector<ItemEnchantment> m_bonuses;
    //Helmet() { m_bonuses.emplace_back(Ability(crit_immunity)); }
};
