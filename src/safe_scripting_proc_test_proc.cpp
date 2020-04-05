
#include "safe_scripting_proc_test_proc.h"
#include <wsjcpp_core.h>

// ---------------------------------------------------------------------
// SafeScriptingProcTestProc

SafeScriptingProcTestProc::SafeScriptingProcTestProc() 
: WsjcppSafeScriptingProc("test_proc") {

}

// ---------------------------------------------------------------------

bool SafeScriptingProcTestProc::exec(const std::vector<WsjcppSafeScriptingVariable *> &vArgs) {
    WsjcppLog::err(TAG, "Not implemented");
    return false;
}

