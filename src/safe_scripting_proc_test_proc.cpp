
#include "safe_scripting_proc_test_proc.h"
#include <wsjcpp_core.h>

// ---------------------------------------------------------------------
// SafeScriptingProcTestProc

SafeScriptingProcTestProc::SafeScriptingProcTestProc() 
: WSJCppSafeScriptingProc("test_proc") {

}

// ---------------------------------------------------------------------

bool SafeScriptingProcTestProc::exec(const std::vector<WSJCppSafeScriptingVariable *> &vArgs) {
    WSJCppLog::err(TAG, "Not implemented");
    return false;
}

