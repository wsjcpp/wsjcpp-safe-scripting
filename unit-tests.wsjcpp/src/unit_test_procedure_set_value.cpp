#include "unit_test_procedure_set_value.h"
#include <vector>
#include <wsjcpp_core.h>
#include <wsjcpp_safe_scripting.h>

REGISTRY_WSJCPP_UNIT_TEST(UnitTestProcedureSetValue)

UnitTestProcedureSetValue::UnitTestProcedureSetValue()
    : WsjcppUnitTestBase("UnitTestProcedureSetValue") {
}

// ---------------------------------------------------------------------

bool UnitTestProcedureSetValue::doBeforeTest() {
    // nothing
    return true;
}

// ---------------------------------------------------------------------

void UnitTestProcedureSetValue::executeTest() {
    
    WsjcppSafeScriptingVariable *pVar1 = new WsjcppSafeScriptingVariable("123");
    WsjcppSafeScriptingVariable *pVar2 = new WsjcppSafeScriptingVariable("456");

    compare("Var1", pVar1->getValue(), "123");
    compare("Var2", pVar2->getValue(), "456");

    WsjcppSafeScriptingProcedureSetValue *pProcedureSetValue = new WsjcppSafeScriptingProcedureSetValue();
    std::vector<WsjcppSafeScriptingVariable *> vArgs;
    vArgs.push_back(pVar1);
    vArgs.push_back(pVar2);

    compare("Check name", pProcedureSetValue->getName(), "set_value");

    pProcedureSetValue->exec(vArgs);
    
    compare("Var1", pVar1->getValue(), "456");
    compare("Var2", pVar2->getValue(), "456");

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

    compare("has-var14", scriptContext.hasVar("var14"), true);
    compare("has-var24", scriptContext.hasVar("var24"), true);

    if (scriptContext.hasVar("var14")) {
        compare("check-content-var14", 
            scriptContext.getVariable("var14")->getValue(),
            "a\nbc"
        );
    }

    if (scriptContext.hasVar("var24")) {
        compare("check-content-var24", 
            scriptContext.getVariable("var24")->getValue(),
            "a\nbc"
        );
    }
}

// ---------------------------------------------------------------------

bool UnitTestProcedureSetValue::doAfterTest() {
    // nothing
    return true;
}