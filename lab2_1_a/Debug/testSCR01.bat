@ECHO OFF


echo lab2_1_a.exe
lab2_1_a.exe
IF ERRORLEVEL 1 GOTO err

echo -------------------------------------------------------------------
echo lab2_1_a.exe notANumber
lab2_1_a.exe notANumber
IF ERRORLEVEL 1 GOTO err
echo -------------------------------------------------------------------
echo lab2_1_a.exe ""
lab2_1_a.exe ""
IF ERRORLEVEL 1 GOTO err
echo -------------------------------------------------------------------
echo lab2_1_a.exe "in2.txt"
lab2_1_a.exe "in2.txt"
IF ERRORLEVEL 1 GOTO err
echo -------------------------------------------------------------------
echo lab2_1_a.exe "in2.txt" ""
lab2_1_a.exe "in2.txt" ""
IF ERRORLEVEL 1 GOTO err
echo -------------------------------------------------------------------
echo lab2_1_a.exe "in2.txt" "obligations of business"
erase /Q output.txt
lab2_1_a.exe "in2.txt" "obligations of business" >> output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt out1.txt
IF ERRORLEVEL 1 GOTO err
echo -------------------------------------------------------------------
echo lab2_1_a.exe "in2.txt" "are"
erase /Q output.txt
lab2_1_a.exe "in2.txt" "are" >> output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt out2.txt
IF ERRORLEVEL 1 GOTO err
echo -------------------------------------------------------------------
echo lab2_1_a.exe "in2.txt" "Power of World"
erase /Q output.txt
lab2_1_a.exe "in2.txt" "Power of World" >> output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt out3.txt
IF ERRORLEVEL 1 GOTO err
echo -------------------------------------------------------------------

ECHO Program testing succeeded :-)

EXIT

:err
ECHO Program testing failed :-(
EXIT
