from the code we can see a server listening on 5151. it's checking a hash in sha1sum but we don't care about that.
to calculate the hash it call shell code, and the user input is expanded in the shell as is,
so we can just send this to the server using `nc 0.0.0.0 5151` :
`;getflag>tmp/a` and get the token in tmp/a
