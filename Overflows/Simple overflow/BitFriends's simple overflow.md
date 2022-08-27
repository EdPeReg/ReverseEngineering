2022-08-27 13:24

When you run the program, my mission is to get **logged as an admin**

![image](https://user-images.githubusercontent.com/30558331/187045443-89ba6b17-5abc-4d55-adc3-0d7411cfe101.png)


Using Guidra to analyze the code, we can see some interesting points in the login() function:

1. We are using ***malloc***, allocating in the heap some blocks of memory. 16 bytes for the user password and 8 bytes for the user's id.

```
  password = (char *)malloc(0x10);
  id = (uint *)malloc(8);
```

In a 64 bit-system, the smallest allowed allocation for malloc is 32 bytes (REMEMBER THIS). This is because malloc uses ***dlmalloc*** (Doug Lea memory allocator).

2. Now, here is the hint to see that we can overflow the user's password:

```
  fgets(password,0xa0,stdin);
```

We are reading from the standard input a size of 0xa0 (160) and store it in our password, we can read more than 0x10, we can overflow.

3. The user's "id" has a value 1, and our goal is to change it to 0.

How can we do that? Well, we need to input a string of length 31, why 31? because the smallest allowed  allocation for malloc is 32 bytes, there are **16 bytes we can use without any problem but other 16 bytes free**, after those bytes you will find the first block of memory that the user's id have. fgets appends the null terminator (remember, its value is 0), **we need to insert that null terminator to the first block of memory from from the user's id.**

![image](https://user-images.githubusercontent.com/30558331/187045464-0c9d3ce8-8a3c-46c2-ba82-fb78e869bbea.png)


As we can see above, if we enter a string of 31 length, with the null terminator appended, we will invade the next block of memory, which belongs to user's id, changing the value from 1 to 0 and gaining admin access.

Remember that you should write exactly 31 characters, the last character is the null terminator *\0*, which would be byte 32, or the first byte for the user's id.

**Note:** This is possible because user's id allocation is done after password's allocation:

```
  password = (char *)malloc(0x10);
  uid = (uint *)malloc(8)
```

If you allocate memory between *password* and *uid*, it won't work, because the layout will change.

```
  password = (char *)malloc(0x10);
  var = (uint *)malloc(8)
  uid = (uint *)malloc(8)
```

---

# Refereces
- [Problem link](https://crackmes.one/crackme/5f05ec3c33c5d42a7c66792b)
- [null terminator](https://en.wikipedia.org/wiki/Null_character)
- [dlmalloc](https://cw.fel.cvut.cz/old/_media/courses/a4m33pal/04_dynamic_memory_v6.pdf)
- [How much memory malloc allocates](https://prog21.dadgum.com/179.html#:~:text=In%20dlmalloc%20%2C%20the%20smallest%20allowed,(1)%20allocates%2032%20bytes.)

