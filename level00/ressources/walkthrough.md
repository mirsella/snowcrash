# Level00

En arrivant l'iso est vide, mais apres une recherche sur discord, j'ai trouve le README qu'il y avait avant sur le projet, disant:<br>
_`FIND this first file who can run only as flag00`_

La commande `find / -user flag00 2>/dev/null` permet donc de trouver tous les fichiers qui appartiennent a l'utilisateur flag00.(`2>/dev/null` permet de ne pas afficher les erreurs)

```sh
find / -user flag00 2>/dev/null
/usr/sbin/john
/rofs/usr/sbin/john
```

Maintenant, si on cat le /usr/sbin/john, on obtient:

```sh
cat /usr/sbin/john
cdiiddwpgswtgt
```

En essayant ce flag, cela ne marche pas, mais en le mettant sur le site [Dcode](https://www.dcode.fr/chiffre-cesar), on voit qu'il a ete chiffre avec un chiffrement de Cesar, avec un decalage de 15 caracteres.
Le flag est donc `nottoohardhere`.
