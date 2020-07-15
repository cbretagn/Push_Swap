# Push_Swap

## Assignment

Write two programs
- `./checker` takes a list of numbers as parameter, treats it as a pile, then reads moves on standard input, checks if the moves sort the pile and prints either `OK` or `KO`
- `./push-swap` takes a list of numbers as parameter, treats it as a pile, then prints a list of moves to sort the pile. Goal is to sort it in as few moves as possible.

Both programs have access to pile A, filled with the numbers passed as parameters, and pile B which starts empty. Authorized moves are :
- **pa / pb** : push the first element of pile B to pile a / of pile A to pile B *ie push to A / push to B*
- **sa / sb** : swap the first and second element of pile A / of pile B
- **ss** : do sa and sb
- **ra / rb** : rotate pile A / pile B (first element becomes the last, second becomes first, ...)
- **rr** : do ra and rb
- **rra / rrb** reverse rotate pile A / pile B (last element becomes the first, first becomes second, ...)
- **rrr** : do rra and rrb

## How to run it

`make`
`./push-swap 0 -256 12 4 7 789456` (parameters must be integers)
`./push-swap 1 2 5 -8 96 | ./checker 1 2 5 -8 96` to check validity

## Bonus

`./random.sh` lets you run `./push-swap` on a number of different piles to see the average number of moves
