.class public test2
.super java/lang/Object
.field public static aa I
.field public static bb I
.field public static cc I
.field public static g [[[I
.field public static r [[I
.method public static ss()V
.limit locals 50
.limit stack 50
    ldc 0
    istore 0
    return
.end method
.method public static tt(IIFF)I
.limit locals 50
.limit stack 50
    ldc 0
    istore 4
    ldc 3
    ldc 4
    ldc 5
    imul
    iadd
    istore 4
    iload  4
    invokestatic io/writelnI(I)V
    iload  0
    ldc 5
    iadd
    ireturn
.end method
.method public static main([Ljava/lang/String;)V
.limit locals 50
.limit stack 50
    ldc 0
    putstatic test2/aa I
    ldc 0
    putstatic test2/bb I
    ldc 0
    putstatic test2/cc I
    ldc 2
    ldc 2
    ldc 2
    multianewarray [[[I 3
    putstatic test2/g [[[I
    ldc 2
    ldc 2
    multianewarray [[I 2
    putstatic test2/r [[I
    getstatic test2/aa I
    ldc 3
    getstatic test2/bb I
    imul
    iadd
    ldc 4
    ldc 2
    idiv
    isub
    putstatic test2/aa I
    getstatic test2/aa I
    invokestatic io/writelnI(I)V
    getstatic test2/bb I
    invokestatic io/writelnI(I)V
    getstatic test2/aa I
    getstatic test2/bb I
    if_icmple L1
    ldc 0
    goto L2
L1:
    ldc 1
L2:
    ifne L3
    ldc 222
    putstatic test2/aa I
    goto L4
L3:
    getstatic test2/aa I
    ldc 0
    if_icmplt L5
    ldc 0
    goto L6
L5:
    ldc 1
L6:
    ifne L7
    ldc 111
    putstatic test2/aa I
    goto L8
L7:
    ldc 333
    putstatic test2/aa I
    goto L8
L8:
    goto L4
L4:
    getstatic test2/aa I
    invokestatic io/writelnI(I)V
L9:
    getstatic test2/bb I
    ldc 5
    if_icmplt L10
    ldc 0
    goto L11
L10:
    ldc 1
L11:
    ifeq L12
    ldc 0
    putstatic test2/aa I
L13:
    getstatic test2/aa I
    ldc 5
    if_icmplt L14
    ldc 0
    goto L15
L14:
    ldc 1
L15:
    ifeq L16
    getstatic test2/aa I
    ldc 1
    iadd
    putstatic test2/aa I
    goto L13
L16:
    getstatic test2/bb I
    ldc 1
    iadd
    putstatic test2/bb I
    getstatic test2/bb I
    invokestatic io/writelnI(I)V
    goto L9
L12:
    getstatic test2/g [[[I
    ldc 0
    ldc 0
    isub
    aaload
    ldc 3
    ldc 2
    isub
    aaload
    ldc 4
    ldc 4
    isub
    getstatic test2/aa I
    getstatic test2/r [[I
    ldc 1
    ldc 0
    isub
    aaload
    ldc 4
    ldc 4
    isub
    iaload
    iadd
    ldc 2
    ldc 3
    ldc 4.000000
    ldc 6.500000
    invokestatic test2/tt(IIFF)I
    iadd
    iastore
    getstatic test2/g [[[I
    ldc 0
    ldc 0
    isub
    aaload
    ldc 3
    ldc 2
    isub
    aaload
    ldc 4
    ldc 4
    isub
    iaload
    invokestatic io/writelnI(I)V
    return
.end method
