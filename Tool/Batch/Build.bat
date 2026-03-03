@echo off

set BUILD_TYPE=%~1
set TARGET_NAME=%~2
set IS_REBUILD=%~3
if "%IS_REBUILD%"=="" (
    set IS_REBUILD=false
)

if /I "%IS_REBUILD%"=="true" (
    set IS_REBUILD=true
) else if /I "%IS_REBUILD%"=="false" (
    set IS_REBUILD=false
) else (
    echo [ERROR] Invalid argument defined!
    echo Usage: %~nx0 ^<BuildType^> ^<TargetName^> [true^|false]
    echo Example: %~nx0 Debug DataChunkGenerator true
    exit /b 1
)

set SCRIPT_DIR=%~dp0..\Script\
set SOLUTION_DIR=%~dp0..\..\Solution
set TEMP_DIR=%~dp0..\..\Temp

if not exist "%TEMP_DIR%" (
    mkdir "%TEMP_DIR%"
)

python "%SCRIPT_DIR%cli.py" build ^
    --solution-path "%SOLUTION_DIR%" ^
    --config "%BUILD_TYPE%" ^
    --target-name "%TARGET_NAME%" ^
    --is-rebuild %IS_REBUILD% ^
    --log-file-path "%TEMP_DIR%"

pause