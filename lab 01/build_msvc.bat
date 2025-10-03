@echo off
setlocal

rem 1) Подготовить среду MSVC (Build Tools)
call "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars64.bat" >nul 2>&1
if errorlevel 1 (
  call "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvarsall.bat" x64
)

rem 2) Диагностика: убедимся, что cl найден
where cl || (echo [ERROR] cl.exe not found & exit /b 1)

rem 3) Компиляция: %1 — путь к main.cpp; %~dpn1 — путь+имя без .cpp
echo [INFO] Compiling "%~1"
cl /nologo /Zi /EHsc "%~1" /Fe:"%~dpn1.exe"
echo [INFO] cl exit code = %ERRORLEVEL%
endlocal