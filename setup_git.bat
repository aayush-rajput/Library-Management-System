@echo off
if not exist README.md (
  echo # Library-Management-System > README.md
)
git init
git add README.md
git commit -m "first commit"
git branch -M main
git remote remove origin 2>nul
git remote add origin https://github.com/aayush-rajput/Library-Management-System.git
