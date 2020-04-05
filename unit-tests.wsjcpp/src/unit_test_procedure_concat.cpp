#include "unit_test_procedure_concat.h"
#include <vector>
#include <wsjcpp_core.h>
#include <wsjcpp_safe_scripting.h>

REGISTRY_UNIT_TEST(UnitTestProcedureConcat)

UnitTestProcedureConcat::UnitTestProcedureConcat()
    : WsjcppUnitTestBase("UnitTestProcedureConcat") {
}

// ---------------------------------------------------------------------

void UnitTestProcedureConcat::init() {
    // nothing
}

// ---------------------------------------------------------------------

bool UnitTestProcedureConcat::run() {
    bool bTestSuccess = true;

    WsjcppSafeScriptingProcedureConcat *pProcedureConcat = new WsjcppSafeScriptingProcedureConcat();
    std::vector<WsjcppSafeScriptingVariable *> vArgs;
    WsjcppSafeScriptingVariable *pVar1 = new WsjcppSafeScriptingVariable("123");
    WsjcppSafeScriptingVariable *pVar2 = new WsjcppSafeScriptingVariable("456");
    WsjcppSafeScriptingVariable *pVar3 = new WsjcppSafeScriptingVariable("789");
    WsjcppSafeScriptingVariable *pVar4 = new WsjcppSafeScriptingVariable("0");
    vArgs.push_back(pVar1);
    vArgs.push_back(pVar2);
    vArgs.push_back(pVar3);
    vArgs.push_back(pVar4);

    compareS(bTestSuccess, "Check name", pProcedureConcat->getName(), "concat");

    pProcedureConcat->exec(vArgs);
    
    compareS(bTestSuccess, "Var1", pVar1->getValue(), "1234567890");
    compareS(bTestSuccess, "Var2", pVar2->getValue(), "456");
    compareS(bTestSuccess, "Var3", pVar3->getValue(), "789");
    compareS(bTestSuccess, "Var4", pVar4->getValue(), "0");

    return bTestSuccess;
}

