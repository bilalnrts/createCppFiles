# The aim of this project :

I was doing the cpp module projects in 42 schools and as you know, in these modules the classes have to be in canonical form and this is very troublesome. I thought how to make it easier and I wrote a short script where you just type the name of the class you want to create. And that's it!

## How To Install
First you need to clone this repository to your desktop (or anywhere else you want. But I will continue explaining the installation process as desktop).
```c
  git clone https://github.com/bilalnrts/createCppFiles.git
```
After cloning, go inside the file
```c
  cd createCppFiles
```
 and run the 'make' command
```c
  make
```
then run this command. (Please make sure you clone the repository to the desktop and make sure of the file name. OTHERWISE IT WILL NOT WORK !)
```c
  export PATH=$PATH:~/Desktop/createCppFiles 
```

And that's it. Enjoy!

## How To Use
It is actually very easy to use. Now you can create any file you want with the 'create' command. There are two 'flags' I want to mention here. These are ```f``` and ```c```.

If you run this command: you will have "<className>.hpp" file in the canonic form
```c
  create <className>
```
If you run this command with the ```f``` flag: you will have a '<className>.hpp' file in canonical form and a '<className>.cpp' file. Example :
```c
  create <className> -f
```
Finally we have the 'c' flag. This flag helps you when you want to avoid creating classes in the canonical form. It creates your file and class with the <className> you specify. It does not include any function. Example :
```c
  create <className> -f -c
```
### That's all. The script is very simple and useful. Please let me know if you improve it! 