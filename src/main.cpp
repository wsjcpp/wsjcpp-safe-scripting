#include <wsjcpp_core.h>
#include <wsjcpp_safe_scripting.h>
#include <safe_scripting_proc_test_proc.h>

int main(int argc, const char* argv[]) {
    std::string TAG = "MAIN";
    std::string appName = std::string(WSJCPP_NAME);
    std::string appVersion = std::string(WSJCPP_VERSION);
    WSJCppCore::initRandom();
    if (!WSJCppCore::dirExists(".logs")) {
        WSJCppCore::makeDir(".logs");
    }
    WSJCppLog::setPrefixLogFile("wsjcpp-safe-scripting");
    WSJCppLog::setLogDirectory(".logs");
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
        return -1;
    }
    std::string sScriptFileName = std::string(argv[1]);
    std::string sScriptContent = "";
    if (!WSJCppCore::readTextFile(sScriptFileName, sScriptContent)) {
        WSJCppLog::err(TAG, "Could not read file '" + sScriptFileName + "'");
        return -1;
    }
    std::string sCurrentDirectory = WSJCppCore::getCurrentDirectory();
    WSJCppLog::info(TAG, "Current directory " + sCurrentDirectory);

    WSJCppSafeScriptingContext scriptContext;
    scriptContext.addProc(new SafeScriptingProcTestProc());

    WSJCppLog::info(TAG, "Start executing script '" + sScriptFileName + "'"); // with content: \n" + sScriptContent);
    std::vector<std::string> vScriptArgs;
    for (int i = 2; i < argc; i++) {
        vScriptArgs.push_back(argv[i]);
    }
    return scriptContext.exec(
        sCurrentDirectory,
        sScriptFileName,
        sScriptContent, 
        vScriptArgs
    );
}

