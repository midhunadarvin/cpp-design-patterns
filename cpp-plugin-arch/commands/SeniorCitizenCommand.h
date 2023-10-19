#ifndef SENIOR_CITIZEN_COMMAND_DOT_H
#define SENIOR_CITIZEN_COMMAND_DOT_H
#include "./BaseComputationCommand.h" // Include the header where ComputationCommand is defined
#include "./ComputationContext.h"     // Include the header for COMPUTATION_CONTEXT, if needed
#include "./TaxableEntity.h"          // Include the header for TaxDTO, if needed

class SeniorCitizenCommand : public BaseComputationCommand
{
public:
    bool Execute(ComputationContext &ctx) override
    {
        // Assuming TaxDTO is a class, you need to include its definition and cast ctx.Get("tax_cargo") accordingly.
        TaxableEntity *td;
        try
        {
            td = std::any_cast<TaxableEntity *>(ctx.Get("tax_cargo")); // Attempt to cast
        }
        catch (const std::bad_any_cast &e)
        {
            std::cerr << "Casting failed: " << e.what() << std::endl;
        }

        if (td != NULL)
        {
            // Instead of computation, assign a constant tax for each archetype.
            td->taxparams.TaxLiability = 1000;
            td->taxparams.Computed = true;
            return true;
        }
        else
        {
            // Handle the case where the cast fails (e.g., object with key "tax_cargo" not found or of the wrong type).
            return false;
        }
    }

    std::shared_ptr<BaseComputationCommand> Clone() const override
    {
        return std::make_shared<SeniorCitizenCommand>(*this);
    }
};
#endif
