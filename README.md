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

### Testcases

**Testcase 1**

Comandă:
```powershell
./caesar.exe -e input.txt -k 3000 -o output.txt
```
Fișierul input.txt:
```
These are short, famous texts in English from classic sources like the Bible or Shakespeare. Some texts have word definitions and explanations to help you. Some of these texts are written in an old style of English. Try to understand them, because the English that we speak today is based on what our great, great, great, great grandparents spoke before! Of course, not all these texts were originally written in English. The Bible, for example, is a translation. But they are all well known in English today, and many of them express beautiful thoughts.
```
Fișierul output.txt:
```
Droco kbo crybd, pkwyec dohdc sx Oxqvscr pbyw mvkccsm cyebmoc vsuo dro Lslvo yb Crkuoczokbo. Cywo dohdc rkfo gybn nopsxsdsyxc kxn ohzvkxkdsyxc dy rovz iye. Cywo yp droco dohdc kbo gbsddox sx kx yvn cdivo yp Oxqvscr. Dbi dy exnobcdkxn drow, lomkeco dro Oxqvscr drkd go czoku dynki sc lkcon yx grkd yeb qbokd, qbokd, qbokd, qbokd qbkxnzkboxdc czyuo lopybo! Yp myebco, xyd kvv droco dohdc gobo ybsqsxkvvi gbsddox sx Oxqvscr. Dro Lslvo, pyb ohkwzvo, sc k dbkxcvkdsyx. Led droi kbo kvv govv uxygx sx Oxqvscr dynki, kxn wkxi yp drow ohzbocc lokedspev dryeqrdc.
```

**Testcase 2**

Comandă:
```powershell
./caesar.exe -d input.txt -k 3000 -o output.txt
```
Fișierul input.txt:
```
Droco kbo crybd, pkwyec dohdc sx Oxqvscr pbyw mvkccsm cyebmoc vsuo dro Lslvo yb Crkuoczokbo. Cywo dohdc rkfo gybn nopsxsdsyxc kxn ohzvkxkdsyxc dy rovz iye. Cywo yp droco dohdc kbo gbsddox sx kx yvn cdivo yp Oxqvscr. Dbi dy exnobcdkxn drow, lomkeco dro Oxqvscr drkd go czoku dynki sc lkcon yx grkd yeb qbokd, qbokd, qbokd, qbokd qbkxnzkboxdc czyuo lopybo! Yp myebco, xyd kvv droco dohdc gobo ybsqsxkvvi gbsddox sx Oxqvscr. Dro Lslvo, pyb ohkwzvo, sc k dbkxcvkdsyx. Led droi kbo kvv govv uxygx sx Oxqvscr dynki, kxn wkxi yp drow ohzbocc lokedspev dryeqrdc.
```
Fișierul output.txt:
```
These are short, famous texts in English from classic sources like the Bible or Shakespeare. Some texts have word definitions and explanations to help you. Some of these texts are written in an old style of English. Try to understand them, because the English that we speak today is based on what our great, great, great, great grandparents spoke before! Of course, not all these texts were originally written in English. The Bible, for example, is a translation. But they are all well known in English today, and many of them express beautiful thoughts.
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

### Testcases

**Testcase 1**

Comandă:
```powershell
./transposition.exe -e input.txt -k 3 -o output.txt
```
Fișierul input.txt:
```
These are short, famous texts in English from classic sources like the Bible or Shakespeare. Some texts have word definitions and explanations to help you. Some of these texts are written in an old style of English. Try to understand them, because the English that we speak today is based on what our great, great, great, great grandparents spoke before! Of course, not all these texts were originally written in English. The Bible, for example, is a translation. But they are all well known in English today, and many of them express beautiful thoughts.
```
Fișierul output.txt:
```
Tsa o,auttiElhr aisrsi eierheeeSeesa rditna pnisoe uSefheesrwtnnnlsloElhT  dsntmbaehElhh  e d  s  ao e,rtga e apespeer  uen lheese inlwtnnni.hBl rxp,s ali.utyra lkwiElhoya notmxe ailhgshersr msesnni ocscoc kt b  asa.o x vwdenisnelao  ly.o  e x ert   dtefni.rtuetdh,eu eni awsataibeowtuga e,rtgagnan o feOcr,oa e x rogayrt  gs eief al  tnao th elwlnnnni d,nmyfh psbuf oh.e ehtfo x  gsfmls uelehBloSkpr mttheo fio dxatnthpo motstta ieiao y  gs yonra e cst gsttepkoysadnh rrtga e,rtrdrtskbo!fos tltsttweril ieiElhT b,oemeiarstnB ea le o  gsta da  eersetutut_
```

**Testcase 2**

Comandă:
```powershell
./transposition.exe -d input.txt -k 3 -o output.txt
```
Fișierul input.txt:
```
Tsa o,auttiElhr aisrsi eierheeeSeesa rditna pnisoe uSefheesrwtnnnlsloElhT  dsntmbaehElhh  e d  s  ao e,rtga e apespeer  uen lheese inlwtnnni.hBl rxp,s ali.utyra lkwiElhoya notmxe ailhgshersr msesnni ocscoc kt b  asa.o x vwdenisnelao  ly.o  e x ert   dtefni.rtuetdh,eu eni awsataibeowtuga e,rtgagnan o feOcr,oa e x rogayrt  gs eief al  tnao th elwlnnnni d,nmyfh psbuf oh.e ehtfo x  gsfmls uelehBloSkpr mttheo fio dxatnthpo motstta ieiao y  gs yonra e cst gsttepkoysadnh rrtga e,rtrdrtskbo!fos tltsttweril ieiElhT b,oemeiarstnB ea le o  gsta da  eersetutut_
```
Fișierul output.txt:
```
These are short, famous texts in English from classic sources like the Bible or Shakespeare. Some texts have word definitions and explanations to help you. Some of these texts are written in an old style of English. Try to understand them, because the English that we speak today is based on what our great, great, great, great grandparents spoke before! Of course, not all these texts were originally written in English. The Bible, for example, is a translation. But they are all well known in English today, and many of them express beautiful thoughts.
```
