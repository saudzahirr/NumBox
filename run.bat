@echo off

REM Check if a filename is provided as an argument
if "%1"=="" (
    echo Error: Please provide a C++ file as an argument.
    goto :eof
)

REM Extract the file name and extension
set "cpp_file=%1"
set "filename=%~n1"
set "exe_file=%filename%.exe"

REM Compile the C++ file
g++ -o %exe_file% %cpp_file%

REM Check if the compilation was successful
if %errorlevel% neq 0 (
    echo Compilation failed.
    goto :eof
)

REM Execute the compiled program
%exe_file%
