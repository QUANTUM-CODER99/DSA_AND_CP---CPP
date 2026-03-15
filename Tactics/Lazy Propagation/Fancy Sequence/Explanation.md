# 🎯 Fancy Sequence — Lazy Propagation with Modular Inverse

**Username:** Aethernox
**Date:** 15/03/2026

---

## 🧠 My Core Idea — Why This Approach?

The naive approach would be to loop over every element in the array every time `addAll()` or `multAll()` is called. But that's $O(n)$ per operation — too slow when we have thousands of calls.

So I asked myself:

> *"Instead of transforming all elements on every call, what if I track the global transformation and normalize each element at insertion time?"*

This is the **lazy propagation** trick. I maintain two global variables:

| Variable | Meaning |
|----------|---------|
| `add` | The total amount added to every element so far |
| `mult` | The total multiplier applied to every element so far |

At any point in time, the **actual value** of a stored element `v[i]` is:

$$\text{actual}(i) = v[i] \times \text{mult} + \text{add} \pmod{10^9+7}$$

This means `getIndex()` is always $O(\log MOD)$ (just a formula evaluation with modular inverse), and `addAll()` / `multAll()` are $O(1)$.

---

## 🔢 The Normalization Trick in `append(val)`

When I insert a new value `val`, the global state already has some `add` and `mult` baked in. But I want to store elements in a **canonical normalized form** so the formula above always works.

I need to find the stored value `s` such that:

$$s \times \text{mult} + \text{add} \equiv \text{val} \pmod{MOD}$$

Solving for `s`:

$$s = (\text{val} - \text{add}) \times \text{mult}^{-1} \pmod{MOD}$$

Here, $\text{mult}^{-1}$ is the **modular inverse** of `mult`, computed using **Fermat's Little Theorem**:

$$a^{-1} \equiv a^{p-2} \pmod{p} \quad \text{where } p = 10^9 + 7 \text{ (prime)}$$

---

## ⚙️ How `multAll(m)` Works

When I multiply everything by `m`, the new actual value becomes:

$$\text{new actual}(i) = v[i] \times (\text{mult} \times m) + (\text{add} \times m)$$

So I update **both** globals:

```
mult = mult * m  (mod MOD)
add  = add  * m  (mod MOD)
```

> 🔑 This is the subtle part — `add` also gets scaled by `m` because the multiplication distributes over the entire expression.

---

## ➕ How `addAll(inc)` Works

When I add `inc` to everything:

$$\text{new actual}(i) = v[i] \times \text{mult} + (\text{add} + \text{inc})$$

So I only update `add`:

```
add = add + inc  (mod MOD)
```

---

## 📊 Step-by-Step Example

Let's trace through this sequence of operations:

```
append(2)
append(3)
addAll(100)
append(5)
multAll(2)
getIndex(0)   → expected: (2 + 100) * 2 = 204
getIndex(1)   → expected: (3 + 100) * 2 = 206
getIndex(2)   → expected: 5 * 2 = 10
```

### Trace Table

> State: `(mult, add)` | Stored `v[]`

| Operation | mult | add | v[0] | v[1] | v[2] | Notes |
|-----------|------|-----|------|------|------|-------|
| Initial   | 1    | 0   | —    | —    | —    | — |
| `append(2)` | 1 | 0 | $s = (2-0)\times1^{-1} = 2$ | — | — | Stored as 2 |
| `append(3)` | 1 | 0 | 2 | $s = (3-0)\times1^{-1} = 3$ | — | Stored as 3 |
| `addAll(100)` | 1 | 100 | 2 | 3 | — | Only `add` changes |
| `append(5)` | 1 | 100 | 2 | 3 | $s = (5-100)\times1^{-1} = -95 \equiv MOD-95$ | Normalized |
| `multAll(2)` | 2 | 200 | 2 | 3 | MOD-95 | Both `mult` and `add` scale |

### Retrieval

$$\text{getIndex}(0) = v[0] \times \text{mult} + \text{add} = 2 \times 2 + 200 = 204 \checkmark$$

$$\text{getIndex}(1) = 3 \times 2 + 200 = 206 \checkmark$$

$$\text{getIndex}(2) = (MOD - 95) \times 2 + 200 \equiv (-95 \times 2) + 200 = -190 + 200 = 10 \pmod{MOD} \checkmark$$

---

## 🧮 The `power()` Function — Fast Exponentiation

To compute $a^{p-2} \pmod{p}$ efficiently, I use **binary exponentiation** (also called exponentiation by squaring):

$$a^n = \begin{cases} 1 & \text{if } n = 0 \\ (a^{n/2})^2 & \text{if } n \text{ is even} \\ a \cdot a^{n-1} & \text{if } n \text{ is odd} \end{cases}$$

This runs in $O(\log n)$ instead of $O(n)$.

---

## ⏱️ Time & Space Complexity

| Operation | Time Complexity | Notes |
|-----------|----------------|-------|
| `append(val)` | $O(\log MOD)$ | One modular inverse via fast exponentiation |
| `addAll(inc)` | $O(1)$ | Just update `add` |
| `multAll(m)` | $O(1)$ | Update `mult` and `add` |
| `getIndex(idx)` | $O(1)$ | Direct formula evaluation |

> $\log(10^9+7) \approx 30$, so modular inverse is essentially constant in practice.

| Space | Complexity | Notes |
|-------|-----------|-------|
| Storage | $O(n)$ | One stored value per appended element |
| Globals | $O(1)$ | Just `add` and `mult` |

**Overall:** $O(n)$ space, $O(\log MOD)$ per `append`, $O(1)$ for all other operations — a massive win over the naive $O(n)$ per `addAll`/`multAll`.

---

## 💡 Key Takeaways

- 🧲 **Lazy propagation**: Don't update all elements — track the transformation globally.
- 🔄 **Normalization on insert**: Store elements in a canonical form so retrieval is always a simple formula.
- 🔢 **Fermat's Little Theorem**: The elegant way to compute modular inverses when the modulus is prime.
- ⚡ **Binary exponentiation**: Keeps the modular inverse computation in $O(\log p)$.

---

*Written by AETHERNOX | LeetCode 1622 — Fancy Sequence*
