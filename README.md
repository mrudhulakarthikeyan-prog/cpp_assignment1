# DSA01 Assignment 1 – C++ Implementation Pack

This pack contains starter implementations for Tasks 1–12 of the Namma Metro Smart-Card Fare System assignment.

## Environment
- Language: C++17
- Compiler: GCC (`g++`)
- Suggested compile flags: `-std=c++17 -Wall -Wextra -pedantic`

## Compile and run
From the project root in PowerShell:

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic Task02/constants.cpp -o Task02/constants.exe
.\Task02\constants.exe
```

Repeat with the relevant `.cpp` file in each task folder. Task 7 has two programs (`procedural.cpp` and `oop.cpp`).

## Important assignment assumptions
1. The assignment gives regular base fares of ₹10, ₹20 and ₹30 and a 20% peak surcharge.
2. It mentions student and senior-citizen concessions but does not specify their rates or whether they combine with peak surcharge. No concession percentage is invented in this implementation pack.
3. Peak hours are treated as 08:00–09:59 and 17:00–19:59. Therefore 10:00 and 20:00 are off-peak.
4. Money is represented internally as integer paise.
5. A journey is accepted only when the remaining card balance is at least ₹50.
6. Task 12 adds Airport at ₹60 and a 10% weekend discount. The weekend discount replaces, rather than combines with, the peak surcharge. Monthly passes allow unlimited travel in two selected zones.

## Before submission
- Run every program on your own computer.
- Save your own terminal screenshots in the corresponding task folders.
- Record your compiler version and exact commands.
- Check each output against the assignment handout.
- Commit progressively to your own GitHub repository.
- Be prepared to explain and modify the programs in the viva.

The report is intentionally not included; prepare it after completing and verifying implementation, as requested.
