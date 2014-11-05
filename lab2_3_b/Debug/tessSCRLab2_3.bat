@ECHO OFF

echo lab2_3_b.exe
lab2_3_b.exe
IF NOT ERRORLEVEL 1 GOTO err
echo -------------------------------------------------------------------
echo lab2_3_b.exe inM1
lab2_3_b.exe inM1
IF NOT ERRORLEVEL 1 GOTO err
echo -------------------------------------------------------------------
echo lab2_3_b.exe inM1.txt
lab2_3_b.exe inM1.txt
IF NOT ERRORLEVEL 1 GOTO err
echo -------------------------------------------------------------------
echo lab2_3_b.exe inM1.txt inm2
lab2_3_b.exe inM1.txt inm2
IF NOT ERRORLEVEL 1 GOTO err
echo -------------------------------------------------------------------
echo lab2_3_b.exe inM1.txt inM2.txt
erase /Q output.txt
lab2_3_b.exe inM1.txt inM2.txt >> output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt out1.txt
IF ERRORLEVEL 1 GOTO err
echo -------------------------------------------------------------------
echo lab2_3_b.exe inM1.txt zeroM.txt
erase /Q output.txt
lab2_3_b.exe inM1.txt zeroM.txt >> output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt out2.txt
IF ERRORLEVEL 1 GOTO err
echo -------------------------------------------------------------------

ECHO Program testing succeeded :-)

EXIT

:err
ECHO Program testing failed :-(
EXIT
