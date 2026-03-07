@echo off

set SCRIPT_DIR=%~dp0..\Script\
set CSV_DIR=%~dp0..\..\CSV
set HEADER_OUT_DIR=%~dp0..\..\DataPack\DataPack\Source
set PARSER_OUT_DIR=%~dp0..\..\DataPack\DataChunkGenerator\Source\Inc
set TEMP_DIR=%~dp0..\..\Temp

if not exist "%TEMP_DIR%" (
    mkdir "%TEMP_DIR%"
)

python "%SCRIPT_DIR%cli.py" generate-all-data-pack-header ^
    --target-csv-path "%CSV_DIR%" ^
    --output-header-path "%HEADER_OUT_DIR%" ^
    --output-parser-path "%PARSER_OUT_DIR%" ^
    --log-file-path "%TEMP_DIR%"

pause
