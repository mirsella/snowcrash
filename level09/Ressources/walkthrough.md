En jouant avec l'executable, on s'apercoit qu'il affiche la string rentree en argument, en ajoutant sa position dans la string a la valeur ascii de chaque caractere.

```bash
./level09 aaaaaaaaaaaaaaaaaaaaaaaaaa
abcdefghijklmnopqrstuvwxyz
```

Le token du fichier est encode avec la meme methode, on peut donc le decoder en soustrayant la position du caractere a sa valeur ascii.

```c
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	(void) argc;
	int fd = open(argv[1], O_RDONLY);
	char buf[25] = {0};
	read(fd, buf, 25);
	for (int i = 0; i < 25; i++) {
		buf[i] = buf[i] - i;
	}
	write(1, buf, 25);
}
```

```bash
cc main.c ; ./a.out token
f3iji1ju5yuevaus41q1afiuq
```

Petit piege, le token n'est pas le flag, mais le mot de passe pour se connecter au compte `flag09`.
Alors on a juste a se connecter a celui ci et faire getflag !
