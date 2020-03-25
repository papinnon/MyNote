# Windows SEH Exploit

### What is SEH(Structured Exception Handling)

SEH是windows操作系统异常处理机制，在程序源代码中使用\_\_try,\_\_except,\_\_finally关键字来具体实现。这些并不是编译程序本身所固有的,本质上只不过是对windows内在提供的结构化异常处理的包装。 

[Windows异常和SEH](https://bbs.pediy.com/thread-249592.htm)

SEH以链的形式存在。第一个异常处理中未处理相关异常，它就会被传递到下一个异常处理器，直到得到处理。SEH是由_EXCEPTION_REGISTRATION_RECORD结构体组成的链表。

```c
ntdll!_EXCEPTION_REGISTRAranTION_RECORD
   +0x000 Next             : Ptr32 _EXCEPTION_REGISTRATION_RECORD
   +0x004 Handler          : Ptr32 _EXCEPTION_DISPOSITION 
}
```



**SEH链表表项在当前子例程的栈帧中**。



### Exploiting SEH

覆盖 record.next 为 jmp near 的机器码( 0xeb xxx)。

覆盖 record.handler 为 "pop pop ret ” gadget 的地址。

这是因为操作系统**跳到handler执行时**，栈上第三个元素是 &record.next。这样可以控制 IP 到栈上。

* 绕过SafeSEH: 寻找 一个未开启保护模块中的 "pop pop ret" gadget
* SEHOP