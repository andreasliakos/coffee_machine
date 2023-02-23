# coffee_machine
This program is a simulation of a coffee vending machine in C++, which allows the user to select various drinks and pay for them.

1) Coffee for €1.5

2) Coffee with milk for €1.8

3) Hot chocolate for €2.1

4) Hot chocolate with milk for €2.4

5) Refill (coffee, chocolate and milk)

-1. Exit

Initially, the coffee vending machine will have enough materials to make 10 coffees, 10 hot chocolates and add milk to 20 drinks. With each drink preparation, the available stock will be reduced by one unit. When the quantity is not sufficient to prepare the selected drink, a suitable message will be displayed to the user. When the available quantity is sufficient to prepare the selected drink, payment will be requested. The user will be allowed to enter only coins and banknotes of 10 cents, 20 cents, 50 cents, 1 euro, 2 euros, 5 euros and 10 euros. After each coin or banknote is entered, the amount remaining to pay for the drink will be displayed. When the amount is paid, the change that must be returned will be displayed, using the smallest possible number of coins and banknotes. During the coin and banknote entry, if the value -1 is entered, the order will be canceled, and the coins and banknotes that have already been entered will be returned to the user.
