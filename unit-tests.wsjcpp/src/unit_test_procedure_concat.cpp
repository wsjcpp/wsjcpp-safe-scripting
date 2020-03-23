#include "unit_test_procedure_concat.h"
#include <vector>
#include <wsjcpp_core.h>
#include <wsjcpp_safe_scripting.h>

REGISTRY_UNIT_TEST(UnitTestProcedureConcat)

UnitTestProcedureConcat::UnitTestProcedureConcat()
    : WSJCppUnitTestBase("UnitTestProcedureConcat") {
}

// ---------------------------------------------------------------------

void UnitTestProcedureConcat::init() {
    // nothing
}

// ---------------------------------------------------------------------

bool UnitTestProcedureConcat::run() {
    bool bTestSuccess = true;

    WSJCppSafeScriptingProcedureConcat *pProcedureConcat = new WSJCppSafeScriptingProcedureConcat();
    std::vector<WSJCppSafeScriptingVariable *> vArgs;
    WSJCppSafeScriptingVariable *pVar1 = new WSJCppSafeScriptingVariable("123");
    WSJCppSafeScriptingVariable *pVar2 = new WSJCppSafeScriptingVariable("456");
    WSJCppSafeScriptingVariable *pVar3 = new WSJCppSafeScriptingVariable("789");
    WSJCppSafeScriptingVariable *pVar4 = new WSJCppSafeScriptingVariable("0");
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

