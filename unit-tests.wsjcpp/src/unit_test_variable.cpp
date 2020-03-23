#include "unit_test_variable.h"
#include <vector>
#include <wsjcpp_core.h>
#include <wsjcpp_safe_scripting.h>

REGISTRY_UNIT_TEST(UnitTestVariable)

UnitTestVariable::UnitTestVariable()
    : WSJCppUnitTestBase("UnitTestVariable") {
}

// ---------------------------------------------------------------------

void UnitTestVariable::init() {
    // nothing
}

// ---------------------------------------------------------------------

bool UnitTestVariable::run() {
    bool bTestSuccess = true;
    std::string sValue = "Test 1";
    WSJCppSafeScriptingVariable *pValue = new WSJCppSafeScriptingVariable(sValue);
    compareS(bTestSuccess, "Value 1", pValue->getValue(), sValue);
    sValue = "some 2";
    pValue->setValue(sValue);
    compareS(bTestSuccess, "Value 2", pValue->getValue(), sValue);
    delete pValue;
    return bTestSuccess;
}

