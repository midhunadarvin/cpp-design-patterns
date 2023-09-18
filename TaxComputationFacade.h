#pragma once
#include "./commands/ComputationContext.h"
#include "./commands/TaxableEntity.h" // Include the header for TaxDTO, if needed
#include "CommandDispatcher.h"
#include <string>

class TaxComputationFacade
{
    /// <summary>
    ///  A Rule Engine can do Archetype detection
    ///  One can write a small Expression Evaluator Engine
    ///  and GOF terms its Interpreter pattern
    /// </summary>
    /// <param name="te"></param>
    /// <returns></returns>
    private:
        static std::string ComputeArchetype(TaxableEntity* te)
        {
            if ((te->sex == 'F') && (te->age > 59))
            {
                return "SeniorCitizenFemale";
            }
            else if (te->age < 18)
            {
                return "JuevenileCitizen";
            }
            return (te->age > 60) ? "SeniorCitizen" : "OrdinaryCitizen";
        }

    public:
        static bool Compute(TaxableEntity *td)
        {
            // compute archetype
            std::string archetype = ComputeArchetype(td);

            ComputationContext ctx;
            ctx.Put("tax_cargo", td);
            bool rs = CommandDispatcher::Dispatch(archetype, ctx);
            return rs;
        }
};
