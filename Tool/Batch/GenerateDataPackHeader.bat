@echo off

set SCRIPT_DIR=%~dp0..\Script\
set CSV_DIR=%~dp0..\..\CSV
set HEADER_OUT_DIR=%~dp0..\..\DataPack\DataPack\Source
set PARSER_OUT_DIR=%~dp0..\..\DataPack\DataChunkGenerator\Source\Inc
set TEMP_DIR=%~dp0..\..\Temp

if not exist "%TEMP_DIR%" (
    mkdir "%TEMP_DIR%"
)

if "%~1" == "" (
    echo [ERROR] Target name is required!
    echo Usage: GenerateDataPackHeader.bat ^<TargetName^>
    pause
    exit /b 1
)
set TARGET_NAME=%~1

python "%SCRIPT_DIR%cli.py" generate-data-pack-header ^
    --target-csv-path "%CSV_DIR%" ^
    --target-name "%TARGET_NAME%" ^
    --output-header-path "%HEADER_OUT_DIR%" ^
    --output-parser-path "%PARSER_OUT_DIR%" ^
    --log-file-path "%TEMP_DIR%"

pause
