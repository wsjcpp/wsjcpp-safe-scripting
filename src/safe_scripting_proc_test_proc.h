#ifndef SAFE_SCRIPTING_PROC_TEST_PROC_H
#define SAFE_SCRIPTING_PROC_TEST_PROC_H

#include <wsjcpp_safe_scripting.h>

class SafeScriptingProcTestProc : public WsjcppSafeScriptingProc {
    public:
        SafeScriptingProcTestProc();
        virtual bool exec(const std::vector<WsjcppSafeScriptingVariable *> &m_vArgs);
};

#endif // SAFE_SCRIPTING_PROC_TEST_PROC_H
