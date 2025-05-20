# Завдання 1:  GLV Multiplication on BN254

Цей репозиторій містить покрокову реалізацію алгоритму GLV-множення на еліптичній кривій BN254. Він відповідає пунктами A1–A5 Завдання 1.

## Структура папки `glv_bn254_code/`

```
A1_endomorphism_omega.py      # Обчислення ω — нетривіального кубічного кореня з 1 у Fp

A2_compute_lambda.py          # Обчислення λ, власного значення для φ(P) = (ωx, y)

A3_glv_decompose.py           # Розклад α → (α₁, α₂) для зменшення розрядності скалярів

A4_shamir_trick.py            # Ефективне обчислення [α₁]P + [α₂]φ(P) методом Шаміра

A5_glv_multiplication.py      # Повна реалізація GLV-множення та порівняння з класикою
```

## Залежності
- Python 3.8+
- `sympy` — для обчислення квадратного кореня з −3 у A2
- `decimal` — високоточна арифметика (A3)

## Запуск
Використовуйте кожен скрипт окремо для перевірки відповідного етапу:
```bash
python A1_endomorphism_omega.py
python A2_compute_lambda.py
python A3_glv_decompose.py
python A4_shamir_trick.py
python A5_glv_multiplication.py
```

## Рекомендоване джерело: *Guide to Elliptic Curve Cryptography* (Hankerson, Menezes, Vanstone).

---

**Попередження:** φ(P) = (ωx, y) не завжди збігається з [λ]P для довільної точки. GLV-множення 
гарантує правильність лише для спеціальних точок або при точній відповідності ендоморфізму.
