#include <wsjcpp_core.h>
#include <wsjcpp_safe_scripting.h>
#include <safe_scripting_proc_test_proc.h>

int main(int argc, const char* argv[]) {
    std::string TAG = "MAIN";
    std::string appName = std::string(WSJCPP_NAME);
    std::string appVersion = std::string(WSJCPP_VERSION);
    WsjcppCore::initRandom();
    if (!WsjcppCore::dirExists(".logs")) {
        WsjcppCore::makeDir(".logs");
    }
    WsjcppLog::setPrefixLogFile("wsjcpp-safe-scripting");
    WsjcppLog::setLogDirectory(".logs");
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
        return -1;
    }
    std::string sScriptFileName = std::string(argv[1]);
    std::string sScriptContent = "";
    if (!WsjcppCore::readTextFile(sScriptFileName, sScriptContent)) {
        WsjcppLog::err(TAG, "Could not read file '" + sScriptFileName + "'");
        return -1;
    }
    std::string sCurrentDirectory = WsjcppCore::getCurrentDirectory();
    WsjcppLog::info(TAG, "Current directory " + sCurrentDirectory);

    WsjcppSafeScriptingContext scriptContext;
    scriptContext.addProc(new SafeScriptingProcTestProc());

    WsjcppLog::info(TAG, "Start executing script '" + sScriptFileName + "'"); // with content: \n" + sScriptContent);
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

