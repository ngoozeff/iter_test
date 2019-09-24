set FLAGS= /D"DEBUG" /Zi /D"_DEBUG" /MDd

cl /c %FLAGS% main.cc || exit /B 1
cl /c %FLAGS% /clr mgd.cc || exit /B 1

cl main.obj mgd.obj /link /DEBUG || exit /B 1

.\main

