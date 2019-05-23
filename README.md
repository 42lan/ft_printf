# ft_printf
Implementation of my own printf function in C because I’m fed up alternating the **ft_putnbr()** and **ft_putstr()** when doing my printing.

### Introduction
Regardless of the programming language considered, the **printf** function, (or its equiv-alents) is always highly useful.
The main reason is the ease of its formatting, and the support of diverse types in variable numbers.
Some variations even propose to be able to write the resulting string of characters either in a file descriptor
or in a particular stream. Some also propose to recall this string without printing it.
</br></br>
In short, undeniably, **printf** is a vital function. In this project, I asked to recode it and add it to my **libft** so that
I can use it in all my future projects, such as **ft_ls**..
</br></br>
It was a chance for me to discover a feature of the C language – *variadic functions* – and to practice
detailed management of the printing options.


# Speed test
On iMac (Late 2012) the average result is **121%**

> 129 124 128 116 117 115 122 124 118 126 120 114 121 120 122 117 **137** 126 121 118 117 122 122 123 115 125 123 117 121 121 130 122 120 122 124 123 124 119 124 121 121 117
```
macOS Sierra	10.12.6 (16G29)
Processor	2,9 GHz Intel Core i5
Memory		8 GB 1600 MHz DDR3
```
</br></br>
On MacBook Pro  (Early 2015) the average result is **137%**
> 133 133 130 134 134 150 132 134 140 135 138 134 114 134 131 134 135 142 128 133 134 165 121 137 130 203 103 131 137 133 146 136 134 130 126 120 130 134 135 131 132 **256**
```
macOS Sierra	10.12.6 (16G1918)
Processor	3,1 GHz Intel Core i7
Memory		16 GB 1867 MHz DDR3
```
