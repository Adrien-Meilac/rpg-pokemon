#include "PKMN_Type.h"

PKMN_Type::PKMN_Type():
    m_Name(),
    m_InternalName(),
    m_Weaknesses(),
    m_Immunities(),
    m_Resistances(),
    m_IsSpecialType()
{

}

PKMN_Type::PKMN_Type(std::string Name,
                    std::string InternalName,
                    std::string Weaknesses,
                    std::string Immunities,
                    std::string Resistances,
                    std::string IsSpecialType)
{
    m_Name = Name;
    m_InternalName = InternalName;
    m_Weaknesses = string_split(Weaknesses, ',');
    m_Immunities = string_split(Immunities, ',');
    m_Resistances = string_split(Resistances, ',');
    m_IsSpecialType = string_to_bool(IsSpecialType);
}

PKMN_Type::PKMN_Type(std::vector<std::string> Line)
{
    std::string Name = Line[0];
    std::string InternalName = Line[1];
    std::string Weaknesses = Line[2];
    std::string Immunities = Line[3];
    std::string Resistances = Line[4];
    std::string IsSpecialType = Line[5];
    m_Name = Name;
    m_InternalName = InternalName;
    m_Weaknesses = string_split(Weaknesses, ',');
    m_Immunities = string_split(Immunities, ',');
    m_Resistances = string_split(Resistances, ',');
    m_IsSpecialType = string_to_bool(IsSpecialType);
}

double PKMN_Type::effectiveness(PKMN_Type const Type_att) const
{
    double typeMultiplicativeFactor = NORMAL_EFFECTIVENESS;
    if(vector_in(m_Immunities, Type_att.m_InternalName))
    {
        typeMultiplicativeFactor = INEFFECTIVE;
    }
    else if(vector_in(m_Weaknesses, Type_att.m_InternalName))
    {
        typeMultiplicativeFactor = SUPER_EFFECTIVE;
    }
    else if(vector_in(m_Resistances, Type_att.m_InternalName))
    {
        typeMultiplicativeFactor = NOT_VERY_EFFECTIVE;
    }

    return typeMultiplicativeFactor;
}

double PKMN_Type::effectiveness(std::pair<PKMN_Type, PKMN_Type> PairType_att) const
{
    return this->effectiveness(PairType_att.first) * this->effectiveness(PairType_att.second);
}

std::string PKMN_Type::getName() const
{
    return m_Name;
}

std::string PKMN_Type_message(double typeMultiplicativeFactor)
{
    std::string message("");
    if(typeMultiplicativeFactor == INEFFECTIVE)
    {
        message = "It's totally ineffective !";
    }
    else if(typeMultiplicativeFactor < NORMAL_EFFECTIVENESS)
    {
        message = "It's not very effective !";
    }
    else if(typeMultiplicativeFactor > NORMAL_EFFECTIVENESS)
    {
        message = "It's super effective !";
    }
    return message;
}

std::string PKMN_Type::getInternalName() const
{
    return m_InternalName;
}
std::vector<std::string> PKMN_Type::getWeaknesses() const
{
    return m_Weaknesses;
}

std::vector<std::string> PKMN_Type::getImmunities() const
{
    return m_Immunities;
}

std::vector<std::string> PKMN_Type::getResistances() const
{
    return m_Resistances;
}
