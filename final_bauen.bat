cd .\Aufgabe_4\source
g++ -o Aufgabe_4 Aufgabe_4.cpp -Wall -Wextra -std=c++11 -O2
cd ..\..
cd .\Aufgabe_5\source
g++ -o Aufgabe_5 Aufgabe_5.cpp -Wall -Wextra -std=c++11 -O2
cd ..\..

copy .\Aufgabe_1\source\*.py .\Final\Aufgabe_1\source\
copy .\Aufgabe_2\source\*.py .\Final\Aufgabe_2\source\
copy .\Aufgabe_4\source\*.cpp .\Final\Aufgabe_4\source\
copy .\Aufgabe_5\source\*.cpp .\Final\Aufgabe_5\source\

copy .\Aufgabe_4\source\*.exe .\Final\Aufgabe_4\executables\
copy .\Aufgabe_5\source\*.exe .\Final\Aufgabe_5\executables\

copy .\Aufgabe_1\source\*.bat .\Final\Aufgabe_1\executables\
copy .\Aufgabe_2\source\*.bat .\Final\Aufgabe_2\executables\
copy .\Aufgabe_4\source\*.bat .\Final\Aufgabe_4\executables\
copy .\Aufgabe_5\source\*.bat .\Final\Aufgabe_5\executables\

copy .\Aufgabe_1\documentation\*.pdf .\Final\
copy .\Aufgabe_2\documentation\*.pdf .\Final\
copy .\Aufgabe_4\documentation\*.pdf .\Final\
copy .\Aufgabe_5\documentation\*.pdf .\Final\

copy .\Aufgabe_4\documentation\*.xlsx .\Final\Aufgabe_4\

copy .\README.md .\Final\


copy .\Aufgabe_1\beispielausgaben\*.* .\Final\Aufgabe_1\beispielausgaben\
copy .\Aufgabe_2\beispielausgaben\*.* .\Final\Aufgabe_2\beispielausgaben\
copy .\Aufgabe_4\beispielausgaben\*.* .\Final\Aufgabe_4\beispielausgaben\
copy .\Aufgabe_5\beispielausgaben\*.* .\Final\Aufgabe_5\beispielausgaben\

copy .\Aufgabe_1\beispieleingaben\*.txt .\Final\Aufgabe_1\beispieleingaben\
copy .\Aufgabe_2\beispieleingaben\*.txt .\Final\Aufgabe_2\beispieleingaben\
copy .\Aufgabe_4\beispieleingaben\*.txt .\Final\Aufgabe_4\beispieleingaben\
copy .\Aufgabe_5\beispieleingaben\*.txt .\Final\Aufgabe_5\beispieleingaben\


echo on

for /f "tokens=3,2,4 delims=/- " %%x in ("%date%") do set d=%%y%%x%%z

set data=%d%

Echo zipping...

"C:\Program Files\7-Zip\7z.exe" a -tzip ".\Final.zip" ".\Final\*"

echo Done!

pause