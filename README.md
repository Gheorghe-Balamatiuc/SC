# Algoritmi de criptare

Acest proiect conține implementarea a 2 algoritmi de criptare: **Algoritmul lui Caesar** (cifru de substituție), **Cifru transpunere coloane**.

## Algoritmul lui Caesar

### Descriere

Cifrul Caesar este un algoritm simplu de criptare care implică deplasarea fiecărei litere dintr-un text cu un număr fix de poziții în alfabet. Este un exemplu de cifru de substituție monoalfabetic. Deplasarea este determinată de o cheie numerică.

### Rulare program

1. Compilați programul folosind GCC:
```powershell
gcc caesar.c -o caesar.exe
```
2. Rulați programul specificând modul (`-e` pentru criptare sau `-d` pentru decriptare), fișierul de intrare, cheia și fișierul de ieșire:
```powershell
./caesar.exe -e input.txt -k 3 -o output.txt
```
- `-e`: Criptare
- `-d`: Decriptare
- `-k`: Cheia (număr întreg)
- `-o`: Fișierul de ieșire

### Exemplu

Comandă:
```powershell
./caesar.exe -e input.txt -k 3 -o output.txt
```
Fișierul input.txt:
```
Hello, World!
```
Fișierul output.txt:
```
Khoor, Zruog!
```

## Cifru transpunere coloane

### Descriere

Cifrul de transpunere pe coloane implică rearanjarea caracterelor unui text în funcție de un număr de coloane specificat de o cheie. Textul este scris într-o matrice pe rânduri, iar ieșirea este obținută citind matricea pe coloane.

### Rulare program

1. Compilați programul folosind GCC:
```powershell
gcc transposition.c -o transposition.exe
```

2. Rulați programul specificând modul (`-e` pentru criptare sau `-d` pentru decriptare), fișierul de intrare, cheia și fișierul de ieșire:
```powershell
./transposition.exe -e input.txt -k 3 -o output.txt
```
- `-e`: Criptare
- `-d`: Decriptare
- `-k`: Cheia (număr întreg pozitiv)
- `-o`: Fișierul de ieșire

### Exemplu

Comandă:
```powershell
./transposition.exe -e input.txt -k 3 -o output.txt
```
Fișierul input.txt:
```
Hello, World!
```
Fișierul output.txt:
```
Hl r!eoWl_l,od_
```
