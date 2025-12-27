@echo off
echo Start > log.txt
git add README.md >> log.txt 2>&1
git commit -m "first commit" >> log.txt 2>&1
git branch -M main >> log.txt 2>&1
git remote remove origin >> log.txt 2>&1
git remote add origin https://github.com/aayush-rajput/Library-Management-System.git >> log.txt 2>&1
git push -u origin main >> log.txt 2>&1
echo End >> log.txt
