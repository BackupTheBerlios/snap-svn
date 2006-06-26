pause
REM The purpose of this script is to allow output redirection to file from
REM the DotNet environment which doesnt support this feature

REM see http://labmice.techtarget.com/articles/batchcmds.htm for details
REM on batch file programming

REM the 1st argument is be the name of the console redirection output file.
REM usage: the 2nd argument is be the command to run
REM the 3rd and onward arguments are parameters of the command

SET snap_command=

:LOOP
if "%2"=="" goto run_command
SET snap_command=%snap_command% %2
shift /2
goto LOOP

:run_command
%snap_command% > %1
pause
