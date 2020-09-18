#ifndef UNIT_TEST_PROCEDURE_SET_VALUE_H
#define UNIT_TEST_PROCEDURE_SET_VALUE_H

#include <wsjcpp_unit_tests.h>

class UnitTestProcedureSetValue : public WsjcppUnitTestBase {
    public:
        UnitTestProcedureSetValue();
        virtual bool doBeforeTest() override;
        virtual void executeTest() override;
        virtual bool doAfterTest() override;
};

#endif // UNIT_TEST_PROCEDURE_SET_VALUE_H

