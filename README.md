#Brain Double F\*\*\*
This is an extension to the BF language which adds several new operators and a second tape.

The new operators allow you to modify the loaded BF program so that BF code can be modified on the fly.

The second tape contains the loaded program stored as integers % 16 and map to the different operators.

The mappings are as follows

> 00 -> _ `This is a nop`

> 01 -> +	`Increment the selected cell`

> 02 -> - `Decrement the selected cell`
> 03 -> > `Move the selector right`
> 04 -> < `Move the selector left`
> 05 -> [ `If the selected cell is 0, jump to the corresponding ']'`
> 06 -> ] `If the selected cell is not 0, jump to the corresponding '['
> 07 -> . `Print the selected cell to stdout`
> 08 -> , `Read a byte from stdin and store it in the selected cell`
> 09 -> * `Increment the selected cell in the program tape`
> 10 -> / `Decrement the selected cell in the program tape`
> 11 -> ^ `Move the program selector up in the program (backwards)`
> 12 -> v `Move the program selector down in the program (forwards)`
> 13 -> # `Halt the program`
> 14 -> ~ `Dump the program tape to stdout`
> 15 -> ! `Dump the memory tape to stdout`

##Building
Use compile.sh to build the program. Providing any parameter (doesn't matter what it is) will enable debug mode.

##Running
./bdf <programName.bdf> [SlowMode]

If a parameter (doesn't matter what it is) is provided for SlowMode the program will wait 1s between each step in the code.
