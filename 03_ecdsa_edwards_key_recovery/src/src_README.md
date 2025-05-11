
# Source Code Overview (src/)

This folder contains the source code used to perform ECDSA signature generation
with a vulnerable implementation (k = h mod n). It allows recovering the private key and verifying the signature.

## Files description

### main.c
Demo program that:
- Initializes curve parameters.
- Loads recovered private key and message hash.
- Signs the message and prints (r, s) signature values.

### dsa.c
ECDSA signature algorithm implementation:
- Generates k = h mod n (vulnerable)
- Computes signature (r, s)
- Debug prints signature values

### ec.c
Elliptic curve point operations (basic):
- Point initialization, copy, multiplication.
- Required for signature process.

### gf.c
Big integer arithmetic:
- Addition, subtraction, multiplication, modulo and inversion.
- Used internally by elliptic curve calculations.

### ec.h
Header file for elliptic curve operations and structures.

### dsa.h
Header file for ECDSA signature structure and sign function.

### gf.h
Header file for big integer operations.

---

All of these files together are required to produce and verify ECDSA signature in the context of the recovered private key demonstration.
