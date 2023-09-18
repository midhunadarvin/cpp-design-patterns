#include "./commands/TaxableEntity.h" // Include the header for TaxDTO, if needed
#include "./commands/ComputationContext.h"
#include <iostream>
#include <any>
#include "TaxComputationFacade.h"

TaxableEntity GetEntityFromUI()
{
    TaxableEntity td;
    td.id = 1;
    TaxParamVO taxparams;
    taxparams.Basic = 100;
    td.taxparams = taxparams;
    td.age = 61;
    return td;
}

void ViewHandler()
{
    
    TaxableEntity te = GetEntityFromUI();

    bool rs = TaxComputationFacade::Compute(&te);
    if (rs)
    {
        std::cout << std::to_string(te.taxparams.TaxLiability) << std::endl;
    }
}

int main()
{
    ViewHandler();
    return 0;
}