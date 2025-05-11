
# Brute-force пошук k для ECDSA (демонстраційна версія, приклад простого перебору)

from Crypto.Util.number import inverse

# Параметри
n = 0x4000000000000000000000000000000029E26087789BC2815BDFF97093543CCF
r = 0x03ED92681510AC291C473A58ECEEE7AD4C181CEB781BF8FAEADEE47FDE4C5E48
s = 0x048BCD9074A0BEA08A601089017700219A2C577E6ABF32364FEBE3A6CEEA6EC8
h = 0x5433A582070AF8FBAFDF65B5310CA99164F4F3DE016194163B239412F778A16B

# Перебираємо k (демонстраційно перевіримо h % n спочатку)
k_guess = h % n

# Обчислимо можливий d
d = ((s * k_guess - h) * inverse(r, n)) % n

# Відтворимо підпис
r_check = (k_guess % n)

print("Guessed k =", hex(k_guess))
print("Recovered d =", hex(d))
print("Recomputed r =", hex(r_check))

if r_check == r:
    print("Found correct k!")
else:
    print("Incorrect k (this should not happen if k = h mod n is true)")
