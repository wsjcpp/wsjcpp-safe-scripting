# wsjcpp-safe-scripting

[![Build Status](https://api.travis-ci.com/wsjcpp/wsjcpp-safe-scripting.svg?branch=master)](https://travis-ci.com/wsjcpp/wsjcpp-safe-scripting) [![Github Stars](https://img.shields.io/github/stars/wsjcpp/wsjcpp-safe-scripting.svg?label=github%20%E2%98%85)](https://github.com/wsjcpp/wsjcpp-safe-scripting/stargazers) [![Github Stars](https://img.shields.io/github/contributors/wsjcpp/wsjcpp-safe-scripting.svg)](https://github.com/wsjcpp/wsjcpp-safe-scripting/) [![Github Forks](https://img.shields.io/github/forks/wsjcpp/wsjcpp-safe-scripting.svg?label=github%20forks)](https://github.com/wsjcpp/wsjcpp-safe-scripting/network/members) [![Total alerts](https://img.shields.io/lgtm/alerts/g/wsjcpp/wsjcpp-safe-scripting.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/wsjcpp/wsjcpp-safe-scripting/alerts/) [![Language grade: C/C++](https://img.shields.io/lgtm/grade/cpp/g/wsjcpp/wsjcpp-safe-scripting.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/wsjcpp/wsjcpp-safe-scripting/context:cpp)

* Light script language for integration to your project
* Script deny access read/write to out folders/files 
* Any variables or procedure is global
* Used a procedure simple language
* You can set variables before run script
* You can get variables after run script
* You can extend or disable procedures on c++ 
* Multiline strings
* no if, for, while

## Integrate to your project

Just include this files:

- src/wsjcpp_core/wsjcpp_core.h
- src/wsjcpp_core/wsjcpp_core.cpp
- src/wsjcpp_safe_scripting.h
- src/wsjcpp_safe_scripting.cpp

## Integrate via wsjcpp

```
$ wsjcpp install https://github.com/wsjcpp/wsjcpp-safe-scripting:master
```

## List of default variables and procedures

Default Variables:

- `rootdir` - directory when will be run script
- `script_filename` - name of script

Default procedures:

- `exit` - will be exit from script with exitcode 0
- `error` - will be exit from script with exitcode -1 (error code)
- `print_all_variables` - print to log all defined variables
- `log_info [args]` - print args
- `var <varname>` - define new variable
- `set_value <varname1> "some"` - set string value to variable
- `set_value <varname1> <varname2>` - set value to variable
- `concat <varname1> [args]` - concatinate string values from all vars to <varname1>
- `make_dir "dir_name"` - try create dirname
- `normalize_class_name <varname1>` - will be removed characters which not in [a-zA-Z0-9]
- `convert_CamelCase_to_snake_case <from> <to>` - convert from CamelCase to snake_case
- `write_file <filepath> <content>` - write variable to file
- `cmakelists_txt_append_wsjcpp <filepath>` - append string like 'list (APPEND WSJCPP_SOURCES "%filepath%")' to CMakeLists.txt into between '#### BEGIN_WSJCPP_APPEND' and '#### END_WSJCPP_APPEND'

## Example of exec script

```
#include <wsjcpp_safe_scripting.h>

...

WsjcppSafeScriptingContext scriptContext;

std::string sCurrentDirectory = WsjcppCore::getCurrentDirectory();
std::string sScriptFileName = "script_filename";
std::vector<std::string> vScriptArgs = {"Some1", "Some2"}; // script args: arg1, arg2

// script content
std::string sScriptContent = 
    "var test1\n"
    "set_value test1 \"test string\"\n"
    "log_info test1\n"
    "log_info arg1\n"
    "log_info arg2\n";

int nResult = scriptContext.exec(
    sCurrentDirectory, 
    sScriptFileName, 
    sScriptContent,
    vScriptArgs
);

if (nResult == 0) {
    std::string sTest1 = scriptContext.getVariable("test1")->getValue();
}
```

## Customizing procedures / variables

### New procedures via wsjcpp

```
wsjcpp generate WsjcppSafeScriptingProc YourClassName
```

After this will be generated files and added to your CMakeLists.txt:
```
#### BEGIN_WSJCPP_APPEND
list (APPEND WSJCPP_SOURCES "src/wsjcpp_safe_scripting_proc_your_class_name.h")
list (APPEND WSJCPP_SOURCES "src/wsjcpp_safe_scripting_proc_your_class_name.cpp")
#### END_WSJCPP_APPEND
```

Now you can write you code in this files or move to another place

### New procedures copy-paste-code

header `src/wsjcpp_safe_scripting_proc_your_class_name.h`:
```
#ifndef WSJCPP_SAFE_SCRIPTING_PROC_YOUR_CLASS_NAME_H
#define WSJCPP_SAFE_SCRIPTING_PROC_YOUR_CLASS_NAME_H

#include <wsjcpp_safe_scripting.h>

class WsjcppSafeScriptingProcYourClassName : public WsjcppSafeScriptingProc {
    public:
        WsjcppSafeScriptingProcYourClassName();
        virtual bool exec(const std::vector<WsjcppSafeScriptingVariable *> &m_vArgs);
};


#endif // WSJCPP_SAFE_SCRIPTING_PROC_YOUR_CLASS_NAME_H
```

source-code `src/wsjcpp_safe_scripting_proc_your_class_name.cpp`:
```
#include "wsjcpp_safe_scripting_proc_your_class_name.h"
#include <wsjcpp_core.h>

// ---------------------------------------------------------------------
// WsjcppSafeScriptingProcYourClassName

WsjcppSafeScriptingProcYourClassName::WsjcppSafeScriptingProcYourClassName() 
: WsjcppSafeScriptingProc("your_class_name") {

}

// ---------------------------------------------------------------------

bool WsjcppSafeScriptingProcYourClassName::exec(const std::vector<WsjcppSafeScriptingVariable *> &vArgs) {
    // you code here
    WsjcppLog::err(TAG, "Not implemented")
    return false;
}
```

### Add new procedures / variables to script context

Example:
```
WsjcppSafeScriptingContext scriptContext;

// variable
WsjcppSafeScriptingVariable *pVar = new WsjcppSafeScriptingVariable("");
scriptContext.addVar(pVar);

WsjcppSafeScriptingProcYourClassName *pProc = new WsjcppSafeScriptingProcYourClassName();
scriptContext.addProc(pProc);

```

