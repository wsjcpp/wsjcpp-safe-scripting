#include "unit_test_procedure_set_value.h"
#include <vector>
#include <wsjcpp_core.h>
#include <wsjcpp_safe_scripting.h>

REGISTRY_UNIT_TEST(UnitTestProcedureSetValue)

UnitTestProcedureSetValue::UnitTestProcedureSetValue()
    : WsjcppUnitTestBase("UnitTestProcedureSetValue") {
}

// ---------------------------------------------------------------------

void UnitTestProcedureSetValue::init() {
    // nothing
}

// ---------------------------------------------------------------------

bool UnitTestProcedureSetValue::run() {
    bool bTestSuccess = true;
    
    WsjcppSafeScriptingVariable *pVar1 = new WsjcppSafeScriptingVariable("123");
    WsjcppSafeScriptingVariable *pVar2 = new WsjcppSafeScriptingVariable("456");

    compareS(bTestSuccess, "Var1", pVar1->getValue(), "123");
    compareS(bTestSuccess, "Var2", pVar2->getValue(), "456");

    WsjcppSafeScriptingProcedureSetValue *pProcedureSetValue = new WsjcppSafeScriptingProcedureSetValue();
    std::vector<WsjcppSafeScriptingVariable *> vArgs;
    vArgs.push_back(pVar1);
    vArgs.push_back(pVar2);

    compareS(bTestSuccess, "Check name", pProcedureSetValue->getName(), "set_value");

    pProcedureSetValue->exec(vArgs);
    
    compareS(bTestSuccess, "Var1", pVar1->getValue(), "456");
    compareS(bTestSuccess, "Var2", pVar2->getValue(), "456");

    WsjcppSafeScriptingContext scriptContext;
    scriptContext.addVariable("var14")->setValue("");
    scriptContext.exec(
         // folder
        "./",
         // script_name
        "./test_procedure_set_value",
        // script
        "var var24\n"
        "set_value var24 \"\"\n"
        "set_value var24 \"a\\nbc\"\n"
        "set_value var14 var24\n", 
         // args
        {}
    );

    compareB(bTestSuccess, "has-var14", scriptContext.hasVar("var14"), true);
    compareB(bTestSuccess, "has-var24", scriptContext.hasVar("var24"), true);

    if (scriptContext.hasVar("var14")) {
        compareS(bTestSuccess, "check-content-var14", 
            scriptContext.getVariable("var14")->getValue(),
            "a\nbc"
        );
    }

    if (scriptContext.hasVar("var24")) {
        compareS(bTestSuccess, "check-content-var24", 
            scriptContext.getVariable("var24")->getValue(),
            "a\nbc"
        );
    }

    return bTestSuccess;
}

