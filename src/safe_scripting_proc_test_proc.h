#ifndef SAFE_SCRIPTING_PROC_TEST_PROC_H
#define SAFE_SCRIPTING_PROC_TEST_PROC_H

#include <wsjcpp_safe_scripting.h>

class SafeScriptingProcTestProc : public WSJCppSafeScriptingProc {
    public:
        SafeScriptingProcTestProc();
        virtual bool exec(const std::vector<WSJCppSafeScriptingVariable *> &m_vArgs);
};

#endif // SAFE_SCRIPTING_PROC_TEST_PROC_H
