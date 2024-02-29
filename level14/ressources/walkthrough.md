this last user don't have anything to exploit, which lets us with getflag. we will hack the command getflag itself.
there is probably multiple way of doing it. opening it in binaryninja we see multiple anti debugging measures :
![anti debug measures](./antidebug.png)
after that a forest of if else that call the ft_des function with a token for each userid.
![original tokens](./original-tokens.png)
the ft_des function decode thoses token to give us the end flag.
![ft_des](./ft_des.png)

we will launch the program with gdb and jump to the call to fputs and ft_des to get the token and the flag.

```shell
gdb getflag
breakpoint main
run
jump *0x8048de5
```

the program will print the token as if the if statement was true. we get the flag
