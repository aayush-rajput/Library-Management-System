@echo off
git --version > git_version.txt 2>&1
if %errorlevel% neq 0 echo "Git failed" > git_error.txt
echo "Done" > debug_done.txt
