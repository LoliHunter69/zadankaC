# zadankaC

## Kolorowanie tekstu w linuxowym terminalu C

`printf("\033[1;31mbold red text\033[0m\n");`

`\033[` + Styl [+ `;`+ Styl...] +`m`+ _NASZ_TEKST_ + `\033[` + Styl [np. `0`(reset)] + `m`

Styl- Kolor:
```
         foreground background
black        30         40
red          31         41
green        32         42
yellow       33         43
blue         34         44
magenta      35         45
cyan         36         46
white        37         47
```

Styl- Modyfikacje tekstu:
```
reset             0  (everything back to normal)
bold/bright       1  (often a brighter shade of the same colour)
underline         4
inverse           7  (swap foreground and background colours)
bold/bright off  21
underline off    24
inverse off      27
```
