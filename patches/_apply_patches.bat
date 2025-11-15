@echo off
rem Apply all .patch files in the current directory
for %%f in (B:\Temp\patches\*.patch) do (
    call timeout 1 && git apply --check --inaccurate-eof --ignore-space-change --ignore-whitespace --verbose "%%f"
)
pause
exit /b 0