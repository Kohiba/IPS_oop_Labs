@ECHO OFF

echo lab2_2_a.exe
lab2_2_a.exe
IF NOT ERRORLEVEL 1 GOTO err
echo -------------------------------------------------------------------
echo lab2_2_a.exe notANumber
lab2_2_a.exe notANumber
IF NOT ERRORLEVEL 1 GOTO err
echo -------------------------------------------------------------------
echo lab2_2_a.exe ""
lab2_2_a.exe ""
IF NOT ERRORLEVEL 1 GOTO err
echo -------------------------------------------------------------------
echo lab2_2_a.exe -1
lab2_2_a.exe -1
IF NOT ERRORLEVEL 1 GOTO err
echo -------------------------------------------------------------------
echo lab2_2_a.exe 256	
lab2_2_a.exe 256
IF NOT ERRORLEVEL 1 GOTO err
echo -------------------------------------------------------------------
echo lab2_2_a.exe 2555	
lab2_2_a.exe 2555
IF NOT ERRORLEVEL 1 GOTO err
echo -------------------------------------------------------------------
echo lab2_2_a.exe 1
erase /Q output.txt
lab2_2_a.exe 1 >> output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt out1.txt
IF ERRORLEVEL 1 GOTO err
echo -------------------------------------------------------------------
echo lab2_2_a.exe 6
erase /Q output.txt
lab2_2_a.exe 6 >> output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt out2.txt
IF ERRORLEVEL 1 GOTO err
echo -------------------------------------------------------------------
echo lab2_2_a.exe 200
erase /Q output.txt
lab2_2_a.exe 200 >> output.txt
IF ERRORLEVEL 1 GOTO err
FC /B output.txt out3.txt
IF ERRORLEVEL 1 GOTO err
echo -------------------------------------------------------------------

ECHO Program testing succeeded :-)

EXIT

:err
ECHO Program testing failed :-(
EXIT
