
# ECDSA Key Recovery on Edwards Curve (Vulnerable Library Exploit)

## Overview

This project demonstrates how a poor implementation of ECDSA (k = h mod n vulnerability) allowed to recover the private key from a single signature.

## Project structure

```
/src
    -> All source files (library + test program)
README.md
LICENSE
task.md
task.pdf
```

## Vulnerability exploited

The vulnerable library used the following method for nonce (k) generation:

```
k = h mod n
```

This made it possible to recover the private key using only (r, s) signature and message hash (h).

## Verification

The private key was recovered, then used to re-generate the signature.  
Resulting (r, s) perfectly matched the original signature from the task.

```
r = 03ed92681510ac291c473a58eceee7ad4c181ceb781bf8faeadee47fde4c5e48
s = 048bcd9074a0bea08a601089017700219a2c577e6abf32364febe3a6ceea6ec8
```

## Conclusions

This proves that the recovered private key is correct and the vulnerability is fully exploitable.

## Epilogue

> "There is no cipher made by man that cannot be decrypted. If cryptanalysis fails, there's always the universal tool: the thermorectal cryptoanalyzer. However, it only works in the physical presence of the encryptor." — A seasoned cryptanalyst :)

## License

MIT License
