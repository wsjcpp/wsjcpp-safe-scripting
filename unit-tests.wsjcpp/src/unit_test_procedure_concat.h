#ifndef UNIT_TEST_PROCEDURE_CONCAT_H
#define UNIT_TEST_PROCEDURE_CONCAT_H

#include <wsjcpp_unit_tests.h>

class UnitTestProcedureConcat : public WsjcppUnitTestBase {
    public:
        UnitTestProcedureConcat();
        virtual bool doBeforeTest() override;
        virtual void executeTest() override;
        virtual bool doAfterTest() override;
};

#endif // UNIT_TEST_PROCEDURE_CONCAT_H

