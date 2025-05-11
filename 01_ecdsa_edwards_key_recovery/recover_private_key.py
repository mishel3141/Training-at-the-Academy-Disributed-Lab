
# Відновлення приватного ключа ECDSA (формула) на основі підпису (r, s) та хешу повідомлення (h)
# Параметри задачі (всі числа вказані у шістнадцятковій формі)

from Crypto.Util.number import inverse

# Параметри
n = 0x4000000000000000000000000000000029E26087789BC2815BDFF97093543CCF
r = 0x03ED92681510AC291C473A58ECEEE7AD4C181CEB781BF8FAEADEE47FDE4C5E48
s = 0x048BCD9074A0BEA08A601089017700219A2C577E6ABF32364FEBE3A6CEEA6EC8
h = 0x5433A582070AF8FBAFDF65B5310CA99164F4F3DE016194163B239412F778A16B

# Крок 1: Припускаємо уразливу реалізацію: k = h mod n
k = h % n

# Крок 2: Знаходимо обернене до r по модулю n
def modinv(a, n):
    return pow(a, -1, n)
r_inv = modinv(r, n)

# Крок 3: Відновлюємо d (приватний ключ)
d = (s * k - h) * r_inv % 

print(f"Private key d = {hex(d)}")
