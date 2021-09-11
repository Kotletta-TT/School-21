#ft_printf - project by School 21

## Base version

### How it works

1.Parse flags/nums - Flags maybe any sequence, general remember formating string start - %, end - any symbol not in flags/nums  
Example:  
`%(flags/nums)specifier`  
`%-5.10s` - flag minus, width = 5, flag dot, precision = 10, specifier = s(string)  
`%.10-5s` - the same thing  

Little parsing rules:  
- (After the dot is a number is always - precision)  
- (Minus in printing have high priority than zero);


1.1 If specifier not in specifiers - "sudipcxX" symbol not flags and not num it will be character specifier and all flags apply to him  
Example:  
`|%07.2M|` - printed: `|000000M|`  


####- d,i flags: logic printf

```c
result = 0;
if (dot)
	//special case - empty print
    if (!precision && !num)
    	my_flag = 2;
    	//nothing print, but width active! examples:
        printf("|%.0d|", 0); // printed: ||
        //simillary
        printf("|%.d|", 0); // printed: || because dot without nums equal precision = 0; 
    if (precision > num)
    	//add 0`s to at the top num by formula:
    	    //precision - len(num) = count 0 add to the number examples:
    	    printf("%.3d", 10); // printed: 010; len(10) = 2; 
    	    printf("%.3d", -10); // printed: -010; len(-10) = 3 but precision not include sign.
    //Two ways:
        //1. malloc int + precision - easy way but not recommended, you need future free memory
        //2. build logic correctly when printing - hard way but, right and fast.
        // I use 2. - special switch flags - (for example: my_flag = 0, 1, 2) - for special cases i use by printing;
        // And i use variable int zeroes_precision which by print while printing, and sign variable by print sign;
    //special case - zero changes to space, if there is a dot-flag
    if (width > len(num) + precision && ((zero && !minus) || (!zero && !minus))) // examples:
	    printf("%3.2d|", 1); //printed: | 01|
	    printf("|%3.2d|", -1); //printed: |-01| !the sign num refers to len(d)!
if (width)
    while (width-- && my_flag == 2)
        ft_putchar(1, ' ', 1);
        result++;
	if (zero && !minus) // Yes, they both maybe in format string, but minus high priority by formating
	{
	    if (sign && my_flag != 2)
	        while (width-- > (sign + zeroes_precision + len(num)) && dot) // It is this sequence
	        	ft_putchar(1, ' ', 1);
	            result++;
	        while (width-- > (sign + len(num)) && !dot)
	            ft_putchar(1, '0', 1);
	            result++;
	    else if (!sign && my_flag != 2)
	        while (width-- > (zeroes_precision + len(num)) && dot)
	            ft_putchar(1, ' ', 1);
	            result++;
	        while (width-- > (len(num)) && !dot)
	            ft_putchar(1, '0', 1);
	            result++;
	}
	if (!zero && !minus)
    {
	    if (sign && my_flag != 2)
	        while (width-- > (sign + zeroes_precision + len(num)))
	            ft_putchar(1, ' ', 1);
	            result++;
        else if (!sign && my_flag != 2)        
            while (width-- > (zeroes_precision + len(num)))
                ft_putchar(1, ' ', 1);
                result++;    
    }
	if (minus)
    {
		print_num_func();
		if (sign && my_flag != 2)
		    while (width-- > (sign + zeroes_precision + len(num)))
		        ft_putchar(1, ' ', 1);
		        result++;
		else if (!sign && my_flag != 2)
		    while (width-- > (zeroes_precision + len(num)))
		        ft_putchar(1, ' ', 1);
		        result++;
    }
if (!width)
{
    print_num_func();	
}
```

need struct:  
{  
(int)dot  
(int)width  
(int)precision  
(int)minus  
(int)zero  
(int)zeroes_precision  
(int)len_num  
(int)my_flag  
(int)sign  
(int)result  
}  

neeed functions:  
void print_num_func(structure, arg);  
void putchar_result(char, structure);