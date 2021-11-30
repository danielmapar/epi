# Elements of Programming Interviews in C++ - Notes

## Bitwise questions

### Primitive Types

operator	asm equivalent	description
* `&`	AND	Bitwise AND
* `|`	OR	Bitwise inclusive OR
* `^`	XOR	Bitwise exclusive OR
* `~`	NOT	Unary complement (bit inversion)
* `<<`	SHL	Shift bits left
* `>>`	SHR	Shift bits right

* Question: `count_bits.cc`
    * Use of `&` operand and `00000001` to isolate the right most bit of a number.

* Question: `parity.cc`
    * We can use the `&` operator to determine the presence of `1`s and `0`s in the number. Based on that we can establish if the number of `1` aka parity (odd or even)
        * `&` is good to isolate a bit

* Question: `swap_bits.cc`
    * Swapping two distinct bits from a number X. 
    * In order to do that we can use the `>>` (shift) operator to isolate the two bits. Then we can create two new numbers (`0000000`) and inject the isolated bits via shift (`<<`). Finally, we can use the OR `|` operator to merge the two new numbers and use the XOR `^` operator to switch the bits from the original number.
        * `|` is useful to merge bits from two numbers
        * `^` is useful to switch a bit on and off in a number

* Question: `reverse_bits.cc`
    * We can reverse a numbers bits by using the `&` operand to isolate the right most bit and re-injecting it to a new number via the `<<` operand.

* Question: `closest_int_same_weight.cc`
    * We calculate the weight of a binary stream by calculating the number of `1` in it. For example, for number (`3` = `00000011`) has a weight of `2`.
    * The closest number to `00000011` (`3`) with the same weight is `00000101` (`5`).
    * In order to do that we can create a new number (mask = `00000011`) that will carry the number to be switched. Example `00000110`. The mask is initialized with `11` because we want to guarantee it to change the neighbour bits.
    * The mask will be applied to the original number using the XOR operator `^`.

* Question: `primitive_multiple.cc`
    * This one is not the most intuitive, but we basically can re-create a `add` function by using `&` to find the carry and `^` to merge two numbers. We can repeat the `add` function X times to simulate a multiplication.

* Question: `primitive_divide.cc`
    * We can find the quotient of a division by doing the same strategy as the multiplication problem. We can do N subtractions to a number to find its quotient. Example: `n / m` = `((n - m) - m) - m...`

* Question: `power_x_y.cc`
    * We can use the same strategy as the divide problem. `pow(m, n)` can be found by doing `result = ((m * m) * m) * m` about `n` times. If the exponential is negative remember to `1 / result`