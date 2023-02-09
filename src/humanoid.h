#pragma once
#include <stdint.h>
#include <iostream>
#include "items.h"


struct Humanoid
{
    std::string m_name = "Human Male";
    // abilities
    int m_strength = 10;
    int m_dexterity = 10;
    int m_constitution = 10;
    int m_intelligence = 10;
    int m_wisdom = 10;
    int m_charisma = 10;
    // stats
    int m_health_pool = 10;
    int m_experience = 0;
    int m_movement_speed = 10;
    int m_armor_class = 10;
    int m_thac0 = 20;
    int m_reputation = 10;
    int m_gold = 0;
    int m_attacks = 1;
    int m_levels = 0;
    int m_morale_break = 3;
    int m_morale_recovery = 1;
    int m_fatigue = 0;
    int m_intoxication = 0;
    // skills
    int m_stealth = 0;
    int m_open_locks = 0;
    int m_pick_pockets = 0;
    int m_find_traps = 0;
    int m_set_traps = 0;
    int m_detect_illusion = 0;
    // characteristics
    bool m_gender = 0; // 0 male, 1 female
    int m_race = 0; //0 human
    int alignment = 0; // 0 evil, 1 neutral, 2 good
    int m_class = 0; // 0 fighter, 1 mage, 2 cleric, 3 rogue
    int m_kit = 0; // 0 base
    int m_faction = 0; //0 enemy, 1 pc, 2 ally 
    //                        acid, aid, beserk, blind, blur, bless, chant, chantbad
    //                               charmed, confused, dead, debuff, disabled, disabled casting, diseased
    //                                        drawuponholymight, exploding death, feebled minded, flame death, frozen death, harmless, hasted, helpless
    //                                                illusion, immobile, improved invisibility, infravision, invisible, luck, mirror image, nondetection
    //                                                       normal, non aproachable, not targetable, panic, poison, ranged target, really dead, silenced
    //                                                                sleeping, slowed, stone death, stunned
                            //        8       16      24     32       40      48      56     64
    uint64_t m_state_flags = 0b0000000100000001000000010000000100000001000000010000000100000001;

    // inventory
    // 0 helmet, 1 amulet, 2 armor, 3 cloak, 4 ringR, 5 ringL, 6 weapon, 7 shield, 8 belt, 9 boots, 10 quickslot_1, 11 quickslot_2, 12 quickslot_3 
    // 13 extra wep_1, 14 extra wep_2
    // 15 inventory_0, 16 inventory_1, 17 inventory_2, 18 inventory_3, 19 inventory_4, 20 inventory_5, 21 inventory_6, 22 inventory_7
    // 23 inventory_8, 24 inventory_9, 25 inventory_10, 26 inventory_11, 27 inventory_11, 28 inventory_12, 29 inventory_13, 30 inventory_14
    Item m_inventory[30];

    Humanoid()
    {
        for(int i = 0; i < 30; i++)
        {
            m_inventory[i] = EmptySpace();
        }
    }
    
    public:
    void PrintStat()
    {
        std::cout << m_name << "\n" << "gender: " << m_gender << "\n" << "weapon equipped: " << m_inventory[6].m_name << "\n";
        std::cout << "gold: " << m_gold << "\n" << "experinece: " << m_experience << "\n";
    }
};