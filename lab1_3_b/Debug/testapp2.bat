@ lab1_3_a.exe
@ IF NOT ERRORLEVEL -1 GOTO err

@ lab1_3_a.exe notANumber
@ IF NOT ERRORLEVEL -1 GOTO err

@ lab1_3_a.exe ""
@ IF NOT ERRORLEVEL -1 GOTO err

@ lab1_3_a.exe 10 / 0 - 8 * 0 + 5
@ IF NOT ERRORLEVEL -1 GOTO err

@ lab1_3_a.exe 10 / / - 8 * 0 + 5
@ IF NOT ERRORLEVEL -1 GOTO err

@ lab1_3_a.exe 10 + 0 - + 8 * / / 0 + 5
@ IF NOT ERRORLEVEL -1 GOTO err

@ lab1_3_a.exe 10 + 0 - 8 * 0 + 
@ IF NOT ERRORLEVEL -1 GOTO err

@ lab1_3_a.exe 10 - 0 % 8 * 0 + 5
@ IF NOT ERRORLEVEL -1 GOTO err

@ lab1_3_a.exe -123 > output.txt
@ IF ERRORLEVEL 1 GOTO err
@ FC /B output.txt -123.txt
@ IF ERRORLEVEL 1 GOTO err

@ lab1_3_a.exe 15 * 2 + 8 > output.txt
@ IF ERRORLEVEL 1 GOTO err
@ FC /B output.txt 15U2+8.txt
@ IF ERRORLEVEL 1 GOTO err

@ lab1_3_a.exe - 10 / 2.5 - 8 * 2.3 + 5 > output.txt
@ IF ERRORLEVEL 1 GOTO err
@ FC /B output.txt _10D2_5-8U2_3+5.txt
@ IF ERRORLEVEL 1 GOTO err

@ ECHO Program testing succeeded :-)

@ EXIT

:err
@ ECHO Program testing failed :-(
@ EXIT
