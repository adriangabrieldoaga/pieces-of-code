@echo off
setlocal
set "folder1=full-path-1"
set "folder2=full-path-2"
set "output_file=text-file-full-path"
set "file_mask=*"

for /f "delims=" %%F in (
  'echo "."^&forfiles /s /p "%folder1%" /m "%file_mask%" /c "cmd /c if @isdir==TRUE echo @relpath"'
) do fc /b "%folder1%\%%~F\%file_mask%" "%folder2%\%%~F\*" >> "%output_file%"