#include <vector>
#include <wsjcpp_core.h>
#include <wsjcpp_safe_scripting.h>
#include <wsjcpp_unit_tests.h>

// ---------------------------------------------------------------------
// UnitTestVariable

class UnitTestVariable : public WsjcppUnitTestBase {
    public:
        UnitTestVariable();
        virtual bool doBeforeTest() override;
        virtual void executeTest() override;
        virtual bool doAfterTest() override;
};

REGISTRY_WSJCPP_UNIT_TEST(UnitTestVariable)

// ---------------------------------------------------------------------

UnitTestVariable::UnitTestVariable()
: WsjcppUnitTestBase("UnitTestVariable") {
    // nothing
}

// ---------------------------------------------------------------------

bool UnitTestVariable::doBeforeTest() {
    // nothing
    return true;
}

// ---------------------------------------------------------------------

void UnitTestVariable::executeTest() {
    std::string sValue = "Test 1";
    WsjcppSafeScriptingVariable *pValue = new WsjcppSafeScriptingVariable(sValue);
    compare("Value 1", pValue->getValue(), sValue);
    sValue = "some 2";
    pValue->setValue(sValue);
    compare("Value 2", pValue->getValue(), sValue);
    delete pValue;
}

// ---------------------------------------------------------------------

bool UnitTestVariable::doAfterTest() {
    // nothing
    return true;
}