en faisant `grep flag01 /etc/passwd` on obtient `flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash`.
puis en utilisant johntheripper sur le fichier passwd, il crack le hash en une fraction de seconde.
`john -show hash.txt` -> flag01:*abcdefg*:3001:3001::/home/flag/flag01:/bin/bash
