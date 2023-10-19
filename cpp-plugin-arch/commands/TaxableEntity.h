#ifndef TAX_DTO_DOT_H
#define TAX_DTO_DOT_H

#include <string>

class TaxParamVO
{
public:
    double Basic = 0.0;
    double DA = 0.0;
    double HRA = 0.0;
    double Allowance = 0.0;
    double Deductions = 0.0;
    double Cess = 0.0;
    double TaxLiability = 0.0;
    bool Computed = false;
};

class TaxableEntity {
    public:
        int id;
        std::string name; 
        int age;
        char sex;
        std::string location; 
        TaxParamVO taxparams;
};

#endif