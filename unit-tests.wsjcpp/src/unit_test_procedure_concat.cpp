#include "unit_test_procedure_concat.h"
#include <vector>
#include <wsjcpp_core.h>
#include <wsjcpp_safe_scripting.h>

REGISTRY_WSJCPP_UNIT_TEST(UnitTestProcedureConcat)

UnitTestProcedureConcat::UnitTestProcedureConcat()
    : WsjcppUnitTestBase("UnitTestProcedureConcat") {
}

// ---------------------------------------------------------------------

bool UnitTestProcedureConcat::doBeforeTest() {
    // nothing
    return true;
}

// ---------------------------------------------------------------------

void UnitTestProcedureConcat::executeTest() {

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

    compare("Check name", pProcedureConcat->getName(), "concat");

    pProcedureConcat->exec(vArgs);
    
    compare("Var1", pVar1->getValue(), "1234567890");
    compare("Var2", pVar2->getValue(), "456");
    compare("Var3", pVar3->getValue(), "789");
    compare("Var4", pVar4->getValue(), "0");
    
    delete pProcedureConcat;
    delete pVar1;
    delete pVar2;
    delete pVar3;
    delete pVar4;
}

// ---------------------------------------------------------------------

bool UnitTestProcedureConcat::doAfterTest() {
    // nothing
    return true;
}
